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
    setMotorSpeed(left_motor, 75);
    setMotorSpeed(right_motor, 75);
    sleep(1000);
    setMotorBrakeMode(left_motor, motorBrake);
    setMotorSpeed(left_motor, 0);
    setMotorBrakeMode(right_motor, motorBrake);
    setMotorSpeed(right_motor, 0);
    sleep(5000);
    setMotorSpeed(left_motor, 75);
    setMotorSpeed(right_motor, 75);
    sleep(1000);
    setMotorBrakeMode(left_motor, motorCoast);
    setMotorSpeed(left_motor, 0);
    setMotorBrakeMode(right_motor, motorCoast);
    setMotorSpeed(right_motor, 0);
    sleep(5000);
    setMotorSpeed(left_motor, 75);
    setMotorSpeed(right_motor, 75);
    sleep(1000);
    setMotorBrakeMode(left_motor, motorHold);
    setMotorSpeed(left_motor, 0);
    setMotorBrakeMode(right_motor, motorHold);
    setMotorSpeed(right_motor, 0);
    sleep(5000);

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
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="463">
    <statement name="DO">
      <block type="vex_iq_motor_spin_velocity" id="RNm#Q,wAGeX0dF`e_M=^">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="DIRECTION">FORWARD</field>
        <value name="VELOCITY">
          <shadow type="math_number" id="|a[Oq8T@7qV4%`]eAFWL">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="^]kC.1Cm6;Xl6Qq2ZFp#">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="p2L2Y+q9^Ns[fMQatabY">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_sleep" id="MX!S~vm5bJyplUV82WA/">
                <value name="DURATION">
                  <shadow type="math_number" id="N}aRIi2}=Qu+m#+2Zf2m">
                    <field name="NUM">1000</field>
                  </shadow>
                </value>
                <next>
                  <block type="vex_iq_motor_stop" id="MJ{:C4IaS|TB/5p=n:Od">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                    <field name="STOP_MODE">BRAKE</field>
                    <next>
                      <block type="vex_iq_motor_stop" id="x^@J9.h^5uc[,g9OyyDP">
                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                        <field name="STOP_MODE">BRAKE</field>
                        <next>
                          <block type="vex_iq_sleep" id="n0*AU`;~!Dl5ADAk2T:,">
                            <value name="DURATION">
                              <shadow type="math_number" id="XFzN`cx#+u-@#~1!C.2q">
                                <field name="NUM">5000</field>
                              </shadow>
                            </value>
                            <next>
                              <block type="vex_iq_motor_spin_velocity" id=":hE.IE;cnpoc)!o4cH)l">
                                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                <field name="DIRECTION">FORWARD</field>
                                <value name="VELOCITY">
                                  <shadow type="math_number" id="XcY!UkT)f6h~G%Zv#{HK">
                                    <field name="NUM">75</field>
                                  </shadow>
                                </value>
                                <next>
                                  <block type="vex_iq_motor_spin_velocity" id="(pP:675Y)9t1(aK;);aq">
                                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                    <field name="DIRECTION">FORWARD</field>
                                    <value name="VELOCITY">
                                      <shadow type="math_number" id="oKyZO)6Khx$]2DHGUeA9">
                                        <field name="NUM">75</field>
                                      </shadow>
                                    </value>
                                    <next>
                                      <block type="vex_iq_sleep" id="BdPJe~#7c0aH;[=)Qd+e">
                                        <value name="DURATION">
                                          <shadow type="math_number" id="u7v/Z$CrMVJsu6[8$clo">
                                            <field name="NUM">1000</field>
                                          </shadow>
                                        </value>
                                        <next>
                                          <block type="vex_iq_motor_stop" id="5YtdyvcAdE@7_:fj*$47">
                                            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                            <field name="STOP_MODE">COAST</field>
                                            <next>
                                              <block type="vex_iq_motor_stop" id="??wK++zFsuqoxB-lf)xo">
                                                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                                <field name="STOP_MODE">COAST</field>
                                                <next>
                                                  <block type="vex_iq_sleep" id="HBH*kU?$#ns=*7oXOW^E">
                                                    <value name="DURATION">
                                                      <shadow type="math_number" id="%V6{jj0{#J~{zbKKd_?W">
                                                        <field name="NUM">5000</field>
                                                      </shadow>
                                                    </value>
                                                    <next>
                                                      <block type="vex_iq_motor_spin_velocity" id="M$azix,q7+j*nX2hoY70">
                                                        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                                        <field name="DIRECTION">FORWARD</field>
                                                        <value name="VELOCITY">
                                                          <shadow type="math_number" id="8~D_uFck^^:Zb`=Y2=dk">
                                                            <field name="NUM">75</field>
                                                          </shadow>
                                                        </value>
                                                        <next>
                                                          <block type="vex_iq_motor_spin_velocity" id="C_;3p(_)Q5?/w;(wY$*W">
                                                            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                                            <field name="DIRECTION">FORWARD</field>
                                                            <value name="VELOCITY">
                                                              <shadow type="math_number" id="}`:SH{P%5oq!W$RD(~G6">
                                                                <field name="NUM">75</field>
                                                              </shadow>
                                                            </value>
                                                            <next>
                                                              <block type="vex_iq_sleep" id="BW!4Uk?ANN@8^-HYl:2R">
                                                                <value name="DURATION">
                                                                  <shadow type="math_number" id="w-2noa|2dCET![{8vpRQ">
                                                                    <field name="NUM">1000</field>
                                                                  </shadow>
                                                                </value>
                                                                <next>
                                                                  <block type="vex_iq_motor_stop" id="cT0e^Ox52FpAptcCmO%j">
                                                                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                                                    <field name="STOP_MODE">HOLD</field>
                                                                    <next>
                                                                      <block type="vex_iq_motor_stop" id="8{/ReOfe-q9*%Z`OjIdA">
                                                                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                                                        <field name="STOP_MODE">HOLD</field>
                                                                        <next>
                                                                          <block type="vex_iq_sleep" id="LX,hvSL*`|uu@Tu~S7.5">
                                                                            <value name="DURATION">
                                                                              <shadow type="math_number" id="TVEHnFH%I?ye_ETA{]mt">
                                                                                <field name="NUM">5000</field>
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
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
