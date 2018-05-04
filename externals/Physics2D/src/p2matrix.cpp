/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <p2matrix.h>
#include <iostream>

p2Mat22::p2Mat22()
{
}

p2Mat22::p2Mat22(p2Vec2 r1, p2Vec2 r2)
{
	this->column[0] = r1;
	this->column[1] = r2;
}

p2Mat22 p2Mat22::operator+(p2Mat22 m1)
{

	return p2Mat22
	(p2Vec2(column[0].x + m1.column[0].x, column[0].y + m1.column[0].y),
		p2Vec2(column[1].x + m1.column[1].x, column[1].y + m1.column[1].y));
}

p2Mat22 p2Mat22::operator-(p2Mat22 m1)
{
	return p2Mat22
	(p2Vec2(column[0].x - m1.column[0].x, column[0].y - m1.column[0].y),
		p2Vec2(column[1].x - m1.column[1].x, column[1].y - m1.column[1].y));
}

p2Mat22 p2Mat22::operator*(p2Mat22 m1)
{
	return p2Mat22
	(p2Vec2(column[0].x * m1.column[0].x + column[1].x * m1.column[0].y,
		column[0].y * m1.column[0].x + column[1].y * m1.column[0].y),
		p2Vec2(column[0].x * m1.column[1].x + column[1].y * m1.column[1].y,
			column[0].y * m1.column[1].x + column[1].y * m1.column[1].y));
}

p2Vec2 p2Mat22::operator*(p2Vec2 v)
{
	return p2Vec2
	(column[0].x * v.x + column[1].x * v.y,
		column[0].y * v.x + column[1].y * v.y);
}

p2Mat22 p2Mat22::operator*(float f)
{
	return p2Mat22
	(p2Vec2(column[0].x * f, column[0].y * f),
		p2Vec2(column[1].x * f, column[1].y * f));
}

p2Mat22 p2Mat22::operator/(float f)
{
	return p2Mat22
	(p2Vec2(column[0].x / f, column[0].y / f),
		p2Vec2(column[1].x / f, column[1].y / f));
}

p2Mat22 p2Mat22::Invert()
{
	if (this->GetDeterminant() == 0)
	{
		std::cout << "This matrix is singular.\n";
	}

	else
	{
		p2Mat22 coMatrix
		(p2Vec2(column[1].y, -column[0].y),
			p2Vec2(-column[1].x, column[0].x));

		return p2Mat22(coMatrix.operator*(1 / this->GetDeterminant()));
	}
}

float p2Mat22::GetDeterminant()
{
	return (column[0].x * column[1].y) - (column[0].y * column[1].x);
}

p2Mat33::p2Mat33()
{
}

p2Mat33::p2Mat33(p2Vec3 r1, p2Vec3 r2, p2Vec3 r3)
{
	this->column[0] = r1;
	this->column[1] = r2;
	this->column[2] = r3;
}

p2Mat33 p2Mat33::operator+(p2Mat33 m1)
{
	return p2Mat33
	(p2Vec3(column[0].x + m1.column[0].x, column[0].y + m1.column[0].y, column[0].z + m1.column[0].z),
		p2Vec3(column[1].x + m1.column[1].x, column[1].y + m1.column[1].y, column[1].z + m1.column[1].z),
		p2Vec3(column[2].x + m1.column[2].x, column[2].y + m1.column[2].y, column[2].z + m1.column[2].z));
}

p2Mat33 p2Mat33::operator-(p2Mat33 m1)
{
	return p2Mat33
	(p2Vec3(column[0].x - m1.column[0].x, column[0].y - m1.column[0].y, column[0].z - m1.column[0].z),
		p2Vec3(column[1].x - m1.column[1].x, column[1].y - m1.column[1].y, column[1].z - m1.column[1].z),
		p2Vec3(column[2].x - m1.column[2].x, column[2].y - m1.column[2].y, column[2].z - m1.column[2].z));
}

p2Mat33 p2Mat33::operator*(p2Mat33 m1)
{
	return p2Mat33
	(p2Vec3(column[0].x * m1.column[0].x + column[1].x * m1.column[0].y + column[2].x * m1.column[0].z,
		column[0].y * m1.column[0].x + column[1].y * m1.column[0].y + column[2].y * m1.column[0].z,
		column[0].z * m1.column[0].x + column[1].z * m1.column[0].y + column[2].z * m1.column[0].z),

		p2Vec3(column[0].x * m1.column[1].x + column[1].x * m1.column[1].y + column[2].x * m1.column[1].z,
			column[0].y * m1.column[1].x + column[1].y * m1.column[1].y + column[2].y * m1.column[1].z,
			column[0].z * m1.column[1].x + column[1].z * m1.column[1].y + column[2].z * m1.column[1].z),

		p2Vec3(column[0].x * m1.column[2].x + column[1].x * m1.column[2].y + column[2].x * m1.column[2].z,
			column[0].y * m1.column[2].x + column[1].y * m1.column[2].y + column[2].y * m1.column[2].z,
			column[0].z * m1.column[2].x + column[1].z * m1.column[2].y + column[2].z * m1.column[2].z)
	);
}

p2Vec3 p2Mat33::operator*(p2Vec3 v)
{
	return p2Vec3
	(column[0].x * v.x + column[1].x * v.y + column[2].x * v.z,
		column[0].y * v.x + column[1].y * v.y + column[2].y * v.z,
		column[0].z * v.x + column[1].z * v.y + column[2].z * v.z);
}

p2Mat33 p2Mat33::operator*(float f)
{
	return p2Mat33
	(p2Vec3(column[0].x * f, column[0].y * f, column[0].z * f),
		p2Vec3(column[1].x * f, column[1].y * f, column[1].z * f),
		p2Vec3(column[2].x * f, column[2].y * f, column[2].z * f));
}

p2Mat33 p2Mat33::operator/(float f)
{
	return p2Mat33
	(p2Vec3(column[0].x / f, column[0].y / f, column[0].z / f),
		p2Vec3(column[1].x / f, column[1].y / f, column[1].z / f),
		p2Vec3(column[2].x / f, column[2].y / f, column[2].z / f));
}

p2Mat33 p2Mat33::Invert()
{
	p2Mat22 subMatrix1(
		p2Vec2(column[1].y, column[1].z),    //Identification of the 9 sub matrix 
		p2Vec2(column[2].y, column[2].z));

	p2Mat22 subMatrix2(
		p2Vec2(column[0].y, column[0].z),
		p2Vec2(column[2].y, column[2].z));

	p2Mat22 subMatrix3(
		p2Vec2(column[0].y, column[0].z),
		p2Vec2(column[1].y, column[1].z));

	p2Mat22 subMatrix4(
		p2Vec2(column[1].x, column[1].z),
		p2Vec2(column[2].x, column[2].z));

	p2Mat22 subMatrix5(
		p2Vec2(column[0].x, column[0].z),
		p2Vec2(column[2].x, column[2].z));

	p2Mat22 subMatrix6(
		p2Vec2(column[0].x, column[0].z),
		p2Vec2(column[1].x, column[1].z));

	p2Mat22 subMatrix7(
		p2Vec2(column[1].x, column[1].y),
		p2Vec2(column[2].x, column[2].y));

	p2Mat22 subMatrix8(
		p2Vec2(column[0].x, column[0].y),
		p2Vec2(column[2].x, column[2].y));

	p2Mat22 subMatrix9(
		p2Vec2(column[0].x, column[0].y),
		p2Vec2(column[1].x, column[1].y));


	p2Mat33 transposedMatrix(			
		p2Vec3(subMatrix1.GetDeterminant(), -subMatrix2.GetDeterminant(), subMatrix3.GetDeterminant()),
		p2Vec3(-subMatrix4.GetDeterminant(), subMatrix5.GetDeterminant(), -subMatrix6.GetDeterminant()),
		p2Vec3(subMatrix7.GetDeterminant(), -subMatrix8.GetDeterminant(), subMatrix9.GetDeterminant()));


	return p2Mat33(
		transposedMatrix.operator*(1 / this->GetDeterminant()));
}

float p2Mat33::GetDeterminant()
{
	p2Mat22 subMatrix1(
		p2Vec2(column[1].y, column[1].z),
		p2Vec2(column[2].y, column[2].z));

	p2Mat22 subMatrix2(
		p2Vec2(column[0].y, column[0].z),
		p2Vec2(column[2].y, column[2].z));

	p2Mat22 subMatrix3(
		p2Vec2(column[0].y, column[0].z),
		p2Vec2(column[1].y, column[1].z));

	return column[0].x * subMatrix1.GetDeterminant() -
		column[1].x * subMatrix2.GetDeterminant() +
		column[2].x * subMatrix3.GetDeterminant();
}