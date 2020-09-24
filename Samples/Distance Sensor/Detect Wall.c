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

float distance__3E_100();

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

bool when_true_old_state = false;
void when_true2() {
  bool new_state = (distance__3E_100());
  if (new_state && new_state != when_true_old_state) {
    setMotorSpeed(left_motor, 50);
    setMotorSpeed(right_motor, 50);

  }
  when_true_old_state = new_state;
}

bool when_false_old_state = false;
void when_false2() {
  bool new_state = (distance__3E_100());
  if (!new_state && new_state != when_false_old_state) {
    setMotorBrakeMode(left_motor, motorBrake);
    setMotorSpeed(left_motor, 0);
    setMotorBrakeMode(right_motor, motorBrake);
    setMotorSpeed(right_motor, 0);

  }
  when_false_old_state = new_state;
}

// Describe this function...
float distance__3E_100() {
  return getDistanceStrongest(distance_sensor2) > 100;
}



task main() {
  activate_event(start);
  while(true) {
    when_true2();
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
    <variable id="^+4/-T,O-t[iqqC$$[Up">distance sensor</variable>
    <variable id="z6z0}I;#nZ0)+.go64uO">port_8</variable>
    <variable id="S?1OP,zVs50qC@pokl3E">port 9</variable>
    <variable id="UCC-Z#0}d85!qaB^`*EY">port_10</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">port_11</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
    <variable id="MNx^E0$IqBIO4WysGAE,">distance_sensor</variable>
  </variables>
  <block type="comment_block" id="|XF+gjVqjTv/2,r#6XsE" x="13" y="13">
    <field name="NAME">Move forward until the VEX IQ Distance Sensors</field>
    <next>
      <block type="comment_block" id="Q!b::Vl,!$Mg/WBMc7V`">
        <field name="NAME">sees an object 100 millimeters (mm) away. The</field>
        <next>
          <block type="comment_block" id="-mX=Q{DhkiQ#1iw(v+F6">
            <field name="NAME">VEX IQ Distance Sensor returns values in</field>
            <next>
              <block type="comment_block" id="cRi`H:YrlmFL39JSqLH`">
                <field name="NAME">millimeters.</field>
              </block>
            </next>
          </block>
        </next>
      </block>
    </next>
  </block>
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="138">
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
  <block type="events_when" id="#(,ivPVP_~{^Jc_`3m,^" x="13" y="513">
    <value name="WHEN">
      <block type="procedures_callreturn" id="h^fy{86M[Uf;fXu]Ks0)">
        <mutation name="distance &gt; 100"></mutation>
      </block>
    </value>
    <statement name="DO">
      <block type="comment_block" id="~HmX6|lIytx2`YVvMnj]">
        <field name="NAME">Spin motors if farther than 10cm</field>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="i*3?}[Q3G0C,_o1ZYVjI">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="wB|ZAPz!r;K~%dmT$%vv">
                <field name="NUM">50</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_motor_spin_velocity" id="fc1=9tR=vukObb@Q[l2X">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                <field name="DIRECTION">FORWARD</field>
                <value name="VELOCITY">
                  <shadow type="math_number" id="@gZ@KD0ks%Ix[(n*^:#j">
                    <field name="NUM">50</field>
                  </shadow>
                </value>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="events_after" id="eyt.svMz7E)YJB#!r_Lx" x="13" y="688">
    <value name="AFTER">
      <block type="procedures_callreturn" id="Y;1yr7eaKMe8kqQ17F5+">
        <mutation name="distance &gt; 100"></mutation>
      </block>
    </value>
    <statement name="DO">
      <block type="comment_block" id="p/MKkFt(d5*4YAba];@A">
        <field name="NAME">Stop motors if closer than 10cm</field>
        <next>
          <block type="vex_iq_motor_stop" id="(b9eKG`2f;GW^F__RZb7">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="STOP_MODE">BRAKE</field>
            <next>
              <block type="vex_iq_motor_stop" id="#y*.o7]86hFN}ow`z/;6">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                <field name="STOP_MODE">BRAKE</field>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="procedures_defreturn" id="{8{e(b=hK//%DG*IYGp*" x="13" y="838">
    <mutation statements="false"></mutation>
    <field name="NAME">distance &gt; 100</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <value name="RETURN">
      <block type="logic_compare" id="SdSYu$m9hh[MwR;a1Mo@">
        <field name="OP">GT</field>
        <value name="A">
          <block type="vex_iq_distance" id="^)W}[Wsr)/SsGd3OYu@+">
            <field name="DISTANCE_SENSOR" id="MNx^E0$IqBIO4WysGAE,">distance_sensor</field>
            <field name="MODE">STRONGEST</field>
          </block>
        </value>
        <value name="B">
          <block type="math_number" id="vBbuSshM1{bpmzuv!PUk">
            <field name="NUM">100</field>
          </block>
        </value>
      </block>
    </value>
  </block>
</xml>
END XML */
