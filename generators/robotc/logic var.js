/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for logic blocks.
 * @author q.neutron@gmail.com (Quynh Neutron)
 */
'use strict';

goog.provide('Blockly.RobotC.logic');

goog.require('Blockly.RobotC');


Blockly.RobotC['controls_if'] = function(block) {
  // If/elseif/else condition.
  var n = 0;
  var code = '', branchCode, conditionCode;
  if (Blockly.RobotC.STATEMENT_PREFIX) {
    // Automatic prefix insertion is switched off for this block.  Add manually.
    code += Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_PREFIX,
        block);
  }
  do {
    conditionCode = Blockly.RobotC.valueToCode(block, 'IF' + n,
        Blockly.RobotC.ORDER_NONE) || 'FALSE';
    branchCode = Blockly.RobotC.statementToCode(block, 'DO' + n);
    if (Blockly.RobotC.STATEMENT_SUFFIX) {
      branchCode = Blockly.RobotC.prefixLines(
          Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_SUFFIX,
          block), Blockly.RobotC.INDENT) + branchCode;
    }
    code += (n > 0 ? ' else ' : '') +
        'if (vtob(' + conditionCode + ')) {\n' + branchCode + '}';
    ++n;
  } while (block.getInput('IF' + n));

  if (block.getInput('ELSE') || Blockly.RobotC.STATEMENT_SUFFIX) {
    branchCode = Blockly.RobotC.statementToCode(block, 'ELSE');
    if (Blockly.RobotC.STATEMENT_SUFFIX) {
      branchCode = Blockly.RobotC.prefixLines(
          Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_SUFFIX,
          block), Blockly.RobotC.INDENT) + branchCode;
    }
    code += ' else {\n' + branchCode + '}';
  }
  return code + '\n';
};

Blockly.RobotC['controls_ifelse'] = Blockly.RobotC['controls_if'];

Blockly.RobotC['logic_compare'] = function(block) {
  // Comparison operator.
  var OPERATORS = {
    'EQ': 'eq',
    'NEQ': 'ne',
    'LT': 'lt',
    'LTE': 'lte',
    'GT': 'gt',
    'GTE': 'gte'
  };
  var operator = OPERATORS[block.getFieldValue('OP')];
  var order = (operator == 'eq' || operator == 'ne') ?
      Blockly.RobotC.ORDER_EQUALITY : Blockly.RobotC.ORDER_RELATIONAL;
  var argument0 = Blockly.RobotC.valueToCode(block, 'A', order) || '0';
  var argument1 = Blockly.RobotC.valueToCode(block, 'B', order) || '0';
  var code = operator + '(' + argument0 + ', ' + argument1 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['logic_operation'] = function(block) {
  // Operations 'and', 'or'.
  var operator = (block.getFieldValue('OP') == 'AND') ? 'and' : 'or';
  var order = (operator == 'and') ? Blockly.RobotC.ORDER_LOGICAL_AND :
      Blockly.RobotC.ORDER_LOGICAL_OR;
  var argument0 = Blockly.RobotC.valueToCode(block, 'A', order);
  var argument1 = Blockly.RobotC.valueToCode(block, 'B', order);
  if (!argument0 && !argument1) {
    // If there are no arguments, then the return value is false.
    argument0 = 'FALSE';
    argument1 = 'FALSE';
  } else {
    // Single missing arguments have no effect on the return value.
    var defaultArgument = (operator == 'and') ? 'TRUE' : 'FALSE';
    if (!argument0) {
      argument0 = defaultArgument;
    }
    if (!argument1) {
      argument1 = defaultArgument;
    }
  }
  var code = operator + '(' + argument0 + ', ' + argument1 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['logic_negate'] = function(block) {
  // Negation.
  var argument0 = Blockly.RobotC.valueToCode(block, 'BOOL', Blockly.RobotC.ORDER_LOGICAL_NOT) ||
      'TRUE';
  var code = 'not(' + argument0 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['logic_boolean'] = function(block) {
  // Boolean values true and false.
  var code = (block.getFieldValue('BOOL') == 'TRUE') ? 'TRUE' : 'FALSE';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['logic_ternary'] = function(block) {
  // Ternary operator.
  var value_if = Blockly.RobotC.valueToCode(block, 'IF',
      Blockly.RobotC.ORDER_CONDITIONAL) || 'FALSE';
  var value_then = Blockly.RobotC.valueToCode(block, 'THEN',
      Blockly.RobotC.ORDER_CONDITIONAL) || 'ZERO';
  var value_else = Blockly.RobotC.valueToCode(block, 'ELSE',
      Blockly.RobotC.ORDER_CONDITIONAL) || 'ZERO';
  var code = 'vtob(' + value_if + ') ? ' + value_then + ' : ' + value_else;
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};
