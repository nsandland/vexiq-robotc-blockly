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

void on_start2() {
  if (event_is_active(start)) {
    resetMotorEncoder(left_motor);
    resetMotorEncoder(right_motor);
    setMotorTarget(left_motor, 5000, abs(75));
    setMotorTarget(right_motor, 5000, abs(75));

  }
}

bool when_false_old_state = false;
void when_false2() {
  bool new_state = (getMotorSpeed(left_motor) > 0 || getMotorSpeed(right_motor) > 0 == 0);
  if (!new_state && new_state != when_false_old_state) {
    displayTextLine(1, "Left Motor: %1.2f", getMotorEncoder(left_motor));
    displayTextLine(3, "Right Motor: %1.2f", getMotorEncoder(right_motor));

  }
  when_false_old_state = new_state;
}



task main() {
  activate_event(start);
  while(true) {
    on_start2();
    when_false2();
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
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="188">
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
      <block type="vex_iq_motor" id="}[[kQ*i`PIO+m@shA1mE">
        <field name="DIRECTION">FORWARD</field>
      </block>
    </value>
    <value name="PORT_6">
      <block type="vex_iq_motor" id="oLsxr9=dh1okfPB:JTz9">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
  </block>
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="563">
    <statement name="DO">
      <block type="vex_iq_motor_reset_absolute_position" id="0K7zc-`|+H:8G%VcS#(%">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <next>
          <block type="vex_iq_motor_reset_absolute_position" id="F~571#7F~W@@vD4Uz6j9">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <next>
              <block type="vex_iq_motor_spin_to" id="O5Eb?f%_CW|[yG)(]Tsf">
                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                <field name="STOP_MODE">BRAKE</field>
                <value name="POSITION">
                  <shadow type="math_number" id="Yyh-0gW[[$1]2}.[txtl">
                    <field name="NUM">5000</field>
                  </shadow>
                </value>
                <value name="VELOCITY">
                  <shadow type="math_number" id="C%XUY-|y,reZDGK-q+qE">
                    <field name="NUM">75</field>
                  </shadow>
                </value>
                <next>
                  <block type="vex_iq_motor_spin_to" id="A.(mm6|9u%qQ?.N.8,9F">
                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                    <field name="STOP_MODE">BRAKE</field>
                    <value name="POSITION">
                      <shadow type="math_number" id="c7NE@9(h.+S[0qZS?.Hd">
                        <field name="NUM">5000</field>
                      </shadow>
                    </value>
                    <value name="VELOCITY">
                      <shadow type="math_number" id="@]kS=0Px!|_pCgWl1NN9">
                        <field name="NUM">75</field>
                      </shadow>
                    </value>
                  </block>
                </next>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="events_after" id=".3m(GD~S~/ieS#^PHEBY" x="13" y="763">
    <value name="AFTER">
      <block type="logic_operation" id="XkLR!rMuT/UGf*B:3O^n">
        <field name="OP">OR</field>
        <value name="A">
          <block type="logic_compare" id="JaP0=IIoc8u(((+gVYFL">
            <field name="OP">GT</field>
            <value name="A">
              <block type="vex_iq_motor_velocity" id="~ajxf`#dYIo0aOZ`q=Ms">
                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
              </block>
            </value>
            <value name="B">
              <block type="math_number" id="B,-bVidKZTy3`#pUvZHq">
                <field name="NUM">0</field>
              </block>
            </value>
          </block>
        </value>
        <value name="B">
          <block type="logic_compare" id="KJNx:r+y|q`h1:|/!nS~">
            <field name="OP">EQ</field>
            <value name="A">
              <block type="logic_compare" id="S_d[Ufo/z{!EpOC$-2%K">
                <field name="OP">GT</field>
                <value name="A">
                  <block type="vex_iq_motor_velocity" id="^9W3wW9z{X4]VRoR@P#0">
                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                  </block>
                </value>
                <value name="B">
                  <block type="math_number" id="hZB)a2oUfW;YlyNXf,[%">
                    <field name="NUM">0</field>
                  </block>
                </value>
              </block>
            </value>
          </block>
        </value>
      </block>
    </value>
    <statement name="DO">
      <block type="vex_iq_lcd_print" id="G/oRaT1e{3emga|KR4B2">
        <mutation vars="1"></mutation>
        <field name="TEXT0">Left Motor: </field>
        <field name="TEXT1"></field>
        <field name="LINE">1</field>
        <value name="VAR0">
          <block type="vex_iq_motor_position" id="RocL:r8s.8=z=kSR_c4]">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
          </block>
        </value>
        <next>
          <block type="vex_iq_lcd_print" id="Rr,7Na|X0xcRO?NhQ`2C">
            <mutation vars="1"></mutation>
            <field name="TEXT0">Right Motor: </field>
            <field name="TEXT1"></field>
            <field name="LINE">3</field>
            <value name="VAR0">
              <block type="vex_iq_motor_position" id="!:hR;0WyT`5fPSx+FXDr">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
              </block>
            </value>
          </block>
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
