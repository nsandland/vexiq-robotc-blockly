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

void on_start2() {
  if (event_is_active(start)) {
    setDistanceMinRange(distance_sensor2, 200);
    setDistanceMaxRange(distance_sensor2, 1000);

  }
}

void always2() {
  displayTextLine(1, "Distance: %1.2f mm", getDistanceStrongest(distance_sensor2));
  sleep(50);

}



task main() {
  activate_event(start);
  while(true) {
    on_start2();
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
  <block type="comment_block" id="2.8drdYJ5j:-oCSW,XI]" x="13" y="13">
    <field name="NAME">The VEX IQ Distance sensor is able to detect</field>
    <next>
      <block type="comment_block" id="xOjXyh/xnk94[}?{+*QT">
        <field name="NAME">objects up to 600mm (60cm) away by default. This</field>
        <next>
          <block type="comment_block" id="Va.iK428!e`L[5.$RXm.">
            <field name="NAME">range is the optimal range for the Distance</field>
            <next>
              <block type="comment_block" id="ql8KX:nvkb+y$Brd#[,8">
                <field name="NAME">Sensor, but the distance sensor is able to </field>
                <next>
                  <block type="comment_block" id="DmWL^pE~T@/I4g@daVgx">
                    <field name="NAME">detect up to 1000mm. You can also change the</field>
                    <next>
                      <block type="comment_block" id=":?gX`xBgqYb*MYr*?q8t">
                        <field name="NAME"> minimum range to ignore objects that are too </field>
                        <next>
                          <block type="comment_block" id="W:DADkAe`0X4upE%v]*Q">
                            <field name="NAME">close (like a lifter arm). This program will </field>
                            <next>
                              <block type="comment_block" id="[|akACE10P,4^6O9Kn?V">
                                <field name="NAME">switch the range of the sensor by adjusting both</field>
                                <next>
                                  <block type="comment_block" id="3w!;[#F`d@+b)IMT3eFX">
                                    <field name="NAME">the minimum and maximum detected range for the</field>
                                    <next>
                                      <block type="comment_block" id="Ed[@T(F454qEv7w%}UHn">
                                        <field name="NAME">sensor.</field>
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
  <block type="events_on_start" id=")LZQbUvmq55?Gk$Q71z3" x="13" y="688">
    <statement name="DO">
      <block type="comment_block" id="}B4s)gjouje2j)*X7;jq">
        <field name="NAME">Set the minimum detectable range to 200mm (20cm)</field>
        <next>
          <block type="vex_iq_distance_min" id="i**!}g9?bSwH+Bx}7DEG">
            <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
            <value name="DISTANCE">
              <block type="math_number" id="K6YBWm`xVe5i69rP4R73">
                <field name="NUM">200</field>
              </block>
            </value>
            <next>
              <block type="comment_block" id="YTS:+_bs^FcSD=SnB|g(">
                <field name="NAME">Set the maximum detectable range to 1000mm (100cm)</field>
                <next>
                  <block type="vex_iq_distance_max" id="i,Qqk$f09WiBm{,cDfJa">
                    <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
                    <value name="DISTANCE">
                      <block type="math_number" id="0r@]hPUEh6B$BmfV,{1:">
                        <field name="NUM">1000</field>
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
  <block type="events_always" id="%Pwmj?;Y8gwY*F8Z$#WM" x="13" y="888">
    <statement name="DO">
      <block type="vex_iq_lcd_print" id="ms7JN?UV!$y(mbUyWuZM">
        <mutation vars="1"></mutation>
        <field name="TEXT0">Distance: </field>
        <field name="TEXT1"> mm</field>
        <field name="LINE">1</field>
        <value name="VAR0">
          <block type="vex_iq_distance" id="vk(/8pN[!WC+f8$xif5a">
            <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
            <field name="MODE">STRONGEST</field>
          </block>
        </value>
        <next>
          <block type="vex_iq_sleep" id=",P*rO6L~]j7sJ?oM;Xd2">
            <value name="DURATION">
              <shadow type="math_number" id="%c)e1~tBvUi?#+|4@it]">
                <field name="NUM">50</field>
              </shadow>
            </value>
          </block>
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
