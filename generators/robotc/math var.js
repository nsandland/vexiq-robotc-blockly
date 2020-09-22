/**
 * @license
 * Copyright 2012 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for math blocks.
 * @author q.neutron@gmail.com (Quynh Neutron)
 */
'use strict';

goog.provide('Blockly.RobotC.math');

goog.require('Blockly.RobotC');


Blockly.RobotC['math_number'] = function(block) {
  // Numeric value.
  var num = Number(block.getFieldValue('NUM'));
  var code = num;
  var order = code >= 0 ? Blockly.RobotC.ORDER_ATOMIC :
              Blockly.RobotC.ORDER_UNARY_NEGATION;
  return [code, order];
};

Blockly.RobotC['math_arithmetic'] = function(block) {
  // Basic arithmetic operators, and power.
  var OPERATORS = {
    'ADD': ['add', Blockly.RobotC.ORDER_ADDITION],
    'MINUS': ['sub', Blockly.RobotC.ORDER_SUBTRACTION],
    'MULTIPLY': ['mul', Blockly.RobotC.ORDER_MULTIPLICATION],
    'DIVIDE': ['div', Blockly.RobotC.ORDER_DIVISION],
    'POWER': ['pow', Blockly.RobotC.ORDER_COMMA]  // Handle power separately.
  };
  var tuple = OPERATORS[block.getFieldValue('OP')];
  var operator = tuple[0];
  var order = tuple[1];
  var argument0 = Blockly.RobotC.valueToCode(block, 'A', order) || 'ZERO';
  var argument1 = Blockly.RobotC.valueToCode(block, 'B', order) || 'ZERO';
  var code = operator + '(' + argument0 + ', ' + argument1 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_single'] = function(block) {
  // Math operators with single operand.
  var OPERATORS = {
    'NEG': 'vneg',
    'SIN': 'vsindeg',
    'COS': 'vcosdeg',
    'TAN': 'vtandeg',
    'ASIN': 'vasindeg',
    'ACOS': 'vacosdeg',
    'ATAN': 'vatandeg',
    'ABS': 'vabs',
    'ROOT': 'vsqrt',
    'LN': 'vln',
    'LOG10': 'vlog10',
    'EXP': 'veexp',
    'POW10': 'v10exp',
    'ROUND': 'vround',
    'ROUNDUP': 'vceil',
    'ROUNDDOWN': 'vfloor',
    'SIN': 'vsin'
  };
  var operator = OPERATORS[block.getFieldValue('OP')];
  var code;
  var arg;
  if (operator == 'vneg') {
    arg = Blockly.RobotC.valueToCode(block, 'NUM',
        Blockly.RobotC.ORDER_UNARY_NEGATION) || 'ZERO';
  }
  if (operator == 'vsindeg' || operator == 'vcosdeg' || operator == 'vtandeg') {
    arg = Blockly.RobotC.valueToCode(block, 'NUM',
        Blockly.RobotC.ORDER_DIVISION) || 'ZERO';
  } else {
    arg = Blockly.RobotC.valueToCode(block, 'NUM',
        Blockly.RobotC.ORDER_NONE) || 'ZERO';
  }
  code = operator + '(' + arg + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_constant'] = function(block) {
  // Constants: PI, E, the Golden Ratio, sqrt(2), 1/sqrt(2), INFINITY.
  var CONSTANTS = {
    'PI': 'VPI',
    'E': 'VE',
    'GOLDEN_RATIO': 'VGOLDEN_RATIO',
    'SQRT2': 'VSQRT2',
    'SQRT1_2': 'VSQRT1_2',
    'INFINITY': 'VINFINITY'
  };
  var code = CONSTANTS[block.getFieldValue('CONSTANT')];
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['math_number_property'] = function(block) {
  // Check if a number is even, odd, prime, whole, positive, or negative
  // or if it is divisible by certain number. Returns true or false.
  var number_to_check = Blockly.RobotC.valueToCode(block, 'NUMBER_TO_CHECK',
      Blockly.RobotC.ORDER_MODULUS) || 'ZERO';
  var dropdown_property = block.getFieldValue('PROPERTY');
  var code;
  switch (dropdown_property) {
    case 'EVEN':
      code = 'eq(mod(' + number_to_check + ', TWO), ZERO)';
      break;
    case 'ODD':
      code = 'eq(mod(' + number_to_check + ', TWO), ONE)';
      break;
    case 'WHOLE':
      code = 'eq(mod(' + number_to_check + ', ONE), ZERO)';
      break;
    case 'POSITIVE':
      code = 'gt(' + number_to_check + ', ZERO)';
      break;
    case 'NEGATIVE':
      code = 'lt(' + number_to_check + ', ZERO)';
      break;
    case 'DIVISIBLE_BY':
      var divisor = Blockly.RobotC.valueToCode(block, 'DIVISOR',
          Blockly.RobotC.ORDER_MODULUS) || 'ZERO';
      code = 'eq(mod(' + number_to_check + ', ' + divisor + '), ZERO)';
      break;
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_change'] = function(block) {
  // Add to a variable in place.
  var argument0 = Blockly.RobotC.valueToCode(block, 'DELTA',
      Blockly.RobotC.ORDER_ADDITION) || 'ZERO';
  var varName = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('VAR'), Blockly.VARIABLE_CATEGORY_NAME);
  return 'addto(' + varName + ', ' + argument0 + ');\n';
};

// Rounding functions have a single operand.
Blockly.RobotC['math_round'] = Blockly.RobotC['math_single'];
// Trigonometry functions have a single operand.
Blockly.RobotC['math_trig'] = Blockly.RobotC['math_single'];

Blockly.RobotC['math_on_list'] = function(block) {
  // Math functions for lists.
  var func = block.getFieldValue('OP');
  var list, code;
  switch (func) {
    case 'SUM':
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_MEMBER) || '[]';
      code = list + '.reduce(function(x, y) {return x + y;})';
      break;
    case 'MIN':
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_COMMA) || '[]';
      code = 'Math.min.apply(null, ' + list + ')';
      break;
    case 'MAX':
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_COMMA) || '[]';
      code = 'Math.max.apply(null, ' + list + ')';
      break;
    case 'AVERAGE':
      // mathMean([null,null,1,3]) == 2.0.
      var functionName = Blockly.RobotC.provideFunction_(
          'mathMean',
          ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
              '(myList) {',
            '  return myList.reduce(function(x, y) {return x + y;}) / ' +
                  'myList.length;',
            '}']);
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_NONE) || '[]';
      code = functionName + '(' + list + ')';
      break;
    case 'MEDIAN':
      // mathMedian([null,null,1,3]) == 2.0.
      var functionName = Blockly.RobotC.provideFunction_(
          'mathMedian',
          ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
              '(myList) {',
            '  var localList = myList.filter(function (x) ' +
              '{return typeof x == \'number\';});',
            '  if (!localList.length) return null;',
            '  localList.sort(function(a, b) {return b - a;});',
            '  if (localList.length % 2 == 0) {',
            '    return (localList[localList.length / 2 - 1] + ' +
              'localList[localList.length / 2]) / 2;',
            '  } else {',
            '    return localList[(localList.length - 1) / 2];',
            '  }',
            '}']);
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_NONE) || '[]';
      code = functionName + '(' + list + ')';
      break;
    case 'MODE':
      // As a list of numbers can contain more than one mode,
      // the returned result is provided as an array.
      // Mode of [3, 'x', 'x', 1, 1, 2, '3'] -> ['x', 1].
      var functionName = Blockly.RobotC.provideFunction_(
          'mathModes',
          ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
              '(values) {',
            '  var modes = [];',
            '  var counts = [];',
            '  var maxCount = 0;',
            '  for (var i = 0; i < values.length; i++) {',
            '    var value = values[i];',
            '    var found = false;',
            '    var thisCount;',
            '    for (var j = 0; j < counts.length; j++) {',
            '      if (counts[j][0] === value) {',
            '        thisCount = ++counts[j][1];',
            '        found = true;',
            '        break;',
            '      }',
            '    }',
            '    if (!found) {',
            '      counts.push([value, 1]);',
            '      thisCount = 1;',
            '    }',
            '    maxCount = Math.max(thisCount, maxCount);',
            '  }',
            '  for (var j = 0; j < counts.length; j++) {',
            '    if (counts[j][1] == maxCount) {',
            '        modes.push(counts[j][0]);',
            '    }',
            '  }',
            '  return modes;',
            '}']);
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_NONE) || '[]';
      code = functionName + '(' + list + ')';
      break;
    case 'STD_DEV':
      var functionName = Blockly.RobotC.provideFunction_(
          'mathStandardDeviation',
          ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
              '(numbers) {',
            '  var n = numbers.length;',
            '  if (!n) return null;',
            '  var mean = numbers.reduce(function(x, y) {return x + y;}) / n;',
            '  var variance = 0;',
            '  for (var j = 0; j < n; j++) {',
            '    variance += Math.pow(numbers[j] - mean, 2);',
            '  }',
            '  variance = variance / n;',
            '  return Math.sqrt(variance);',
            '}']);
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_NONE) || '[]';
      code = functionName + '(' + list + ')';
      break;
    case 'RANDOM':
      var functionName = Blockly.RobotC.provideFunction_(
          'mathRandomList',
          ['function ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
              '(list) {',
            '  var x = Math.floor(Math.random() * list.length);',
            '  return list[x];',
            '}']);
      list = Blockly.RobotC.valueToCode(block, 'LIST',
          Blockly.RobotC.ORDER_NONE) || '[]';
      code = functionName + '(' + list + ')';
      break;
    default:
      throw Error('Unknown operator: ' + func);
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_modulo'] = function(block) {
  // Remainder computation.
  var argument0 = Blockly.RobotC.valueToCode(block, 'DIVIDEND',
      Blockly.RobotC.ORDER_MODULUS) || 'ZERO';
  var argument1 = Blockly.RobotC.valueToCode(block, 'DIVISOR',
      Blockly.RobotC.ORDER_MODULUS) || 'ZERO';
  var code = 'mod(' + argument0 + ', ' + argument1 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_constrain'] = function(block) {
  // Constrain a number between two limits.
  var argument0 = Blockly.RobotC.valueToCode(block, 'VALUE',
      Blockly.RobotC.ORDER_COMMA) || 'ZERO';
  var argument1 = Blockly.RobotC.valueToCode(block, 'LOW',
      Blockly.RobotC.ORDER_COMMA) || 'ZERO';
  var argument2 = Blockly.RobotC.valueToCode(block, 'HIGH',
      Blockly.RobotC.ORDER_COMMA) || 'INFINITY';
  var code = 'vmin(vmax(' + argument0 + ', ' + argument1 + '), ' +
      argument2 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_random_int'] = function(block) {
  // Random integer between [X] and [Y].
  var argument0 = Blockly.RobotC.valueToCode(block, 'FROM',
      Blockly.RobotC.ORDER_COMMA) || 'ZERO';
  var argument1 = Blockly.RobotC.valueToCode(block, 'TO',
      Blockly.RobotC.ORDER_COMMA) || 'ZERO';
  var code = 'vrand(' + argument1 + ', ' + argument0 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};
