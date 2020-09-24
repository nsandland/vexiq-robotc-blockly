#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Sensor, port4, gyro_sensor, sensorVexIQ_Gyro)
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
    resetGyro(gyro_sensor);
    setMotorSpeed(left_motor, -25);
    setMotorSpeed(right_motor, 25);

  }
}

bool when_true_old_state = false;
void when_true2() {
  bool new_state = (getGyroHeadingFloat(gyro_sensor) >= 90);
  if (new_state && new_state != when_true_old_state) {
    setMotorBrakeMode(left_motor, motorBrake);
    setMotorSpeed(left_motor, 0);
    setMotorBrakeMode(right_motor, motorBrake);
    setMotorSpeed(right_motor, 0);

  }
  when_true_old_state = new_state;
}



task main() {
  activate_event(start);
  while(true) {
    on_start2();
    when_true2();

    advance_event(start);
  }
}

/* XML
<xml xmlns="https://developers.google.com/blockly/xml">
  <variables>
    <variable id="2C_w(9X|eyDoXJZtSlGb">left motor</variable>
    <variable id="%U9G3C1f~]_Kp7^^-7Ir">port_2</variable>
    <variable id="W]!UnnR..||G/=zrEIJt">port_3</variable>
    <variable id="s4u0G;(du~#s/n8=ibn}">gyro sensor</variable>
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
    <field name="PORT_4_NAME" id="s4u0G;(du~#s/n8=ibn}">gyro sensor</field>
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
    <value name="PORT_4">
      <block type="vex_iq_gyro" id="m{?_xs`*nyhJp{y.iA3-"></block>
    </value>
    <value name="PORT_6">
      <block type="vex_iq_motor" id="oLsxr9=dh1okfPB:JTz9">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
  </block>
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="463">
    <statement name="DO">
      <block type="vex_iq_gyro_reset_heading" id="s+e%#ZZn@}Ov-$G8;tIi">
        <field name="NAME" id="s4u0G;(du~#s/n8=ibn}">gyro sensor</field>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="FMtdcUjps#k,~6_i~Kag">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="DIRECTION">BACKWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="2UDTk`tIZdVsh1Hulj^#">
                <field name="NUM">25</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_motor_spin_velocity" id="8Z^$HJRt9-]5E@uvSrR@">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                <field name="DIRECTION">FORWARD</field>
                <value name="VELOCITY">
                  <shadow type="math_number" id="8ToqcncdB7{_VJ}{1K^8">
                    <field name="NUM">25</field>
                  </shadow>
                </value>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="events_when" id="+-yf-CKi`3]rSli!0Jh*" x="13" y="638">
    <value name="WHEN">
      <block type="logic_compare" id=",I;@ZF0zq,Alh-:H:;uo">
        <field name="OP">GTE</field>
        <value name="A">
          <block type="vex_iq_gyro_heading" id="([RQc?S6nON6*4ZE[?9d">
            <field name="NAME" id="s4u0G;(du~#s/n8=ibn}">gyro sensor</field>
          </block>
        </value>
        <value name="B">
          <block type="math_number" id=";Q96sNPS[*Q7LI=}n?H1">
            <field name="NUM">90</field>
          </block>
        </value>
      </block>
    </value>
    <statement name="DO">
      <block type="vex_iq_motor_stop" id="A,FRAY7z1H;n~/z-pz/9">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="STOP_MODE">BRAKE</field>
        <next>
          <block type="vex_iq_motor_stop" id="B-q`alm-K.ZDJ$DR!Ehm">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="STOP_MODE">BRAKE</field>
          </block>
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
