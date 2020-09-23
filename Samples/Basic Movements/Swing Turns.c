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
    setMotorBrakeMode(left_motor, motorBrake);
    setMotorSpeed(left_motor, 0);
    setMotorSpeed(right_motor, 100);
    sleep(1000);
    setMotorSpeed(left_motor, 100);
    setMotorBrakeMode(right_motor, motorBrake);
    setMotorSpeed(right_motor, 0);
    sleep(1000);
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
    <variable id="S?1OP,zVs50qC@pokl3E">port_9</variable>
    <variable id="UCC-Z#0}d85!qaB^`*EY">port_10</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">port_11</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
  </variables>
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="13">
    <field name="HAS_CONTROLLER">TRUE</field>
    <field name="PORT_1_NAME" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
    <field name="PORT_2_NAME" id="%U9G3C1f~]_Kp7^^-7Ir">port_2</field>
    <field name="PORT_3_NAME" id="W]!UnnR..||G/=zrEIJt">port_3</field>
    <field name="PORT_4_NAME" id="s4u0G;(du~#s/n8=ibn}">port_4</field>
    <field name="PORT_5_NAME" id="haGj?M05(YHo?$VWjx1^">port_5</field>
    <field name="PORT_6_NAME" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
    <field name="PORT_7_NAME" id="^+4/-T,O-t[iqqC$$[Up">port_7</field>
    <field name="PORT_8_NAME" id="z6z0}I;#nZ0)+.go64uO">port_8</field>
    <field name="PORT_9_NAME" id="S?1OP,zVs50qC@pokl3E">port_9</field>
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
  <block type="events_on_start" id="1|*G6NmWsHDvUxJ2)(qX" x="13" y="388">
    <statement name="DO">
      <block type="vex_iq_motor_stop" id="Gbrl@]g[)qZMWSqn9.+f">
        <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
        <field name="STOP_MODE">BRAKE</field>
        <next>
          <block type="vex_iq_motor_spin_velocity" id="GF#tYl*Sf*-ClrG.%l5#">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="uF=yg%GW+k-4I/2HmM=:">
                <field name="NUM">100</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_sleep" id="mSv@CFh*a)f]f)Z[IhpH">
                <value name="DURATION">
                  <shadow type="math_number" id="uwZ_GJ5Ogu;DKssw6q:!">
                    <field name="NUM">1000</field>
                  </shadow>
                </value>
                <next>
                  <block type="vex_iq_motor_spin_velocity" id="+|D~cV_hmu]kJcf=mBIk">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                    <field name="DIRECTION">FORWARD</field>
                    <value name="VELOCITY">
                      <shadow type="math_number" id="A=gdC:WA#eq67;|VMiHC">
                        <field name="NUM">100</field>
                      </shadow>
                    </value>
                    <next>
                      <block type="vex_iq_motor_stop" id="Xm+fYoRheD}LVK(dR9%D">
                        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                        <field name="STOP_MODE">BRAKE</field>
                        <next>
                          <block type="vex_iq_sleep" id="YO3Z-zQVTI6P.JovYl4g">
                            <value name="DURATION">
                              <shadow type="math_number" id="J-r)=Z:g#Iv1Xw4{MMpQ">
                                <field name="NUM">1000</field>
                              </shadow>
                            </value>
                            <next>
                              <block type="vex_iq_motor_stop" id="0[?Hf)Qg0;3GBo4A9xr}">
                                <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                                <field name="STOP_MODE">BRAKE</field>
                                <next>
                                  <block type="vex_iq_motor_stop" id="!DqGSGPaA!q^unUDz0,o">
                                    <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                                    <field name="STOP_MODE">BRAKE</field>
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
