#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor, motor10, arm_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor11, claw_motor, tmotorVexIQ, PIDControl, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float threshold;
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
    threshold = 10;

  }
}

void always2() {
  if (notbetween(getJoystickValue(ChA), -threshold, threshold)) {
    setMotorSpeed(left_motor, (getJoystickValue(ChA)));
  } else {
    setMotorBrakeMode(left_motor, motorCoast);
    setMotorSpeed(left_motor, 0);
  }

}

void always32() {
  if (notbetween(getJoystickValue(ChD), -threshold, threshold)) {
    setMotorSpeed(right_motor, (getJoystickValue(ChD)));
  } else {
    setMotorBrakeMode(right_motor, motorCoast);
    setMotorSpeed(right_motor, 0);
  }

}

void always42() {
  if (getJoystickValue(BtnLUp)) {
    setMotorSpeed(arm_motor, -100);
  } else if (getJoystickValue(BtnLDown)) {
    setMotorSpeed(arm_motor, 100);
  } else {
    setMotorBrakeMode(arm_motor, motorHold);
    setMotorSpeed(arm_motor, 0);
  }

}



task main() {
  activate_event(start);
  while(true) {
    on_start2();
    always2();
    always32();
    always42();

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
    <variable id="h5!zdxA0SxPI63X-k[TY">threshold</variable>
  </variables>
  <block type="vex_iq_brain" id="%y[i=TI^e=S5W5q!.w0+" x="13" y="13">
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
      <block type="vex_iq_motor" id="n@7f(@%z`QZIt1.aI6f?">
        <field name="DIRECTION">FORWARD</field>
      </block>
    </value>
    <value name="PORT_6">
      <block type="vex_iq_motor" id="{PF=KUcv-4IZ6m#NvjFx">
        <field name="DIRECTION">REVERSE</field>
      </block>
    </value>
    <value name="PORT_10">
      <block type="vex_iq_motor" id="LIO_nj|xpF25lAwGnrib">
        <field name="DIRECTION">FORWARD</field>
      </block>
    </value>
    <value name="PORT_11">
      <block type="vex_iq_motor" id="NTPU+LN2]/7k,PwGn2sb">
        <field name="DIRECTION">FORWARD</field>
      </block>
    </value>
  </block>
  <block type="events_on_start" id="unu4LZ=;_A{(*fR6uw~y" x="13" y="388">
    <statement name="DO">
      <block type="variables_set" id="/zT0c07Km|TJHIloN_6;">
        <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
        <value name="VALUE">
          <block type="math_number" id="xV6M$BMiH,3p#$O]+@Zi">
            <field name="NUM">10</field>
          </block>
        </value>
      </block>
    </statement>
  </block>
  <block type="events_always" id=")]:q!gVH*Wc~xl|H58|6" x="13" y="488">
    <statement name="DO">
      <block type="controls_if" id="$Z^SK^u|Y|.YIVY]|)Xj">
        <mutation else="1"></mutation>
        <value name="IF0">
          <block type="logic_between" id="T0pytOXuAO}*1W)1N+]8">
            <field name="OPERATOR">NOT_BETWEEN</field>
            <value name="VALUE">
              <block type="vex_iq_controller_joystick_position" id="@1cls_Ed+4^i|!i[Cpa_">
                <field name="JOYSTICK">LEFT</field>
                <field name="AXIS">VERTICAL</field>
              </block>
            </value>
            <value name="BOUND1">
              <shadow type="math_number" id="=aL:(Y_aR`6N*]((hVWu">
                <field name="NUM">0</field>
              </shadow>
              <block type="math_single" id="d@Gk-G9;nj26{B;h,n`u">
                <field name="OP">NEG</field>
                <value name="NUM">
                  <shadow type="math_number" id="r:aF2rcu?IBtXo)Z{@CH">
                    <field name="NUM">9</field>
                  </shadow>
                  <block type="variables_get" id="0.Q;)M1s}nL5d+}Uc,7m">
                    <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
                  </block>
                </value>
              </block>
            </value>
            <value name="BOUND2">
              <shadow type="math_number" id="mK!k9BXaTP?~.Gy8:Syq">
                <field name="NUM">10</field>
              </shadow>
              <block type="variables_get" id="z!:Hd60zDNGZj__5,nR^">
                <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
              </block>
            </value>
          </block>
        </value>
        <statement name="DO0">
          <block type="vex_iq_motor_spin_velocity" id="V}%pt!=Q7(@hismu,cL1">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="%)]ws@3Q+?LM_E4wgTS{">
                <field name="NUM">100</field>
              </shadow>
              <block type="vex_iq_controller_joystick_position" id="~pMvj|sDK55R7bor:mG-">
                <field name="JOYSTICK">LEFT</field>
                <field name="AXIS">VERTICAL</field>
              </block>
            </value>
          </block>
        </statement>
        <statement name="ELSE">
          <block type="vex_iq_motor_stop" id="q?CbPnvg,%HR,]^dUN=4">
            <field name="MOTOR" id="2C_w(9X|eyDoXJZtSlGb">left motor</field>
            <field name="STOP_MODE">COAST</field>
          </block>
        </statement>
      </block>
    </statement>
  </block>
  <block type="events_always" id="`f_0C1O][j2}m$v1_ycf" x="13" y="688">
    <statement name="DO">
      <block type="controls_if" id="wT`-@;l*-[{iN8=`8`8$">
        <mutation else="1"></mutation>
        <value name="IF0">
          <block type="logic_between" id="|50CPlD7_$Coi?{`#dVT">
            <field name="OPERATOR">NOT_BETWEEN</field>
            <value name="VALUE">
              <block type="vex_iq_controller_joystick_position" id="71|nhEBjGkDhVkjh%Q]m">
                <field name="JOYSTICK">RIGHT</field>
                <field name="AXIS">VERTICAL</field>
              </block>
            </value>
            <value name="BOUND1">
              <shadow type="math_number">
                <field name="NUM">0</field>
              </shadow>
              <block type="math_single" id="]-S?ZBfwW#RDgE;^ZE2w">
                <field name="OP">NEG</field>
                <value name="NUM">
                  <shadow type="math_number">
                    <field name="NUM">9</field>
                  </shadow>
                  <block type="variables_get" id="L]/^F/l^N$l|ZA#oryd:">
                    <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
                  </block>
                </value>
              </block>
            </value>
            <value name="BOUND2">
              <shadow type="math_number">
                <field name="NUM">10</field>
              </shadow>
              <block type="variables_get" id="u!#av{9l6:+eS%d1:q_p">
                <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
              </block>
            </value>
          </block>
        </value>
        <statement name="DO0">
          <block type="vex_iq_motor_spin_velocity" id="m!+e?JA5f{T})Iar%A7,">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number">
                <field name="NUM">100</field>
              </shadow>
              <block type="vex_iq_controller_joystick_position" id="p8kO8x;Tgn.=dkGy1S@u">
                <field name="JOYSTICK">RIGHT</field>
                <field name="AXIS">VERTICAL</field>
              </block>
            </value>
          </block>
        </statement>
        <statement name="ELSE">
          <block type="vex_iq_motor_stop" id="8~pknI@^;EyR4bvp+,(n">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="STOP_MODE">COAST</field>
          </block>
        </statement>
      </block>
    </statement>
  </block>
  <block type="events_always" id="?{,eq!/oY~wOAi+KVq9z" x="13" y="888">
    <statement name="DO">
      <block type="controls_if" id="`)DoL9GCg,EyS=hrMzg[">
        <mutation elseif="1" else="1"></mutation>
        <value name="IF0">
          <block type="vex_iq_controller_button_pressed" id="pb|vqNh[[+._zZAhh}Cb">
            <field name="BUTTON">L_UP</field>
          </block>
        </value>
        <statement name="DO0">
          <block type="vex_iq_motor_spin_velocity" id="(;xO?=Y,$P[k0`eJJqX(">
            <field name="MOTOR" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
            <field name="DIRECTION">BACKWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="uo)OC7+?M?Q%HDK?un/f">
                <field name="NUM">100</field>
              </shadow>
            </value>
          </block>
        </statement>
        <value name="IF1">
          <block type="vex_iq_controller_button_pressed" id="8$r0Nt-2Ky0Uwd{Q:~#1">
            <field name="BUTTON">L_DOWN</field>
          </block>
        </value>
        <statement name="DO1">
          <block type="vex_iq_motor_spin_velocity" id="}vHo@ak]TZdY9+D@LjM$">
            <field name="MOTOR" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="ero5!10~EWH!(_sF^R/7">
                <field name="NUM">100</field>
              </shadow>
            </value>
          </block>
        </statement>
        <statement name="ELSE">
          <block type="vex_iq_motor_stop" id="}OhcU1.zydbHx%i%GixY">
            <field name="MOTOR" id="UCC-Z#0}d85!qaB^`*EY">arm motor</field>
            <field name="STOP_MODE">HOLD</field>
          </block>
        </statement>
      </block>
    </statement>
  </block>
</xml>
END XML */
