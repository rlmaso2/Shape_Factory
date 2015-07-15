#include "circlefactory.h"

#include <cassert>

static CircleFactory circleFactory;

CircleFactory::CircleFactory() {
  ShapeFactory::registerShape("circle", this);
}

Circle* CircleFactory::createShape(const QDomElement& element) const {
  assert(!element.isNull());
  assert(element.tagName()=="circle");
  
  Circle* circle = new Circle(element);
  
  return circle;
}
