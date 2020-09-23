#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float forward_time, backward_time, right_turn_time, left_turn_time;
Event start;

void move_forward(float forward_time);
void move_backward(float backward_time);
void right_turn(float right_turn_time);
void left_turn(float left_turn_time);

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

// Describe this function...
void move_forward(float forward_time) {
  setMotorSpeed(left_motor, 75);
  setMotorSpeed(right_motor, 75);
  sleep(forward_time);
  setMotorBrakeMode(left_motor, motorBrake);
  setMotorSpeed(left_motor, 0);
  setMotorBrakeMode(right_motor, motorBrake);
  setMotorSpeed(right_motor, 0);
  sleep(1000);
}

// Describe this function...
void move_backward(float backward_time) {
  setMotorSpeed(left_motor, -75);
  setMotorSpeed(right_motor, -75);
  sleep(backward_time);
  setMotorBrakeMode(left_motor, motorBrake);
  setMotorSpeed(left_motor, 0);
  setMotorBrakeMode(right_motor, motorBrake);
  setMotorSpeed(right_motor, 0);
  sleep(1000);
}

// Describe this function...
void right_turn(float right_turn_time) {
  setMotorSpeed(left_motor, -75);
  setMotorSpeed(right_motor, 75);
  sleep(right_turn_time);
  setMotorBrakeMode(left_motor, motorBrake);
  setMotorSpeed(left_motor, 0);
  setMotorBrakeMode(right_motor, motorBrake);
  setMotorSpeed(right_motor, 0);
  sleep(1000);
}

// Describe this function...
void left_turn(float left_turn_time) {
  setMotorSpeed(left_motor, 75);
  setMotorSpeed(right_motor, -75);
  sleep(left_turn_time);
  setMotorBrakeMode(left_motor, motorBrake);
  setMotorSpeed(left_motor, 0);
  setMotorBrakeMode(right_motor, motorBrake);
  setMotorSpeed(right_motor, 0);
  sleep(1000);
}

void on_start2() {
  if (event_is_active(start)) {
    move_forward(2500);
    move_backward(3000);
    right_turn(800);
    left_turn(1200);

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
    <variable id="}0[^|jC7HI:|N9=OC-|{">forward time</variable>
    <variable id="8;8FLTBhige|goe8M^A~">backward time</variable>
    <variable id="*5rZkI.0aRs1@hTKoIS~">right turn time</variable>
    <variable id="X/syq:bhXZAx21E+`jOc">left turn time</variable>
  </variables>
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="88">
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
      <block type="vex_iq_motor" id="ag@b,lw@^S*Z!LZA*9u)">
        <field name="DIRECTION">FORWARD</field>
      </block>
    </value>
    <value name="PORT_6">
      <block type="vex_iq_motor" id="oLsxr9=dh1okfPB:JTz9">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
  </block>
  <block type="procedures_defnoreturn" id="tT^]eD51`[jGlYn/aa?:" x="13" y="463">
    <mutation>
      <arg name="forward time" varid="}0[^|jC7HI:|N9=OC-|{"></arg>
    </mutation>
    <field name="NAME">move forward</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_velocity" id="yMJ?`9sn:qqXZO:c{s?C">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="DIRECTION">FORWARD</field>
        <value name="VELOCITY">
          <shadow type="math_number" id=")/)ZF,8K]N6V$Ndv,xDo">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_velocity" id=".TWndccvgVCEgxv/kgNe">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="=qR2X5.X.~w=J$SvZ}~,">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_sleep" id="JU9W5j6LX?w^d:yYC]m_">
                <value name="DURATION">
                  <shadow type="math_number" id="%Gw$k6:bRP(mCzj^W?Zv">
                    <field name="NUM">0</field>
                  </shadow>
                  <block type="variables_get" id="J7tcRm5qx`kCpo9/ViGw">
                    <field name="VAR" id="}0[^|jC7HI:|N9=OC-|{">forward time</field>
                  </block>
                </value>
                <next>
                  <block type="vex_iq_motor_stop" id="RKo!E(u8]Pg|^0N7f@ko">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                    <field name="STOP_MODE">BRAKE</field>
                    <next>
                      <block type="vex_iq_motor_stop" id="lvba*Aj-?GX^Z6MC:}.H">
                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                        <field name="STOP_MODE">BRAKE</field>
                        <next>
                          <block type="vex_iq_sleep" id="F4^ca}K;l_{R4AO{7xK}">
                            <value name="DURATION">
                              <shadow type="math_number" id="%z.RQq30K@IMKYO8!93X">
                                <field name="NUM">1000</field>
                              </shadow>
                            </value>
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
  <block type="procedures_defnoreturn" id="Zg6Pv~Gmfp`9utf#qz=`" x="13" y="738">
    <mutation>
      <arg name="backward time" varid="8;8FLTBhige|goe8M^A~"></arg>
    </mutation>
    <field name="NAME">move backward</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_velocity" id="$=-wr:j0oO1p$zC7:57-">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="DIRECTION">BACKWARD</field>
        <value name="VELOCITY">
          <shadow type="math_number" id="n.%OfLqX;YYC(w@]*Lig">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="O`0V^MS[op}hP=hhJ;C]">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">BACKWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="cXmrsoT7uTV,KtN`|!*k">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_sleep" id="jM~g@t[SODpi10u|]]44">
                <value name="DURATION">
                  <shadow type="math_number">
                    <field name="NUM">0</field>
                  </shadow>
                  <block type="variables_get" id="w3HrzA^jB2)(~N#G#AKE">
                    <field name="VAR" id="8;8FLTBhige|goe8M^A~">backward time</field>
                  </block>
                </value>
                <next>
                  <block type="vex_iq_motor_stop" id="xVh4p$}*P,,WLm?[TclM">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                    <field name="STOP_MODE">BRAKE</field>
                    <next>
                      <block type="vex_iq_motor_stop" id="PWf@XPM*(2}R*4y6R*ZC">
                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                        <field name="STOP_MODE">BRAKE</field>
                        <next>
                          <block type="vex_iq_sleep" id="/p3*Mm|07g23re-#KhH:">
                            <value name="DURATION">
                              <shadow type="math_number" id="l%?ekoztp+^0iUk7{r;N">
                                <field name="NUM">1000</field>
                              </shadow>
                            </value>
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
  <block type="procedures_defnoreturn" id="H#M=qLM(eqVvE:e[K/1Q" x="13" y="1013">
    <mutation>
      <arg name="right turn time" varid="*5rZkI.0aRs1@hTKoIS~"></arg>
    </mutation>
    <field name="NAME">right turn</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_velocity" id="_=.@a+u3D9DWc#M1zv}P">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="DIRECTION">BACKWARD</field>
        <value name="VELOCITY">
          <shadow type="math_number" id="R^/@!0Hlo?k#B[E!zS39">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="OgHv`PLyR/nLzW1~U0=?">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="_}6n)_Af^rJSo+[wCXV[">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_sleep" id="CD~6T)a%}YRH$=NiO~;D">
                <value name="DURATION">
                  <shadow type="math_number">
                    <field name="NUM">0</field>
                  </shadow>
                  <block type="variables_get" id="mSEpIApiDNrqSC78kw*;">
                    <field name="VAR" id="*5rZkI.0aRs1@hTKoIS~">right turn time</field>
                  </block>
                </value>
                <next>
                  <block type="vex_iq_motor_stop" id="$`iV,uQ[nYVqjDV#8SPz">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                    <field name="STOP_MODE">BRAKE</field>
                    <next>
                      <block type="vex_iq_motor_stop" id="=!PZ,K@R5zH!.A/zK6l4">
                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                        <field name="STOP_MODE">BRAKE</field>
                        <next>
                          <block type="vex_iq_sleep" id="i?V7}P:S1+Gsg#)et(_5">
                            <value name="DURATION">
                              <shadow type="math_number" id="(,F@p:h-.*0u[~]$zs=[">
                                <field name="NUM">1000</field>
                              </shadow>
                            </value>
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
  <block type="procedures_defnoreturn" id="NwzJ0~;;VCE3{+jWiH@n" x="13" y="1288">
    <mutation>
      <arg name="left turn time" varid="X/syq:bhXZAx21E+`jOc"></arg>
    </mutation>
    <field name="NAME">left turn</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_velocity" id="t2CFoNuZN=m[OjV^q#4?">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="DIRECTION">FORWARD</field>
        <value name="VELOCITY">
          <shadow type="math_number" id="{,fN4+xOPC~d+4Mic+Ap">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="_*1hg3,^|7R]7}2m$Yr9">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">BACKWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="nRr0UvPtK-aI!l1/c#M=">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_sleep" id="EqdWMq@gY-P{PqfGsZeC">
                <value name="DURATION">
                  <shadow type="math_number" id="-J:0ll+chbe2ZvRg8{ty">
                    <field name="NUM">0</field>
                  </shadow>
                  <block type="variables_get" id="Att43xjr8;,=yr0MBMxo">
                    <field name="VAR" id="X/syq:bhXZAx21E+`jOc">left turn time</field>
                  </block>
                </value>
                <next>
                  <block type="vex_iq_motor_stop" id="l}*|(c:O-e+;vL-04m*M">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                    <field name="STOP_MODE">BRAKE</field>
                    <next>
                      <block type="vex_iq_motor_stop" id="q6lM8DLREBral8v?^B4u">
                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                        <field name="STOP_MODE">BRAKE</field>
                        <next>
                          <block type="vex_iq_sleep" id="x[AZ;Qq()Y0CQ|){?;IM">
                            <value name="DURATION">
                              <shadow type="math_number" id="4lk5HJEY|H6D=eX,KvG0">
                                <field name="NUM">1000</field>
                              </shadow>
                            </value>
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
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="1563">
    <statement name="DO">
      <block type="procedures_callnoreturn" id="Qq}MAXJ!k40Kf/BLxWyT">
        <mutation name="move forward">
          <arg name="forward time"></arg>
        </mutation>
        <value name="ARG0">
          <block type="math_number" id="X/l$8dGcDKs=k!z,pccT">
            <field name="NUM">2500</field>
          </block>
        </value>
        <next>
          <block type="procedures_callnoreturn" id="siZtYpnO4rJ*]JWF.|EA">
            <mutation name="move backward">
              <arg name="backward time"></arg>
            </mutation>
            <value name="ARG0">
              <block type="math_number" id="r!mMH@qU#_{85#ZFKX3,">
                <field name="NUM">3000</field>
              </block>
            </value>
            <next>
              <block type="procedures_callnoreturn" id=":=#6I)DCI7!kY`e|jy$w">
                <mutation name="right turn">
                  <arg name="right turn time"></arg>
                </mutation>
                <value name="ARG0">
                  <block type="math_number" id="Qh51v/k;7m:|b%b}*[O:">
                    <field name="NUM">800</field>
                  </block>
                </value>
                <next>
                  <block type="procedures_callnoreturn" id="gBW~550.DQqw2nE3eK%y">
                    <mutation name="left turn">
                      <arg name="left turn time"></arg>
                    </mutation>
                    <value name="ARG0">
                      <block type="math_number" id="#t+cHQE}RsCt!{LhZoYF">
                        <field name="NUM">1200</field>
                      </block>
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
</xml>
END XML */
