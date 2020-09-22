Blockly.JavaScript['events_on_start'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_on_press'] = function(block) {
  var value_on_press = Blockly.JavaScript.valueToCode(block, 'ON_PRESS', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_on_release'] = function(block) {
  var value_on_release = Blockly.JavaScript.valueToCode(block, 'ON_RELEASE', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_on_move'] = function(block) {
  var value_on_move = Blockly.JavaScript.valueToCode(block, 'ON_MOVE', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_on_change'] = function(block) {
  var value_on_change = Blockly.JavaScript.valueToCode(block, 'ON_CHANGE', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_on_event'] = function(block) {
  var variable_event = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_trigger_event'] = function(block) {
  var variable_event = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_trigger_event_after'] = function(block) {
  var variable_event = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  var value_name = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_time_unit = block.getFieldValue('TIME_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor'] = function(block) {
  var dropdown_direction = block.getFieldValue('DIRECTION');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_bumper'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_touchled'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_color_sensor'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_distance_sensor'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_gyro'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_brain'] = function(block) {
  var dropdown_has_controller = block.getFieldValue('HAS_CONTROLLER');
  var variable_controller_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('CONTROLLER_NAME'), Blockly.Variables.NAME_TYPE);
  var variable_port_1_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_1_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_1 = Blockly.JavaScript.valueToCode(block, 'PORT_1', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_2_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_2_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_2 = Blockly.JavaScript.valueToCode(block, 'PORT_2', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_3_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_3_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_3 = Blockly.JavaScript.valueToCode(block, 'PORT_3', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_4_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_4_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_4 = Blockly.JavaScript.valueToCode(block, 'PORT_4', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_5_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_5_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_5 = Blockly.JavaScript.valueToCode(block, 'PORT_5', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_6_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_6_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_6 = Blockly.JavaScript.valueToCode(block, 'PORT_6', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_7_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_7_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_7 = Blockly.JavaScript.valueToCode(block, 'PORT_7', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_8_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_8_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_8 = Blockly.JavaScript.valueToCode(block, 'PORT_8', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_9_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_9_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_9 = Blockly.JavaScript.valueToCode(block, 'PORT_9', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_10_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_10_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_10 = Blockly.JavaScript.valueToCode(block, 'PORT_10', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_11_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_11_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_11 = Blockly.JavaScript.valueToCode(block, 'PORT_11', Blockly.JavaScript.ORDER_ATOMIC);
  var variable_port_12_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('PORT_12_NAME'), Blockly.Variables.NAME_TYPE);
  var value_port_12 = Blockly.JavaScript.valueToCode(block, 'PORT_12', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_lcd_print'] = function(block) {
  var value_string = Blockly.JavaScript.valueToCode(block, 'STRING', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_line = block.getFieldValue('LINE');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_lcd_clear_screen'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_brain_check_button'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_brain_play_note'] = function(block) {
  var dropdown_note = block.getFieldValue('NOTE');
  var dropdown_octave = block.getFieldValue('OCTAVE');
  var value_name = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_unit = block.getFieldValue('UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_brain_play_sound'] = function(block) {
  var dropdown_note = block.getFieldValue('NOTE');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_brain_stop_sound'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_spin_velocity'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_direction = block.getFieldValue('DIRECTION');
  var value_velocity = Blockly.JavaScript.valueToCode(block, 'VELOCITY', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_unit = block.getFieldValue('UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_spin_distance'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_direction = block.getFieldValue('DIRECTION');
  var value_distance = Blockly.JavaScript.valueToCode(block, 'DISTANCE', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_distance_unit = block.getFieldValue('DISTANCE_UNIT');
  var value_velocity = Blockly.JavaScript.valueToCode(block, 'VELOCITY', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_velocity_unit = block.getFieldValue('VELOCITY_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_spin_to'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var value_position = Blockly.JavaScript.valueToCode(block, 'POSITION', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_position_unit = block.getFieldValue('POSITION_UNIT');
  var value_velocity = Blockly.JavaScript.valueToCode(block, 'VELOCITY', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_velocity_unit = block.getFieldValue('VELOCITY_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['events_trigger_event_on_motor_stop'] = function(block) {
  var variable_event = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('EVENT'), Blockly.Variables.NAME_TYPE);
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_spin_duration'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var value_duration = Blockly.JavaScript.valueToCode(block, 'DURATION', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_duration_unit = block.getFieldValue('DURATION_UNIT');
  var value_velocity = Blockly.JavaScript.valueToCode(block, 'VELOCITY', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_velocity_unit = block.getFieldValue('VELOCITY_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_stop'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_stop_mode = block.getFieldValue('STOP_MODE');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_position'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_position_unit = block.getFieldValue('POSITION_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_motor_velocity'] = function(block) {
  var variable_motor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('MOTOR'), Blockly.Variables.NAME_TYPE);
  var dropdown_unit = block.getFieldValue('UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_button_is_pressed'] = function(block) {
  var variable_button = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('BUTTON'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_touch_led_on'] = function(block) {
  var variable_touch_led = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('TOUCH_LED'), Blockly.Variables.NAME_TYPE);
  var colour_color = block.getFieldValue('COLOR');
  var value_brightness = Blockly.JavaScript.valueToCode(block, 'BRIGHTNESS', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_touch_led_blink'] = function(block) {
  var variable_touch_led = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('TOUCH_LED'), Blockly.Variables.NAME_TYPE);
  var colour_color = block.getFieldValue('COLOR');
  var value_brightness = Blockly.JavaScript.valueToCode(block, 'BRIGHTNESS', Blockly.JavaScript.ORDER_ATOMIC);
  var value_on_duration = Blockly.JavaScript.valueToCode(block, 'ON_DURATION', Blockly.JavaScript.ORDER_ATOMIC);
  var value_off_duration = Blockly.JavaScript.valueToCode(block, 'OFF_DURATION', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_time_unit = block.getFieldValue('TIME_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_touch_led_off'] = function(block) {
  var variable_touch_led = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('TOUCH_LED'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_distance_max'] = function(block) {
  var variable_distance_sensor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.JavaScript.valueToCode(block, 'DISTANCE', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_unit = block.getFieldValue('UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_distance_min'] = function(block) {
  var variable_distance_sensor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.JavaScript.valueToCode(block, 'DISTANCE', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_unit = block.getFieldValue('UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_distance'] = function(block) {
  var variable_distance_sensor = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('DISTANCE_SENSOR'), Blockly.Variables.NAME_TYPE);
  var value_distance = Blockly.JavaScript.valueToCode(block, 'DISTANCE', Blockly.JavaScript.ORDER_ATOMIC);
  var dropdown_unit = block.getFieldValue('UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_motor_reset_absolute_position'] = function(block) {
  var variable_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_gyro_heading'] = function(block) {
  var variable_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_gyro_reset_heading'] = function(block) {
  var variable_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_gyro_rate'] = function(block) {
  var variable_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var dropdown_time_unit = block.getFieldValue('TIME_UNIT');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_gyro_sensitivity'] = function(block) {
  var variable_name = Blockly.JavaScript.variableDB_.getName(block.getFieldValue('NAME'), Blockly.Variables.NAME_TYPE);
  var dropdown_sensitivity = block.getFieldValue('SENSITIVITY');
  // TODO: Assemble JavaScript into code variable.
  var code = '...;\n';
  return code;
};

Blockly.JavaScript['vex_iq_controller_button_pressed'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_controller_button'] = function(block) {
  var dropdown_button = block.getFieldValue('BUTTON');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_controller_joystick_position'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  var dropdown_axis = block.getFieldValue('AXIS');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_controller_joystick'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['vex_iq_controller_joystick_point_position'] = function(block) {
  var dropdown_joystick = block.getFieldValue('JOYSTICK');
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_points_x'] = function(block) {
  var value_name = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_points_y'] = function(block) {
  var value_name = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_points_constructor'] = function(block) {
  var value_x = Blockly.JavaScript.valueToCode(block, 'X', Blockly.JavaScript.ORDER_ATOMIC);
  var value_y = Blockly.JavaScript.valueToCode(block, 'Y', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};

Blockly.JavaScript['math_points_rotation'] = function(block) {
  var value_name = Blockly.JavaScript.valueToCode(block, 'NAME', Blockly.JavaScript.ORDER_ATOMIC);
  var value_theta = Blockly.JavaScript.valueToCode(block, 'THETA', Blockly.JavaScript.ORDER_ATOMIC);
  // TODO: Assemble JavaScript into code variable.
  var code = '...';
  // TODO: Change ORDER_NONE to the correct strength.
  return [code, Blockly.JavaScript.ORDER_NONE];
};