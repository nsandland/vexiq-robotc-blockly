#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float i;
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
    for (i = 1; i <= 20; i++) {
      setMotorSpeed(left_motor, 50);
      setMotorSpeed(right_motor, 50);
      sleep(2000);
      setMotorSpeed(left_motor, -50);
      setMotorSpeed(right_motor, 50);
      sleep(500);
    }
    setMotorBrakeMode(left_motor, motorBrake);
    setMotorSpeed(left_motor, 0);
    setMotorBrakeMode(right_motor, motorBrake);
    setMotorSpeed(right_motor, 0);

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
    <variable id="S?1OP,zVs50qC@pokl3E">bump switch</variable>
    <variable id="UCC-Z#0}d85!qaB^`*EY">port_10</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">port_11</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
    <variable id=".I!7/F#By!UWc4eQe#Z4">i</variable>
  </variables>
  <block type="comment_block" id="!uAjl^d?r]-`@cj9*zTJ" x="13" y="13">
    <field name="NAME">This program uses a "for" loop to instruct the</field>
    <next>
      <block type="comment_block" id="Nw/3dWVHCgn[UVqet;)(">
        <field name="NAME">robot to traverse a square 5 times by repeating</field>
        <next>
          <block type="comment_block" id=";NG#9w{Eg6;Zmg6^.!0T">
            <field name="NAME">moving forward and turning behaviors 20 times.</field>
          </block>
        </next>
      </block>
    </next>
  </block>
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="113">
    <field name="HAS_CONTROLLER">TRUE</field>
    <field name="PORT_1_NAME" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
    <field name="PORT_2_NAME" id="%U9G3C1f~]_Kp7^^-7Ir">port_2</field>
    <field name="PORT_3_NAME" id="W]!UnnR..||G/=zrEIJt">port_3</field>
    <field name="PORT_4_NAME" id="s4u0G;(du~#s/n8=ibn}">port_4</field>
    <field name="PORT_5_NAME" id="haGj?M05(YHo?$VWjx1^">port_5</field>
    <field name="PORT_6_NAME" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
    <field name="PORT_7_NAME" id="^+4/-T,O-t[iqqC$$[Up">port_7</field>
    <field name="PORT_8_NAME" id="z6z0}I;#nZ0)+.go64uO">port_8</field>
    <field name="PORT_9_NAME" id="S?1OP,zVs50qC@pokl3E">bump switch</field>
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
  <block type="events_on_start" id=")LZQbUvmq55?Gk$Q71z3" x="13" y="488">
    <statement name="DO">
      <block type="comment_block" id="z^Co75`t3v=x,ICD[eTI">
        <field name="NAME">This count loop counts from 1 to 20.</field>
        <next>
          <block type="controls_for" id="#-d#%AAYxcqwv$W3Zu6V">
            <field name="VAR" id=".I!7/F#By!UWc4eQe#Z4">i</field>
            <value name="FROM">
              <shadow type="math_number" id="/;JTwB-Sn0zoF6jAl#aJ">
                <field name="NUM">1</field>
              </shadow>
            </value>
            <value name="TO">
              <shadow type="math_number" id="RS5*p)D(`f8wZrd9X:Qi">
                <field name="NUM">20</field>
              </shadow>
            </value>
            <value name="BY">
              <shadow type="math_number" id="cQDyf=X+Snvo)^|JFla)">
                <field name="NUM">1</field>
              </shadow>
            </value>
            <statement name="DO">
              <block type="vex_iq_motor_spin_velocity" id="HxMm[RO@SbSPs@YzI!Ux">
                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                <field name="DIRECTION">FORWARD</field>
                <value name="VELOCITY">
                  <shadow type="math_number" id="RQ{jY]S_i5+-TTo)a5M:">
                    <field name="NUM">50</field>
                  </shadow>
                </value>
                <next>
                  <block type="vex_iq_motor_spin_velocity" id=".@Od5n5}xA#I:F.SvG.t">
                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                    <field name="DIRECTION">FORWARD</field>
                    <value name="VELOCITY">
                      <shadow type="math_number" id="Ii!:i1q|V:n`kFr7~Fr7">
                        <field name="NUM">50</field>
                      </shadow>
                    </value>
                    <next>
                      <block type="vex_iq_sleep" id="SCe$B{?t!p9w?OHWGOhM">
                        <value name="DURATION">
                          <shadow type="math_number" id="Hd[]5_RZEbmD3eJ;~zRF">
                            <field name="NUM">2000</field>
                          </shadow>
                        </value>
                        <next>
                          <block type="vex_iq_motor_spin_velocity" id="#!ycEy%!rB+nHN_E`2.d">
                            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                            <field name="DIRECTION">BACKWARD</field>
                            <value name="VELOCITY">
                              <shadow type="math_number" id="]$W0[26HLWxXC9dKyAqg">
                                <field name="NUM">50</field>
                              </shadow>
                            </value>
                            <next>
                              <block type="vex_iq_motor_spin_velocity" id="BvJ5Mja)ZI8%]p{E~f^y">
                                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                <field name="DIRECTION">FORWARD</field>
                                <value name="VELOCITY">
                                  <shadow type="math_number" id="8D]f+6kvBFC{dSiw/4^1">
                                    <field name="NUM">50</field>
                                  </shadow>
                                </value>
                                <next>
                                  <block type="vex_iq_sleep" id=";/L/k1Bs0.lK;UZ2~$]T">
                                    <value name="DURATION">
                                      <shadow type="math_number" id="v=Y,`8Y3@/,:_u9acg:Y">
                                        <field name="NUM">500</field>
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
            <next>
              <block type="vex_iq_motor_stop" id="[MHG#vZs[}@xE#GHpb(/">
                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                <field name="STOP_MODE">BRAKE</field>
                <next>
                  <block type="vex_iq_motor_stop" id=")4Uf/$]#g?*hTQT#9)8G">
                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                    <field name="STOP_MODE">BRAKE</field>
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
