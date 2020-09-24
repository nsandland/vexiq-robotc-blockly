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

// Describe this function...
task one() {
  while (true) {
    displayTextLine(0, "Task ONE: /    |", );
    sleep(75);
    displayTextLine(0, "Task ONE:  -   /", );
    sleep(75);
    displayTextLine(0, "Task ONE:   -  -", );
    sleep(75);
    displayTextLine(0, "Task ONE:    \\ \\", );
    sleep(75);
  }
}

// Describe this function...
task two() {
  while (true) {
    displayTextLine(1, "Task TWO:    / |", );
    sleep(75);
    displayTextLine(1, "Task TWO:   -  \\", );
    sleep(75);
    displayTextLine(1, "Task TWO:  -   -", );
    sleep(75);
    displayTextLine(1, "Task TWO: \\    /", );
    sleep(75);
  }
}

void on_start2() {
  if (event_is_active(start)) {
    startTask(one);
    startTask(two);

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
  </variables>
  <block type="comment_block" id="BY;OUrM=iJ$6?3|]559]" x="13" y="13">
    <field name="NAME">This program will run two tasks simulatenously,</field>
    <next>
      <block type="comment_block" id=":$e2Fm4WXB~|():VfM0Z">
        <field name="NAME">showing the ability to have your robot complete</field>
        <next>
          <block type="comment_block" id="T!]f`cAMp]bPu+ni[{s7">
            <field name="NAME">multiple objectives/tasks at the same time. This</field>
            <next>
              <block type="comment_block" id="ZdePMFemts1nH{vj1n%#">
                <field name="NAME">is illustrated by displaying characters on the</field>
                <next>
                  <block type="comment_block" id="tvK|gppaoIz-O|=DRu@s">
                    <field name="NAME">VEX IQ's LCD Screen to show the two tasks</field>
                    <next>
                      <block type="comment_block" id="7z+6ZqHC#7TWp=1X4BGj">
                        <field name="NAME">running at the same time.</field>
                        <next>
                          <block type="comment_block" id="Ye6bj{Mk]s4ml8R5.gtX">
                            <field name="NAME"></field>
                            <next>
                              <block type="comment_block" id=":?K6;1.9Ln2{p3$(`@ny">
                                <field name="NAME">In each task is a number of "sleep" commands -</field>
                                <next>
                                  <block type="comment_block" id="7^1I07.U8f0[c%)9Q[=t">
                                    <field name="NAME">these commands yield the processor for a</field>
                                    <next>
                                      <block type="comment_block" id="yfQYEy]{-pU@L0HjH=3H">
                                        <field name="NAME">specific amount of time to allow other tasks to</field>
                                        <next>
                                          <block type="comment_block" id="7qo[6%zq{0Mw{:6_YG`M">
                                            <field name="NAME"> run.</field>
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
  <block type="vex_iq_brain" id="(^W84*BmMq_oQZrg1R28" x="13" y="338">
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
  <block type="procedures_deftask" id=")CVq:$v^Ph`z;zI$4||^" x="13" y="713">
    <field name="NAME">one</field>
    <field name="IS_TASK">asynchronously</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="controls_whileUntil" id="!j~GENE29.C|fQyKlVYI">
        <field name="MODE">WHILE</field>
        <value name="BOOL">
          <block type="logic_boolean" id="9)iNQHJwsVzyk`QTM:Z[">
            <field name="BOOL">TRUE</field>
          </block>
        </value>
        <statement name="DO">
          <block type="vex_iq_lcd_print" id="*3tR.gFoa6V+m3[_Mc.W">
            <mutation vars="0"></mutation>
            <field name="TEXT0">Task ONE: /    |</field>
            <field name="LINE">0</field>
            <next>
              <block type="vex_iq_sleep" id="2oeEdD{g4^0dRG+R(8=L">
                <value name="DURATION">
                  <shadow type="math_number" id="#nrBkZhhG`91QgZl]enF">
                    <field name="NUM">75</field>
                  </shadow>
                </value>
                <next>
                  <block type="vex_iq_lcd_print" id="$EV$C_8/U0m7?DX!!_Di">
                    <mutation vars="0"></mutation>
                    <field name="TEXT0">Task ONE:  -   /</field>
                    <field name="LINE">0</field>
                    <next>
                      <block type="vex_iq_sleep" id="ebCq5?EfX=GnN1(puJL=">
                        <value name="DURATION">
                          <shadow type="math_number" id="a(x#sPC`rHKOw1jl#WI=">
                            <field name="NUM">75</field>
                          </shadow>
                        </value>
                        <next>
                          <block type="vex_iq_lcd_print" id="3=!P6oCD:yzjB9f}Dr3j">
                            <mutation vars="0"></mutation>
                            <field name="TEXT0">Task ONE:   -  -</field>
                            <field name="LINE">0</field>
                            <next>
                              <block type="vex_iq_sleep" id="Y;HX2r}BgBTNcE@Ng[c9">
                                <value name="DURATION">
                                  <shadow type="math_number" id="DIph8ob2WcrCGQH!Z0cr">
                                    <field name="NUM">75</field>
                                  </shadow>
                                </value>
                                <next>
                                  <block type="vex_iq_lcd_print" id="xWT+*Q9wN@m)98pp{{;l">
                                    <mutation vars="0"></mutation>
                                    <field name="TEXT0">Task ONE:    \ \</field>
                                    <field name="LINE">0</field>
                                    <next>
                                      <block type="vex_iq_sleep" id="[:{o0IoOjoXz}.Ba|;%i">
                                        <value name="DURATION">
                                          <shadow type="math_number" id="978_i2inPSc;Nq$O5~t2">
                                            <field name="NUM">75</field>
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
    </statement>
  </block>
  <block type="procedures_deftask" id="z$?v.85mkspGccYojK,j" x="13" y="1063">
    <field name="NAME">two</field>
    <field name="IS_TASK">asynchronously</field>
    <comment pinned="false" h="80" w="160">Describe this function...</comment>
    <statement name="STACK">
      <block type="controls_whileUntil" id="Gm[LEuo)v~yVu.B4Gn_{">
        <field name="MODE">WHILE</field>
        <value name="BOOL">
          <block type="logic_boolean" id="b$V2$w%G,La`4H0ETI~1">
            <field name="BOOL">TRUE</field>
          </block>
        </value>
        <statement name="DO">
          <block type="vex_iq_lcd_print" id=")9K2,@;D)}nMF,$$T`wz">
            <mutation vars="0"></mutation>
            <field name="TEXT0">Task TWO:    / |</field>
            <field name="LINE">1</field>
            <next>
              <block type="vex_iq_sleep" id="V%hyLGx|ov~0e4~R1aN)">
                <value name="DURATION">
                  <shadow type="math_number" id="Pn*BIG8U@hUU~p5Bs/+h">
                    <field name="NUM">75</field>
                  </shadow>
                </value>
                <next>
                  <block type="vex_iq_lcd_print" id="RQ*la@{.O-#oRlvOWA-:">
                    <mutation vars="0"></mutation>
                    <field name="TEXT0">Task TWO:   -  \</field>
                    <field name="LINE">1</field>
                    <next>
                      <block type="vex_iq_sleep" id="ubPqZdlAJmqacAH}5odc">
                        <value name="DURATION">
                          <shadow type="math_number" id="I(vUZdHK?k$f;$dOpYlp">
                            <field name="NUM">75</field>
                          </shadow>
                        </value>
                        <next>
                          <block type="vex_iq_lcd_print" id=";a(JP+H=%kV:qYYFK`v!">
                            <mutation vars="0"></mutation>
                            <field name="TEXT0">Task TWO:  -   -</field>
                            <field name="LINE">1</field>
                            <next>
                              <block type="vex_iq_sleep" id="S,9eD6D|.qsc!CRERA$:">
                                <value name="DURATION">
                                  <shadow type="math_number" id="FK:L}t~4(hq/%ZSh9e|l">
                                    <field name="NUM">75</field>
                                  </shadow>
                                </value>
                                <next>
                                  <block type="vex_iq_lcd_print" id="M2s=KYIRg`gc5fQa[^Am">
                                    <mutation vars="0"></mutation>
                                    <field name="TEXT0">Task TWO: \    /</field>
                                    <field name="LINE">1</field>
                                    <next>
                                      <block type="vex_iq_sleep" id="+$l0T*U}-dYLNzW:iaT{">
                                        <value name="DURATION">
                                          <shadow type="math_number" id="VIr6?{itC[q{DJ.YEY!A">
                                            <field name="NUM">75</field>
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
    </statement>
  </block>
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="13" y="1413">
    <statement name="DO">
      <block type="comment_block" id="rzgF9Q|;_e2aexHLgXJQ">
        <field name="NAME">Remove either of these two lines to see a Task</field>
        <next>
          <block type="comment_block" id="JFZi,iO$3,onBmD-=!-c">
            <field name="NAME">running individually</field>
            <next>
              <block type="procedures_startstoptask" id="T4_ys5T(?.`|@Y`)#Jfk">
                <mutation name="one"></mutation>
                <field name="ACTION">START</field>
                <next>
                  <block type="procedures_startstoptask" id="/bl#hf70v[l*R-3{kLiG">
                    <mutation name="two"></mutation>
                    <field name="ACTION">START</field>
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
