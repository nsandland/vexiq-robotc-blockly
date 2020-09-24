#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Sensor, port4, gyro_sensor, sensorVexIQ_Gyro)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float display_value;
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
    display_value = 250;
    displayTextLine(1, "Hello from", );
    displayTextLine(2, "ROBOTC  :]", );
    displayTextLine(1, "My Value is: %1.2f", display_value);

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
    <variable id="s4u0G;(du~#s/n8=ibn}">gyro sensor</variable>
    <variable id="haGj?M05(YHo?$VWjx1^">port_5</variable>
    <variable id="|}5]3]?#UB6;p-p@$?Zo">right motor</variable>
    <variable id="^+4/-T,O-t[iqqC$$[Up">port_7</variable>
    <variable id="z6z0}I;#nZ0)+.go64uO">port_8</variable>
    <variable id="S?1OP,zVs50qC@pokl3E">port 9</variable>
    <variable id="UCC-Z#0}d85!qaB^`*EY">port_10</variable>
    <variable id="Sq;4ZphrM!WA8xQBm)1F">port_11</variable>
    <variable id="f+3LAb5_1]ObyC0i9eX^">port_12</variable>
    <variable id="^SRP[oWh!(U-vjUd|C?d">display value</variable>
  </variables>
  <block type="comment_block" id="T|/]mRdWjYNbDf=CCv/_" x="13" y="13">
    <field name="NAME">This program uses the DisplayTextLine function</field>
    <next>
      <block type="comment_block" id=".!`V]j2YaIkoUKJW?mLz">
        <field name="NAME">of ROBOTC on the VEX IQ Platform. It will</field>
        <next>
          <block type="comment_block" id="]BN,UFKj/:3nQA^4!ar|">
            <field name="NAME">display a message and a number.</field>
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
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="488">
    <statement name="DO">
      <block type="variables_set" id=";HaRJdQ7R!iP@AHWT^io">
        <field name="VAR" id="^SRP[oWh!(U-vjUd|C?d">display value</field>
        <value name="VALUE">
          <block type="math_number" id="4lTK/EX$!rF*[1V:ijw)">
            <field name="NUM">250</field>
          </block>
        </value>
        <next>
          <block type="vex_iq_lcd_print" id="NOn!cpN1i2aaQSf[K|?5">
            <mutation vars="0"></mutation>
            <field name="TEXT0">Hello from</field>
            <field name="LINE">1</field>
            <next>
              <block type="vex_iq_lcd_print" id="95p@EE?1NMLmBi]-u7Vo">
                <mutation vars="0"></mutation>
                <field name="TEXT0">ROBOTC  :]</field>
                <field name="LINE">2</field>
                <next>
                  <block type="vex_iq_lcd_print" id="4erQ.tW_$N^!dnSssX@$">
                    <mutation vars="1"></mutation>
                    <field name="TEXT0">My Value is: </field>
                    <field name="TEXT1"></field>
                    <field name="LINE">1</field>
                    <value name="VAR0">
                      <block type="variables_get" id="iune21Z]dvx-|QpS/*}M">
                        <field name="VAR" id="^SRP[oWh!(U-vjUd|C?d">display value</field>
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
