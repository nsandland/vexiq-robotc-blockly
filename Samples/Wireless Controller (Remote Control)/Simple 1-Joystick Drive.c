#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

Event start;



Event EVENT_ACTIVE = 0x01;
Event EVENT_QUEUED = 0x02;

void queue_event(Event &event) {
  event |= EVENT_QUEUED;
}

void dequeue_event(Event &event) {
  event &= ~EVENT_QUEUED;
}

void activate_event(Event &event) {
  event |= EVENT_ACTIVE;
}

void deactivate_event(Event &event) {
  event &= ~EVENT_ACTIVE;
}

bool event_is_queued(Event event) {
  return (bool)(event & EVENT_QUEUED);
}

bool event_is_active(Event event) {
  return (bool)(event & EVENT_ACTIVE);
}

void advance_event(Event &event) {
  if (event_is_queued(event)) {
    dequeue_event(event);
    activate_event(event);
  } else {
    deactivate_event(event);
  }
}


void rotate(Point &p, float theta) {
  float newX = p.x * cosDegrees(theta) - p.y * sinDegrees(theta);
  float newY = p.x * sinDegrees(theta) + p.y * cosDegrees(theta);
  p.x = newX;
  p.y = newY;
}

void always2() {
  setMotorSpeed(left_motor, (getJoystickValue(ChA) + getJoystickValue(ChB) / 2));
  setMotorSpeed(right_motor, (getJoystickValue(ChA) - getJoystickValue(ChB) / 2));

}



task main() {
  activate_event(start);
  while(true) {
    always2();
    advance_event(start);
  }
}

/* XML
<xml xmlns="https://developers.google.com/blockly/xml">
  <variables>
    <variable id="2C_w(9X|eyDoXJZtSlGb">left motor</variable>
    <variable id="%U9G3C1f~]_Kp7^^-7Ir">port_2</variable>
    <variable id="W]!UnnR..||G/=zrEIJt">port_3</variable>
    <variable id="s4u0G;(du~#s/n8=ibn}">port_4</variable>
    <variable id="haGj?M05(YHo?$VWjx1^">port_5</variable>
    <variable id="|}5]3]?#UB6;p-p@$?Zo">right motor</variable>
    <variable id="^+4/-T,O-t[iqqC$$[Up">port_7</variable>
    <variable id="z6z0}I;#nZ0)+.go64uO">port_8</variable>
    <variable id="S?1OP,zVs50qC@pokl3E">port 9</variable>
    <variable id="UCC-Z#0}d85!qaB^`*EY">port_10</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">port_11</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
  </variables>
  <block type="vex_iq_brain" id="%y[i=TI^e=S5W5q!.w0+" x="13" y="113">
    <field name="HAS_CONTROLLER">TRUE</field>
    <field name="PORT_1_NAME" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
    <field name="PORT_2_NAME" id="%U9G3C1f~]_Kp7^^-7Ir">port_2</field>
    <field name="PORT_3_NAME" id="W]!UnnR..||G/=zrEIJt">port_3</field>
    <field name="PORT_4_NAME" id="s4u0G;(du~#s/n8=ibn}">port_4</field>
    <field name="PORT_5_NAME" id="haGj?M05(YHo?$VWjx1^">port_5</field>
    <field name="PORT_6_NAME" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
    <field name="PORT_7_NAME" id="^+4/-T,O-t[iqqC$$[Up">port_7</field>
    <field name="PORT_8_NAME" id="z6z0}I;#nZ0)+.go64uO">port_8</field>
    <field name="PORT_9_NAME" id="S?1OP,zVs50qC@pokl3E">port 9</field>
    <field name="PORT_10_NAME" id="UCC-Z#0}d85!qaB^`*EY">port_10</field>
    <field name="PORT_11_NAME" id="Sq;4ZphrM!WA8xQBm)1F">port_11</field>
    <field name="PORT_12_NAME" id="f+3LAb5_1]ObyC0i9eX^">port_12</field>
    <value name="PORT_1">
      <block type="vex_iq_motor" id="n@7f(@%z`QZIt1.aI6f?">
        <field name="DIRECTION">FORWARD</field>
      </block>
    </value>
    <value name="PORT_6">
      <block type="vex_iq_motor" id="{PF=KUcv-4IZ6m#NvjFx">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
  </block>
  <block type="events_always" id="}@B~$VOG`.Vx%#fCUCgg" x="13" y="488">
    <statement name="DO">
      <block type="vex_iq_motor_spin_velocity" id="i!jY/=bu[dhk+]v8q)V[">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="DIRECTION">FORWARD</field>
        <value name="VELOCITY">
          <shadow type="math_number" id="IH-F].Zg~r.L3ZNA{=pf">
            <field name="NUM">100</field>
          </shadow>
          <block type="math_arithmetic" id="bT$2$.,(:R%0jzsvJ$W~">
            <field name="OP">ADD</field>
            <value name="A">
              <shadow type="math_number" id="sFc*CE1.u,TV^Bql,eJO">
                <field name="NUM">1</field>
              </shadow>
              <block type="vex_iq_controller_joystick_position" id="UBMUIv:T$C[.d.nHRh%?">
                <field name="JOYSTICK">LEFT</field>
                <field name="AXIS">VERTICAL</field>
              </block>
            </value>
            <value name="B">
              <shadow type="math_number" id="@S)h:ERV}s6riXV`*pQ@">
                <field name="NUM">1</field>
              </shadow>
              <block type="math_arithmetic" id="B(REi_bUwE=u=_:;V;Oo">
                <field name="OP">DIVIDE</field>
                <value name="A">
                  <shadow type="math_number" id=")Vz|UHv]~aYe[xtaz^!$">
                    <field name="NUM">1</field>
                  </shadow>
                  <block type="vex_iq_controller_joystick_position" id="}[lTE7:U?GW5Q#t:zJpy">
                    <field name="JOYSTICK">LEFT</field>
                    <field name="AXIS">HORIZONTAL</field>
                  </block>
                </value>
                <value name="B">
                  <shadow type="math_number" id="=ume9svq?T)d/P/QtVW%">
                    <field name="NUM">2</field>
                  </shadow>
                </value>
              </block>
            </value>
          </block>
        </value>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="]BKMA%gJ._m[#mabts7]">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number">
                <field name="NUM">100</field>
              </shadow>
              <block type="math_arithmetic" id="(+4n|Yl82Kb0p8p9iP)F">
                <field name="OP">MINUS</field>
                <value name="A">
                  <shadow type="math_number">
                    <field name="NUM">1</field>
                  </shadow>
                  <block type="vex_iq_controller_joystick_position" id="D=5WtE`~d+MKL?]5EcA3">
                    <field name="JOYSTICK">LEFT</field>
                    <field name="AXIS">VERTICAL</field>
                  </block>
                </value>
                <value name="B">
                  <shadow type="math_number">
                    <field name="NUM">1</field>
                  </shadow>
                  <block type="math_arithmetic" id="IZANoXv9|noxpLSY/n2_">
                    <field name="OP">DIVIDE</field>
                    <value name="A">
                      <shadow type="math_number">
                        <field name="NUM">1</field>
                      </shadow>
                      <block type="vex_iq_controller_joystick_position" id="q52)Bt$kdh.O%_7K,gM=">
                        <field name="JOYSTICK">LEFT</field>
                        <field name="AXIS">HORIZONTAL</field>
                      </block>
                    </value>
                    <value name="B">
                      <shadow type="math_number" id="^]h~NhggZ5pE00`U-nCQ">
                        <field name="NUM">2</field>
                      </shadow>
                    </value>
                  </block>
                </value>
              </block>
            </value>
          </block>
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
