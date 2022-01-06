#include "Shapes.h"


// Destructors
Shape::~Shape() {}
Shape2D::~Shape2D() {}
Square::~Square() {}
Triangle::~Triangle() {}
Circle::~Circle() {}
TriangularPyramid::~TriangularPyramid() {}
Cylinder::~Cylinder() {}
Sphere::~Sphere() {}


// Shape2D
bool Shape2D::operator>(const Shape2D& rhs) const
{
	if (this->Area() > rhs.Area())
		return true;
	else
		return false;
}
bool Shape2D::operator<(const Shape2D& rhs) const
{
	if (this->Area() < rhs.Area())
		return true;
	else
		return false;
}
bool Shape2D::operator==(const Shape2D& rhs) const
{
	if (this->Area() == rhs.Area())
		return true;
	else
		return false;
}
void Shape2D::ShowArea() const
{
	cout << "The area of the " << GetName2D() << "is : " << Area() << endl;
}

// Shape3D
bool Shape3D::operator>(const Shape3D& rhs) const
{
	if (this->Volume() > rhs.Volume())
		return true;
	else
		return false;
}
bool Shape3D::operator<(const Shape3D& rhs) const
{
	if (this->Volume() < rhs.Volume())
		return true;
	else
		return false;
}
bool Shape3D::operator==(const Shape3D& rhs) const
{
	if (this->Volume() == rhs.Volume())
		return true;
	else
		return false;
}
void Shape3D::ShowVolume() const
{
	cout << "The volume of the " << GetName3D() << "is : " << Volume() << endl;
}

// Square
Square::Square()
{
	side = 0;
}
Square::Square(float s)
{
	side = s;
}
string Square::GetName2D() const
{
	return "Square";
}
float Square::Area() const
{
	return (pow(side, 2));
}
void Square::Display() const
{
	cout << "The area of the Square is: " << this->Area() << endl;
	cout << "Length of a side: " << this->side << endl;
}
void Square::Scale(float scaleFactor)
{
	side *= scaleFactor;
}

// Triangle
Triangle::Triangle()
{
	base = 0;
	height = 0;
}
Triangle::Triangle(float b, float h)
{
	base = b;
	height = h;
}
string Triangle::GetName2D() const
{
	return "Triangle";
}
float Triangle::Area() const
{
	return (0.5 * base * height);
}
void Triangle::Display() const
{
	cout << "The area of the Triangle is: " << this->Area() << endl;
	cout << "Base: " << this->base << endl;
	cout << "Height: " << this->height << endl;
}
void Triangle::Scale(float scaleFactor)
{
	base *= scaleFactor;
	height *= scaleFactor;
}

// Circle
Circle::Circle()
{
	radius = 0;
}
Circle::Circle(float r)
{
	radius = r;
}
string Circle::GetName2D() const
{
	return "Circle";
}
float Circle::GetRadius() const
{
	return radius;
}
float Circle::Area() const
{
	return ((PI) * pow(radius,2));
}
void Circle::Display() const
{
	cout << "The area of the Circle is: " << this->Area() << endl;
	cout << "Radius: " << this->radius << endl;
}
void Circle::Scale(float scaleFactor)
{
	radius *= scaleFactor;
}

// Triangular Pyramid
TriangularPyramid::TriangularPyramid() : Triangle()
{
	height = 0;
}
TriangularPyramid::TriangularPyramid(float height3D, float baseLength, float baseHeight) : Triangle(baseLength, baseHeight)
{
	height = height3D;
}
string TriangularPyramid::GetName3D() const
{
	return "Triangular Pyramid";
}
float TriangularPyramid::Volume() const
{
	float baseArea = this->Triangle::Area();
	float volume = (1.0f/3.0f) * baseArea * height;
	return volume;
}
void TriangularPyramid::Display() const
{
	cout << "The volume of the Triangular Pyramid is: " << this->Volume() << endl;
	cout << "The height is: " << height << endl;
	this->Triangle::Display();
}
void TriangularPyramid::Scale(float scaleFactor)
{
	height *= scaleFactor;
	this->Triangle::Scale(scaleFactor);
}

// Cylinder
Cylinder::Cylinder() : Circle()
{
	height = 0;
}
Cylinder::Cylinder(float h, float r) : Circle(r)
{
	height = h;
}
string Cylinder::GetName3D() const
{
	return "Cylinder";
}
float Cylinder::Volume() const
{
	return (this->Circle::Area()) * (height);
}
void Cylinder::Display() const
{
	cout << "The volume of the Cylinder is: " << this->Volume() << endl;
	cout << "The height is: " << height << endl;
	this->Circle::Display();
}
void Cylinder::Scale(float scaleFactor)
{
	height *= scaleFactor;
	this->Circle::Scale(scaleFactor);
}

//Sphere
Sphere::Sphere() : Circle() {}
Sphere::Sphere(float r) : Circle(r) {}
string Sphere::GetName3D() const
{
	return "Sphere";
}
float Sphere::Volume() const
{
	return ((4.0f/3.0f) * PI * pow(this->GetRadius(), 3));
}
void Sphere::Display() const
{
	cout << "The volume of the Sphere is: " << this->Volume() << endl;
	this->Circle::Display();
}
void Sphere::Scale(float scaleFactor)
{
	this->Circle::Scale(scaleFactor);
}
