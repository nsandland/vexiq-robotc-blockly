/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for procedure blocks.
 * @author fraser@google.com (Neil Fraser)
 */
'use strict';

goog.provide('Blockly.RobotC.procedures');

goog.require('Blockly.RobotC');


Blockly.RobotC['procedures_defreturn'] = function(block) {
  // Define a procedure with a return value.
  var funcName = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('NAME'), Blockly.PROCEDURE_CATEGORY_NAME);
  var xfix1 = '';
  if (Blockly.RobotC.STATEMENT_PREFIX) {
    xfix1 += Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_PREFIX,
        block);
  }
  if (Blockly.RobotC.STATEMENT_SUFFIX) {
    xfix1 += Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_SUFFIX,
        block);
  }
  if (xfix1) {
    xfix1 = Blockly.RobotC.prefixLines(xfix1, Blockly.RobotC.INDENT);
  }
  var loopTrap = '';
  if (Blockly.RobotC.INFINITE_LOOP_TRAP) {
    loopTrap = Blockly.RobotC.prefixLines(
        Blockly.RobotC.injectId(Blockly.RobotC.INFINITE_LOOP_TRAP,
        block), Blockly.RobotC.INDENT);
  }
  var branch = Blockly.RobotC.statementToCode(block, 'STACK');
  var returnValue = Blockly.RobotC.valueToCode(block, 'RETURN',
      Blockly.RobotC.ORDER_NONE) || '';
  var xfix2 = '';
  if (branch && returnValue) {
    // After executing the function body, revisit this block for the return.
    xfix2 = xfix1;
  }
  var returnType = 'void';
  if (returnValue) {
    returnValue = Blockly.RobotC.INDENT + 'return ' + returnValue + ';\n';
    returnType = 'float';
  }
  if (block.getFieldValue('IS_TASK')) {
    returnType = 'task';
  }
  var args = [];
  var variables = block.getVars();
  for (var i = 0; i < variables.length; i++) {
    args[i] = Blockly.RobotC.variableDB_.getName(variables[i],
        Blockly.VARIABLE_CATEGORY_NAME);
  }
  var argText = args.map(arg => Blockly.RobotC.getVariableType(arg) + ' ' + arg).join(', ');
  var innerCode = xfix1 + loopTrap + branch + xfix2;
  var signature = returnType + ' ' + funcName + '(' + argText + ')'
  var code = signature + ' {\n' +
      innerCode + returnValue + '}';      
  code = Blockly.RobotC.scrub_(block, code);
  // Add % so as not to collide with helper functions in definitions list.
  Blockly.RobotC.definitions_['%' + funcName] = code;
  if (!block.getFieldValue('IS_TASK')) {
    Blockly.RobotC.functionDeclarations_.push(signature + ';');
  }
  return null;
};

// Defining a procedure without a return value uses the same generator as
// a procedure with a return value.
Blockly.RobotC['procedures_defnoreturn'] =
    Blockly.RobotC['procedures_defreturn'];

Blockly.RobotC['procedures_deftask'] =
    Blockly.RobotC['procedures_defreturn'];

Blockly.RobotC['procedures_callreturn'] = function(block) {
  // Call a procedure with a return value.
  var funcName = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('NAME'), Blockly.PROCEDURE_CATEGORY_NAME);
  var args = [];
  var variables = block.getVars();
  for (var i = 0; i < variables.length; i++) {
    args[i] = Blockly.RobotC.valueToCode(block, 'ARG' + i,
        Blockly.RobotC.ORDER_COMMA) || 'null';
  }
  var code = funcName + '(' + args.join(', ') + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['procedures_callnoreturn'] = function(block) {
  // Call a procedure with no return value.
  // Generated code is for a function call as a statement is the same as a
  // function call as a value, with the addition of line ending.
  var tuple = Blockly.RobotC['procedures_callreturn'](block);
  return tuple[0] + ';\n';
};

Blockly.RobotC['procedures_startstoptask'] = function(block) {
  var ACTIONS = {
    'START' : 'startTask',
    'STOP' : 'stopTask'
  };
  var action = ACTIONS[block.getFieldValue('ACTION')];
  var funcName = Blockly.RobotC.variableDB_.getName(
    block.getFieldValue('NAME'), Blockly.PROCEDURE_CATEGORY_NAME);
  return action + '(' + funcName + ');\n';
};

Blockly.RobotC['procedures_killtask'] = function(block) {
  var funcName = Blockly.RobotC.variableDB_.getName(
    block.getFieldValue('NAME'), Blockly.PROCEDURE_CATEGORY_NAME);
  return 'StopTask(' + funcName + ');\n';
};

Blockly.RobotC['procedures_ifreturn'] = function(block) {
  // Conditionally return value from a procedure.
  var condition = Blockly.RobotC.valueToCode(block, 'CONDITION',
      Blockly.RobotC.ORDER_NONE) || 'false';
  var code = 'if (' + condition + ') {\n';
  if (Blockly.RobotC.STATEMENT_SUFFIX) {
    // Inject any statement suffix here since the regular one at the end
    // will not get executed if the return is triggered.
    code += Blockly.RobotC.prefixLines(
        Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_SUFFIX, block),
        Blockly.RobotC.INDENT);
  }
  if (block.hasReturnValue_) {
    var value = Blockly.RobotC.valueToCode(block, 'VALUE',
        Blockly.RobotC.ORDER_NONE) || 'null';
    code += Blockly.RobotC.INDENT + 'return ' + value + ';\n';
  } else {
    code += Blockly.RobotC.INDENT + 'return;\n';
  }
  code += '}\n';
  return code;
};
