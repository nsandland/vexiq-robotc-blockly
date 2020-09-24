#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Sensor, port7, distance_sensor, sensorVexIQ_Distance)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float distance_sensor2;
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
  displayTextLine(1, "Strong:  %1.2f mm", getDistanceStrongest(distance_sensor2));
  displayTextLine(2, "2ndStr:  %1.2f mm", getDistanceSecondStrongest(distance_sensor2));
  displayTextLine(3, "Reflect: %1.2f mm", getDistanceMostReflective(distance_sensor2));
  sleep(50);

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
    <variable id="^+4/-T,O-t[iqqC$$[Up">distance sensor</variable>
    <variable id="z6z0}I;#nZ0)+.go64uO">port_8</variable>
    <variable id="S?1OP,zVs50qC@pokl3E">port 9</variable>
    <variable id="UCC-Z#0}d85!qaB^`*EY">port_10</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">port_11</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
    <variable id="MNx^E0$IqBIO4WysGAE,">distance_sensor</variable>
  </variables>
  <block type="comment_block" id="_{E-F(4P~WYw_|kmu)GG" x="13" y="13">
    <field name="NAME">The VEX IQ Distance Sensor is able to detect up</field>
    <next>
      <block type="comment_block" id="2a[K_2A9Nk79/wH7H6wY">
        <field name="NAME">to 3 different values -</field>
        <next>
          <block type="comment_block" id="I!6~e[leSf|IVxpO2bn@">
            <field name="NAME"></field>
            <next>
              <block type="comment_block" id="K5$AK!^[dVW.sx*)QD5h">
                <field name="NAME">Closest: Returns the strongest signal based on</field>
                <next>
                  <block type="comment_block" id="Pc#uGCw9:vWkOK|[H^pC">
                    <field name="NAME">proximity to the sensor.</field>
                    <next>
                      <block type="comment_block" id="(hLY){F[/+?^V~1^i?}w">
                        <field name="NAME"></field>
                        <next>
                          <block type="comment_block" id="3q|ivg`/FRetLS}tW5wg">
                            <field name="NAME">Second Closest: Returns the second strongest</field>
                            <next>
                              <block type="comment_block" id=",5jnb1Vq1mVX+B1?m@2]">
                                <field name="NAME">signal based on proximity to the sensor.</field>
                                <next>
                                  <block type="comment_block" id="l7~+$A.;N=yJ3877(5PV">
                                    <field name="NAME"></field>
                                    <next>
                                      <block type="comment_block" id="PAotw1%1gihgZw|JFA:F">
                                        <field name="NAME">Biggest: Returns the distance to the most</field>
                                        <next>
                                          <block type="comment_block" id="HW5_|t.DTc+3?@z/lD4$">
                                            <field name="NAME">reflective (typically the largest) object detect.</field>
                                            <next>
                                              <block type="comment_block" id="^z)xvn*^Opf`$ZT:6fmH">
                                                <field name="NAME">This is the object that returns the most</field>
                                                <next>
                                                  <block type="comment_block" id="uC=A(q]bI56Wmwu/HDnt">
                                                    <field name="NAME">reflected sound.</field>
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
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="388">
    <field name="HAS_CONTROLLER">TRUE</field>
    <field name="PORT_1_NAME" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
    <field name="PORT_2_NAME" id="%U9G3C1f~]_Kp7^^-7Ir">port_2</field>
    <field name="PORT_3_NAME" id="W]!UnnR..||G/=zrEIJt">port_3</field>
    <field name="PORT_4_NAME" id="s4u0G;(du~#s/n8=ibn}">port_4</field>
    <field name="PORT_5_NAME" id="haGj?M05(YHo?$VWjx1^">port_5</field>
    <field name="PORT_6_NAME" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
    <field name="PORT_7_NAME" id="^+4/-T,O-t[iqqC$$[Up">distance sensor</field>
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
    <value name="PORT_7">
      <block type="vex_iq_distance_sensor" id="t-pwZ%gw#FbV2gXB_o;)"></block>
    </value>
  </block>
  <block type="events_always" id="`;J[`]{vq4R,^@ie2#vl" x="13" y="763">
    <statement name="DO">
      <block type="comment_block" id="12x}orgawP^iM[`5sl+6">
        <field name="NAME">Display the 3 different values from the Distance</field>
        <next>
          <block type="comment_block" id="Uc?Y/0[b6m%|yWAng`ZC">
            <field name="NAME">Sensor to the VEX IQ LCD Screen</field>
            <next>
              <block type="vex_iq_lcd_print" id="BmKG/54ahOMANPG;~@!8">
                <mutation vars="1"></mutation>
                <field name="TEXT0">Strong:  </field>
                <field name="TEXT1"> mm</field>
                <field name="LINE">1</field>
                <value name="VAR0">
                  <block type="vex_iq_distance" id="3_0[#W)d~#Zv$1/ISDlM">
                    <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
                    <field name="MODE">STRONGEST</field>
                  </block>
                </value>
                <next>
                  <block type="vex_iq_lcd_print" id="}Yu^WlsjhXU-Js=0n}93">
                    <mutation vars="1"></mutation>
                    <field name="TEXT0">2ndStr:  </field>
                    <field name="TEXT1"> mm</field>
                    <field name="LINE">2</field>
                    <value name="VAR0">
                      <block type="vex_iq_distance" id="ZLKWn|8qirKuB$,r]!+8">
                        <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
                        <field name="MODE">SECOND_STRONGEST</field>
                      </block>
                    </value>
                    <next>
                      <block type="vex_iq_lcd_print" id="{s$7dS=Lk;uym}[AEj?h">
                        <mutation vars="1"></mutation>
                        <field name="TEXT0">Reflect: </field>
                        <field name="TEXT1"> mm</field>
                        <field name="LINE">3</field>
                        <value name="VAR0">
                          <block type="vex_iq_distance" id="y1n40!w74RCRW;-IF8|B">
                            <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
                            <field name="MODE">MOST_REFLECTIVE</field>
                          </block>
                        </value>
                        <next>
                          <block type="vex_iq_sleep" id="^g2w1VNBLz;f2-6|xaZ9">
                            <value name="DURATION">
                              <shadow type="math_number" id="]eMbj}%;:4y1^fsB=C.=">
                                <field name="NUM">50</field>
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
</xml>
END XML */
