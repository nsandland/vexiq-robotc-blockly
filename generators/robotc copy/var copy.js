Blockly.RobotC.vars = `
typedef union {
  long l;
  float f;
  string s;
  bool b;
} valueHolder;

typedef enum td {
  LONG = 1,
  FLOAT = 2,
  STRING = 3,
  BOOL = 4
} typeDefinition;

typedef struct {
  typeDefinition type;
  valueHolder value; 
} var;

void ltov(long l, var &ret) {
  ret.type = LONG;
  ret.value.l = l;
}

void ftov(float f, var &ret) {
  ret.type = FLOAT;
  ret.value.f = f;
}

void stov(string s, var &ret) {
  ret.type = STRING;
  ret.value.s = s;
}

void btov(bool b, var &ret) {
  ret.type = BOOL;
  ret.value.b = b;
}

long vtol(var v) {
  switch (v.type) {
    case LONG:
      return v.value.l;
    case FLOAT:
      return round(v.value.f);
    case STRING:
      return atoi(v.value.s);
    case BOOL:
      return v.value.b ? 1 : 0;
  }
}

float vtof(var v) {
  switch (v.type) {
    case LONG:
      return (float)v.value.l;
    case FLOAT:
      return v.value.f;
    case STRING:
      return atof(v.value.s);
    case BOOL:
      return v.value.b ? 1.0 : 0.0;
  }
}

string vtos(var v) {
  switch (v.type) {
    case LONG:
      sprintf(stringBuffer, "%d", v.value.l);
      return stringBuffer
    case FLOAT:
      sprintf(stringBuffer, "%f", v.value.f);
      return stringBuffer;
    case STRING:
      return v.value.s;
    case BOOL:
      return v.value.b ? "true" : "false";
  }
}

bool vtob(var v) {
  switch (v.type) {
    case LONG:
      return v.value.l != 0;
    case FLOAT:
      return v.value.f != 0.0;
    case STRING:
      return v.value.s == 'true';
    case BOOL:
      return v.value.b;
  }
}

typeDefinition commonRealTypeLogic(var a, var b) {
  if (a.type == STRING || b.type == STRING) {
    return STRING;
  } else if (a.type == FLOAT || b.type == FLOAT) {
    return FLOAT;
  } else if (a.type == LONG || b.type == LONG) {
    return LONG;
  } else {
    return BOOL;
  }
}

typeDefinition commonRealTypeMath(var a, var b) {
  if (a.type == STRING || b.type == STRING || a.type == FLOAT || b.type == FLOAT) {
    return FLOAT;
  } else {
    return LONG;
  }
}

void vset(var target, var source) {
  target.type = source.type;
  switch (source.type) {
    case LONG:
      target.value.l = source.value.l;
      break;
    case FLOAT:
      target.value.f = source.value.f;
      break;
    case STRING:
      target.value.s = source.value.s;
      break;
    case BOOL:
      target.value.b = source.value.b;
      break; 
    }
}

void not(var a, var &ret) {
  btov(!vtob(a), ret);
}

void eq(var a, var b, var &ret) {
  switch (commonRealTypeLogic(a, b)) {
    case LONG:
      btov(vtol(a) == vtol(b), ret);
      break;
    case FLOAT:
      btov(vtof(a) == vtof(b), ret);
      break;
    case STRING:
      btov(vtos(a) == vtos(b), ret);
      break;
    case BOOL:
      btov(vtob(a) == vtob(b), ret);
      break;
  }
}

void ne(var a, var b, var &ret) {
  var eqret;
  eq(a, b, eqret);
  not(eqret, ret);
}

var gt(var a, var b) {
  switch (commonRealTypeLogic(a, b)) {
    case LONG:
      return btov(vtol(a) > vtol(b));
    case FLOAT:
      return btov(vtof(a) > vtof(b));
    case STRING:
      return btov(vtos(a) > vtos(b));
    case BOOL:
      return btov(vtob(a) > vtob(b));
  }
}

var gte(var a, var b) {
  return not(lt(a, b));
}

var lt(var a, var b) {
  switch (commonRealTypeLogic(a, b)) {
    case LONG:
      return btov(vtol(a) < vtol(b));
    case FLOAT:
      return btov(vtof(a) < vtof(b));
    case STRING:
      return btov(vtos(a) < vtos(b));
    case BOOL:
      return btov(vtob(a) < vtob(b));
  }
}

var lte(var a, var b) {
  return not(gt(a, b));
}

var and(var a, var b) {
  return btov(vtob(a) && vtob(b));
}

var or(var a, var b) {
  return btov(vtob(a) && vtob(b));
}

var add(var a, var b) {
  switch (commonRealTypeMath(a, b)) {
    case LONG:
      return ltov(vtol(a) + vtol(b));
    case FLOAT:
      return ftov(vtof(a) + vtof(b));
  }
}

var sub(var a, var b) {
  switch (commonRealTypeMath(a, b)) {
    case LONG:
      return ltov(vtol(a) - vtol(b));
    case FLOAT:
      return ftov(vtof(a) - vtof(b));
  }
}

var mul(var a, var b) {
  switch (commonRealTypeMath(a, b)) {
    case LONG:
      return ltov(vtol(a) * vtol(b));
    case FLOAT:
      return ftov(vtof(a) * vtof(b));
  }
}

var div(var a, var b) {
  return ftov(vtof(a) / vtof(b));
}

var mod(var a, var b) {
  return ftov(vtof(a) % vtof(b));
}

var vpow(var a, var b) {
  return ftov(pow(vtof(a), vtof(b)));
}

var vmin(var a, var b) {
  return vtof(a) < vtof(b) ? a : b;
}

var vmax(var a, var b) {
  return vtof(a) > vtof(b) ? a : b;
}

var vsqrt(var a) {
  return ftov(sqrt(vtof(a)));
}

var vabs(var a) {
  return ftov(abs(vtof(a)));
}

var vln(var a) {
  return ftov(log(vtof(a)));
}

var vlog10(var a) {
  return ftov(log10(vtof(a)));
}

var veexp(var a) {
  return ftov(exp(vtof(a)));
}

var v10exp(var a) {
  return ftov(pow(10.0, vtof(a)));
}

var vsindeg(var a) {
  return ftov(sin(vtof(a) / 180 * PI));
}

var vcosdeg(var a) {
  return ftov(cos(vtof(a) / 180 * PI));
}

var vtandeg(var a) {
  return ftov(tan(vtof(a) / 180 * PI));
}

var vasindeg(var a) {
  return ftov(asin(vtof(a)) / PI * 180);
}

var vacosdeg(var a) {
  return ftov(acos(vtof(a)) / PI * 180);
}

var vatandeg(var a) {
  return ftov(atan(vtof(a)) / PI * 180);
}

var neg(var a) {
  if (a.type == LONG || a.type == BOOL) {
    return ltov(-vtol(a));
  } else {
    return ftov(-vtof(a));
  }
}

var vround(var a) {
  return ftov(floor(vtof(a) + 0.5));
}

var vfloor(var a) {
  return ftov(floor(vtof(a)));
}

var vceil(var a) {
  return ftov(ceil(vtof(a)));
}

var vrand(var min, var max) {
  long minl = vtol(min);
  long maxl = vtol(max);
  return ltov((randLong() % (maxl - minl)) + minl);
}

void addto(var a, var amount) {
  vset(a, add(a, amount));
}

var vbitwiseor(var a, var b) {
  return ltov(vtol(a) | vtol(b));
}

var vbitwiseand(var a, var b) {
  return ltov(vtol(a) & vtol(b));
}

var vstrjoin(var a, var b) {
  strcpy(stringBuffer, vtos(a));
  strcat(stringBuffer, vtos(b));
  return stov(stringBuffer);
}

var vstrcat(var a, var b) {
  return stov(strcat(vtos(a), vtos(b)));
}

var vstrlen(var a) {
  return ltov(strlen(vtos(a)));
}

var vstrempty(var a) {
  return ltob(strlen(vtos(a)) == 0);
}

string stringBuffer;
var TRUE = btov(true);
var FALSE = btov(false);
var ZERO = ltov(0);
var ONE = ltov(1);
var TWO = ltov(2);
var VPI = ftov(PI);
var VE = ftov(exp(1));
var VGOLDEN_RATIO = ftov((1.0 + sqrt(5.0)) / 2.0);
var VSQRT2 = ftov(sqrt(2.0));
var VSQRT1_2 = ftov(1.0 / sqrt(2.0));
var VINFINITY = ftov(INFINITY);
var EMPTY_STRING = stov("");
`;

Blockly.RobotC.addReservedWords(
    'valueHolder,typeDefinition,var,' +
    'ltov,ftov,stov,btov,' +
    'vtol,vtof,vtos,vtob,' + 
    'commonRealTypeLogic,commonRealTypeMath,' + 
    'vset,' +
    'eq,ne,gt,gte,lt,lte,' +
    'not,sub,mul,div,mod,' +
    'vpow,vmin,vmax,vsqrt,vabs,vln,vlog10,veexp,v10exp,' +
    'vsindeg,vcosdeg,vtandeg,vasindeg,vacosdeg,vatandeg,' +
    'neg,vround,vfloor,vceil,vrand,' +
    'addto,' +
    'vbitwiseor,vbitwiseand,' + 
    'vstrjoin,vstrcat,vstrlen,vstrempty,' +
    'stringBuffer,' +
    'TRUE,FALSE,' +
    'ZERO,ONE,TWO' +
    'VPI,VE,VGOLDEN_RATIO,VSQRT2,VSQRT1_2,VINFINITY,' +
    'EMPTY_STRING');