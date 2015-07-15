#include "shapefactory.h"
#include "triangle.h"

#include <cassert>
#include <iostream>

ShapeFactory* ShapeFactory::m_instance = 0;
static ShapeFactory factory;

ShapeFactory* ShapeFactory::instance() {
  if(m_instance == 0){
    m_instance = new ShapeFactory;
  }
  
  return m_instance;
}

Shape* ShapeFactory::createShape(const QDomElement& element) const {
  assert(!element.isNull());
  
  Shape* shape = 0;
  
  // get the tag name for the current DOM element
  const QString tagName = element.tagName();
  
  // request object creation from registered factory
  std::map<std::string, ShapeFactory*>::const_iterator it =
    m_factories.find(tagName.toStdString());
  assert(it!=m_factories.end());
  ShapeFactory* factory = it->second;
  assert(factory!=0);
  shape = factory->createShape(element);
  
  // if the schema definition and the and the type list above are in sync,
  // shape should never be null
  assert(shape!=0);
  
  return shape;
}

void ShapeFactory::registerShape(const QString& shapeName, 
                                 ShapeFactory* factory) {
  assert(shapeName.length()>0);
  assert(factory!=0);  
  ShapeFactory::instance()->m_factories[shapeName.toStdString()] = factory;
}

void ShapeFactory:: printStatus() const
{
    std::cout<< "Factory status: \n";
    std::cout<<"Instance Object: "<< &m_instance<< "\n";
    std::cout<<"Number of Types: "<< m_factories.size()<< "\n";
    std::cout<<"Registered factories and types: \n";
    std::cout<< instance()->m_factories["circle"]<< " at Circle \n";
    std::cout<< instance()->m_factories["rectangle"]<< " at Rectangle \n";
    std::cout<< instance()->m_factories["square"]<< " at Square \n";
    std::cout<< instance()->m_factories["triangle"]<< " at Triangle \n \n";

}
