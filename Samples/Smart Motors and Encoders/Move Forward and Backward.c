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
    waitUntilMotorStop(left_motor);
    waitUntilMotorStop(right_motor);
    resetMotorEncoder(left_motor);
    resetMotorEncoder(right_motor);
    setMotorTarget(left_motor, (-5000), abs(75));
    setMotorTarget(right_motor, (-5000), abs(75));
    waitUntilMotorStop(left_motor);
    waitUntilMotorStop(right_motor);

  }
}



task main() {
  activate_event(start);
  while(true) {
    on_start2();
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
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="163">
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
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="538">
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
                    <next>
                      <block type="vex_iq_motor_wait" id="!0|2~UF_}=u6Csoc8-y,">
                        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                        <next>
                          <block type="vex_iq_motor_wait" id="ZxMC{M(5CJmP=CgB1p8v">
                            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                            <next>
                              <block type="vex_iq_motor_reset_absolute_position" id="]F7|{%XWY3ODWZG,;=,c">
                                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                <next>
                                  <block type="vex_iq_motor_reset_absolute_position" id="4qz$80rc*^U?qrd5suI7">
                                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                    <next>
                                      <block type="vex_iq_motor_spin_to" id="$}M~9]jhHvR.iFvsn}(V">
                                        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                        <field name="STOP_MODE">BRAKE</field>
                                        <value name="POSITION">
                                          <shadow type="math_number" id="9YaJsmW]1kRn0iQsCg?7">
                                            <field name="NUM">-5000</field>
                                          </shadow>
                                        </value>
                                        <value name="VELOCITY">
                                          <shadow type="math_number" id="8Cjp[r9VIK{$Q2Z2gRs1">
                                            <field name="NUM">75</field>
                                          </shadow>
                                        </value>
                                        <next>
                                          <block type="vex_iq_motor_spin_to" id="gh,As;m7THW9Fo9s5=.l">
                                            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                            <field name="STOP_MODE">BRAKE</field>
                                            <value name="POSITION">
                                              <shadow type="math_number" id="[=wka06%TGcwnQM|mz]c">
                                                <field name="NUM">-5000</field>
                                              </shadow>
                                            </value>
                                            <value name="VELOCITY">
                                              <shadow type="math_number" id="49u9Dtc`|Kg@^#)j1Y9L">
                                                <field name="NUM">75</field>
                                              </shadow>
                                            </value>
                                            <next>
                                              <block type="vex_iq_motor_wait" id="^z0X7}9I?ofx-r:qj*3W">
                                                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                                <next>
                                                  <block type="vex_iq_motor_wait" id="oB!Iqz(YuRE~!|B~IErL">
                                                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                                  </block>
                                                </next>
                                              </block>
                                            </next>
                                          </block>
                                        </next>
                                      </block>
                                    </next>
                                  </block>
                                </next>
                              </block>
                            </next>
                          </block>
                        </next>
                      </block>
                    </next>
                  </block>
                </next>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
