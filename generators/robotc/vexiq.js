// TODO: 
// Nice to have:
// Points and rotation


Blockly.RobotC['events_on_start'] = function(block) {
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('on_' + Blockly.RobotC.startEventName_,
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  if (event_is_active(' + Blockly.RobotC.startEventName_ + ')) {',
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
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('when_true',
      Blockly.PROCEDURE_CATEGORY_NAME);
  var oldStateVarName = Blockly.RobotC.variableDB_.getName(functionName + '_old_state',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  block.getDeveloperVariables = () => [oldStateVarName];
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  bool new_state = ' + value_when + ';',
       '  if (new_state && new_state != ' + oldStateVarName + ') {',
       code,
       '  }',
       '  ' + oldStateVarName + ' = new_state;',
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
};

Blockly.RobotC['events_after'] = function(block) {
  var value_after = Blockly.RobotC.valueToCode(block, 'AFTER', Blockly.RobotC.ORDER_ATOMIC);
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('when_false',
      Blockly.PROCEDURE_CATEGORY_NAME);
  var oldStateVarName = Blockly.RobotC.variableDB_.getName(functionName + '_old_state',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  block.getDeveloperVariables = () => [oldStateVarName];
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  bool new_state = ' + value_after + ';',
       '  if (!new_state && new_state != ' + oldStateVarName + ') {',
       code,
       '  }',
       '  ' + oldStateVarName + ' = new_state;',
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
};

Blockly.RobotC['events_while'] = function(block) {
  var value_while = Blockly.RobotC.valueToCode(block, 'WHILE', Blockly.RobotC.ORDER_ATOMIC);
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('while',
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  if (' + value_while + ') {',
       code,
       '  }',
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
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
  Blockly.RobotC.variableTypes[variable_event] = 'Event';
  var code = Blockly.RobotC.statementToCode(block, 'DO');
  code = Blockly.RobotC.prefixLines(code, Blockly.RobotC.INDENT);
  var functionName = Blockly.RobotC.variableDB_.getDistinctName('on_' + variable_event,
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(
      functionName,
      ['void ' + Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_ + '() {',
       '  if (event_is_active(' + variable_event +')) {',
       code,
       '  }',
       '}']);
  Blockly.RobotC.eventFunctionNames_.push(functionName);
  return null;
};

Blockly.RobotC['events_trigger_event'] = function(block) {
  var variable_event = Blockly.RobotC.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.variableTypes[variable_event] = 'ubyte';
  var code = 'queue_event(' + variable_event + ');\n';
  return code;
};

Blockly.RobotC['events_trigger_event_after'] = function(block) {
  var variable_event = Blockly.RobotC.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.variableTypes[variable_event] = 'Event';
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
  Blockly.RobotC.lastGyroDrift_ = Blockly.RobotC.valueToCode(block, 'DRIFT', Blockly.RobotC.ORDER_ATOMIC);
  Blockly.RobotC.lastGyroDirection_ = block.getFieldValue('DIRECTION');
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['vex_iq_brain'] = function(block) {
  //var dropdown_has_controller = block.getFieldValue('HAS_CONTROLLER');
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
    if (value == 'sensorVexIQ_Gyro') {
      Blockly.RobotC.gyroDrifts_[variable] = Blockly.RobotC.lastGyroDrift_;
      Blockly.RobotC.gyroDirections_[variable] = Blockly.RobotC.lastGyroDirection_;
    }
    Blockly.RobotC.variableTypes_[variable] = '#pragma';
  }
  Blockly.RobotC.pragmas_ = code;
  return null;
};

Blockly.RobotC['vex_iq_lcd_print'] = function(block) {
  var escape = function(s) {
    return s.replace(/[\\"']/g, '\\$&').replace(/\u0000/g, '\\0');
  }
  var text = new Array(block.varCount_ + 1);
  var vars = new Array(block.varCount_);
  line = block.getFieldValue('LINE');
  text[0] = escape(block.getFieldValue('TEXT0'));
  for (var i = 0; i < block.varCount_; i++) {
    vars[i] = Blockly.RobotC.valueToCode(block, 'VAR' + i,
        Blockly.RobotC.ORDER_COMMA) || '0';
    text[i + 1] = escape(block.getFieldValue('TEXT' + (i + 1)));
  }
  var formatstr = text.join('%1.2f');
  var code = 'displayTextLine(' + line + ', "' + formatstr + '", ' + vars.join(', ') + ');\n';
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
    'G_SHARP': 'noteGSharp'
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
  var code = 'playNote(' + noteConstant + ', ' + octaveConstant + ', ceil(' + duration + '));\n';
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
    value_velocity = '- (' + value_velocity + ')'
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
  var target = 'getMotorEncoder(' + variable_motor + ')'
  if (dropdown_direction == 'BACKWARD') {
    target += ' - ' + value_distance;
  } else {
    target += ' + ' + value_distance;
  }
  var motorTargetVarName = Blockly.RobotC.variableDB_.getName(variable_motor + '_target',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  block.getDeveloperVariables = () => [motorTargetVarName];
  var setTarget = motorTargetVarName + ' = ' + target + ';\n';
  if (dropdown_stop_mode === 'HOLD') {
    return setTarget + 'setServoTarget(' + variable_motor + ', ' + motorTargetVarName + ');\n';
  } else {
    return setTarget + 'setMotorTarget(' + variable_motor + ', ' + motorTargetVarName + ', ' + value_velocity + ');\n';
  }
};

Blockly.RobotC['vex_iq_motor_spin_to'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var value_position = Blockly.RobotC.valueToCode(block, 'POSITION', Blockly.RobotC.ORDER_ATOMIC);
  var dropdown_stop_mode = block.getFieldValue('STOP_MODE');
  var value_velocity = Blockly.RobotC.valueToCode(block, 'VELOCITY', Blockly.RobotC.ORDER_ATOMIC);
  value_velocity = 'abs(' + value_velocity + ')';
  var motorTargetVarName = Blockly.RobotC.variableDB_.getName(variable_motor + '_target',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  block.getDeveloperVariables = () => [motorTargetVarName];
  var setTarget = motorTargetVarName + ' = ' + value_position + ';\n';
  if (dropdown_stop_mode === 'HOLD') {
    return setTarget + 'setServoTarget(' + variable_motor + ', ' + motorTargetVarName + ');\n';
  } else {
    return setTarget + 'setMotorTarget(' + variable_motor + ', ' + motorTargetVarName + ', ' + value_velocity + ');\n';
  }
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

Blockly.RobotC['vex_iq_motor_current'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var code = 'getMotorCurrent(' + variable_motor + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_motor_wait'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var motorTargetVarName = Blockly.RobotC.variableDB_.getName(variable_motor + '_target',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  block.getDeveloperVariables = () => [motorTargetVarName];
  var code = 'while (abs(getMotorEncoder(' +  variable_motor + ') - ' + motorTargetVarName + ') > 10 && getMotorSpeed(' + variable_motor + ') > 5) {\n' +
      Blockly.RobotC.INDENT + 'sleep(1);\n' +
      '}\n'
  return code;
};

Blockly.RobotC['vex_iq_bumper_is_pressed'] = function(block) {
  var variable_bumper = Blockly.RobotC.variableDB_.getName(block.getFieldValue('BUMPER'), Blockly.Variables.NAME_TYPE);
  var code = 'getBumperValue(' + variable_bumper + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
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

// Deprecated
Blockly.RobotC['vex_iq_distance_max'] = function(block) {
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  var code = 'setDistanceMaxRange(' + variable_distance_sensor + ', ' + value_distance + ');\n';
  return code;
};

// Deprecated
Blockly.RobotC['vex_iq_distance_min'] = function(block) {
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  var code = 'setDistanceMinRange(' + variable_distance_sensor + ', ' + value_distance + ');\n';
  return code;
};

Blockly.RobotC['vex_iq_distance_bound'] = function(block) {
  var BOUNDS = {
    'MAXIMUM': 'setDistanceMaxRange',
    'MINIMUM': 'setDistanceMinRange',
    'BRIGHTNESS_THRESHOLD': 'setDistanceBrightnessThreshold',
    'SNR_THRESHOLD': 'setDistanceSNRThreshold',
    'FILTER_FACTOR': 'setDistanceFilterFactor',
    'TRANSMIT_POWER': 'setDistanceTransmitPower'
  };
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.RobotC.valueToCode(block, 'DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  var funcName = BOUNDS[block.getFieldValue('BOUND')];
  var code = funcName + '(' + variable_distance_sensor + ', ' + value_distance + ');\n';
  return code;
};

Blockly.RobotC['vex_iq_distance_tracker'] = function(block) {
  var MODES = {
    'STRONGEST': 'getDistanceStrongest',
    'SECOND_STRONGEST': 'getDistanceSecondStrongest', 
    'MOST_REFLECTIVE': 'getDistanceMostReflective'
  };
  var modeFunction = MODES[block.getFieldValue('MODE')];
  var value_initial_distance = Blockly.RobotC.valueToCode(block, 'INITIAL_DISTANCE', Blockly.RobotC.ORDER_ATOMIC);
  var value_max_velocity = Blockly.RobotC.valueToCode(block, 'MAX_VELOCITY', Blockly.RobotC.ORDER_ATOMIC);
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var trackedDistanceVarName = Blockly.RobotC.variableDB_.getName(variable_distance_sensor + '_tracked_distance',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  var trackedMeasurementTimeVarName = Blockly.RobotC.variableDB_.getName(variable_distance_sensor + '_tracked_measurement_time',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  var trackedMaxVelocityVarName = Blockly.RobotC.variableDB_.getName(variable_distance_sensor + '_tracked_max_velocity',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);      
  block.getDeveloperVariables = () => [trackedDistanceVarName, trackedMeasurementTimeVarName, trackedMaxVelocityVarName];
      
  // TODO: Assemble JavaScript into code variable.
  var code = trackedDistanceVarName + ' = ' + value_initial_distance + ';\n' +
      trackedMaxVelocityVarName + ' = ' + value_max_velocity + ';\n' +
      trackedMeasurementTimeVarName + ' = 0;\n';

  var functionName = Blockly.RobotC.variableDB_.getDistinctName('track_' + variable_distance_sensor,
      Blockly.PROCEDURE_CATEGORY_NAME);
  functionName = Blockly.RobotC.provideFunction_(functionName, [
`void ${Blockly.RobotC.FUNCTION_NAME_PLACEHOLDER_}() {
  float now = nPgmTime;
  float allowable_deviation = (now - ${trackedMeasurementTimeVarName}) * ${trackedMaxVelocityVarName} + 5;
  float range_min = ${trackedDistanceVarName} - allowable_deviation;
  if (range_min < 0) {
    range_min = 0;
  }
  float range_max = ${trackedDistanceVarName} + allowable_deviation;
  if (range_max > 1200) {  // practical max distance of vex iq sensor
    range_max = 1200;
  }
  setDistanceMinRange(${variable_distance_sensor}, range_min);
  setDistanceMaxRange(${variable_distance_sensor}, range_max);

  // median of three helps avoid spurious measurements
  float a = ${modeFunction}(${variable_distance_sensor});
  float b = ${modeFunction}(${variable_distance_sensor});
  float c = ${modeFunction}(${variable_distance_sensor});
  float measured_distance;
  if (a >= b && a <= c || a >= c && a <= b) {
    measured_distance = a;
  } else if (b >= a && b <= c || b >= c && b <= a) {
    measured_distance = b;
  } else {
    measured_distance = c;
  }
  if (measured_distance >= range_min && measured_distance <= range_max) {
    ${trackedDistanceVarName} = measured_distance;
    ${trackedMeasurementTimeVarName} = now;
  }
}`
  ]);
  Blockly.RobotC.eventFunctionNames_.push(functionName);

  return code;
};

// Deprecated
Blockly.RobotC['vex_iq_distance_sampler'] = function(block) {
  var MODES = {
    'STRONGEST': ['strongest', 'getDistanceStrongest'],
    'SECOND_STRONGEST': ['secondStrongest', 'getDistanceSecondStrongest'], 
    'MOST_REFLECTIVE': ['mostReflective', 'getDistanceMostReflective']
  };
  var AGGREGATORS = {
    'BRIGHTEST': 'brightest',
    'HIGHEST_SNR': 'highestSNR',
    'AVERAGE': 'average',
  }
  var dropdown_aggregator = AGGREGATORS[block.getFieldValue('AGGREGATOR')];
  var dropdown_samples = block.getFieldValue('SAMPLES') || '1';
  var dropdown_period = block.getFieldValue('PERIOD') || '0';
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var modeEnum = MODES[block.getFieldValue('MODE')][0];
  var modeFunction = MODES[block.getFieldValue('MODE')][1];
  var code;
  if (dropdown_samples == '1') {
    code = modeFunction + '(' + variable_distance_sensor + ')';
  } else {
    code = 'sample_distances(' + modeEnum + ', ' + variable_distance_sensor + ', ' + dropdown_samples + ', ' + dropdown_period + ', ' + dropdown_aggregator + ')';
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_distance'] = function(block) {
  var MODES = {
    'STRONGEST': 'getDistanceStrongest',
    'SECOND_STRONGEST': 'getDistanceSecondStrongest', 
    'MOST_REFLECTIVE': 'getDistanceMostReflective',
    'TRACKED': 'TRACKED'
  };
  var variable_distance_sensor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var modeFunction = MODES[block.getFieldValue('MODE')];
  var code;
  if (modeFunction == 'TRACKED') {
    code = Blockly.RobotC.variableDB_.getName(variable_distance_sensor + '_tracked_distance',
        Blockly.Names.DEVELOPER_VARIABLE_TYPE);
    block.getDeveloperVariables = () => [code];
  } else {
    code = modeFunction + '(' + variable_distance_sensor + ')';
  }
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_motor_reset_absolute_position'] = function(block) {
  var variable_motor = Blockly.RobotC.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var code = 'resetMotorEncoder(' + variable_motor + ');\n';
  return code;
};

Blockly.RobotC['vex_iq_gyro_heading'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var resetTimeVarName = Blockly.RobotC.variableDB_.getName(variable_name + '_reset_time',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  block.getDeveloperVariables = () => [resetTimeVarName];
  var sign = '';
  if (Blockly.RobotC.gyroDirections_[variable_name] == 'CW') {
    sign = '-';
  }
  var code = 'mod(' + sign + 'getGyroHeadingFloat(' + variable_name + ') - (nPgmTime - ' + resetTimeVarName + ') * ' + Blockly.RobotC.gyroDrifts_[variable_name] + ' / 1000.0, 360)';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_gyro_reset_heading'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var resetTimeVarName = Blockly.RobotC.variableDB_.getName(variable_name + '_reset_time',
      Blockly.Names.DEVELOPER_VARIABLE_TYPE);
  var code = 'resetGyro(' + variable_name + ');\n' +
      resetTimeVarName + ' = nPgmTime;\n' ;
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
  var CONTROLLER_BUTTONS = {
    'E_UP' : 'BtnEUp',
    'E_DOWN' : 'BtnEDown',
    'F_UP' : 'BtnFUp',
    'F_DOWN' : 'BtnFDown',
    'L_UP' : 'BtnLUp',
    'L_DOWN' : 'BtnLDown',
    'R_UP' : 'BtnRUp',
    'R_DOWN' : 'BtnRDown'
  };
  var button = CONTROLLER_BUTTONS[block.getFieldValue('BUTTON')];
  var code = 'getJoystickValue(' + button + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_controller_button'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_controller_joystick_position'] = function(block) {
  var JOYSTICK_CHANNELS = {
    'LEFT' : {
      'VERTICAL' : 'ChA',
      'HORIZONTAL' : 'ChB'
    },
    'RIGHT' : {
      'VERTICAL' : 'ChD',
      'HORIZONTAL' : 'ChC'
    }
  };
  var channel = JOYSTICK_CHANNELS[block.getFieldValue('JOYSTICK')][block.getFieldValue('AXIS')];
  var code = 'getJoystickValue(' + channel + ')';
  return [code, Blockly.RobotC.ORDER_FUNCTION_CALL];
};

Blockly.RobotC['vex_iq_controller_joystick'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  // TODO: Assemble RobotC into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.RobotC.ORDER_NONE];
};

Blockly.RobotC['vex_iq_controller_joystick_point_position'] = function(block) {
  var JOYSTICK_X_CHANNEL = {
    'LEFT' : 'ChB',
    'RIGHT' : 'ChC'
  };
  var JOYSTICK_Y_CHANNEL = {
    'LEFT' : 'ChA',
    'RIGHT' : 'ChD'
  };
  var x_channel = JOYSTICK_X_CHANNEL[block.getFieldValue('JOYSTICK')];
  var y_channel = JOYSTICK_Y_CHANNEL[block.getFieldValue('JOYSTICK')];
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.variableTypes_[variable_name] = 'Point';
  var code = variable_name + '.x = getJoystickValue(' + x_channel + ');\n' +
      variable_name + '.y = getJoystickValue(' + y_channel + ');\n';
  return code;
};

Blockly.RobotC['math_points_value'] = function(block) {
  var VALUES = {
    'X' : 'x',
    'Y' : 'y'
  };
  var value = VALUES[block.getFieldValue('VALUE')];
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.variableTypes_[variable_name] = 'Point';
  var code = variable_name + '.' + value;
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

// Deprecated
Blockly.RobotC['math_points_x'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.variableTypes_[variable_name] = 'Point';
  var code = variable_name + '.x';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

// Deprecated
Blockly.RobotC['math_points_y'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  Blockly.RobotC.variableTypes_[variable_name] = 'Point';
  var code = variable_name + '.y';
  return [code, Blockly.RobotC.ORDER_ATOMIC];
};

Blockly.RobotC['math_points_constructor'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var value_x = Blockly.RobotC.valueToCode(block, 'X', Blockly.RobotC.ORDER_ATOMIC);
  var value_y = Blockly.RobotC.valueToCode(block, 'Y', Blockly.RobotC.ORDER_ATOMIC);
  Blockly.RobotC.variableTypes_[variable_name] = 'Point';
  var code = variable_name + '.x = ' + value_x + ';\n' + 
      variable_name + '.y = ' + value_y + ';\n';
  return code;
};

Blockly.RobotC['math_points_rotation'] = function(block) {
  var variable_name = Blockly.RobotC.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var value_theta = Blockly.RobotC.valueToCode(block, 'THETA', Blockly.RobotC.ORDER_ATOMIC);
  Blockly.RobotC.variableTypes_[variable_name] = 'Point';
  var code = 'rotate(' + variable_name + ', ' + value_theta + ');\n';
  return code;
};

Blockly.RobotC['math_points_arithmetic'] = function(block) {
  var variable_point1 = Blockly.RobotC.variableDB_.getName(block.getFieldValue('POINT1'), Blockly.Variables.NAME_TYPE);
  var dropdown_op = block.getFieldValue('OP');
  switch (dropdown_op) {
    case 'DIVIDE':
      var value_number = Blockly.RobotC.valueToCode(block, 'BY_NUMBER', Blockly.RobotC.ORDER_ATOMIC);
      value_number = '1 / ' + value_number;
      return 'scale(' + variable_point1 + ', ' +  value_number + ');\n';     
    case 'MULTIPLY':
      var value_number = Blockly.RobotC.valueToCode(block, 'BY_NUMBER', Blockly.RobotC.ORDER_ATOMIC);
      return 'scale(' + variable_point1 + ', ' +  value_number + ');\n';
    case 'ADD':
      var variable_point2 = Blockly.RobotC.variableDB_.getName(block.getFieldValue('POINT2'), Blockly.Variables.NAME_TYPE);
      return 'translate(' + variable_point1 + ', ' +  variable_point2 + '.x, ' + variable_point2 + '.y);\n';
    case 'MINUS':
      var variable_point2 = Blockly.RobotC.variableDB_.getName(block.getFieldValue('POINT2'), Blockly.Variables.NAME_TYPE);
      return 'translate(' + variable_point1 + ', -' +  variable_point2 + '.x, -' + variable_point2 + '.y);\n';
  }
};

Blockly.RobotC['vex_iq_sleep'] = function(block) {
  var value_duration = Blockly.RobotC.valueToCode(block, 'DURATION', Blockly.RobotC.ORDER_ATOMIC);
  var code = 'sleep(' + value_duration + ');\n';
  return code;
};

Blockly.RobotC['comment_block'] = function(block) {
  return '';
};

Blockly.RobotC.typedefs_.push(`
typedef enum distanceMode {
  strongest,
  secondStrongest, 
  mostReflective
} DistanceMode;
`);

Blockly.RobotC.typedefs_.push(`
typedef enum aggregator {
  brightest,
  highestSNR,
  average
} Aggregator;
`);

Blockly.RobotC.typedefs_.push(`
typedef struct {
  uword distance;
  ubyte brightness;
  ubyte snr;
} DistanceSample;
`);

Blockly.RobotC.vexiq = `
DistanceSample samples[100];
float sample_distances(DistanceMode mode, tSensors distance_sensor, int sampleCount, int period, Aggregator aggregator) {
  TDistanceInfo distanceInfo;
  for (int i = 0; i < sampleCount; i++) {
    getDistanceAdvanced(distance_sensor, distanceInfo);
    switch (mode) {
      case strongest:
        samples[i].distance = distanceInfo.n1stStrongestTargetDistance;
        samples[i].brightness = distanceInfo.n1stStrongestTargetBrightness;
        samples[i].snr = distanceInfo.n1stStrongestTargetSNR;
        break;
      case secondStrongest:
        samples[i].distance = distanceInfo.n2ndStrongestTargetDistance;
        samples[i].brightness = distanceInfo.n2ndStrongestTargetBrightness;
        samples[i].snr = distanceInfo.n2ndStrongestTargetSNR;
        break;
      case mostReflective:
        samples[i].distance = distanceInfo.nBrightestTargetDistance;
        samples[i].brightness = distanceInfo.nBrightestTargetBrightness;
        samples[i].snr = distanceInfo.nBrightestTargetSNR;
        break;
    }
    sleep(period);
  }
  switch (aggregator) {
    case brightest:
      ubyte maxBrightness = 0;
      uword brightestDistance = 0;
      for (int i = 0; i < sampleCount; i++) {
        if (samples[i].brightness > maxBrightness) {
          maxBrightness = samples[i].brightness;
          brightestDistance = samples[i].distance;
        }
      }
      return brightestDistance;
    case highestSNR:
      ubyte maxSNR = 0;
      uword bestDistance = 0;
      for (int i = 0; i < sampleCount; i++) {
        if (samples[i].snr > maxSNR) {
          maxSNR = samples[i].snr;
          bestDistance = samples[i].distance;
        }
      }
      return bestDistance;      
    case average:
      uword totalDistance = 0;
      for (int i = 0; i < sampleCount; i++) {
        totalDistance += samples[i].distance;
      }
      return (float) totalDistance / sampleCount;
  }
  return -1;
}

`;

Blockly.RobotC.addReservedWords(
  'strongest,secondStrongest,mostReflective,DistanceMode,'+
  'brightest,highestSNR,average,Aggregator,'+
  'distance,brightness,snr,DistanceSample,'+
  'samples,sample_distances');
