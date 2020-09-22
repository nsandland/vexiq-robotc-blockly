Blockly.RobotC['events_on_start'] = function(block) {
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  startEventName = Blockly.RobotC.variableDB_.getName(
      'start', Blockly.VARIABLE_CATEGORY_NAME);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('on_' + startEventName,
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  if (event_active(' + startEventName + ')) {',
       code,
       '  }',
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
};

Blockly.RobotC['events_always'] = function(block) {
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('always',
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       code,
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
};

Blockly.RobotC['events_when'] = function(block) {
  var value_when = Blockly.RobotC.valueToCode(block, 'WHEN', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['events_after'] = function(block) {
  var value_when = Blockly.RobotC.valueToCode(block, 'AFTER', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

/*Blockly.RobotC['events_on_press'] = function(block) {
  var value_on_press = Blockly.RobotC.valueToCode(block, 'ON_PRESS', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['events_on_release'] = function(block) {
  var value_on_release = Blockly.RobotC.valueToCode(block, 'ON_RELEASE', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['events_on_move'] = function(block) {
  var value_on_move = Blockly.RobotC.valueToCode(block, 'ON_MOVE', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['events_on_change'] = function(block) {
  var value_on_change = Blockly.RobotC.valueToCode(block, 'ON_CHANGE', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};*/

Blockly.RobotC['events_on_event'] = function(block) {
  var variable_event = Blockly.RobotC.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.eventVariableNames_.add(variable_event);
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('on_' + variable_event,
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  if (event_active(' + variable_event +')) {',
       code,
       '  }',
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
};

Blockly.RobotC['events_trigger_event'] = function(block) {
  var variable_event = Blockly.RobotC.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.eventVariableNames_.add(variable_event);
  var code = 'queue_event(' + variable_event + ');\n';
  return code;
};

Blockly.RobotC['events_trigger_event_after'] = function(block) {
  var variable_event = Blockly.RobotC.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.eventVariableNames_.add(variable_event);
  var value_name = Blockly.RobotC.valueToCode(block, 'NAME', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_motor'] = function(block) {
  var direction = block.getFieldValue('DIRECTION');
  var code = 'tmotorVexIQ, PIDControl, ';
  if (direction == 'REVERSE') {
    code += 'reversed, ';
  }
  code += 'encoder';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_bumper'] = function(block) {
  var code = 'sensorVexIQ_Touch';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_touchled'] = function(block) {
  var code = 'sensorVexIQ_LED';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_color_sensor'] = function(block) {
  var code = 'sensorVexIQ_ColorHue';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_distance_sensor'] = function(block) {
  var code = 'sensorVexIQ_Distance';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_gyro'] = function(block) {
  var code = 'sensorVexIQ_Gyro';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_brain'] = function(block) {
  var dropdown_has_controller = block.getFieldValue('HAS_CONTROLLER');
  var variable_controller_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('CONTROLLER_NAME'), Blockly.Variables.NAME_TYPE);
  var code = '';
  for (i = 1; i <= 12; i++) {
    var value = Blockly.RobotC.valueToCode(block, 'PORT_' + i, Blockly.RobotC.ORDER_ATOMIC);
    var variable = Blockly.RobotC.variableDB_.getName(block.getFieldValue('PORT_' + i + '_NAME'), Blockly.Variables.NAME_TYPE);  
    if (value.length > 0) {
      code += '#pragma config(';
      if (value.includes("tmotorVexIQ")) {
        code += 'Motor, motor' + i + ', ';
      } else {
        code += 'Sensor, port' + i + ', ';
      }
      code += variable + ', ';
      code += value + ')\n';
    }
    Blockly.RobotC.pragmaVariableNames_.add(variable);
  }
  Blockly.RobotC.pragmas_ = code;
  return null;
};

Blockly.RobotC['vex_iq_lcd_print'] = function(block) {
  var value_string = Blockly.RobotC.valueToCode(block, 'STRING', Blockly.RobotC.ORDER_ATOMIC);
  var dropdown_line = block.getFieldValue('LINE');
  var code = 'displayString(' + dropdown_line + ', vtos(' + value_string + '));\n';
  return code;
};

Blockly.RobotC['vex_iq_lcd_clear_screen'] = function(block) {
  var code = 'eraseDisplay();\n';
  return code;
};

Blockly.RobotC['vex_iq_brain_check_button'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_brain_play_note'] = function(block) {
  var NOTE_CONSTANTS = {
    'A': 'noteA',
    'A_SHARP': 'noteASharp',
    'B': 'noteB',
    'C': 'noteC',
    'C_SHARP': 'noteCSharp',
    'D': 'noteD',
    'D_SHARP': 'noteDSharp',
    'E': 'noteE',
    'F': 'noteF',
    'F_SHARP': 'noteFSharp',
    'G': 'noteG',
  };
  var noteConstant = NOTE_CONSTANTS[block.getFieldValue('NOTE')];
  var OCTAVE_CONSTANTS = {
    '1': 'octave1',
    '2': 'octave2',
    '3': 'octave3',
  };
  var octaveConstant = OCTAVE_CONSTANTS[block.getFieldValue('OCTAVE')];
  var duration = Blockly.RobotC.valueToCode(block, 'DURATION', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = 'playNote(' + noteConstant + ', ' + octaveConstant + ', ceil(' + duration + ') / 100.0));\n';
  return code;
};

Blockly.RobotC['vex_iq_brain_play_sound'] = function(block) {
  var SOUND_CONSTANTS = {
    'SIREN_2': 'soundSiren2',
    'WRONG_WAY': 'soundWrongWay', 
    'WRONG_WAY_SLOW': 'soundWrongWays',
    'GAS_FILLUP': 'soundGasFillup',
    'HEADLIGHTS_ON': 'soundHeadlightsOn',
    'HEADLIGHTS_OFF': 'soundHeadlightsOff',
    'TOLL_BOOTH': 'soundTollBooth',
    'CAR_ALARM_2': 'soundCarAlarm2',
    'TADA': 'soundTada',
    'GARAGE_DOOR_CLOSE': 'soundGarageDoorClose',
    'RATCHET': 'soundRatcht',
    'AIR_WRENCH': 'soundAirWrench',
    'SIREN_4': 'soundSiren4',
    'RATCHET_4': 'soundRatchet4',
    'CAR_ALARM_4': 'soundCarAlarm4',
    'POWER_OFF_2': 'soundPowerOff2'
  };
  var soundConstant = SOUND_CONSTANTS[block.getFieldValue('SOUND')];
  var code = 'playSound(' + soundConstant + ');\n';
  return code;
};

Blockly.RobotC['vex_iq_motor_spin_velocity'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_direction = block.getFieldValue('DIRECTION');
  var value_velocity = Blockly.RobotC.valueToCode(block, 'VELOCITY', Blockly.RobotC.ORDER_ATOMIC);
  if (dropdown_direction === 'BACKWARD') {
    if (value_velocity[0] == '-') {
      value_velocity = value_velocity.substring(1);
    } else {
      value_velocity = '-' + value_velocity;
    }
  }
  var code = 'setMotorSpeed(' + variable_motor + ', ' + value_velocity + ');\n';
  return code;
};

Blockly.RobotC['vex_iq_motor_spin_distance'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_direction = block.getFieldValue('DIRECTION');
  var dropdown_stop_mode = block.getFieldValue('STOP_MODE');
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  var value_velocity = Blockly.RobotC.valueToCode(block, 'VELOCITY', Blockly.RobotC.ORDER_ATOMIC);
  if (dropdown_direction[0] == 'BACKWARD') {
    if (value_distance[0] == '-') {
      value_distance = value_distance.substring(1);
    } else {
      value_distance = '-' + value_distance;
    }
  }
  var target = 'getMotorEncoder(' + variable_motor + ') + ' + value_distance;
  var f = dropdown_stop_mode === 'HOLD' ? 'setServoTarget' : 'setMotorTarget';
  var code = f + '(' + variable_motor + ', ' + target + ', abs(' + value_velocity + '));\n';
  return code;
};

Blockly.RobotC['vex_iq_motor_spin_to'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var value_position = Blockly.RobotC.valueToCode(block, 'POSITION', Blockly.RobotC.ORDER_ATOMIC);
  var dropdown_stop_mode = block.getFieldValue('STOP_MODE');
  var value_velocity = Blockly.RobotC.valueToCode(block, 'VELOCITY', Blockly.RobotC.ORDER_ATOMIC);
  value_velocity = 'abs(' + value_velocity + ')';
  var f = dropdown_stop_mode === 'HOLD' ? 'setServoTarget' : 'setMotorTarget';
  var code = f + '(' + variable_motor + ', ' + value_position + ', ' + value_velocity + ');\n';
  return code;
};

Blockly.RobotC['events_trigger_event_on_motor_stop'] = function(block) {
  var variable_event = Blockly.RobotC.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

/*Blockly.RobotC['vex_iq_motor_spin_duration'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var value_duration = Blockly.RobotC.valueToCode(block, 'DURATION', Blockly.RobotC.ORDER_ATOMIC);
  var value_velocity = Blockly.RobotC.valueToCode(block, 'VELOCITY', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};*/

Blockly.RobotC['vex_iq_motor_stop'] = function(block) {
  var STOP_MODES = {
    'HOLD': 'motorHold',
    'BRAKE': 'motorBrake', 
    'COAST': 'motorCoast'
  };
  var stop_mode = STOP_MODES[block.getFieldValue('STOP_MODE')];
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var code = 'setMotorBrakeMode(' + variable_motor + ', ' + stop_mode + ');\n' +
      'setMotorSpeed(' + variable_motor + ', 0);\n';
  return code;
};

Blockly.RobotC['vex_iq_motor_position'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var code = 'getMotorEncoder(' + variable_motor + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_motor_velocity'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var code = 'getMotorSpeed(' + variable_motor + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_button_is_pressed'] = function(block) {
  var variable_button = Blockly.RobotC.variableDB_.getName(block.getFieldValue('BUTTON'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_touch_led_on'] = function(block) {
  var variable_touch_led = Blockly.RobotC.variableDB_.getName(block.getFieldValue('TOUCH_LED'), Blockly.Variables.NAME_TYPE);
  var colour_color = block.getFieldValue('COLOR');
  var value_brightness = Blockly.RobotC.valueToCode(block, 'BRIGHTNESS', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_touch_led_blink'] = function(block) {
  var variable_touch_led = Blockly.RobotC.variableDB_.getName(block.getFieldValue('TOUCH_LED'), Blockly.Variables.NAME_TYPE);
  var colour_color = block.getFieldValue('COLOR');
  var value_brightness = Blockly.RobotC.valueToCode(block, 'BRIGHTNESS', Blockly.RobotC.ORDER_ATOMIC);
  var value_on_duration = Blockly.RobotC.valueToCode(block, 'ON_DURATION', Blockly.RobotC.ORDER_ATOMIC);
  var value_off_duration = Blockly.RobotC.valueToCode(block, 'OFF_DURATION', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_touch_led_off'] = function(block) {
  var variable_touch_led = Blockly.RobotC.variableDB_.getName(block.getFieldValue('TOUCH_LED'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_distance_max'] = function(block) {
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_distance_min'] = function(block) {
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_distance'] = function(block) {
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_motor_reset_absolute_position'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var code = 'resetMotorEncoder(' + variable_motor + ');\n';
  return code;
};

Blockly.RobotC['vex_iq_gyro_heading'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_gyro_reset_heading'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_gyro_rate'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_gyro_sensitivity'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var dropdown_sensitivity = block.getFieldValue('SENSITIVITY');
  // TODO: Assemble RobotC into code variable.
  var code = '...;\n';
  return code;
};

Blockly.RobotC['vex_iq_controller_button_pressed'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_controller_button'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_controller_joystick_position'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  var dropdown_axis = block.getFieldValue('AXIS');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_controller_joystick'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_controller_joystick_point_position'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['math_points_x'] = function(block) {
  var value_name = Blockly.RobotC.valueToCode(block, 'NAME', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['math_points_y'] = function(block) {
  var value_name = Blockly.RobotC.valueToCode(block, 'NAME', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['math_points_constructor'] = function(block) {
  var value_x = Blockly.RobotC.valueToCode(block, 'X', Blockly.RobotC.ORDER_ATOMIC);
  var value_y = Blockly.RobotC.valueToCode(block, 'Y', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['math_points_rotation'] = function(block) {
  var value_name = Blockly.RobotC.valueToCode(block, 'NAME', Blockly.RobotC.ORDER_ATOMIC);
  var value_theta = Blockly.RobotC.valueToCode(block, 'THETA', Blockly.RobotC.ORDER_ATOMIC);
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};