/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for text blocks.
 * @author fraser@google.com (Neil Fraser)
 */
'use strict';

goog.provide('Blockly.RobotC.texts');

goog.require('Blockly.RobotC');


Blockly.RobotC['text'] = function(block) {
  // Text value.
  var code = Blockly.RobotC.quote_(block.getFieldValue('TEXT'));
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['text_multiline'] = function(block) {
  // Text value.
  var code = Blockly.RobotC.multiline_quote_(block.getFieldValue('TEXT'));
  if (code.indexOf('\n') != -1) {
      code = '(' + code + ')'
  }
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['text_join'] = function(block) {
  // Create a string made up of any number of elements of any type.
  switch (block.itemCount_) {
    case 0:
      return ['""', Blockly.RobotC.ORDER_ATOMIC];
    case 1:
      var code = Blockly.RobotC.valueToCode(block, 'ADD0',
          Blockly.RobotC.ORDER_NONE) || '""';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
    case 2:
      var element0 = Blockly.RobotC.valueToCode(block, 'ADD0',
          Blockly.RobotC.ORDER_NONE) || '""';
      var element1 = Blockly.RobotC.valueToCode(block, 'ADD1',
          Blockly.RobotC.ORDER_NONE) || '""';
      var code = Blockly.RobotC.text.forceString_(element0) + ' + ' +
          Blockly.RobotC.text.forceString_(element1);
      return [code, Blockly.RobotC.ORDER_ADDITION];
    default:
      var elements = new Array(block.itemCount_);
      for (var i = 0; i < block.itemCount_; i++) {
        elements[i] = Blockly.RobotC.valueToCode(block, 'ADD' + i,
            Blockly.RobotC.ORDER_COMMA) || '""';
      }
      var code = '[' + elements.join(',') + '].join(\'\')';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
  }
};

Blockly.RobotC['text_append'] = function(block) {
  // Append to a variable in place.
  var varName = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('VAR'), Blockly.VARIABLE_CATEGORY_NAME);
  var value = Blockly.RobotC.valueToCode(block, 'TEXT',
      Blockly.RobotC.ORDER_NONE) || '""';
  return varName + ' += ' + Blockly.RobotC.text.forceString_(value) + ';\n';
};

Blockly.RobotC['text_length'] = function(block) {
  // String or array length.
  var text = Blockly.RobotC.valueToCode(block, 'VALUE',
      Blockly.RobotC.ORDER_FUNCTION_CALL) || '""';
  return [text + '.length', Blockly.RobotC.ORDER_MEMBER];
};

Blockly.RobotC['text_isEmpty'] = function(block) {
  // Is the string null or array empty?
  var text = Blockly.RobotC.valueToCode(block, 'VALUE',
      Blockly.RobotC.ORDER_MEMBER) || '""';
  return ['!' + text + '.length', Blockly.RobotC.ORDER_LOGICAL_NOT];
};

Blockly.RobotC['text_indexOf'] = function(block) {
  // Search the text for a substring.
  var operator = block.getFieldValue('END') == 'FIRST' ?
      'indexOf' : 'lastIndexOf';
  var substring = Blockly.RobotC.valueToCode(block, 'FIND',
      Blockly.RobotC.ORDER_NONE) || '""';
  var text = Blockly.RobotC.valueToCode(block, 'VALUE',
      Blockly.RobotC.ORDER_MEMBER) || '""';
  var code = text + '.' + operator + '(' + substring + ')';
  // Adjust index if using one-based indices.
  if (block.workspace.options.oneBasedIndex) {
    return [code + ' + 1', Blockly.RobotC.ORDER_ADDITION];
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['text_charAt'] = function(block) {
  // Get letter at index.
  // Note: Until January 2013 this block did not have the WHERE input.
  var where = block.getFieldValue('WHERE') || 'FROM_START';
  var textOrder = (where == 'RANDOM') ? Blockly.RobotC.ORDER_NONE :
      Blockly.RobotC.ORDER_MEMBER;
  var text = Blockly.RobotC.valueToCode(block, 'VALUE',
      textOrder) || '""';
  switch (where) {
    case 'FIRST':
      var code = text + '.charAt(0)';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
    case 'LAST':
      var code = text + '.slice(-1)';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
    case 'FROM_START':
      var at = Blockly.RobotC.getAdjusted(block, 'AT');
      // Adjust index if using one-based indices.
      var code = text + '.charAt(' + at + ')';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
    case 'FROM_END':
      var at = Blockly.RobotC.getAdjusted(block, 'AT', 1, true);
      var code = text + '.slice(' + at + ').charAt(0)';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
    case 'RANDOM':
      var functionName = Blockly.RobotC.provideFunction_(
          'textRandomLetter',
          ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
              '(text) {',
           '  var x = Math.floor(Math.random() * text.length);',
           '  return text[x];',
           '}']);
      var code = functionName + '(' + text + ')';
      return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
  }
  throw Error('Unhandled option (text_charAt).');
};

/**
 * Returns an expression calculating the index into a string.
 * @param {string} stringName Name of the string, used to calculate length.
 * @param {string} where The method of indexing, selected by dropdown in Blockly
 * @param {string=} opt_at The optional offset when indexing from start/end.
 * @return {string|undefined} Index expression.
 * @private
 */
Blockly.RobotC.text.getIndex_ = function(stringName, where, opt_at) {
  if (where == 'FIRST') {
    return '0';
  } else if (where == 'FROM_END') {
    return stringName + '.length - 1 - ' + opt_at;
  } else if (where == 'LAST') {
    return stringName + '.length - 1';
  } else {
    return opt_at;
  }
};

Blockly.RobotC['text_getSubstring'] = function(block) {
  // Get substring.
  var text = Blockly.RobotC.valueToCode(block, 'STRING',
      Blockly.RobotC.ORDER_FUNCTION_CALL) || '""';
  var where1 = block.getFieldValue('WHERE1');
  var where2 = block.getFieldValue('WHERE2');
  if (where1 == 'FIRST' && where2 == 'LAST') {
    var code = text;
  } else if (text.match(/^'?\w+'?$/) ||
      (where1 != 'FROM_END' && where1 != 'LAST' &&
      where2 != 'FROM_END' && where2 != 'LAST')) {
    // If the text is a variable or literal or doesn't require a call for
    // length, don't generate a helper function.
    switch (where1) {
      case 'FROM_START':
        var at1 = Blockly.RobotC.getAdjusted(block, 'AT1');
        break;
      case 'FROM_END':
        var at1 = Blockly.RobotC.getAdjusted(block, 'AT1', 1, false,
            Blockly.RobotC.ORDER_SUBTRACTION);
        at1 = text + '.length - ' + at1;
        break;
      case 'FIRST':
        var at1 = '0';
        break;
      default:
        throw Error('Unhandled option (text_getSubstring).');
    }
    switch (where2) {
      case 'FROM_START':
        var at2 = Blockly.RobotC.getAdjusted(block, 'AT2', 1);
        break;
      case 'FROM_END':
        var at2 = Blockly.RobotC.getAdjusted(block, 'AT2', 0, false,
            Blockly.RobotC.ORDER_SUBTRACTION);
        at2 = text + '.length - ' + at2;
        break;
      case 'LAST':
        var at2 = text + '.length';
        break;
      default:
        throw Error('Unhandled option (text_getSubstring).');
    }
    code = text + '.slice(' + at1 + ', ' + at2 + ')';
  } else {
    var at1 = Blockly.RobotC.getAdjusted(block, 'AT1');
    var at2 = Blockly.RobotC.getAdjusted(block, 'AT2');
    var getIndex_ = Blockly.RobotC.text.getIndex_;
    var wherePascalCase = {'FIRST': 'First', 'LAST': 'Last',
      'FROM_START': 'FromStart', 'FROM_END': 'FromEnd'};
    var functionName = Blockly.RobotC.provideFunction_(
        'subsequence' + wherePascalCase[where1] + wherePascalCase[where2],
        ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
        '(sequence' +
        // The value for 'FROM_END' and'FROM_START' depends on `at` so
        // we add it as a parameter.
        ((where1 == 'FROM_END' || where1 == 'FROM_START') ? ', at1' : '') +
        ((where2 == 'FROM_END' || where2 == 'FROM_START') ? ', at2' : '') +
        ') {',
          '  var start = ' + getIndex_('sequence', where1, 'at1') + ';',
          '  var end = ' + getIndex_('sequence', where2, 'at2') + ' + 1;',
          '  return sequence.slice(start, end);',
          '}']);
    var code = functionName + '(' + text +
        // The value for 'FROM_END' and 'FROM_START' depends on `at` so we
        // pass it.
        ((where1 == 'FROM_END' || where1 == 'FROM_START') ? ', ' + at1 : '') +
        ((where2 == 'FROM_END' || where2 == 'FROM_START') ? ', ' + at2 : '') +
        ')';
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['text_changeCase'] = function(block) {
  // Change capitalization.
  var OPERATORS = {
    'UPPERCASE': '.toUpperCase()',
    'LOWERCASE': '.toLowerCase()',
    'TITLECASE': null
  };
  var operator = OPERATORS[block.getFieldValue('CASE')];
  var textOrder = operator ? Blockly.RobotC.ORDER_MEMBER :
      Blockly.RobotC.ORDER_NONE;
  var text = Blockly.RobotC.valueToCode(block, 'TEXT',
      textOrder) || '""';
  if (operator) {
    // Upper and lower case are functions built into RobotC.
    var code = text + operator;
  } else {
    // Title case is not a native RobotC function.  Define one.
    var functionName = Blockly.RobotC.provideFunction_(
        'textToTitleCase',
        ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
            '(str) {',
         '  return str.replace(/\\S+/g,',
         '      function(txt) {return txt[0].toUpperCase() + ' +
            'txt.substring(1).toLowerCase();});',
         '}']);
    var code = functionName + '(' + text + ')';
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['text_trim'] = function(block) {
  // Trim spaces.
  var OPERATORS = {
    'LEFT': ".replace(/^[\\s\\xa0]+/, '')",
    'RIGHT': ".replace(/[\\s\\xa0]+$/, '')",
    'BOTH': '.trim()'
  };
  var operator = OPERATORS[block.getFieldValue('MODE')];
  var text = Blockly.RobotC.valueToCode(block, 'TEXT',
      Blockly.RobotC.ORDER_MEMBER) || '""';
  return [text + operator, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['text_print'] = function(block) {
  // Print statement.
  var msg = Blockly.RobotC.valueToCode(block, 'TEXT',
      Blockly.RobotC.ORDER_NONE) || '""';
  return 'window.alert(' + msg + ');\n';
};

Blockly.RobotC['text_prompt_ext'] = function(block) {
  // Prompt function.
  if (block.getField('TEXT')) {
    // Internal message.
    var msg = Blockly.RobotC.quote_(block.getFieldValue('TEXT'));
  } else {
    // External message.
    var msg = Blockly.RobotC.valueToCode(block, 'TEXT',
        Blockly.RobotC.ORDER_NONE) || '""';
  }
  var code = 'window.prompt(' + msg + ')';
  var toNumber = block.getFieldValue('TYPE') == 'NUMBER';
  if (toNumber) {
    code = 'Number(' + code + ')';
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['text_prompt'] = Blockly.RobotC['text_prompt_ext'];

Blockly.RobotC['text_count'] = function(block) {
  var text = Blockly.RobotC.valueToCode(block, 'TEXT',
      Blockly.RobotC.ORDER_MEMBER) || '""';
  var sub = Blockly.RobotC.valueToCode(block, 'SUB',
      Blockly.RobotC.ORDER_NONE) || '""';
  var functionName = Blockly.RobotC.provideFunction_(
      'textCount',
      ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
          '(haystack, needle) {',
       '  if (needle.length === 0) {',
       '    return haystack.length + 1;',
       '  } else {',
       '    return haystack.split(needle).length - 1;',
       '  }',
       '}']);
  var code = functionName + '(' + text + ', ' + sub + ')';
  return [code, Blockly.RobotC.ORDER_SUBTRACTION];
};

Blockly.RobotC['text_replace'] = function(block) {
  var text = Blockly.RobotC.valueToCode(block, 'TEXT',
      Blockly.RobotC.ORDER_MEMBER) || '""';
  var from = Blockly.RobotC.valueToCode(block, 'FROM',
      Blockly.RobotC.ORDER_NONE) || '""';
  var to = Blockly.RobotC.valueToCode(block, 'TO',
      Blockly.RobotC.ORDER_NONE) || '""';
  // The regex escaping code below is taken from the implementation of
  // goog.string.regExpEscape.
  var functionName = Blockly.RobotC.provideFunction_(
      'textReplace',
      ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
          '(haystack, needle, replacement) {',
       '  needle = ' +
           'needle.replace(/([-()\\[\\]{}+?*.$\\^|,:#<!\\\\])/g,"\\\\$1")',
       '                 .replace(/\\x08/g,"\\\\x08");',
       '  return haystack.replace(new RegExp(needle, \'g\'), replacement);',
       '}']);
  var code = functionName + '(' + text + ', ' + from + ', ' + to + ')';
  return [code, Blockly.RobotC.ORDER_MEMBER];
};

Blockly.RobotC['text_reverse'] = function(block) {
  var text = Blockly.RobotC.valueToCode(block, 'TEXT',
      Blockly.RobotC.ORDER_MEMBER) || '""';
  var code = text + '.split(\'\').reverse().join(\'\')';
  return [code, Blockly.RobotC.ORDER_MEMBER];
};
