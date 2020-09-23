
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
    playNote(noteC, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteCSharp, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteD, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteDSharp, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteE, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteF, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteFSharp, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteG, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(undefined, octave1, ceil(15) / 100.0));
    sleep(15);
    playNote(noteA, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteASharp, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteB, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteC, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteCSharp, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteD, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteDSharp, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteE, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteF, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteFSharp, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteG, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(undefined, octave2, ceil(15) / 100.0));
    sleep(15);
    playNote(noteA, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteASharp, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteB, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteC, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteCSharp, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteD, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteDSharp, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteE, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteF, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteFSharp, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(noteG, octave3, ceil(15) / 100.0));
    sleep(15);
    playNote(undefined, octave3, ceil(15) / 100.0));
    sleep(15);

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
  <block type="events_on_start" id="K$86O_u9#5nTErm18@jK" x="-112" y="213">
    <statement name="DO">
      <block type="vex_iq_brain_play_note" id="JlD;I7Vo:9`o17G5g?B3">
        <field name="NOTE">C</field>
        <field name="OCTAVE">1</field>
        <value name="DURATION">
          <block type="math_number" id="tnRLdrg|iKBkrQ}@^}mc">
            <field name="NUM">15</field>
          </block>
        </value>
        <next>
          <block type="vex_iq_sleep" id="4$6GFJp;PbrOce5APO5W">
            <value name="DURATION">
              <shadow type="math_number" id="e~-8Q,o4!9CKS0mlv@Gf">
                <field name="NUM">15</field>
              </shadow>
            </value>
            <next>
              <block type="vex_iq_brain_play_note" id="x@2aw{tEj^}edm=IXCnA">
                <field name="NOTE">C_SHARP</field>
                <field name="OCTAVE">1</field>
                <value name="DURATION">
                  <block type="math_number" id="vm1R*SfUi)eB.b7MZSq4">
                    <field name="NUM">15</field>
                  </block>
                </value>
                <next>
                  <block type="vex_iq_sleep" id="}V^D.J9q~?o~hl`NA-|}">
                    <value name="DURATION">
                      <shadow type="math_number" id="+rAF-j,!q[{rO6l5BcOf">
                        <field name="NUM">15</field>
                      </shadow>
                    </value>
                    <next>
                      <block type="vex_iq_brain_play_note" id="U5jJ;iUT??*|t}y.3*d`">
                        <field name="NOTE">D</field>
                        <field name="OCTAVE">1</field>
                        <value name="DURATION">
                          <block type="math_number" id="d$@?GBVVP,c4,O-Vm1xb">
                            <field name="NUM">15</field>
                          </block>
                        </value>
                        <next>
                          <block type="vex_iq_sleep" id="j@0HA4H0]2FB?`?]XG!H">
                            <value name="DURATION">
                              <shadow type="math_number" id="ibStk@V|[NJ52f}R4MPp">
                                <field name="NUM">15</field>
                              </shadow>
                            </value>
                            <next>
                              <block type="vex_iq_brain_play_note" id="]+q4.#{`!9Ka9YCdG)EI">
                                <field name="NOTE">D_SHARP</field>
                                <field name="OCTAVE">1</field>
                                <value name="DURATION">
                                  <block type="math_number" id="3UwgsU_kjMoAPiEP[2CW">
                                    <field name="NUM">15</field>
                                  </block>
                                </value>
                                <next>
                                  <block type="vex_iq_sleep" id="y)AG*6f$[kpf/TPWgX/`">
                                    <value name="DURATION">
                                      <shadow type="math_number" id="^^L]0/^kIso*J.7P6J14">
                                        <field name="NUM">15</field>
                                      </shadow>
                                    </value>
                                    <next>
                                      <block type="vex_iq_brain_play_note" id="b]F0D`/~W:P4vp#T{n/j">
                                        <field name="NOTE">E</field>
                                        <field name="OCTAVE">1</field>
                                        <value name="DURATION">
                                          <block type="math_number" id="AsRfI`/G)$D=@z|El2w_">
                                            <field name="NUM">15</field>
                                          </block>
                                        </value>
                                        <next>
                                          <block type="vex_iq_sleep" id="OjSZKaj.(e`$v?!zRa{@">
                                            <value name="DURATION">
                                              <shadow type="math_number" id="tdi$5yyYXT$!}JrfbUCe">
                                                <field name="NUM">15</field>
                                              </shadow>
                                            </value>
                                            <next>
                                              <block type="vex_iq_brain_play_note" id="?5PJjcJOH^iRWKckvrZc">
                                                <field name="NOTE">F</field>
                                                <field name="OCTAVE">1</field>
                                                <value name="DURATION">
                                                  <block type="math_number" id="3Yc]h5SJeBu6]CE)]fVd">
                                                    <field name="NUM">15</field>
                                                  </block>
                                                </value>
                                                <next>
                                                  <block type="vex_iq_sleep" id="9snGLy*,C,Ld?L_/YjR|">
                                                    <value name="DURATION">
                                                      <shadow type="math_number" id="FDk1O]9#EFlgRw*7/1KO">
                                                        <field name="NUM">15</field>
                                                      </shadow>
                                                    </value>
                                                    <next>
                                                      <block type="vex_iq_brain_play_note" id="J5!omGj^v|7Z{:YY}9|a">
                                                        <field name="NOTE">F_SHARP</field>
                                                        <field name="OCTAVE">1</field>
                                                        <value name="DURATION">
                                                          <block type="math_number" id="R|@3l:-d_{PzG+HCjm*g">
                                                            <field name="NUM">15</field>
                                                          </block>
                                                        </value>
                                                        <next>
                                                          <block type="vex_iq_sleep" id="EKYoNVYo|I/4NC$@1fkr">
                                                            <value name="DURATION">
                                                              <shadow type="math_number" id="?/p#H94nfmApV0C*e0(u">
                                                                <field name="NUM">15</field>
                                                              </shadow>
                                                            </value>
                                                            <next>
                                                              <block type="vex_iq_brain_play_note" id="x0.n=}]9z^ej2$dKio4r">
                                                                <field name="NOTE">G</field>
                                                                <field name="OCTAVE">1</field>
                                                                <value name="DURATION">
                                                                  <block type="math_number" id="EURO5}Feh#C,xJ^P{lv+">
                                                                    <field name="NUM">15</field>
                                                                  </block>
                                                                </value>
                                                                <next>
                                                                  <block type="vex_iq_sleep" id="Ny665.A~f7N35oF7%2qo">
                                                                    <value name="DURATION">
                                                                      <shadow type="math_number" id="qnm6[cC5Y|MTN,!h!!3.">
                                                                        <field name="NUM">15</field>
                                                                      </shadow>
                                                                    </value>
                                                                    <next>
                                                                      <block type="vex_iq_brain_play_note" id="wK+VDhC1xu;f65ef5J.H">
                                                                        <field name="NOTE">G_SHARP</field>
                                                                        <field name="OCTAVE">1</field>
                                                                        <value name="DURATION">
                                                                          <block type="math_number" id="2,D`VcDy)2tk.bR)WIS6">
                                                                            <field name="NUM">15</field>
                                                                          </block>
                                                                        </value>
                                                                        <next>
                                                                          <block type="vex_iq_sleep" id="AcnS(Gj#+yzu@ymB[~W8">
                                                                            <value name="DURATION">
                                                                              <shadow type="math_number" id="x9nCBB=AuH*%xvG@_;b=">
                                                                                <field name="NUM">15</field>
                                                                              </shadow>
                                                                            </value>
                                                                            <next>
                                                                              <block type="vex_iq_brain_play_note" id="q}Dp[+V{GmY[bEsK#v[Y">
                                                                                <field name="NOTE">A</field>
                                                                                <field name="OCTAVE">2</field>
                                                                                <value name="DURATION">
                                                                                  <block type="math_number" id="LF:ni[Y{^/j{,wVkQn)}">
                                                                                    <field name="NUM">15</field>
                                                                                  </block>
                                                                                </value>
                                                                                <next>
                                                                                  <block type="vex_iq_sleep" id="]6BpcT.iy8ltF9_i~qkN">
                                                                                    <value name="DURATION">
                                                                                      <shadow type="math_number" id="=)/GT=!*,B}7_([ut-+,">
                                                                                        <field name="NUM">15</field>
                                                                                      </shadow>
                                                                                    </value>
                                                                                    <next>
                                                                                      <block type="vex_iq_brain_play_note" id="X$FZWt%9k!71O%6.1Le,">
                                                                                        <field name="NOTE">A_SHARP</field>
                                                                                        <field name="OCTAVE">2</field>
                                                                                        <value name="DURATION">
                                                                                          <block type="math_number" id="`1T]|16ko3_*:ejhakjm">
                                                                                            <field name="NUM">15</field>
                                                                                          </block>
                                                                                        </value>
                                                                                        <next>
                                                                                          <block type="vex_iq_sleep" id="!D{u}tQ}:5p:~RA^tp%G">
                                                                                            <value name="DURATION">
                                                                                              <shadow type="math_number" id="Vq~9p`6M3??biCOwP3;s">
                                                                                                <field name="NUM">15</field>
                                                                                              </shadow>
                                                                                            </value>
                                                                                            <next>
                                                                                              <block type="vex_iq_brain_play_note" id="coLZ0v-3@YdL*Q{M@:h@">
                                                                                                <field name="NOTE">B</field>
                                                                                                <field name="OCTAVE">2</field>
                                                                                                <value name="DURATION">
                                                                                                  <block type="math_number" id="D;bb]b4lyfC4^5G,F=r$">
                                                                                                    <field name="NUM">15</field>
                                                                                                  </block>
                                                                                                </value>
                                                                                                <next>
                                                                                                  <block type="vex_iq_sleep" id="PIG5N)PJ17o`o/T9ubSJ">
                                                                                                    <value name="DURATION">
                                                                                                      <shadow type="math_number" id="{fl?gMAP,Jl,+|VU)tmH">
                                                                                                        <field name="NUM">15</field>
                                                                                                      </shadow>
                                                                                                    </value>
                                                                                                    <next>
                                                                                                      <block type="vex_iq_brain_play_note" id="7|KvJCgy3b},TLvKMaOq">
                                                                                                        <field name="NOTE">C</field>
                                                                                                        <field name="OCTAVE">2</field>
                                                                                                        <value name="DURATION">
                                                                                                          <block type="math_number" id="NZQtLMBka_8X%tW,?MO}">
                                                                                                            <field name="NUM">15</field>
                                                                                                          </block>
                                                                                                        </value>
                                                                                                        <next>
                                                                                                          <block type="vex_iq_sleep" id="xg9cmjTHWra8rt,jMSCQ">
                                                                                                            <value name="DURATION">
                                                                                                              <shadow type="math_number" id="L4%.%nH@A^R=avmYQbBo">
                                                                                                                <field name="NUM">15</field>
                                                                                                              </shadow>
                                                                                                            </value>
                                                                                                            <next>
                                                                                                              <block type="vex_iq_brain_play_note" id="X@iBS.#X}BjyvZSId$JC">
                                                                                                                <field name="NOTE">C_SHARP</field>
                                                                                                                <field name="OCTAVE">2</field>
                                                                                                                <value name="DURATION">
                                                                                                                  <block type="math_number" id="#_%!x~i]+G(]U$wd0:a#">
                                                                                                                    <field name="NUM">15</field>
                                                                                                                  </block>
                                                                                                                </value>
                                                                                                                <next>
                                                                                                                  <block type="vex_iq_sleep" id="T_ql(#s`U#xj(BUL!09Q">
                                                                                                                    <value name="DURATION">
                                                                                                                      <shadow type="math_number" id="DUMo!xH7J.qMg!zNf~N2">
                                                                                                                        <field name="NUM">15</field>
                                                                                                                      </shadow>
                                                                                                                    </value>
                                                                                                                    <next>
                                                                                                                      <block type="vex_iq_brain_play_note" id="~gp)AM[,7cSjX)n:Xc2k">
                                                                                                                        <field name="NOTE">D</field>
                                                                                                                        <field name="OCTAVE">2</field>
                                                                                                                        <value name="DURATION">
                                                                                                                          <block type="math_number" id="#;4k2j#X*Gb,YakF^dV1">
                                                                                                                            <field name="NUM">15</field>
                                                                                                                          </block>
                                                                                                                        </value>
                                                                                                                        <next>
                                                                                                                          <block type="vex_iq_sleep" id="7-VEs@hwRN17Gm)[#dXN">
                                                                                                                            <value name="DURATION">
                                                                                                                              <shadow type="math_number" id="CiJT`i!mtC~KBRyo-dnM">
                                                                                                                                <field name="NUM">15</field>
                                                                                                                              </shadow>
                                                                                                                            </value>
                                                                                                                            <next>
                                                                                                                              <block type="vex_iq_brain_play_note" id="=@[_3y|H4l[qIlu$kB2V">
                                                                                                                                <field name="NOTE">D_SHARP</field>
                                                                                                                                <field name="OCTAVE">2</field>
                                                                                                                                <value name="DURATION">
                                                                                                                                  <block type="math_number" id="s?^~yso?,#_cgCmVQS1W">
                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                  </block>
                                                                                                                                </value>
                                                                                                                                <next>
                                                                                                                                  <block type="vex_iq_sleep" id="Q!s*pX%3Fi|6~3l*z`Q8">
                                                                                                                                    <value name="DURATION">
                                                                                                                                      <shadow type="math_number" id=",MqJoA3U#s]*j6{!1,s$">
                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                      </shadow>
                                                                                                                                    </value>
                                                                                                                                    <next>
                                                                                                                                      <block type="vex_iq_brain_play_note" id="-=}#qzr2-}3^j7ml93ih">
                                                                                                                                        <field name="NOTE">E</field>
                                                                                                                                        <field name="OCTAVE">2</field>
                                                                                                                                        <value name="DURATION">
                                                                                                                                          <block type="math_number" id="(6r,e)bVCyKVsI-?*%/(">
                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                          </block>
                                                                                                                                        </value>
                                                                                                                                        <next>
                                                                                                                                          <block type="vex_iq_sleep" id="Uhn}4b;lZ|[sK_DY`Snu">
                                                                                                                                            <value name="DURATION">
                                                                                                                                              <shadow type="math_number" id="l-jKoo,h3Uv[afP9JfKc">
                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                              </shadow>
                                                                                                                                            </value>
                                                                                                                                            <next>
                                                                                                                                              <block type="vex_iq_brain_play_note" id="g+SJKQx]Evfw(?7%G$8g">
                                                                                                                                                <field name="NOTE">F</field>
                                                                                                                                                <field name="OCTAVE">2</field>
                                                                                                                                                <value name="DURATION">
                                                                                                                                                  <block type="math_number" id="PR:e8_nZ0f^Hf6O5/E|6">
                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                  </block>
                                                                                                                                                </value>
                                                                                                                                                <next>
                                                                                                                                                  <block type="vex_iq_sleep" id="6Qo$JjH6_Cf;_+/$=,wR">
                                                                                                                                                    <value name="DURATION">
                                                                                                                                                      <shadow type="math_number" id="::=mcp+)$-8%@;c94W!*">
                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                      </shadow>
                                                                                                                                                    </value>
                                                                                                                                                    <next>
                                                                                                                                                      <block type="vex_iq_brain_play_note" id="r9E6sVXVypbJX7LW~v0P">
                                                                                                                                                        <field name="NOTE">F_SHARP</field>
                                                                                                                                                        <field name="OCTAVE">2</field>
                                                                                                                                                        <value name="DURATION">
                                                                                                                                                          <block type="math_number" id=".x.9idOe8ejpW79C|!U,">
                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                          </block>
                                                                                                                                                        </value>
                                                                                                                                                        <next>
                                                                                                                                                          <block type="vex_iq_sleep" id="gg=Mx(kyrZ:3!c]@N9~w">
                                                                                                                                                            <value name="DURATION">
                                                                                                                                                              <shadow type="math_number" id="/*k_ZG5a2^R`.mdS$VVf">
                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                              </shadow>
                                                                                                                                                            </value>
                                                                                                                                                            <next>
                                                                                                                                                              <block type="vex_iq_brain_play_note" id="GUCw@vQWq,9;lm%z2p$:">
                                                                                                                                                                <field name="NOTE">G</field>
                                                                                                                                                                <field name="OCTAVE">2</field>
                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                  <block type="math_number" id="u8?HbL-nB-SQvP9H7=,U">
                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                  </block>
                                                                                                                                                                </value>
                                                                                                                                                                <next>
                                                                                                                                                                  <block type="vex_iq_sleep" id=",,mbvwt)#P;EFq;i_$on">
                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                      <shadow type="math_number" id="U=XHP.e{W2{qTON)RT{D">
                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                      </shadow>
                                                                                                                                                                    </value>
                                                                                                                                                                    <next>
                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="CN9{Nl+JsrVt8De]e4vr">
                                                                                                                                                                        <field name="NOTE">G_SHARP</field>
                                                                                                                                                                        <field name="OCTAVE">2</field>
                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                          <block type="math_number" id="nO9Xd^CqdFul(-pS`pJp">
                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                          </block>
                                                                                                                                                                        </value>
                                                                                                                                                                        <next>
                                                                                                                                                                          <block type="vex_iq_sleep" id="=AU;L]tME[!I3U/Ck,*P">
                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                              <shadow type="math_number" id="o!#I:S3(BtN9#kE9-MOs">
                                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                                              </shadow>
                                                                                                                                                                            </value>
                                                                                                                                                                            <next>
                                                                                                                                                                              <block type="vex_iq_brain_play_note" id=")*lj8A4]Tlg8:@^}1e5H">
                                                                                                                                                                                <field name="NOTE">A</field>
                                                                                                                                                                                <field name="OCTAVE">3</field>
                                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                                  <block type="math_number" id=".cfH*iWE-#jM%C}:=LMr">
                                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                                  </block>
                                                                                                                                                                                </value>
                                                                                                                                                                                <next>
                                                                                                                                                                                  <block type="vex_iq_sleep" id="95xM2zV#8AeWT,(3U.%s">
                                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                                      <shadow type="math_number" id="g*@0:;DC.[)P%]v2%z1j">
                                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                                      </shadow>
                                                                                                                                                                                    </value>
                                                                                                                                                                                    <next>
                                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="cX#xpo}j1e]$:V;FGNKK">
                                                                                                                                                                                        <field name="NOTE">A_SHARP</field>
                                                                                                                                                                                        <field name="OCTAVE">3</field>
                                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                                          <block type="math_number" id="d#EY=ZIAzy~B{lwlr,bc">
                                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                                          </block>
                                                                                                                                                                                        </value>
                                                                                                                                                                                        <next>
                                                                                                                                                                                          <block type="vex_iq_sleep" id="m2ZGhoOQ9udunr5Dkxby">
                                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                                              <shadow type="math_number" id="CApI:T/EolY4`]e.ZTws">
                                                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                                                              </shadow>
                                                                                                                                                                                            </value>
                                                                                                                                                                                            <next>
                                                                                                                                                                                              <block type="vex_iq_brain_play_note" id="7DUO?_ySdx.Jr}$L{sPb">
                                                                                                                                                                                                <field name="NOTE">B</field>
                                                                                                                                                                                                <field name="OCTAVE">3</field>
                                                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                                                  <block type="math_number" id="I.!w_v.67Hi;q7MG`]i.">
                                                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                                                  </block>
                                                                                                                                                                                                </value>
                                                                                                                                                                                                <next>
                                                                                                                                                                                                  <block type="vex_iq_sleep" id="1n^qg{JzQ!TK:9n:2rOz">
                                                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                                                      <shadow type="math_number" id="HCJt9XL[g6S+b+0L?*h6">
                                                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                                                      </shadow>
                                                                                                                                                                                                    </value>
                                                                                                                                                                                                    <next>
                                                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="6gV|]G[_pFpe$h8pVx))">
                                                                                                                                                                                                        <field name="NOTE">C</field>
                                                                                                                                                                                                        <field name="OCTAVE">3</field>
                                                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                                                          <block type="math_number" id="YZ:|!(xM:d8M|1+nx_Y6">
                                                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                                                          </block>
                                                                                                                                                                                                        </value>
                                                                                                                                                                                                        <next>
                                                                                                                                                                                                          <block type="vex_iq_sleep" id=",-%26=ncVN8lL3n@jYy3">
                                                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                                                              <shadow type="math_number" id="uK8^+xcT)c%LJyK_Mu`P">
                                                                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                                                                              </shadow>
                                                                                                                                                                                                            </value>
                                                                                                                                                                                                            <next>
                                                                                                                                                                                                              <block type="vex_iq_brain_play_note" id="6.V*VZL^~wQ$6Wwn`a%;">
                                                                                                                                                                                                                <field name="NOTE">C_SHARP</field>
                                                                                                                                                                                                                <field name="OCTAVE">3</field>
                                                                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                                                                  <block type="math_number" id="JN|K:VlPNnEkf[u5.q|V">
                                                                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                                                                  </block>
                                                                                                                                                                                                                </value>
                                                                                                                                                                                                                <next>
                                                                                                                                                                                                                  <block type="vex_iq_sleep" id="xx#l1bycUsf/o7[geR3W">
                                                                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                                                                      <shadow type="math_number" id="#K9FMc3-sf#jZ!b3!bqg">
                                                                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                                                                      </shadow>
                                                                                                                                                                                                                    </value>
                                                                                                                                                                                                                    <next>
                                                                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="]MSwhs*w@*qDzLhtNYXE">
                                                                                                                                                                                                                        <field name="NOTE">D</field>
                                                                                                                                                                                                                        <field name="OCTAVE">3</field>
                                                                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                                                                          <block type="math_number" id="AqK_f9M8L_r;nlo)#B?Z">
                                                                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                                                                          </block>
                                                                                                                                                                                                                        </value>
                                                                                                                                                                                                                        <next>
                                                                                                                                                                                                                          <block type="vex_iq_sleep" id="ixrjTm#KpK.Aoyvy8VX!">
                                                                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                                                                              <shadow type="math_number" id="G:z%Z4U;*1hwM:lb]u4V">
                                                                                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                                                                                              </shadow>
                                                                                                                                                                                                                            </value>
                                                                                                                                                                                                                            <next>
                                                                                                                                                                                                                              <block type="vex_iq_brain_play_note" id="+Oh2Fg;(^qlXWFDxTzn_">
                                                                                                                                                                                                                                <field name="NOTE">D_SHARP</field>
                                                                                                                                                                                                                                <field name="OCTAVE">3</field>
                                                                                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                                                                                  <block type="math_number" id="O}.~]ub~pRiMkWXTvvJd">
                                                                                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                                                                                  </block>
                                                                                                                                                                                                                                </value>
                                                                                                                                                                                                                                <next>
                                                                                                                                                                                                                                  <block type="vex_iq_sleep" id="#d{dOQ*787i0z8ULm[*.">
                                                                                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                                                                                      <shadow type="math_number" id=":1g1!7%fzU~b*NF,?6nF">
                                                                                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                                                                                      </shadow>
                                                                                                                                                                                                                                    </value>
                                                                                                                                                                                                                                    <next>
                                                                                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="Z{ZgX-6+q);jD,VIQR.n">
                                                                                                                                                                                                                                        <field name="NOTE">E</field>
                                                                                                                                                                                                                                        <field name="OCTAVE">3</field>
                                                                                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                                                                                          <block type="math_number" id="vwt=Pt})d4}I#SSsVlS|">
                                                                                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                                                                                          </block>
                                                                                                                                                                                                                                        </value>
                                                                                                                                                                                                                                        <next>
                                                                                                                                                                                                                                          <block type="vex_iq_sleep" id="n(]1pc4.Ci:c9Z:6o0}!">
                                                                                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                                                                                              <shadow type="math_number" id="J[@:w1?n#1dznDm|6:ZS">
                                                                                                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                                                                                                              </shadow>
                                                                                                                                                                                                                                            </value>
                                                                                                                                                                                                                                            <next>
                                                                                                                                                                                                                                              <block type="vex_iq_brain_play_note" id="T`rN$upB2ah;XU:!Zg]u">
                                                                                                                                                                                                                                                <field name="NOTE">F</field>
                                                                                                                                                                                                                                                <field name="OCTAVE">3</field>
                                                                                                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                                                                                                  <block type="math_number" id="JqS:,8X$!)DwNs+!?W[b">
                                                                                                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                                                                                                  </block>
                                                                                                                                                                                                                                                </value>
                                                                                                                                                                                                                                                <next>
                                                                                                                                                                                                                                                  <block type="vex_iq_sleep" id="Ly6Yj-+=VGjK44C)]9/:">
                                                                                                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                                                                                                      <shadow type="math_number" id="Ub(kWWfG.n=8*UOU;-f.">
                                                                                                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                                                                                                      </shadow>
                                                                                                                                                                                                                                                    </value>
                                                                                                                                                                                                                                                    <next>
                                                                                                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="|IADZf2u$?ij,UtsRu59">
                                                                                                                                                                                                                                                        <field name="NOTE">F_SHARP</field>
                                                                                                                                                                                                                                                        <field name="OCTAVE">3</field>
                                                                                                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                                                                                                          <block type="math_number" id="{d]voO{:)BMNs0DT3r,p">
                                                                                                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                                                                                                          </block>
                                                                                                                                                                                                                                                        </value>
                                                                                                                                                                                                                                                        <next>
                                                                                                                                                                                                                                                          <block type="vex_iq_sleep" id="pa@bt~FfIYg5yJ`BQ^Nj">
                                                                                                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                                                                                                              <shadow type="math_number" id="oN$4xpQct(~Hmsf9@%P0">
                                                                                                                                                                                                                                                                <field name="NUM">15</field>
                                                                                                                                                                                                                                                              </shadow>
                                                                                                                                                                                                                                                            </value>
                                                                                                                                                                                                                                                            <next>
                                                                                                                                                                                                                                                              <block type="vex_iq_brain_play_note" id="Z,+@NSo;pVg}JOa[y-^R">
                                                                                                                                                                                                                                                                <field name="NOTE">G</field>
                                                                                                                                                                                                                                                                <field name="OCTAVE">3</field>
                                                                                                                                                                                                                                                                <value name="DURATION">
                                                                                                                                                                                                                                                                  <block type="math_number" id=".m)PCS18K%715XQGNCo4">
                                                                                                                                                                                                                                                                    <field name="NUM">15</field>
                                                                                                                                                                                                                                                                  </block>
                                                                                                                                                                                                                                                                </value>
                                                                                                                                                                                                                                                                <next>
                                                                                                                                                                                                                                                                  <block type="vex_iq_sleep" id="@t$29lct7,UI!tw!)CN5">
                                                                                                                                                                                                                                                                    <value name="DURATION">
                                                                                                                                                                                                                                                                      <shadow type="math_number" id="sdvqkobbhF:MIN57G26Q">
                                                                                                                                                                                                                                                                        <field name="NUM">15</field>
                                                                                                                                                                                                                                                                      </shadow>
                                                                                                                                                                                                                                                                    </value>
                                                                                                                                                                                                                                                                    <next>
                                                                                                                                                                                                                                                                      <block type="vex_iq_brain_play_note" id="-(!a+=g#~:~ZlY_8-n72">
                                                                                                                                                                                                                                                                        <field name="NOTE">G_SHARP</field>
                                                                                                                                                                                                                                                                        <field name="OCTAVE">3</field>
                                                                                                                                                                                                                                                                        <value name="DURATION">
                                                                                                                                                                                                                                                                          <block type="math_number" id="HQ9p)`?GYy!pu;g^;8Z-">
                                                                                                                                                                                                                                                                            <field name="NUM">15</field>
                                                                                                                                                                                                                                                                          </block>
                                                                                                                                                                                                                                                                        </value>
                                                                                                                                                                                                                                                                        <next>
                                                                                                                                                                                                                                                                          <block type="vex_iq_sleep" id="4/v*xR4u-6B$(74k=V_5">
                                                                                                                                                                                                                                                                            <value name="DURATION">
                                                                                                                                                                                                                                                                              <shadow type="math_number" id="-ErpnUj5j,!rp;ii{J2e">
                                                                                                                                                                                                                                                                                <field name="NUM">15</field>
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
    </statement>
  </block>
</xml>
END XML */
