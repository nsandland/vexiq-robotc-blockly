Blockly.Blocks['events_on_start'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("on start");
    this.appendStatementInput("DO")
        .setCheck(null);
    this.setInputsInline(false);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_always'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("always");
    this.appendStatementInput("DO")
        .setCheck(null);    
    this.setInputsInline(false);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_when'] = {
  init: function() {
    this.appendValueInput("WHEN")
        .setCheck("Boolean")
        .appendField("when");
    this.appendStatementInput("DO")
        .setCheck(null);
    this.setInputsInline(false);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_after'] = {
  init: function() {
    this.appendValueInput("AFTER")
        .setCheck("Boolean")
        .appendField("after");
    this.appendStatementInput("DO")
        .setCheck(null);
    this.setInputsInline(false);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_while'] = {
  init: function() {
    this.appendValueInput("WHILE")
        .setCheck("Boolean")
        .appendField("while");
    this.appendStatementInput("DO")
        .setCheck(null);
    this.setInputsInline(false);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

/*Blockly.Blocks['events_on_press'] = {
  init: function() {
    this.appendValueInput("ON_PRESS")
        .setCheck(["Bumper", "ControllerButton", "TouchLED"])
        .appendField("on press");
    this.setInputsInline(false);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_on_release'] = {
  init: function() {
    this.appendValueInput("ON_RELEASE")
        .setCheck(["Bumper", "ControllerButton", "TouchLED"])
        .appendField("on release");
    this.setInputsInline(false);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_on_move'] = {
  init: function() {
    this.appendValueInput("ON_MOVE")
        .setCheck(["ControllerJoystick", "Motor", "DistanceSensor", "Gyro"])
        .appendField("on move");
    this.setInputsInline(false);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_on_change'] = {
  init: function() {
    this.appendValueInput("ON_CHANGE")
        .setCheck(["ControllerButton", "ControllerJoystick", "Motor", "DistanceSensor", "Gyro", "ColorSensor"])
        .appendField("on change");
    this.setInputsInline(false);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};*/

Blockly.Blocks['events_on_event'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("on")
        .appendField(new Blockly.FieldVariable("event"), "EVENT");
    this.appendStatementInput("DO")
        .setCheck(null);
    this.setInputsInline(false);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_trigger_event'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("trigger")
        .appendField(new Blockly.FieldVariable("event"), "EVENT");
    this.setInputsInline(false);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_trigger_event_after'] = {
  init: function() {
    this.appendValueInput("NAME")
        .setCheck("Number")
        .appendField("trigger")
        .appendField(new Blockly.FieldVariable("event"), "EVENT")
        .appendField("in");
    this.appendDummyInput()
        .appendField("ms");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("motor")
        .appendField(new Blockly.FieldDropdown([["going forward","FORWARD"], ["going in reverse","REVERSE"]]), "DIRECTION");
    this.setInputsInline(false);
    this.setOutput(true, "MotorDeclaration");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_bumper'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("bumper");
    this.setInputsInline(false);
    this.setOutput(true, "BumperDeclaration");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_touchled'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("touch LED");
    this.setInputsInline(false);
    this.setOutput(true, "TouchLEDDeclaration");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_color_sensor'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("color sensor");
    this.setInputsInline(false);
    this.setOutput(true, "ColorSensorDeclaration");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_distance_sensor'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("distance sensor");
    this.setInputsInline(false);
    this.setOutput(true, "DistanceSensorDeclaration");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_gyro'] = {
  init: function() {
    this.appendValueInput("DRIFT")
        .setCheck("Number")
        .appendField(new Blockly.FieldDropdown([["clockwise","CW"], ["counter-clockwise","CCW"]]), "DIRECTION")
        .appendField("gyro with ");
    this.appendDummyInput()
        .appendField("degrees/sec drift");
    this.setInputsInline(true);
    this.setOutput(true, "GyroDeclaration");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_brain'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("vex iq brain, where")
        //.appendField(new Blockly.FieldDropdown([["with remote controller","TRUE"], ["without remote controller","FALSE"]]), "HAS_CONTROLLER")
    this.appendValueInput("PORT_1")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 1 named")
        .appendField(new Blockly.FieldVariable("port 1"), "PORT_1_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_2")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 2 named")
        .appendField(new Blockly.FieldVariable("port 2"), "PORT_2_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_3")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 3 named")
        .appendField(new Blockly.FieldVariable("port 3"), "PORT_3_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_4")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 4 named")
        .appendField(new Blockly.FieldVariable("port 4"), "PORT_4_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_5")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 5 named")
        .appendField(new Blockly.FieldVariable("port 5"), "PORT_5_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_6")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 6 named")
        .appendField(new Blockly.FieldVariable("port 6"), "PORT_6_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_7")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 7 named")
        .appendField(new Blockly.FieldVariable("port 7"), "PORT_7_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_8")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 8 named")
        .appendField(new Blockly.FieldVariable("port 8"), "PORT_8_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_9")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 9 named")
        .appendField(new Blockly.FieldVariable("port 9"), "PORT_9_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_10")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 10 named")
        .appendField(new Blockly.FieldVariable("port 10"), "PORT_10_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_11")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 11 named")
        .appendField(new Blockly.FieldVariable("port 11"), "PORT_11_NAME")
        .appendField("has a");
    this.appendValueInput("PORT_12")
        .setCheck(["BumperDeclaration", "MotorDeclaration", "TouchLEDDeclaration", "ColorSensorDeclaration", "DistanceSensorDeclaration", "GyroDeclaration"])
        .setAlign(Blockly.ALIGN_RIGHT)
        .appendField("port 12 named")
        .appendField(new Blockly.FieldVariable("port 12"), "PORT_12_NAME")
        .appendField("has a");
    this.setInputsInline(false);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

// Blockly.Blocks['vex_iq_lcd_print'] = {
//   init: function() {
//     this.appendDummyInput("STRING")
//         .appendField("print")
//         .appendField(new Blockly.FieldDropdown([["on line 0","0"], ["on line 1","1"], ["on line 2","2"], ["on line 3","3"], ["on line 4","4"], ["on line 5","5"]]), "LINE")
//         .appendField(new Blockly.FieldTextInput("hello world"), "TEXT0");
//     this.setInputsInline(true);
//     this.setPreviousStatement(true, null);
//     this.setNextStatement(true, null);
//     this.setColour(65);
//  this.setTooltip("");
//  this.setHelpUrl("");
//   }
// };

Blockly.Blocks['vex_iq_lcd_print'] = {
  /**
   * Block for creating a list with any number of elements of any type.
   * @this {Blockly.Block}
   */
  init: function() {
    this.appendDummyInput("TEXTDUMMY0")
        .appendField("print")
        .appendField(new Blockly.FieldTextInput("hello world"), "TEXT0");
    this.appendDummyInput("LINEDUMMY")
        .appendField(new Blockly.FieldDropdown([["on line 0","0"], ["on line 1","1"], ["on line 2","2"], ["on line 3","3"], ["on line 4","4"], ["on line 5","5"]]), "LINE")
    this.setStyle('list_blocks');
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.varCount_ = 0;
    this.updateShape_();
    this.setMutator(new Blockly.Mutator(['vex_iq_lcd_print_item']));
    this.setTooltip("");
    this.setHelpUrl("");
    this.setColour(65);
  },
  /**
   * Create XML to represent string elements.
   * @return {!Element} XML storage element.
   * @this {Blockly.Block}
   */
  mutationToDom: function() {
    var container = Blockly.utils.xml.createElement('mutation');
    container.setAttribute('vars', this.varCount_);
    return container;
  },
  /**
   * Parse XML to restore the list inputs.
   * @param {!Element} xmlElement XML storage element.
   * @this {Blockly.Block}
   */
  domToMutation: function(xmlElement) {
    this.varCount_ = parseInt(xmlElement.getAttribute('vars'), 0);
    this.updateShape_();
  },
  /**
   * Populate the mutator's dialog with this block's components.
   * @param {!Blockly.Workspace} workspace Mutator's workspace.
   * @return {!Blockly.Block} Root block in mutator.
   * @this {Blockly.Block}
   */
  decompose: function(workspace) {
    var containerBlock = workspace.newBlock('vex_iq_lcd_print_container');
    containerBlock.initSvg();
    var connection = containerBlock.getInput('STACK').connection;
    for (var i = 0; i < this.varCount_; i++) {
      var itemBlock = workspace.newBlock('vex_iq_lcd_print_item');
      itemBlock.initSvg();
      connection.connect(itemBlock.previousConnection);
      connection = itemBlock.nextConnection;
    }
    return containerBlock;
  },
  /**
   * Reconfigure this block based on the mutator dialog's components.
   * @param {!Blockly.Block} containerBlock Root block in mutator.
   * @this {Blockly.Block}
   */
  compose: function(containerBlock) {
    var itemBlock = containerBlock.getInputTargetBlock('STACK');
    // Count number of vars.
    var connections = [];
    while (itemBlock) {
      connections.push(itemBlock.valueConnection_);
      itemBlock = itemBlock.nextConnection &&
          itemBlock.nextConnection.targetBlock();
    }
    // Disconnect any children that don't belong.
    for (var i = 0; i < this.varCount_; i++) {
      var connection = this.getInput('VAR' + i).connection.targetConnection;
      if (connection && connections.indexOf(connection) == -1) {
        connection.disconnect();
      }
    }
    this.varCount_ = connections.length;
    this.updateShape_();
    // Reconnect any child blocks.
    for (var i = 0; i < this.varCount_; i++) {
      Blockly.Mutator.reconnect(connections[i], this, 'VAR' + i);
    }
  },
  /**
   * Store pointers to any connected child blocks.
   * @param {!Blockly.Block} containerBlock Root block in mutator.
   * @this {Blockly.Block}
   */
  saveConnections: function(containerBlock) {
    var itemBlock = containerBlock.getInputTargetBlock('STACK');
    var i = 0;
    while (itemBlock) {
      var v = this.getInput('VAR' + i);
      itemBlock.valueConnection_ = v && v.connection.targetConnection;
      i++;
      itemBlock = itemBlock.nextConnection &&
          itemBlock.nextConnection.targetBlock();
    }
  },
  /**
   * Modify this block to have the correct number of inputs.
   * @private
   * @this {Blockly.Block}
   */
  updateShape_: function() {
    // Add new inputs.
    for (var i = 0; i < this.varCount_; i++) {
      if (!this.getInput('VAR' + i)) {
        this.appendValueInput('VAR' + i)
        this.appendDummyInput('TEXTDUMMY' + (i + 1))
            .appendField(new Blockly.FieldTextInput(""), "TEXT" + (i + 1));
        this.moveInputBefore('VAR' + i, 'LINEDUMMY');
        this.moveInputBefore('TEXTDUMMY' + (i + 1), 'LINEDUMMY');
      }
    }
    // Remove deleted inputs.
    while (this.getInput('VAR' + i)) {
      this.removeInput('VAR' + i);
      this.removeInput('TEXTDUMMY' + (i + 1));
      i++;
    }
  }
};

Blockly.Blocks['vex_iq_lcd_print_container'] = {
  /**
   * Mutator block for lcd print container.
   * @this {Blockly.Block}
   */
  init: function() {
    this.setStyle('list_blocks');
    this.appendDummyInput()
        .appendField('values');
    this.appendStatementInput('STACK');
    this.setTooltip("");
    this.contextMenu = false;
  }
};

Blockly.Blocks['vex_iq_lcd_print_item'] = {
  /**
   * Mutator block for adding items.
   * @this {Blockly.Block}
   */
  init: function() {
    this.setStyle('list_blocks');
    this.appendDummyInput()
        .appendField('value');
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setTooltip("");
    this.contextMenu = false;
  }
};

Blockly.Blocks['vex_iq_lcd_clear_screen'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("clear screen");
    this.setInputsInline(false);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_brain_check_button'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("brain")
        .appendField(new Blockly.FieldDropdown([["up button","UP"], ["down button","DOWN"], ["check button","CHECK"]]), "BUTTON")
        .appendField("is pressed?");
    this.setInputsInline(true);
    this.setOutput(true, "Button");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_brain_play_note'] = {
  init: function() {
    this.appendValueInput("DURATION")
        .setCheck("Number")
        .appendField("play note")
        .appendField(new Blockly.FieldDropdown([["A","A"], ["A#","A_SHARP"], ["B","B"], ["C","C"], ["C#","C_SHARP"], ["D","D"], ["D#","D_SHARP"], ["E","E"], ["F","F"], ["F#","F_SHARP"], ["G","G"], ["G#","G_SHARP"]]), "NOTE")
        .appendField("on octave")
        .appendField(new Blockly.FieldDropdown([["1","1"], ["2","2"], ["3","3"]]), "OCTAVE")
        .appendField("for");
    this.appendDummyInput()
        .appendField("ms");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_brain_play_sound'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("play")
        .appendField(new Blockly.FieldDropdown([["Siren 2","SIREN_2"], ["Wrong Way","WRONG_WAY"], ["Wrong Way Slow","WRONG_WAY_SLOW"], ["Gas Fillup","GAS_FILLUP"], ["Headlights On","HEADLIGHTS_ON"], ["Headlights Off","HEADLIGHTS_OFF"], ["Toll Booth","TOLL_BOOTH"], ["Car Alarm 2","CAR_ALARM_2"], ["Tada","TADA"], ["Garage Door Close","GARAGE_DOOR_CLOSE"], ["Ratchet","RATCHET"], ["Air Wrench","AIR_WRENCH"], ["Siren 4","SIREN_4"], ["Ratchet 4","RATCHET_4"], ["Car Alarm 4","CAR_ALARM_4"], ["Power Off 2","POWER_OFF_2"]]), "SOUND");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_spin_velocity'] = {
  init: function() {
    this.appendValueInput("VELOCITY")
        .setCheck("Number")
        .appendField("spin")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField(new Blockly.FieldDropdown([["forward","FORWARD"], ["backward","BACKWARD"]]), "DIRECTION")
        .appendField("at");
    this.appendDummyInput()
        .appendField("% velocity");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_spin_distance'] = {
  init: function() {
    this.appendValueInput("DISTANCE")
        .setCheck("Number")
        .appendField("spin")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField(new Blockly.FieldDropdown([["forward","FORWARD"], ["backward","BACKWARD"]]), "DIRECTION")
        .appendField("for");
    this.appendValueInput("VELOCITY")
        .setCheck("Number")
        .appendField("degrees at");
    this.appendDummyInput()
        .appendField("% velocity")
        .appendField(new Blockly.FieldDropdown([["and actively hold position","HOLD"], ["and apply brake","BRAKE"]]), "STOP_MODE");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_spin_to'] = {
  init: function() {
    this.appendValueInput("POSITION")
        .setCheck("Number")
        .appendField("spin")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("to absolute position of");
    this.appendValueInput("VELOCITY")
        .setCheck("Number")
        .appendField("degrees at");
    this.appendDummyInput()
        .appendField("% velocity")
        .appendField(new Blockly.FieldDropdown([["and actively hold position","HOLD"], ["and apply brake","BRAKE"]]), "STOP_MODE");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_wait'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("wait until")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("stops");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['events_trigger_event_on_motor_stop'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("trigger")
        .appendField(new Blockly.FieldVariable("event"), "EVENT")
        .appendField("on ")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("stop");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(20);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

/*Blockly.Blocks['vex_iq_motor_spin_duration'] = {
  init: function() {
    this.appendValueInput("DURATION")
        .setCheck("Number")
        .appendField("spin")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("for");
    this.appendValueInput("VELOCITY")
        .setCheck("Number")
        .appendField("ms at");
    this.appendDummyInput()
        .appendField("% velocity");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};*/

Blockly.Blocks['vex_iq_motor_stop'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("stop")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField(new Blockly.FieldDropdown([["and actively hold position","HOLD"], ["and apply brake","BRAKE"], ["allowing to coast","COAST"]]), "STOP_MODE");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_position'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("position in degrees")
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_velocity'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("velocity in %")
    this.setInputsInline(true);
    this.setOutput(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};


Blockly.Blocks['vex_iq_motor_current'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("current in mA")
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_bumper_is_pressed'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldVariable("bumper"), "BUMPER")
        .appendField("is pressed?");
    this.setInputsInline(true);
    this.setOutput(true, "Boolean");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_touch_led_on'] = {
  init: function() {
    this.appendValueInput("BRIGHTNESS")
        .setCheck("Number")
        .appendField("turn on")
        .appendField(new Blockly.FieldVariable("touch_led"), "TOUCH_LED")
        .appendField("with color")
        .appendField(new Blockly.FieldColour("#ff0000"), "COLOR")
        .appendField("and");
    this.appendDummyInput()
        .appendField("% brightness");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_touch_led_blink'] = {
  init: function() {
    this.appendValueInput("BRIGHTNESS")
        .setCheck("Number")
        .appendField("blink")
        .appendField(new Blockly.FieldVariable("touch_led"), "TOUCH_LED")
        .appendField("with color")
        .appendField(new Blockly.FieldColour("#ff0000"), "COLOR")
        .appendField("and");
    this.appendValueInput("ON_DURATION")
        .setCheck("Number")
        .appendField("% brightness, on");
    this.appendValueInput("OFF_DURATION")
        .setCheck("Number")
        .appendField("ms, off");
    this.appendDummyInput()
        .appendField("ms");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_touch_led_off'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("turn off")
        .appendField(new Blockly.FieldVariable("touch_led"), "TOUCH_LED");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_distance_bound'] = {
  init: function() {
    this.appendValueInput("DISTANCE")
        .setCheck("Number")
        .appendField("set")
        .appendField(new Blockly.FieldVariable("distance_sensor"), "DISTANCE_SENSOR")
        .appendField(new Blockly.FieldDropdown([["maximum","MAXIMUM"], ["minimum","MINIMUM"]]), "BOUND")
        .appendField("to");
    this.appendDummyInput()
        .appendField("mm");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

// Deprecated
Blockly.Blocks['vex_iq_distance_max'] = {
  init: function() {
    this.appendValueInput("DISTANCE")
        .setCheck("Number")
        .appendField("set")
        .appendField(new Blockly.FieldVariable("distance_sensor"), "DISTANCE_SENSOR")
        .appendField("maximum to");
    this.appendDummyInput()
        .appendField("mm");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

// Deprecated
Blockly.Blocks['vex_iq_distance_min'] = {
  init: function() {
    this.appendValueInput("DISTANCE")
        .setCheck("Number")
        .appendField("set")
        .appendField(new Blockly.FieldVariable("distance_sensor"), "DISTANCE_SENSOR")
        .appendField("minimum to");
    this.appendDummyInput()
        .appendField("mm");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_distance'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("distance in mm from")
        .appendField(new Blockly.FieldVariable("distance_sensor"), "DISTANCE_SENSOR")
        .appendField("to")
        .appendField(new Blockly.FieldDropdown([["closest object","STRONGEST"], ["2nd closest object","SECOND_STRONGEST"], ["biggest object","MOST_REFLECTIVE"]]), "MODE");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_distance_sampler'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldDropdown([["brightest","BRIGHTEST"], ["best signal:noise","HIGHEST_SNR"], ["average","AVERAGE"]]), "AGGREGATOR")
        .appendField("of")
        .appendField(new Blockly.FieldDropdown([["3","3"], ["5","5"], ["10","10"], ["25","25"], ["50","50"], ["100","100"]]), "SAMPLES")
        .appendField("samples every")
        .appendField(new Blockly.FieldDropdown([["0","0"], ["1","1"], ["3","3"], ["5","5"], ["10","10"], ["30","30"]]), "PERIOD")
        .appendField("ms from")
        .appendField(new Blockly.FieldVariable("distance_sensor"), "DISTANCE_SENSOR")
        .appendField("to")
        .appendField(new Blockly.FieldDropdown([["closest object","STRONGEST"], ["2nd closest object","SECOND_STRONGEST"], ["biggest object","MOST_REFLECTIVE"]]), "MODE");
    this.setOutput(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_motor_reset_absolute_position'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("reset")
        .appendField(new Blockly.FieldVariable("motor"), "MOTOR")
        .appendField("absolute position to 0 degrees");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_gyro_heading'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldVariable("gyro"), "NAME")
        .appendField("heading in degrees");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_gyro_reset_heading'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("reset")
        .appendField(new Blockly.FieldVariable("gyro"), "NAME")
        .appendField("heading to 0 degrees");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_gyro_rate'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldVariable("gyro"), "NAME")
        .appendField("rate in degrees per ms")
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_gyro_sensitivity'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("set")
        .appendField(new Blockly.FieldVariable("gyro"), "NAME")
        .appendField("sensitivity to")
        .appendField(new Blockly.FieldDropdown([["high","HIGH"], ["normal","NORMAL"], ["low","LOW"]]), "SENSITIVITY");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_controller_button_pressed'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("button")
        .appendField(new Blockly.FieldDropdown([["E up","E_UP"], ["E down","E_DOWN"], ["F up","F_UP"], ["F down","F_DOWN"], ["L up","L_UP"], ["L down","L_DOWN"], ["R up","R_UP"], ["R down","R_DOWN"]]), "BUTTON")
        .appendField("is pressed?");
    this.setInputsInline(true);
    this.setOutput(true, "Boolean");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_controller_button'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("button")
        .appendField(new Blockly.FieldDropdown([["E up","E_UP"], ["E down","E_DOWN"], ["F up","F_UP"], ["F down","F_DOWN"], ["L up","L_UP"], ["L down","L_DOWN"], ["R up","R_UP"], ["R down","R_DOWN"]]), "BUTTON");
    this.setInputsInline(true);
    this.setOutput(true, "ControllerButton");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_controller_joystick_position'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldDropdown([["left","LEFT"], ["right","RIGHT"]]), "JOYSTICK")
        .appendField("joystick")
        .appendField(new Blockly.FieldDropdown([["horizontal axis","HORIZONTAL"], ["vertical axis","VERTICAL"]]), "AXIS")
        .appendField("position");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_controller_joystick'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldDropdown([["left","LEFT"], ["right","RIGHT"]]), "JOYSTICK")
        .appendField("joystick");
    this.setInputsInline(true);
    this.setOutput(true, "ControllerJoystick");
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_controller_joystick_point_position'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("set")
        .appendField(new Blockly.FieldVariable("point"), "NAME")
        .appendField("to")
        .appendField(new Blockly.FieldDropdown([["left","LEFT"], ["right","RIGHT"]]), "JOYSTICK")
        .appendField("joystick position");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(65);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};


Blockly.Blocks['math_points_value'] = {
  init: function() {
    this.appendDummyInput()
        .appendField(new Blockly.FieldDropdown([["x","X"], ["y","Y"]]), "VALUE")
        .appendField("position of")
        .appendField(new Blockly.FieldVariable("point"), "NAME");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['math_points_x'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("x position of")
        .appendField(new Blockly.FieldVariable("point"), "NAME");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['math_points_y'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("y position of")
        .appendField(new Blockly.FieldVariable("point"), "NAME");
    this.setInputsInline(true);
    this.setOutput(true, "Number");
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['math_points_constructor'] = {
  init: function() {
    this.appendValueInput("X")
        .setCheck("Number")
        .appendField("set")
        .appendField(new Blockly.FieldVariable("point"), "NAME")
        .appendField("to point with x =");
    this.appendValueInput("Y")
        .setCheck("Number")
        .appendField(", y =");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['math_points_rotation'] = {
  init: function() {
    this.appendValueInput("THETA")
        .setCheck("Number")
        .appendField("rotate point")
        .appendField(new Blockly.FieldVariable("point"), "NAME")
        .appendField("by");
    this.appendDummyInput()
        .appendField("degrees");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['vex_iq_sleep'] = {
  init: function() {
    this.appendValueInput("DURATION")
        .setCheck("Number")
        .appendField("wait");
    this.appendDummyInput()
        .appendField("ms");
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(160);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['procedures_deftask'] = {
  /**
   * Block for defining an asynchronous task.
   * @this {Blockly.Block}
   */
  init: function() {
    var nameField = new Blockly.FieldTextInput('',
        Blockly.Procedures.rename);
    nameField.setSpellcheck(false);
    this.appendDummyInput()
        .appendField(Blockly.Msg['PROCEDURES_DEFRETURN_TITLE'])
        .appendField(nameField, 'NAME')
        .appendField(new Blockly.FieldLabelSerializable('asynchronously'), "IS_TASK")
        .appendField('', 'PARAMS');
    if ((this.workspace.options.comments ||
         (this.workspace.options.parentWorkspace &&
          this.workspace.options.parentWorkspace.options.comments)) &&
        Blockly.Msg['PROCEDURES_DEFRETURN_COMMENT']) {
      this.setCommentText(Blockly.Msg['PROCEDURES_DEFRETURN_COMMENT']);
    }
    this.setStyle('procedure_blocks');
    this.setTooltip('Creates an asynchronous task');
    this.setHelpUrl('http://www.robotc.net/wikiarchive/Multitasking_tips');
    this.arguments_ = [];
    this.argumentVarModels_ = [];
    this.setStatements_(true);
    this.statementConnection_ = null;
  },
  setStatements_: Blockly.Blocks['procedures_defnoreturn'].setStatements_,
  updateParams_: Blockly.Blocks['procedures_defnoreturn'].updateParams_,
  mutationToDom: Blockly.Blocks['procedures_defnoreturn'].mutationToDom,
  domToMutation: Blockly.Blocks['procedures_defnoreturn'].domToMutation,
  decompose: Blockly.Blocks['procedures_defnoreturn'].decompose,
  compose: Blockly.Blocks['procedures_defnoreturn'].compose,
  /**
   * Return the signature of this procedure definition.
   * @return {!Array} Tuple containing three elements:
   *     - the name of the defined procedure,
   *     - a list of all its arguments,
   *     - that it DOES have a return value.
   * @this {Blockly.Block}
   */
  getProcedureDef: function() {
    return [this.getFieldValue('NAME'), this.arguments_, true];
  },
  getVars: Blockly.Blocks['procedures_defnoreturn'].getVars,
  getVarModels: Blockly.Blocks['procedures_defnoreturn'].getVarModels,
  renameVarById: Blockly.Blocks['procedures_defnoreturn'].renameVarById,
  updateVarName: Blockly.Blocks['procedures_defnoreturn'].updateVarName,
  displayRenamedVar_: Blockly.Blocks['procedures_defnoreturn'].displayRenamedVar_,
  customContextMenu: Blockly.Blocks['procedures_defnoreturn'].customContextMenu,
  callType_: 'procedures_startstoptask'
};



Blockly.Blocks['procedures_startstoptask'] = {
  /**
   * Block for calling an asynchronous task.
   * @this {Blockly.Block}
   */
  init: function() {
    this.appendDummyInput('TOPROW')
        .appendField(new Blockly.FieldDropdown([["start","START"], ["stop","STOP"]]), "ACTION")
        .appendField('', 'NAME');
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setStyle('procedure_blocks');
    // Tooltip is set in domToMutation.
    this.setHelpUrl(Blockly.Msg['PROCEDURES_CALLNORETURN_HELPURL']);
    this.arguments_ = [];
    this.quarkConnections_ = {};
    this.quarkIds_ = null;
    this.previousEnabledState_ = true;
  },

  getProcedureCall: Blockly.Blocks['procedures_callnoreturn'].getProcedureCall,
  renameProcedure: Blockly.Blocks['procedures_callnoreturn'].renameProcedure,
  setProcedureParameters_:
      Blockly.Blocks['procedures_callnoreturn'].setProcedureParameters_,
  updateShape_: Blockly.Blocks['procedures_callnoreturn'].updateShape_,
  mutationToDom: Blockly.Blocks['procedures_callnoreturn'].mutationToDom,
  domToMutation: Blockly.Blocks['procedures_callnoreturn'].domToMutation,
  getVars: Blockly.Blocks['procedures_callnoreturn'].getVars,
  getVarModels: Blockly.Blocks['procedures_callnoreturn'].getVarModels,
  onchange: Blockly.Blocks['procedures_callnoreturn'].onchange,
  customContextMenu:
      Blockly.Blocks['procedures_callnoreturn'].customContextMenu,
  defType_: 'procedures_deftask'
};

/**
 * Construct the blocks required by the flyout for the procedure category.
 * @param {!Blockly.Workspace} workspace The workspace containing procedures.
 * @return {!Array.<!Element>} Array of XML block elements.
 */
var defaultFlyoutCategory = Blockly.Procedures.flyoutCategory;
Blockly.Procedures.flyoutCategory = function(workspace) {
  var xmlList = defaultFlyoutCategory(workspace);
  if (Blockly.Blocks['procedures_deftask']) {
    // <block type="procedures_deftask" gap="16">
    //     <field name="NAME">do something</field>
    // </block>
    var block = Blockly.utils.xml.createElement('block');
    block.setAttribute('type', 'procedures_deftask');
    block.setAttribute('gap', 16);
    var nameField = Blockly.utils.xml.createElement('field');
    nameField.setAttribute('name', 'NAME');
    nameField.appendChild(Blockly.utils.xml.createTextNode("do something"));
    block.appendChild(nameField);
    xmlList.splice(2, 0, block);
  }

  function populateProcedures(procedureList, templateName) {
    for (var i = 0; i < procedureList.length; i++) {
      var name = procedureList[i][0];
      // <block type="procedures_callnoreturn" gap="16">
      //   <mutation name="do something">
      //     <arg name="x"></arg>
      //   </mutation>
      // </block>
      var block = Blockly.utils.xml.createElement('block');
      block.setAttribute('type', templateName);
      block.setAttribute('gap', 16);
      var mutation = Blockly.utils.xml.createElement('mutation');
      mutation.setAttribute('name', name);
      block.appendChild(mutation);
      xmlList.push(block);
    }
  }

  function allTasks(root) {
    var tasks = root.getBlocksByType('procedures_deftask', false)
        .map(function(block) {
          return /** @type {!Blockly.Procedures.ProcedureBlock} */ (block).getProcedureDef();
        });
    tasks.sort(Blockly.Procedures.procTupleComparator_);
    return tasks;
  };

  var tasks = allTasks(workspace);
  populateProcedures(tasks, 'procedures_startstoptask');
  return xmlList;
};

Blockly.Blocks['comment_block'] = {
  init: function() {
    this.appendDummyInput()
        .appendField("//")
        .appendField(new Blockly.FieldTextInput("comment"), "NAME");
    this.setPreviousStatement(true, null);
    this.setNextStatement(true, null);
    this.setColour(260);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['logic_between'] = {
  init: function() {
    this.appendValueInput("VALUE")
        .setCheck("Number");
    this.appendValueInput("BOUND1")
        .setCheck("Number")
        .appendField(new Blockly.FieldDropdown([["is between","BETWEEN"], ["is not between","NOT_BETWEEN"]]), "OPERATOR");
    this.appendValueInput("BOUND2")
        .setCheck("Number")
        .appendField("and");
    this.setInputsInline(true);
    this.setOutput(true, null);
    this.setColour(210);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};

Blockly.Blocks['math_angle_distance'] = {
  init: function() {
    this.appendValueInput("FROM")
        .setCheck("Number")
        .appendField("distance from");
    this.appendValueInput("TO")
        .setCheck("Number")
        .appendField("degrees to");
    this.appendDummyInput()
        .appendField("degrees");
    this.setInputsInline(true);
    this.setOutput(true, null);
    this.setColour(230);
 this.setTooltip("");
 this.setHelpUrl("");
  }
};