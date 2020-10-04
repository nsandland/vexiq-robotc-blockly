Blockly.RobotC.typedefs_.push(`
typedef struct {
  float x;
  float y; 
} Point;

`);

Blockly.RobotC.point = `
void rotate(Point &p, float theta) {
  float newX = p.x * cosDegrees(theta) - p.y * sinDegrees(theta);
  float newY = p.x * sinDegrees(theta) + p.y * cosDegrees(theta);
  p.x = newX;
  p.y = newY;
}

void translate(Point &p, float x, float y) {
  p.x += x;
  p.y += y;
}

void scale(Point &p, float amount) {
  p.x *= amount;
  p.y *= amount;
}

`;

Blockly.RobotC.addReservedWords(
    'Point,rotate,translate,scale');