/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for variable blocks.
 * @author fraser@google.com (Neil Fraser)
 */
'use strict';

goog.provide('Blockly.RobotC.variables');

goog.require('Blockly.RobotC');


Blockly.RobotC['variables_get'] = function(block) {
  // Variable getter.
  var code = Blockly.RobotC.variableDB_.getName(block.getFieldValue('VAR'),
      Blockly.VARIABLE_CATEGORY_NAME);
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['variables_set'] = function(block) {
  // Variable setter.
  var argument0 = Blockly.RobotC.valueToCode(block, 'VALUE',
      Blockly.RobotC.ORDER_ASSIGNMENT) || '0';
  var varName = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('VAR'), Blockly.VARIABLE_CATEGORY_NAME);
  return varName + ' = ' + argument0 + ';\n';
};
