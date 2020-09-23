#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float distance_in_degrees, turn_distance_right, turn_distance_left;
Event start;

void move_until_distance(float distance_in_degrees);
void point_turn_right(float turn_distance_right);
void point_turn_left(float turn_distance_left);

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
void move_until_distance(float distance_in_degrees) {
  setMotorTarget(right_motor, getMotorEncoder(right_motor) + distance_in_degrees, abs(75));
  setMotorTarget(left_motor, getMotorEncoder(left_motor) + distance_in_degrees, abs(75));
  waitUntilMotorStop(right_motor);
  waitUntilMotorStop(left_motor);
}

// Describe this function...
void point_turn_right(float turn_distance_right) {
  setMotorTarget(right_motor, getMotorEncoder(right_motor) + turn_distance_right, abs(75));
  setMotorTarget(left_motor, getMotorEncoder(left_motor) + turn_distance_right, abs(75));
  waitUntilMotorStop(right_motor);
  waitUntilMotorStop(left_motor);
}

// Describe this function...
void point_turn_left(float turn_distance_left) {
  setMotorTarget(right_motor, getMotorEncoder(right_motor) + turn_distance_left, abs(75));
  setMotorTarget(left_motor, getMotorEncoder(left_motor) + turn_distance_left, abs(75));
  waitUntilMotorStop(right_motor);
  waitUntilMotorStop(left_motor);
}

void on_start2() {
  if (event_is_active(start)) {
    move_until_distance(960);
    point_turn_right(960);
    point_turn_left(960);

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
    <variable id="Zlup-9p(W,`K;W]fx24K">distance in degrees</variable>
    <variable id="g6iA3~(VkuXpe9n2Bej`">turn distance right</variable>
    <variable id="e^=Gts{00^|aXi~fw:Tb">turn distance left</variable>
  </variables>
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="63">
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
  <block type="procedures_defnoreturn" id="tT^]eD51`[jGlYn/aa?:" x="13" y="438">
    <mutation>
      <arg name="distance in degrees" varid="Zlup-9p(W,`K;W]fx24K"></arg>
    </mutation>
    <field name="NAME">move until distance</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_distance" id="TT^3T3%P/nr+Ga2y(R.3">
        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
        <field name="DIRECTION">FORWARD</field>
        <field name="STOP_MODE">BRAKE</field>
        <value name="DISTANCE">
          <shadow type="math_number" id="k^c8(R:P5#A[SUOdZ:a;">
            <field name="NUM">75</field>
          </shadow>
          <block type="variables_get" id="aE%C:q=_eENauFh];vFf">
            <field name="VAR" id="Zlup-9p(W,`K;W]fx24K">distance in degrees</field>
          </block>
        </value>
        <value name="VELOCITY">
          <shadow type="math_number" id="W*SVL`P@IUk{W/ufZg+]">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_distance" id="M9m5YepkGoX.2:sK@pwC">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="DIRECTION">FORWARD</field>
            <field name="STOP_MODE">BRAKE</field>
            <value name="DISTANCE">
              <shadow type="math_number" id=",S7Td{(NVW9G*Vj9%Hms">
                <field name="NUM">75</field>
              </shadow>
              <block type="variables_get" id="|.z+AoaEDJ@sfvGu?wl-">
                <field name="VAR" id="Zlup-9p(W,`K;W]fx24K">distance in degrees</field>
              </block>
            </value>
            <value name="VELOCITY">
              <shadow type="math_number" id="kP7Hz5:Es7$8L#TLC1x0">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_motor_wait" id="$CC?IRPrT,MRGRXd61z#">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                <next>
                  <block type="vex_iq_motor_wait" id="E!6(]}8)A(](@MH{YpJf">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                  </block>
                </next>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="procedures_defnoreturn" id="snR_/G-wi#_ID7;.KFrB" x="13" y="638">
    <mutation>
      <arg name="turn distance right" varid="g6iA3~(VkuXpe9n2Bej`"></arg>
    </mutation>
    <field name="NAME">point turn right</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_distance" id="Qq[dJTb4)-*BRZ6qN(,.">
        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
        <field name="DIRECTION">BACKWARD</field>
        <field name="STOP_MODE">BRAKE</field>
        <value name="DISTANCE">
          <shadow type="math_number" id="Fa8,vUo[`N9lKvfwT+Xx">
            <field name="NUM">75</field>
          </shadow>
          <block type="variables_get" id="g2`sKAEAdy9niV5Ks){i">
            <field name="VAR" id="g6iA3~(VkuXpe9n2Bej`">turn distance right</field>
          </block>
        </value>
        <value name="VELOCITY">
          <shadow type="math_number" id="/MmJtb/-2G$qyf:Nso]K">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_distance" id="$LV*-CvwJ~a34,Pr2)})">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="DIRECTION">FORWARD</field>
            <field name="STOP_MODE">BRAKE</field>
            <value name="DISTANCE">
              <shadow type="math_number" id="Fl9M=KVlQf]#=*l/1kHI">
                <field name="NUM">75</field>
              </shadow>
              <block type="variables_get" id="4_sgx-B6VdpLh:jA%jt@">
                <field name="VAR" id="g6iA3~(VkuXpe9n2Bej`">turn distance right</field>
              </block>
            </value>
            <value name="VELOCITY">
              <shadow type="math_number" id="Y-D!,.abv~#QpDEyx4]u">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_motor_wait" id="~zm[+~vD$,^3MFyy26$1">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                <next>
                  <block type="vex_iq_motor_wait" id="-9$IpU=SkbPD2;ktVOty">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                  </block>
                </next>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="procedures_defnoreturn" id="fM)TtY_GB2Z_6@_gxE$V" x="13" y="838">
    <mutation>
      <arg name="turn distance left" varid="e^=Gts{00^|aXi~fw:Tb"></arg>
    </mutation>
    <field name="NAME">point turn left</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="vex_iq_motor_spin_distance" id="M%[SYWTVtj6%E|hmyjRp">
        <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
        <field name="DIRECTION">FORWARD</field>
        <field name="STOP_MODE">BRAKE</field>
        <value name="DISTANCE">
          <shadow type="math_number" id=";(E0R~{]VL{:]TGF:$Wt">
            <field name="NUM">75</field>
          </shadow>
          <block type="variables_get" id="sW}{ZLD-i`IniP?ehj24">
            <field name="VAR" id="e^=Gts{00^|aXi~fw:Tb">turn distance left</field>
          </block>
        </value>
        <value name="VELOCITY">
          <shadow type="math_number" id="47[bakNfAmlB-`]tI-AK">
            <field name="NUM">75</field>
          </shadow>
        </value>
        <next>
          <block type="vex_iq_motor_spin_distance" id="-1|i6#!sXJLp8p7Z0V.b">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="DIRECTION">BACKWARD</field>
            <field name="STOP_MODE">BRAKE</field>
            <value name="DISTANCE">
              <shadow type="math_number" id="(fE/O{3j@!x[~[`TLzOb">
                <field name="NUM">75</field>
              </shadow>
              <block type="variables_get" id="f+632hf8[3]Em63_.Eq*">
                <field name="VAR" id="e^=Gts{00^|aXi~fw:Tb">turn distance left</field>
              </block>
            </value>
            <value name="VELOCITY">
              <shadow type="math_number" id="Vms]Y%|3Mcm{;N!U/DfP">
                <field name="NUM">75</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_motor_wait" id="$@rTYkd2S]zXh4w.x-]r">
                <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
                <next>
                  <block type="vex_iq_motor_wait" id="QK:a!1I)Ds+amU%KiP~B">
                    <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
                  </block>
                </next>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="1038">
    <statement name="DO">
      <block type="procedures_callnoreturn" id="Qq}MAXJ!k40Kf/BLxWyT">
        <mutation name="move until distance">
          <arg name="distance in degrees"></arg>
        </mutation>
        <value name="ARG0">
          <block type="math_number" id="X/l$8dGcDKs=k!z,pccT">
            <field name="NUM">960</field>
          </block>
        </value>
        <next>
          <block type="procedures_callnoreturn" id="KLikU@?:0~,d~2JIA]b5">
            <mutation name="point turn right">
              <arg name="turn distance right"></arg>
            </mutation>
            <value name="ARG0">
              <block type="math_number" id="Aym}V:Bo$p`V6MJlac%O">
                <field name="NUM">960</field>
              </block>
            </value>
            <next>
              <block type="procedures_callnoreturn" id="M_Gg-}(1l=da?VAi@iI6">
                <mutation name="point turn left">
                  <arg name="turn distance left"></arg>
                </mutation>
                <value name="ARG0">
                  <block type="math_number" id="N-QU#m=(2v%|a1VhVH(p">
                    <field name="NUM">960</field>
                  </block>
                </value>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
</xml>
END XML */
