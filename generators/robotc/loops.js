/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for loop blocks.
 * @author fraser@google.com (Neil Fraser)
 */
'use strict';

goog.provide('Blockly.RobotC.loops');

goog.require('Blockly.RobotC');


Blockly.RobotC['controls_repeat_ext'] = function(block) {
  // Repeat n times.
  if (block.getField('TIMES')) {
    // Internal number.
    var repeats = String(Number(block.getFieldValue('TIMES')));
  } else {
    // External number.
    var repeats = Blockly.RobotC.valueToCode(block, 'TIMES',
        Blockly.RobotC.ORDER_ASSIGNMENT) || '0';
  }
  var branch = Blockly.RobotC.statementToCode(block, 'DO');
  branch = Blockly.RobotC.addLoopTrap(branch, block);
  var code = '';
  var loopVar = Blockly.RobotC.variableDB_.getDistinctName(
      'count', Blockly.VARIABLE_CATEGORY_NAME);
  var endVar = repeats;
  if (!repeats.match(/^\w+$/) && !Blockly.isNumber(repeats)) {
    endVar = Blockly.RobotC.variableDB_.getDistinctName(
        'repeat_end', Blockly.VARIABLE_CATEGORY_NAME);
    code += 'float ' + endVar + ' = ' + repeats + ';\n';
  }
  code += 'for (int ' + loopVar + ' = 0; ' +
      loopVar + ' < ' + endVar + '; ' +
      loopVar + '++) {\n' +
      branch + '}\n';
  return code;
};

Blockly.RobotC['controls_repeat'] =
    Blockly.RobotC['controls_repeat_ext'];

Blockly.RobotC['controls_whileUntil'] = function(block) {
  // Do while/until loop.
  var until = block.getFieldValue('MODE') == 'UNTIL';
  var argument0 = Blockly.RobotC.valueToCode(block, 'BOOL',
      until ? Blockly.RobotC.ORDER_LOGICAL_NOT :
      Blockly.RobotC.ORDER_NONE) || 'false';
  var branch = Blockly.RobotC.statementToCode(block, 'DO');
  branch = Blockly.RobotC.addLoopTrap(branch, block);
  if (until) {
    argument0 = '!' + argument0;
  }
  return 'while (' + argument0 + ') {\n' + branch + '}\n';
};

Blockly.RobotC['controls_for'] = function(block) {
  // For loop.
  var variable0 = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('VAR'), Blockly.VARIABLE_CATEGORY_NAME);
  var argument0 = Blockly.RobotC.valueToCode(block, 'FROM',
      Blockly.RobotC.ORDER_ASSIGNMENT) || '0';
  var argument1 = Blockly.RobotC.valueToCode(block, 'TO',
      Blockly.RobotC.ORDER_ASSIGNMENT) || '0';
  var increment = Blockly.RobotC.valueToCode(block, 'BY',
      Blockly.RobotC.ORDER_ASSIGNMENT) || '1';
  var branch = Blockly.RobotC.statementToCode(block, 'DO');
  branch = Blockly.RobotC.addLoopTrap(branch, block);
  var code;
  if (Blockly.isNumber(argument0) && Blockly.isNumber(argument1) &&
      Blockly.isNumber(increment)) {
    // All arguments are simple numbers.
    var up = Number(argument0) <= Number(argument1);
    code = 'for (' + variable0 + ' = ' + argument0 + '; ' +
        variable0 + (up ? ' <= ' : ' >= ') + argument1 + '; ' +
        variable0;
    var step = Math.abs(Number(increment));
    if (step == 1) {
      code += up ? '++' : '--';
    } else {
      code += (up ? ' += ' : ' -= ') + step;
    }
    code += ') {\n' + branch + '}\n';
  } else {
    code = '';
    // Cache non-trivial values to variables to prevent repeated look-ups.
    var startVar = argument0;
    if (!argument0.match(/^\w+$/) && !Blockly.isNumber(argument0)) {
      startVar = Blockly.RobotC.variableDB_.getDistinctName(
          variable0 + '_start', Blockly.VARIABLE_CATEGORY_NAME);
      code += 'float ' + startVar + ' = ' + argument0 + ';\n';
    }
    var endVar = argument1;
    if (!argument1.match(/^\w+$/) && !Blockly.isNumber(argument1)) {
      endVar = Blockly.RobotC.variableDB_.getDistinctName(
          variable0 + '_end', Blockly.VARIABLE_CATEGORY_NAME);
      code += 'float ' + endVar + ' = ' + argument1 + ';\n';
    }
    // Determine loop direction at start, in case one of the bounds
    // changes during loop execution.
    var incVar = Blockly.RobotC.variableDB_.getDistinctName(
        variable0 + '_inc', Blockly.VARIABLE_CATEGORY_NAME);
    code += 'int ' + incVar + ' = ';
    if (Blockly.isNumber(increment)) {
      code += Math.abs(increment) + ';\n';
    } else {
      code += 'abs(' + increment + ');\n';
    }
    code += 'if (' + startVar + ' > ' + endVar + ') {\n';
    code += Blockly.RobotC.INDENT + incVar + ' = -' + incVar + ';\n';
    code += '}\n';
    code += 'for (' + variable0 + ' = ' + startVar + '; ' +
        incVar + ' >= 0 ? ' +
        variable0 + ' <= ' + endVar + ' : ' +
        variable0 + ' >= ' + endVar + '; ' +
        variable0 + ' += ' + incVar + ') {\n' +
        branch + '}\n';
  }
  return code;
};

Blockly.RobotC['controls_forEach'] = function(block) {
  // For each loop.
  var variable0 = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('VAR'), Blockly.VARIABLE_CATEGORY_NAME);
  var argument0 = Blockly.RobotC.valueToCode(block, 'LIST',
      Blockly.RobotC.ORDER_ASSIGNMENT) || '[]';
  var branch = Blockly.RobotC.statementToCode(block, 'DO');
  branch = Blockly.RobotC.addLoopTrap(branch, block);
  var code = '';
  // Cache non-trivial values to variables to prevent repeated look-ups.
  var listVar = argument0;
  if (!argument0.match(/^\w+$/)) {
    listVar = Blockly.RobotC.variableDB_.getDistinctName(
        variable0 + '_list', Blockly.VARIABLE_CATEGORY_NAME);
    code += 'list ' + listVar + ' = ' + argument0 + ';\n';
  }
  var indexVar = Blockly.RobotC.variableDB_.getDistinctName(
      variable0 + '_index', Blockly.VARIABLE_CATEGORY_NAME);
  branch = Blockly.RobotC.INDENT + variable0 + ' = ' +
      listVar + '[' + indexVar + '];\n' + branch;
  code += 'for (int ' + indexVar + ' in ' + listVar + ') {\n' + branch + '}\n';
  return code;
};

Blockly.RobotC['controls_flow_statements'] = function(block) {
  // Flow statements: continue, break.
  var xfix = '';
  if (Blockly.RobotC.STATEMENT_PREFIX) {
    // Automatic prefix insertion is switched off for this block.  Add manually.
    xfix += Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_PREFIX,
        block);
  }
  if (Blockly.RobotC.STATEMENT_SUFFIX) {
    // Inject any statement suffix here since the regular one at the end
    // will not get executed if the break/continue is triggered.
    xfix += Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_SUFFIX,
        block);
  }
  if (Blockly.RobotC.STATEMENT_PREFIX) {
    var loop = Blockly.Constants.Loops
        .CONTROL_FLOW_IN_LOOP_CHECK_MIXIN.getSurroundLoop(block);
    if (loop && !loop.suppressPrefixSuffix) {
      // Inject loop's statement prefix here since the regular one at the end
      // of the loop will not get executed if 'continue' is triggered.
      // In the case of 'break', a prefix is needed due to the loop's suffix.
      xfix += Blockly.RobotC.injectId(Blockly.RobotC.STATEMENT_PREFIX,
          loop);
    }
  }
  switch (block.getFieldValue('FLOW')) {
    case 'BREAK':
      return xfix + 'break;\n';
    case 'CONTINUE':
      return xfix + 'continue;\n';
  }
  throw Error('Unknown flow statement.');
};
