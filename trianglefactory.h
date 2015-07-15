#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H

#include "shapefactory.h"
#include "square.h"


class TriangleFactory : public ShapeFactory
{
public:
    TriangleFactory();
    virtual Triangle* createShape(const QDomElement& element) const;
};

#endif // TRIANGLEFACTORY_H
