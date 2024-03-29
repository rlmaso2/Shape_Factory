#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <map>

#include <QDomDocument>

#include "shape.h"
#include "triangle.h"

class ShapeFactory {
public:
  virtual Shape* createShape(const QDomElement& element) const;
  static void registerShape(const QString& shapeName, ShapeFactory* factory);
  static ShapeFactory* instance();
  void printStatus() const;
private:
  static ShapeFactory* m_instance;
  std::map<std::string, ShapeFactory*> m_factories;
};

#endif
