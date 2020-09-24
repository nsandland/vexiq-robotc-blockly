/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Helper functions for generating RobotC for blocks.
 * @author fraser@google.com (Neil Fraser)
 */
'use strict';

goog.provide('Blockly.RobotC');

goog.require('Blockly.Generator');
goog.require('Blockly.utils.global');
goog.require('Blockly.utils.string');


/**
 * RobotC code generator.
 * @type {!Blockly.Generator}
 */
Blockly.RobotC = new Blockly.Generator('RobotC');

/**
 * List of illegal variable names.
 * This is not intended to be a security feature.  Blockly is 100% client-side,
 * so bypassing this list is trivial.  This is intended to prevent users from
 * accidentally clobbering a built-in object or function.
 * @private
 */
Blockly.RobotC.addReservedWords(
    // https://developer.mozilla.org/en-US/docs/Web/RobotC/Reference/Lexical_grammar#Keywords
    'break,case,catch,class,const,continue,debugger,default,delete,do,else,export,extends,finally,for,function,if,import,in,instanceof,new,return,super,switch,this,throw,try,typeof,void,while,with,yield,' +
    'enum,' +
    'implements,interface,let,package,private,protected,public,static,' +
    'await,' +
    'null,true,false,' +
    // Magic variable.
    'arguments,' +
    // Everything in the current environment (835 items in Chrome, 104 in Node).
    Object.getOwnPropertyNames(Blockly.utils.global).join(','));

/**
 * Order of operation ENUMs.
 * https://developer.mozilla.org/en/RobotC/Reference/Operators/Operator_Precedence
 */
Blockly.RobotC.ORDER_ATOMIC = 0;           // 0 "" ...
Blockly.RobotC.ORDER_NEW = 1.1;            // new
Blockly.RobotC.ORDER_MEMBER = 1.2;         // . []
Blockly.RobotC.ORDER_FUNCTION_CALL = 2;    // ()
Blockly.RobotC.ORDER_INCREMENT = 3;        // ++
Blockly.RobotC.ORDER_DECREMENT = 3;        // --
Blockly.RobotC.ORDER_BITWISE_NOT = 4.1;    // ~
Blockly.RobotC.ORDER_UNARY_PLUS = 4.2;     // +
Blockly.RobotC.ORDER_UNARY_NEGATION = 4.3; // -
Blockly.RobotC.ORDER_LOGICAL_NOT = 4.4;    // !
Blockly.RobotC.ORDER_TYPEOF = 4.5;         // typeof
Blockly.RobotC.ORDER_VOID = 4.6;           // void
Blockly.RobotC.ORDER_DELETE = 4.7;         // delete
Blockly.RobotC.ORDER_AWAIT = 4.8;          // await
Blockly.RobotC.ORDER_EXPONENTIATION = 5.0; // **
Blockly.RobotC.ORDER_MULTIPLICATION = 5.1; // *
Blockly.RobotC.ORDER_DIVISION = 5.2;       // /
Blockly.RobotC.ORDER_MODULUS = 5.3;        // %
Blockly.RobotC.ORDER_SUBTRACTION = 6.1;    // -
Blockly.RobotC.ORDER_ADDITION = 6.2;       // +
Blockly.RobotC.ORDER_BITWISE_SHIFT = 7;    // << >> >>>
Blockly.RobotC.ORDER_RELATIONAL = 8;       // < <= > >=
Blockly.RobotC.ORDER_IN = 8;               // in
Blockly.RobotC.ORDER_INSTANCEOF = 8;       // instanceof
Blockly.RobotC.ORDER_EQUALITY = 9;         // == != === !==
Blockly.RobotC.ORDER_BITWISE_AND = 10;     // &
Blockly.RobotC.ORDER_BITWISE_XOR = 11;     // ^
Blockly.RobotC.ORDER_BITWISE_OR = 12;      // |
Blockly.RobotC.ORDER_LOGICAL_AND = 13;     // &&
Blockly.RobotC.ORDER_LOGICAL_OR = 14;      // ||
Blockly.RobotC.ORDER_CONDITIONAL = 15;     // ?:
Blockly.RobotC.ORDER_ASSIGNMENT = 16;      // = += -= **= *= /= %= <<= >>= ...
Blockly.RobotC.ORDER_YIELD = 17;           // yield
Blockly.RobotC.ORDER_COMMA = 18;           // ,
Blockly.RobotC.ORDER_NONE = 99;            // (...)

/**
 * List of outer-inner pairings that do NOT require parentheses.
 * @type {!Array.<!Array.<number>>}
 */
Blockly.RobotC.ORDER_OVERRIDES = [
  // (foo()).bar -> foo().bar
  // (foo())[0] -> foo()[0]
  [Blockly.RobotC.ORDER_FUNCTION_CALL, Blockly.RobotC.ORDER_MEMBER],
  // (foo())() -> foo()()
  [Blockly.RobotC.ORDER_FUNCTION_CALL, Blockly.RobotC.ORDER_FUNCTION_CALL],
  // (foo.bar).baz -> foo.bar.baz
  // (foo.bar)[0] -> foo.bar[0]
  // (foo[0]).bar -> foo[0].bar
  // (foo[0])[1] -> foo[0][1]
  [Blockly.RobotC.ORDER_MEMBER, Blockly.RobotC.ORDER_MEMBER],
  // (foo.bar)() -> foo.bar()
  // (foo[0])() -> foo[0]()
  [Blockly.RobotC.ORDER_MEMBER, Blockly.RobotC.ORDER_FUNCTION_CALL],

  // !(!foo) -> !!foo
  [Blockly.RobotC.ORDER_LOGICAL_NOT, Blockly.RobotC.ORDER_LOGICAL_NOT],
  // a * (b * c) -> a * b * c
  [Blockly.RobotC.ORDER_MULTIPLICATION, Blockly.RobotC.ORDER_MULTIPLICATION],
  // a + (b + c) -> a + b + c
  [Blockly.RobotC.ORDER_ADDITION, Blockly.RobotC.ORDER_ADDITION],
  // a && (b && c) -> a && b && c
  [Blockly.RobotC.ORDER_LOGICAL_AND, Blockly.RobotC.ORDER_LOGICAL_AND],
  // a || (b || c) -> a || b || c
  [Blockly.RobotC.ORDER_LOGICAL_OR, Blockly.RobotC.ORDER_LOGICAL_OR]
];

/**
 * Initialise the database of variable names.
 * @param {!Blockly.Workspace} workspace Workspace to generate code from.
 */
Blockly.RobotC.init = function(workspace) {
  // Create a dictionary of definitions to be printed before the code.
  Blockly.RobotC.definitions_ = Object.create(null);
  // Create a dictionary mapping desired function names in definitions_
  // to actual function names (to avoid collisions with user functions).
  Blockly.RobotC.functionNames_ = Object.create(null);
  Blockly.RobotC.functionDeclarations_ = [];
  // List of all functions which contain events and should be called with
  // every program iteration.
  Blockly.RobotC.eventFunctionNames_ = [];
  // Map of variable names to their types. If a variable is not present in
  // the map, its type is assumed to be float.
  Blockly.RobotC.variableTypes_ = {};
  Blockly.RobotC.pragmas_ = '';

  Blockly.RobotC.getVariableType = function(name) {
    return Blockly.RobotC.variableTypes_[name] || 'float';
  }

  Blockly.RobotC.getAllVariableNames = function() {
    var devVars = Blockly.Variables.allDeveloperVariables(workspace);
    var userVars = Blockly.Variables.allUsedVarModels(workspace);
    return devVars.map(x => Blockly.RobotC.variableDB_.getName(x,
        Blockly.Names.DEVELOPER_VARIABLE_TYPE)).concat(
        userVars.map(x => Blockly.RobotC.variableDB_.getName(x.getId(),
            Blockly.VARIABLE_CATEGORY_NAME)));
  }

  Blockly.RobotC.getVariablesOfType = function(type) {
    return Blockly.RobotC.getAllVariableNames().filter(
        x => Blockly.RobotC.getVariableType(x) == type);
  }

  if (!Blockly.RobotC.variableDB_) {
    Blockly.RobotC.variableDB_ =
        new Blockly.Names(Blockly.RobotC.RESERVED_WORDS_);
  } else {
    Blockly.RobotC.variableDB_.reset();
  }

  Blockly.RobotC.variableDB_.setVariableMap(workspace.getVariableMap());

  Blockly.RobotC.startEventName_ = Blockly.RobotC.variableDB_.getName(
      'start', Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  Blockly.RobotC.variableTypes_[Blockly.RobotC.startEventName_] = 'Event';
};

/**
 * Prepend the generated code with the variable definitions.
 * @param {string} code Generated code.
 * @return {string} Completed code.
 */
Blockly.RobotC.finish = function(code) {
  var events = Blockly.RobotC.getVariablesOfType('Event').concat([Blockly.RobotC.startEventName_]);
  var points = Blockly.RobotC.getVariablesOfType('Point');
  var floats = Blockly.RobotC.getVariablesOfType('float');

  // Declare all of the variables.
  var floatDeclarations = '';
  if (floats.length) {
    floatDeclarations = 'float ' + floats.join(', ') + ';\n';
  }
  var eventDeclarations = '';
  if (events.length) {
    eventDeclarations = 'Event ' + events.join(', ') + ';\n';
  }
  var pointDeclarations = '';
  if (points.length) {
    pointDeclarations = 'Point ' + points.join(', ') + ';\n';
  }
  var functionDeclarations = Blockly.RobotC.functionDeclarations_.join('\n');

  var eventFunctionCalls = Blockly.RobotC.eventFunctionNames_.map(x => x + '();').join('\n') + '\n\n';
  eventFunctionCalls = Blockly.RobotC.prefixLines(eventFunctionCalls, Blockly.RobotC.INDENT);
  eventFunctionCalls = Blockly.RobotC.prefixLines(eventFunctionCalls, Blockly.RobotC.INDENT);

  var advanceEventStates = events.map(name => '    advance_event(' + name + ');').join('\n');

  var typedefDeclarations = Blockly.RobotC.typedefs_.join('\n');

  var main = `
task main() {
  activate_event(` + Blockly.RobotC.startEventName_ + `);
  while(true) {
` + eventFunctionCalls + advanceEventStates + `
  }
}

`;

  // Convert the definitions dictionary into a list.
  var definitions = [];
  for (var name in Blockly.RobotC.definitions_) {
    definitions.push(Blockly.RobotC.definitions_[name]);
  }
  // Clean up temporary data.
  delete Blockly.RobotC.definitions_;
  delete Blockly.RobotC.functionNames_;
  Blockly.RobotC.variableDB_.reset();
  return Blockly.RobotC.pragmas_ 
      + typedefDeclarations
      + floatDeclarations
      + eventDeclarations
      + pointDeclarations + '\n'
      + functionDeclarations
      + Blockly.RobotC.events
      + Blockly.RobotC.point
      + Blockly.RobotC.logic
      + code
      + definitions.join('\n\n') + '\n\n\n'
      + main;
;
};

/**
 * Naked values are top-level blocks with outputs that aren't plugged into
 * anything.  A trailing semicolon is needed to make this legal.
 * @param {string} line Line of generated code.
 * @return {string} Legal line of code.
 */
Blockly.RobotC.scrubNakedValue = function(line) {
  return line + ';\n';
};

/**
 * Encode a string as a properly escaped RobotC string, complete with
 * quotes.
 * @param {string} string Text to encode.
 * @return {string} RobotC string.
 * @private
 */
Blockly.RobotC.quote_ = function(string) {
  // Can't use goog.string.quote since Google's style guide recommends
  // JS string literals use single quotes.
  string = string.replace(/\\/g, '\\\\')
                 .replace(/\n/g, '\\\n')
                 .replace(/"/g, '\\\"');
  return '\"' + string + '\"';
};

/**
 * Encode a string as a properly escaped multiline RobotC string, complete
 * with quotes.
 * @param {string} string Text to encode.
 * @return {string} RobotC string.
 * @private
 */
Blockly.RobotC.multiline_quote_ = function(string) {
  // Can't use goog.string.quote since Google's style guide recommends
  // JS string literals use single quotes.
  var lines = string.split(/\n/g).map(Blockly.RobotC.quote_);
  return lines.join(' + \'\\n\' +\n');
};

/**
 * Common tasks for generating RobotC from blocks.
 * Handles comments for the specified block and any connected value blocks.
 * Calls any statements following this block.
 * @param {!Blockly.Block} block The current block.
 * @param {string} code The RobotC code created for this block.
 * @param {boolean=} opt_thisOnly True to generate code for only this statement.
 * @return {string} RobotC code with comments and subsequent blocks added.
 * @private
 */
Blockly.RobotC.scrub_ = function(block, code, opt_thisOnly) {
  var commentCode = '';
  // Only collect comments for blocks that aren't inline.
  if (!block.outputConnection || !block.outputConnection.targetConnection) {
    // Collect comment for this block.
    var comment = block.getCommentText();
    if (comment) {
      comment = Blockly.utils.string.wrap(comment,
          Blockly.RobotC.COMMENT_WRAP - 3);
      commentCode += Blockly.RobotC.prefixLines(comment + '\n', '// ');
    }
    // Collect comments for all value arguments.
    // Don't collect comments for nested statements.
    for (var i = 0; i < block.inputList.length; i++) {
      if (block.inputList[i].type == Blockly.INPUT_VALUE) {
        var childBlock = block.inputList[i].connection.targetBlock();
        if (childBlock) {
          comment = Blockly.RobotC.allNestedComments(childBlock);
          if (comment) {
            commentCode += Blockly.RobotC.prefixLines(comment, '// ');
          }
        }
      }
    }
  }
  var nextBlock = block.nextConnection && block.nextConnection.targetBlock();
  var nextCode = opt_thisOnly ? '' : Blockly.RobotC.blockToCode(nextBlock);
  return commentCode + code + nextCode;
};

/**
 * Gets a property and adjusts the value while taking into account indexing.
 * @param {!Blockly.Block} block The block.
 * @param {string} atId The property ID of the element to get.
 * @param {number=} opt_delta Value to add.
 * @param {boolean=} opt_negate Whether to negate the value.
 * @param {number=} opt_order The highest order acting on this value.
 * @return {string|number}
 */
Blockly.RobotC.getAdjusted = function(block, atId, opt_delta, opt_negate,
    opt_order) {
  var delta = opt_delta || 0;
  var order = opt_order || Blockly.RobotC.ORDER_NONE;
  if (block.workspace.options.oneBasedIndex) {
    delta--;
  }
  var defaultAtIndex = block.workspace.options.oneBasedIndex ? '1' : '0';
  if (delta > 0) {
    var at = Blockly.RobotC.valueToCode(block, atId,
        Blockly.RobotC.ORDER_ADDITION) || defaultAtIndex;
  } else if (delta < 0) {
    var at = Blockly.RobotC.valueToCode(block, atId,
        Blockly.RobotC.ORDER_SUBTRACTION) || defaultAtIndex;
  } else if (opt_negate) {
    var at = Blockly.RobotC.valueToCode(block, atId,
        Blockly.RobotC.ORDER_UNARY_NEGATION) || defaultAtIndex;
  } else {
    var at = Blockly.RobotC.valueToCode(block, atId, order) ||
        defaultAtIndex;
  }

  if (Blockly.isNumber(at)) {
    // If the index is a naked number, adjust it right now.
    at = Number(at) + delta;
    if (opt_negate) {
      at = -at;
    }
  } else {
    // If the index is dynamic, adjust it in code.
    if (delta > 0) {
      at = at + ' + ' + delta;
      var innerOrder = Blockly.RobotC.ORDER_ADDITION;
    } else if (delta < 0) {
      at = at + ' - ' + -delta;
      var innerOrder = Blockly.RobotC.ORDER_SUBTRACTION;
    }
    if (opt_negate) {
      if (delta) {
        at = '-(' + at + ')';
      } else {
        at = '-' + at;
      }
      var innerOrder = Blockly.RobotC.ORDER_UNARY_NEGATION;
    }
    innerOrder = Math.floor(innerOrder);
    order = Math.floor(order);
    if (innerOrder && order >= innerOrder) {
      at = '(' + at + ')';
    }
  }
  return at;
};

Blockly.RobotC.typedefs_ = [];