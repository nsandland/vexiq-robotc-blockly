#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor, motor10, arm_motor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor, motor11, claw_motor, tmotorVexIQ, PIDControl, reversed, encoder)

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


bool between(float value, float bound1, float bound2) {
  if (bound1 > bound2) {
    return value > bound2 && value < bound1;
  } else {
    return value > bound1 && value < bound2;
  }
}

bool notbetween(float value, float bound1, float bound2) {
  if (bound1 > bound2) {
    return value < bound2 || value > bound1;
  } else {
    return value < bound1 || value > bound2;
  }
}

void on_start2() {
  if (event_is_active(start)) {
    resetMotorEncoder(arm_motor);
    setServoTarget(arm_motor, 300, abs(100));
    sleep(2000);
    setServoTarget(arm_motor, 120, abs(100));
    sleep(2000);

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
    <variable id="UCC-Z#0}d85!qaB^`*EY">arm motor</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">claw motor</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
  </variables>
  <block type="comment_block" id="Fn]R$;CWS(5n)l[8T1b7" x="13" y="13">
    <field name="NAME">The VEX IQ Motors can be used in "Servo" mode to</field>
    <next>
      <block type="comment_block" id="Xc~r,zHNtGo+}oK%NsWZ">
        <field name="NAME">make them run to a specific position at full</field>
        <next>
          <block type="comment_block" id="0{tAcZ)y^bAs^CC4YvjQ">
            <field name="NAME">speed. After the VEX IQ Motor in "Servo" mode</field>
            <next>
              <block type="comment_block" id="vO2I}JtLS6)={mogE?LW">
                <field name="NAME">has completed its movement, it hold it's</field>
                <next>
                  <block type="comment_block" id="-gAdyi[AR4:B%mB+X$c6">
                    <field name="NAME">position like a standard hobby servo motor.</field>
                    <next>
                      <block type="comment_block" id="l)I2+jK_xr=`(53%E]-U">
                        <field name="NAME"></field>
                        <next>
                          <block type="comment_block" id="]Y~kng@qr_X8Tp$_IYE!">
                            <field name="NAME">You can give a Servo any position value,</field>
                            <next>
                              <block type="comment_block" id="yO+[2P^L)XH5WT=[.^L)">
                                <field name="NAME">positive or negative. Note that VEX IQ motors</field>
                                <next>
                                  <block type="comment_block" id="fyo7Gv6IhqQ%HSbXxp9m">
                                    <field name="NAME">will move 360 degrees in one full rotation of</field>
                                    <next>
                                      <block type="comment_block" id="Vp-#hE!rS5WP]]/PSeb%">
                                        <field name="NAME">the motor.</field>
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
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="313">
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
    <field name="PORT_10_NAME" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
    <field name="PORT_11_NAME" id="Sq;4ZphrM!WA8xQBm)1F">claw motor</field>
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
    <value name="PORT_10">
      <block type="vex_iq_motor" id="Rpu7W@q5$7Z/??Jz?`1;">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
    <value name="PORT_11">
      <block type="vex_iq_motor" id=";YS;Kt7wz)A^IMRZ~E6Z">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
  </block>
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="688">
    <statement name="DO">
      <block type="comment_block" id="WO.Mxd|Na13@X2zSy7}Z">
        <field name="NAME">Take current position as zero.</field>
        <next>
          <block type="vex_iq_motor_reset_absolute_position" id="K:n+lxE%[M~kmuo1)z@(">
            <field name="MOTOR" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
            <next>
              <block type="comment_block" id="^kDmkTywgK7|F))VpZto">
                <field name="NAME">Move to 300 degrees.</field>
                <next>
                  <block type="vex_iq_motor_spin_to" id="N:{pMP4e_U=?McWS`?y;">
                    <field name="MOTOR" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
                    <field name="STOP_MODE">HOLD</field>
                    <value name="POSITION">
                      <shadow type="math_number" id="@}n9-DfM%}8us{aRh*WS">
                        <field name="NUM">300</field>
                      </shadow>
                    </value>
                    <value name="VELOCITY">
                      <shadow type="math_number" id="d0GioQ:,R*),#}Ckx]{5">
                        <field name="NUM">100</field>
                      </shadow>
                    </value>
                    <next>
                      <block type="vex_iq_sleep" id="ywvB/}R2V1V[N1LzJLJE">
                        <value name="DURATION">
                          <shadow type="math_number" id="$bFl{U[TJuCeiz6u$h]b">
                            <field name="NUM">2000</field>
                          </shadow>
                        </value>
                        <next>
                          <block type="comment_block" id="]8UjQ]K58=,Fns%td$R{">
                            <field name="NAME">Move to 120 degrees.</field>
                            <next>
                              <block type="vex_iq_motor_spin_to" id="[[9:nhJA4RJqaaf67z-~">
                                <field name="MOTOR" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
                                <field name="STOP_MODE">HOLD</field>
                                <value name="POSITION">
                                  <shadow type="math_number" id="IA)lDn%cVETq*3yb,JUy">
                                    <field name="NUM">120</field>
                                  </shadow>
                                </value>
                                <value name="VELOCITY">
                                  <shadow type="math_number" id="6~Lhw^{x#pXL(ueQ]EpT">
                                    <field name="NUM">100</field>
                                  </shadow>
                                </value>
                                <next>
                                  <block type="vex_iq_sleep" id="lEMAsj9iey/aD?BgcCnw">
                                    <value name="DURATION">
                                      <shadow type="math_number" id="Xhab7D(|d(i]{6kbVXoa">
                                        <field name="NUM">2000</field>
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
    </statement>
  </block>
  <block type="comment_block" id="oCjgV]eoS{}KW2o_8*7p" x="13" y="1013">
    <field name="NAME">comment</field>
  </block>
</xml>
END XML */
