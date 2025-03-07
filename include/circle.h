// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cmath>
#include <cstdint>

constexpr double pi = 3.1415926535;

class Circle {
	double radius;
	double ference;
	double area;

public:
	Circle() :radius(0.0), ference(0.0), area(0.0) {};
	explicit Circle(double r);
	void setRadius(double r);
	void setFerence(double f);
	void setArea(double a);
	double getRadius();
	double getFerence();
	double getArea();

private:
	double calculateRadiusFromFerence(double f);
	double calculateRadiusFromArea(double a);
	double calculateFerence(double r);
	double calculateArea(double r);

};

#endif  // INCLUDE_CIRCLE_H_
