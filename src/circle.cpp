// Copyright 2022 UNN-CS
#include <cmath>
#include <cstdint>
#include "circle.h"

Circle::Circle(double r) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  if (r < 0.0)
    throw "Invalid radius";
  radius = r;
  ference = calculateFerence(r);
  area = calculateArea(r);
}

void Circle::setFerence(double f) {
  if (f < 0.0)
    throw "Invalid ference";
  radius = calculateRadiusFromFerence(f);
  ference = f;
  area = calculateArea(radius);
}

void Circle::setArea(double a) {
  if (a < 0.0)
    throw "Invalid area";
  radius = calculateRadiusFromArea(a);
  ference = calculateFerence(radius);
  area = a;
}

double Circle::getRadius() {
  return radius;
}

double Circle::getFerence() {
  return ference;
}

double Circle::getArea() {
  return area;
}

double Circle::calculateRadiusFromFerence(double f) {
  return f / (2 * pi);
}

double Circle::calculateRadiusFromArea(double a) {
  return sqrt(a / pi);
}

double Circle::calculateFerence(double r) {
  return 2 * pi * r;
}

double Circle::calculateArea(double r) {
  return pi * r * r;
}
