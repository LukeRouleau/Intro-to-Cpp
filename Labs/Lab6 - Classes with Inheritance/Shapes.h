#pragma once
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class Shape
{
public:
	const float PI = 3.14159f;
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape();
};
class Shape2D : virtual public Shape
{
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;	
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
	~Shape2D();
};
class Shape3D : virtual public Shape
{
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;	
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

// 2D Children
class Square : public Shape2D
{
	float side;
public:
	Square();
	Square(float s);
	string GetName2D() const;
	float Area() const;
	void Display() const;
	void Scale(float scaleFactor);
	~Square();
};
class Triangle : public Shape2D
{
	float base;
	float height;
public:
	Triangle();
	Triangle(float b, float s);
	string GetName2D() const;
	float Area() const;
	void Display() const;
	void Scale(float scaleFactor);
	~Triangle();
};
class Circle : public Shape2D
{
	float radius;
public:
	Circle();
	Circle(float r);
	string GetName2D() const;
	float GetRadius() const;
	float Area() const;
	void Display() const;
	void Scale(float scaleFactor);
	~Circle();
};

//3D Children
class TriangularPyramid : public Shape3D, private Triangle
{
	float height;
public:
	TriangularPyramid();
	TriangularPyramid(float height3D, float baseLength, float baseHeight);
	string GetName3D() const;
	float Volume() const;
	void Display() const;
	void Scale(float scaleFactor);
	~TriangularPyramid();
};

class Cylinder : public Shape3D, private Circle
{
	float height;
public:
	Cylinder();
	Cylinder(float h, float r);
	string GetName3D() const;
	float Volume() const;
	void Display() const;
	void Scale(float scaleFactor);
	~Cylinder();
};

class Sphere : public Shape3D, private Circle
{
public:
	Sphere();
	Sphere(float r);
	string GetName3D() const;
	float Volume() const;
	void Display() const;
	void Scale(float scaleFactor);
	~Sphere();
};