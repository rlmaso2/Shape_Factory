#include "triangle.h".h"

#include <cassert>

Triangle::Triangle(const QDomElement& element) {
  QDomElement b = element.namedItem("base").toElement();
  assert(!b.isNull());
  base = b.text().toDouble();
  assert(base>0.0);

  QDomElement h = element.namedItem("height").toElement();
  assert(!h.isNull());
  height = h.text().toDouble();
  assert(height>0.0);
}
