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
  var code = Number(block.getFieldValue('NUM'));
  var order = code >= 0 ? Blockly.RobotC.ORDER_ATOMIC :
              Blockly.RobotC.ORDER_UNARY_NEGATION;
  return [code, order];
};

Blockly.RobotC['math_arithmetic'] = function(block) {
  // Basic arithmetic operators, and power.
  var OPERATORS = {
    'ADD': [' + ', Blockly.RobotC.ORDER_ADDITION],
    'MINUS': [' - ', Blockly.RobotC.ORDER_SUBTRACTION],
    'MULTIPLY': [' * ', Blockly.RobotC.ORDER_MULTIPLICATION],
    'DIVIDE': [' / ', Blockly.RobotC.ORDER_DIVISION],
    'POWER': [null, Blockly.RobotC.ORDER_COMMA]  // Handle power separately.
  };
  var tuple = OPERATORS[block.getFieldValue('OP')];
  var operator = tuple[0];
  var order = tuple[1];
  var argument0 = Blockly.RobotC.valueToCode(block, 'A', order) || '0';
  var argument1 = Blockly.RobotC.valueToCode(block, 'B', order) || '0';
  var code;
  // Power in RobotC requires a special case since it has no operator.
  if (!operator) {
    code = 'pow(' + argument0 + ', ' + argument1 + ')';
    return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
  }
  code = argument0 + operator + argument1;
  return [code, order];
};

Blockly.RobotC['math_single'] = function(block) {
  // Math operators with single operand.
  var operator = block.getFieldValue('OP');
  var code;
  var arg;
  if (operator == 'NEG') {
    // Negation is a special case given its different operator precedence.
    arg = Blockly.RobotC.valueToCode(block, 'NUM',
        Blockly.RobotC.ORDER_UNARY_NEGATION) || '0';
    if (arg[0] == '-') {
      code = arg.substring(1);
    } else {
      code = '-' + arg;
    }
    return [code, Blockly.RobotC.ORDER_UNARY_NEGATION];
  }
  if (operator == 'SIN' || operator == 'COS' || operator == 'TAN') {
    arg = Blockly.RobotC.valueToCode(block, 'NUM',
        Blockly.RobotC.ORDER_DIVISION) || '0';
  } else {
    arg = Blockly.RobotC.valueToCode(block, 'NUM',
        Blockly.RobotC.ORDER_NONE) || '0';
  }
  // First, handle cases which generate values that don't need parentheses
  // wrapping the code.
  switch (operator) {
    case 'ABS':
      code = 'abs(' + arg + ')';
      break;
    case 'ROOT':
      code = 'sqrt(' + arg + ')';
      break;
    case 'LN':
      code = 'log(' + arg + ')';
      break;
    case 'EXP':
      code = 'exp(' + arg + ')';
      break;
    case 'POW10':
      code = 'pow(10,' + arg + ')';
      break;
    case 'ROUND':
      code = 'floor(' + arg + ' + 0.5)';
      break;
    case 'ROUNDUP':
      code = 'ceil(' + arg + ')';
      break;
    case 'ROUNDDOWN':
      code = 'floor(' + arg + ')';
      break;
    case 'SIN':
      code = 'sin(' + arg + ' / 180 * Math.PI)';
      break;
    case 'COS':
      code = 'cos(' + arg + ' / 180 * Math.PI)';
      break;
    case 'TAN':
      code = 'tan(' + arg + ' / 180 * Math.PI)';
      break;
  }
  if (code) {
    return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
  }
  // Second, handle cases which generate values that may need parentheses
  // wrapping the code.
  switch (operator) {
    case 'LOG10':
      code = 'log(' + arg + ') / log(10)';
      break;
    case 'ASIN':
      code = 'asin(' + arg + ') / Math.PI * 180';
      break;
    case 'ACOS':
      code = 'acos(' + arg + ') / Math.PI * 180';
      break;
    case 'ATAN':
      code = 'tan(' + arg + ') / Math.PI * 180';
      break;
    default:
      throw Error('Unknown math operator: ' + operator);
  }
  return [code, Blockly.RobotC.ORDER_DIVISION];
};

Blockly.RobotC['math_constant'] = function(block) {
  // Constants: PI, E, the Golden Ratio, sqrt(2), 1/sqrt(2), INFINITY.
  var CONSTANTS = {
    'PI': ['PI', Blockly.RobotC.ORDER_MEMBER],
    'E': ['exp(1)', Blockly.RobotC.ORDER_FUNCTION_CALL],
    'GOLDEN_RATIO':
        ['(1 + sqrt(5)) / 2', Blockly.RobotC.ORDER_DIVISION],
    'SQRT2': ['sqrt(2.0)', Blockly.RobotC.ORDER_FUNCTION_CALL],
    'SQRT1_2': ['1.0 / sqrt(2.0)', Blockly.RobotC.ORDER_DIVISION],
    'INFINITY': ['INFINITY', Blockly.RobotC.ORDER_ATOMIC]
  };
  return CONSTANTS[block.getFieldValue('CONSTANT')];
};

Blockly.RobotC['math_number_property'] = function(block) {
  // Check if a number is even, odd, prime, whole, positive, or negative
  // or if it is divisible by certain number. Returns true or false.
  var number_to_check = Blockly.RobotC.valueToCode(block, 'NUMBER_TO_CHECK',
      Blockly.RobotC.ORDER_MODULUS) || '0';
  var dropdown_property = block.getFieldValue('PROPERTY');
  var code;
  if (dropdown_property == 'PRIME') {
    // Prime is a special case as it is not a one-liner test.
    var functionName = Blockly.RobotC.provideFunction_(
        'mathIsPrime',
        ['bool ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '(n) {',
         '  // https://en.wikipedia.org/wiki/Primality_test#Naive_methods',
         '  if (n == 2 || n == 3) {',
         '    return true;',
         '  }',
         '  // False if n is negative, is 1, or not whole.',
         '  // And false if n is divisible by 2 or 3.',
         '  if (n <= 1 || n % 1 != 0 || n % 2 == 0 ||' +
            ' n % 3 == 0) {',
         '    return false;',
         '  }',
         '  // Check all the numbers of form 6k +/- 1, up to sqrt(n).',
         '  for (int x = 6; x <= sqrt(n) + 1; x += 6) {',
         '    if (n % (x - 1) == 0 || n % (x + 1) == 0) {',
         '      return false;',
         '    }',
         '  }',
         '  return true;',
         '}']);
    code = functionName + '(' + number_to_check + ')';
    return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
  }
  switch (dropdown_property) {
    case 'EVEN':
      code = number_to_check + ' % 2 == 0';
      break;
    case 'ODD':
      code = 'mod(' + number_to_check + ', 2) == 1';
      break;
    case 'WHOLE':
      code = number_to_check + ' % 1 == 0';
      break;
    case 'POSITIVE':
      code = number_to_check + ' > 0';
      break;
    case 'NEGATIVE':
      code = number_to_check + ' < 0';
      break;
    case 'DIVISIBLE_BY':
      var divisor = Blockly.RobotC.valueToCode(block, 'DIVISOR',
          Blockly.RobotC.ORDER_MODULUS) || '0';
      code = number_to_check + ' % ' + divisor + ' == 0';
      break;
  }
  return [code, Blockly.RobotC.ORDER_EQUALITY];
};

Blockly.RobotC['math_change'] = function(block) {
  // Add to a variable in place.
  var argument0 = Blockly.RobotC.valueToCode(block, 'DELTA',
      Blockly.RobotC.ORDER_ADDITION) || '0';
  var varName = Blockly.RobotC.variableDB_.getName(
      block.getFieldValue('VAR'), Blockly.VARIABLE_CATEGORY_NAME);
  return varName + ' += ' + argument0 + ';\n';
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
      Blockly.RobotC.ORDER_MODULUS) || '0';
  var argument1 = Blockly.RobotC.valueToCode(block, 'DIVISOR',
      Blockly.RobotC.ORDER_MODULUS) || '0';
  var code = 'mod(' + argument0 + ', ' + argument1 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_constrain'] = function(block) {
  // Constrain a number between two limits.
  var argument0 = Blockly.RobotC.valueToCode(block, 'VALUE',
      Blockly.RobotC.ORDER_COMMA) || '0';
  var argument1 = Blockly.RobotC.valueToCode(block, 'LOW',
      Blockly.RobotC.ORDER_COMMA) || '0';
  var argument2 = Blockly.RobotC.valueToCode(block, 'HIGH',
      Blockly.RobotC.ORDER_COMMA) || 'Infinity';
  var code = argument0 + ' < ' + argument1 + ' ? ' + argument1 
      + ' : (' + argument0 + ' > ' + argument2 + ' ? ' + argument2 
      + ' : ' + argument0 + ')';
  return [code, Blockly.RobotC.ORDER_CONDITIONAL];
};

Blockly.RobotC['math_random_int'] = function(block) {
  // Random integer between [X] and [Y].
  var argument0 = Blockly.RobotC.valueToCode(block, 'FROM',
      Blockly.RobotC.ORDER_COMMA) || '0';
  var argument1 = Blockly.RobotC.valueToCode(block, 'TO',
      Blockly.RobotC.ORDER_COMMA) || '0';
  var functionName = Blockly.RobotC.provideFunction_(
      'mathRandomInt',
      ['float ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ +
          '(a, b) {',
       '  if (a > b) {',
       '    // Swap a and b to ensure a is smaller.',
       '    var c = a;',
       '    a = b;',
       '    b = c;',
       '  }',
       '  return randLong() % (b-a) + a;',
       '}']);
  var code = functionName + '(' + argument0 + ', ' + argument1 + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['math_random_float'] = function(block) {
  // Random fraction between 0 and 1.
  return ['(float)randLong() / 2147483647', Blockly.RobotC.ORDER_DIVISION];
};

Blockly.RobotC['math_angle_distance'] = function(block) {
  var value_from = Blockly.RobotC.valueToCode(block, 'FROM', Blockly.RobotC.ORDER_ATOMIC);
  var value_to = Blockly.RobotC.valueToCode(block, 'TO', Blockly.RobotC.ORDER_ATOMIC);
  var code = 'mod(' + value_to + ' - ' + value_from + ' + 180, 360) - 180';
  return [code, Blockly.RobotC.ORDER_SUBTRACTION];
};

Blockly.RobotC.math = `
float mod(int i, int n) {
  return (i % n + n) % n;
}

`;

Blockly.RobotC.addReservedWords(
  'mod');