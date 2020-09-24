#pragma config(Motor, motor1, left_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, right_motor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor, motor10, arm_motor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor11, claw_motor, tmotorVexIQ, PIDControl, encoder)

typedef ubyte Event;


typedef struct {
  float x;
  float y;
} Point;

float joystick_position, threshold, left_speed, right_speed;
Event start;

float exceeds_threshold(float joystick_position);

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
    threshold = 10;
    left_speed = 0;
    right_speed = 0;

  }
}

void always2() {
  left_speed = getJoystickValue(ChA) + getJoystickValue(ChB) / 2;
  right_speed = getJoystickValue(ChA) - getJoystickValue(ChB) / 2;

}

void always32() {
  if (exceeds_threshold(left_speed)) {
    setMotorSpeed(left_motor, left_speed);
  } else {
    setMotorBrakeMode(left_motor, motorCoast);
    setMotorSpeed(left_motor, 0);
  }

}

void always42() {
  if (exceeds_threshold(right_speed)) {
    setMotorSpeed(right_motor, right_speed);
  } else {
    setMotorBrakeMode(right_motor, motorCoast);
    setMotorSpeed(right_motor, 0);
  }

}

void always52() {
  if (getJoystickValue(BtnLUp)) {
    setMotorSpeed(arm_motor, -100);
  } else if (getJoystickValue(BtnLDown)) {
    setMotorSpeed(arm_motor, 100);
  } else {
    setMotorBrakeMode(arm_motor, motorHold);
    setMotorSpeed(arm_motor, 0);
  }

}

void always62() {
  if (getJoystickValue(BtnRUp)) {
    setMotorSpeed(claw_motor, -100);
  } else if (getJoystickValue(BtnRDown)) {
    setMotorSpeed(claw_motor, 100);
  } else {
    setMotorBrakeMode(claw_motor, motorHold);
    setMotorSpeed(claw_motor, 0);
  }

}

// Describe this function...
float exceeds_threshold(float joystick_position) {
  return joystick_position > threshold || joystick_position < -threshold;
}



task main() {
  activate_event(start);
  while(true) {
    on_start2();
    always2();
    always32();
    always42();
    always52();
    always62();

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
    <variable id="6r2!l(wUUb?7kR@4yI9S">joystick position</variable>
    <variable id="h5!zdxA0SxPI63X-k[TY">threshold</variable>
    <variable id="#2%#m/]}mGB9ce;wY=z`">left speed</variable>
    <variable id="`^5*YMper9%GDU{GEr#V">right speed</variable>
  </variables>
  <block type="vex_iq_brain" id="%y[i=TI^e=S5W5q!.w0+" x="13" y="88">
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
  <block type="events_on_start" id="unu4LZ=;_A{(*fR6uw~y" x="13" y="463">
    <statement name="DO">
      <block type="variables_set" id="/zT0c07Km|TJHIloN_6;">
        <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
        <value name="VALUE">
          <block type="math_number" id="xV6M$BMiH,3p#$O]+@Zi">
            <field name="NUM">10</field>
          </block>
        </value>
        <next>
          <block type="variables_set" id="VmliC|y3.x2PHQ-F#|`*">
            <field name="VAR" id="#2%#m/]}mGB9ce;wY=z`">left speed</field>
            <value name="VALUE">
              <block type="math_number" id="T~CqneAy056**@eum39p">
                <field name="NUM">0</field>
              </block>
            </value>
            <next>
              <block type="variables_set" id="CnPMl9ay%5RGlj6`?H_Z">
                <field name="VAR" id="`^5*YMper9%GDU{GEr#V">right speed</field>
                <value name="VALUE">
                  <block type="math_number" id="7669b.{lfNoeF9CXA^O8">
                    <field name="NUM">0</field>
                  </block>
                </value>
              </block>
            </next>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="events_always" id="}@B~$VOG`.Vx%#fCUCgg" x="13" y="738">
    <statement name="DO">
      <block type="variables_set" id="`mnYLi~TIDfimC)hGSHP">
        <field name="VAR" id="#2%#m/]}mGB9ce;wY=z`">left speed</field>
        <value name="VALUE">
          <block type="math_arithmetic" id="bT$2$.,(:R%0jzsvJ$W~">
            <field name="OP">ADD</field>
            <value name="A">
              <shadow type="math_number" id="sFc*CE1.u,TV^Bql,eJO">
                <field name="NUM">1</field>
              </shadow>
              <block type="vex_iq_controller_joystick_position" id="UBMUIv:T$C[.d.nHRh%?">
                <field name="JOYSTICK">LEFT</field>
                <field name="AXIS">VERTICAL</field>
              </block>
            </value>
            <value name="B">
              <shadow type="math_number" id="@S)h:ERV}s6riXV`*pQ@">
                <field name="NUM">1</field>
              </shadow>
              <block type="math_arithmetic" id="B(REi_bUwE=u=_:;V;Oo">
                <field name="OP">DIVIDE</field>
                <value name="A">
                  <shadow type="math_number" id=")Vz|UHv]~aYe[xtaz^!$">
                    <field name="NUM">1</field>
                  </shadow>
                  <block type="vex_iq_controller_joystick_position" id="}[lTE7:U?GW5Q#t:zJpy">
                    <field name="JOYSTICK">LEFT</field>
                    <field name="AXIS">HORIZONTAL</field>
                  </block>
                </value>
                <value name="B">
                  <shadow type="math_number" id="=ume9svq?T)d/P/QtVW%">
                    <field name="NUM">2</field>
                  </shadow>
                </value>
              </block>
            </value>
          </block>
        </value>
        <next>
          <block type="variables_set" id="Id:;ch_+F;q|}W/2AsoZ">
            <field name="VAR" id="`^5*YMper9%GDU{GEr#V">right speed</field>
            <value name="VALUE">
              <block type="math_arithmetic" id="h[XlHWz4@85~AO1O667o">
                <field name="OP">MINUS</field>
                <value name="A">
                  <shadow type="math_number">
                    <field name="NUM">1</field>
                  </shadow>
                  <block type="vex_iq_controller_joystick_position" id="4`AW(0|P2sf~:aU439zW">
                    <field name="JOYSTICK">LEFT</field>
                    <field name="AXIS">VERTICAL</field>
                  </block>
                </value>
                <value name="B">
                  <shadow type="math_number">
                    <field name="NUM">1</field>
                  </shadow>
                  <block type="math_arithmetic" id="{.h2Q-mT!/X9oUB_2B_a">
                    <field name="OP">DIVIDE</field>
                    <value name="A">
                      <shadow type="math_number">
                        <field name="NUM">1</field>
                      </shadow>
                      <block type="vex_iq_controller_joystick_position" id="RV}?6:F@pYDSvA/PfpoG">
                        <field name="JOYSTICK">LEFT</field>
                        <field name="AXIS">HORIZONTAL</field>
                      </block>
                    </value>
                    <value name="B">
                      <shadow type="math_number" id="ez5Y:o-z;B9ZfM-)zueW">
                        <field name="NUM">2</field>
                      </shadow>
                    </value>
                  </block>
                </value>
              </block>
            </value>
          </block>
        </next>
      </block>
    </statement>
  </block>
  <block type="events_always" id=")]:q!gVH*Wc~xl|H58|6" x="13" y="913">
    <statement name="DO">
      <block type="controls_if" id="$Z^SK^u|Y|.YIVY]|)Xj">
        <mutation else="1"></mutation>
        <value name="IF0">
          <block type="procedures_callreturn" id="2lv`|g@U6N/Qsh}xDw7R">
            <mutation name="exceeds threshold">
              <arg name="joystick position"></arg>
            </mutation>
            <value name="ARG0">
              <block type="variables_get" id="~#HU^E.RK/xP(N?Dh;_v">
                <field name="VAR" id="#2%#m/]}mGB9ce;wY=z`">left speed</field>
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
              <block type="variables_get" id="?gV9BPE}scX!=_l6+y35">
                <field name="VAR" id="#2%#m/]}mGB9ce;wY=z`">left speed</field>
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
  <block type="events_always" id="`f_0C1O][j2}m$v1_ycf" x="13" y="1113">
    <statement name="DO">
      <block type="controls_if" id="wT`-@;l*-[{iN8=`8`8$">
        <mutation else="1"></mutation>
        <value name="IF0">
          <block type="procedures_callreturn" id="UY]H2^C)#w74deS0VET=">
            <mutation name="exceeds threshold">
              <arg name="joystick position"></arg>
            </mutation>
            <value name="ARG0">
              <block type="variables_get" id="#!y282%{L-xIe~v5nqco">
                <field name="VAR" id="`^5*YMper9%GDU{GEr#V">right speed</field>
              </block>
            </value>
          </block>
        </value>
        <statement name="DO0">
          <block type="vex_iq_motor_spin_velocity" id="m!+e?JA5f{T})Iar%A7,">
            <field name="MOTOR" id="|}5]3]?#UB6;p-p@$?Zo">right motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="3lD/tg=vd~`KX7-wMY/~">
                <field name="NUM">100</field>
              </shadow>
              <block type="variables_get" id=")RfS6652oho|,]*0.D[@">
                <field name="VAR" id="`^5*YMper9%GDU{GEr#V">right speed</field>
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
  <block type="events_always" id="?{,eq!/oY~wOAi+KVq9z" x="13" y="1313">
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
  <block type="events_always" id="h4kcxe+x7C!%xmCCwa!_" x="13" y="1563">
    <statement name="DO">
      <block type="controls_if" id="ujgE^`xq6kBb*6rio`rE">
        <mutation elseif="1" else="1"></mutation>
        <value name="IF0">
          <block type="vex_iq_controller_button_pressed" id="GrU:%QF#gy6[tw+n#`PJ">
            <field name="BUTTON">R_UP</field>
          </block>
        </value>
        <statement name="DO0">
          <block type="vex_iq_motor_spin_velocity" id="5jj^T~xo}whi0cXcRZIS">
            <field name="MOTOR" id="Sq;4ZphrM!WA8xQBm)1F">claw motor</field>
            <field name="DIRECTION">BACKWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="ljE@qDHgR~]ID5{;j)p~">
                <field name="NUM">100</field>
              </shadow>
            </value>
          </block>
        </statement>
        <value name="IF1">
          <block type="vex_iq_controller_button_pressed" id="vo;NUNht]:I3zh0CFJ5`">
            <field name="BUTTON">R_DOWN</field>
          </block>
        </value>
        <statement name="DO1">
          <block type="vex_iq_motor_spin_velocity" id="Z.IRt2OCi$p1uS3KT)6T">
            <field name="MOTOR" id="Sq;4ZphrM!WA8xQBm)1F">claw motor</field>
            <field name="DIRECTION">FORWARD</field>
            <value name="VELOCITY">
              <shadow type="math_number" id="}X$/D03QP7t(gqpakm{/">
                <field name="NUM">100</field>
              </shadow>
            </value>
          </block>
        </statement>
        <statement name="ELSE">
          <block type="vex_iq_motor_stop" id=".i7dNjmvgC?qoB_@S!V1">
            <field name="MOTOR" id="Sq;4ZphrM!WA8xQBm)1F">claw motor</field>
            <field name="STOP_MODE">HOLD</field>
          </block>
        </statement>
      </block>
    </statement>
  </block>
  <block type="procedures_defreturn" id="/7ceJJ2N^/8b|jb(7B:/" x="13" y="1813">
    <mutation statements="false">
      <arg name="joystick position" varid="6r2!l(wUUb?7kR@4yI9S"></arg>
    </mutation>
    <field name="NAME">exceeds threshold</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <value name="RETURN">
      <block type="logic_operation" id="_F^hK394eir8aUiV(e/.">
        <field name="OP">OR</field>
        <value name="A">
          <block type="logic_compare" id="_bn]0l?X_.DhMSeld0X#">
            <field name="OP">GT</field>
            <value name="A">
              <block type="variables_get" id="59uf}^:DcT9#FpK=|39z">
                <field name="VAR" id="6r2!l(wUUb?7kR@4yI9S">joystick position</field>
              </block>
            </value>
            <value name="B">
              <block type="variables_get" id="z!:Hd60zDNGZj__5,nR^">
                <field name="VAR" id="h5!zdxA0SxPI63X-k[TY">threshold</field>
              </block>
            </value>
          </block>
        </value>
        <value name="B">
          <block type="logic_compare" id="ATbz8i@S5+uv7#~N4m+}">
            <field name="OP">LT</field>
            <value name="A">
              <block type="variables_get" id="FW}~[OzB^b4xV+$,fAVN">
                <field name="VAR" id="6r2!l(wUUb?7kR@4yI9S">joystick position</field>
              </block>
            </value>
            <value name="B">
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
          </block>
        </value>
      </block>
    </value>
  </block>
</xml>
END XML */
