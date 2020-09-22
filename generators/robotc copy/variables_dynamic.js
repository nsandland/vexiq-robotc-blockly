/**
 * @license
 * Copyright 2018 Google LLC
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @fileoverview Generating RobotC for dynamic variable blocks.
 * @author fenichel@google.com (Rachel Fenichel)
 */
'use strict';

goog.provide('Blockly.RobotC.variablesDynamic');

goog.require('Blockly.RobotC');
goog.require('Blockly.RobotC.variables');


// RobotC is dynamically typed.
Blockly.RobotC['variables_get_dynamic'] =
    Blockly.RobotC['variables_get'];
Blockly.RobotC['variables_set_dynamic'] =
    Blockly.RobotC['variables_set'];
