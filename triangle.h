#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QDomElement>

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle(const double& m_base, const double& m_height) : base(m_base), height(m_height) {}
    Triangle(const QDomElement& element);
    virtual double area() const {return .5*base*height;}
private:
    double base, height;

}; // class Triangle

#endif // TRIANGLE_H
