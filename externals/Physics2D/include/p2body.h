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

#ifndef SFGE_P2BODY_H
#define SFGE_P2BODY_H

#include <p2aabb.h>
#include <list>

class p2Collider;
struct p2ColliderDef;

enum class p2BodyType
{
	STATIC,
	KINEMATIC,
	DYNAMIC
};

/**
* \brief Struct Defining the p2Body when creating it
*/
struct p2BodyDef
{
	p2BodyType type;
	p2Vec2 position;
	p2Vec2 linearVelocity;
	float gravityScale;
	float mass;
	
};

/**
* \brief Rigidbody representation
*/
class p2Body
{
public:

	p2Body(p2BodyDef* p2BodyDef);

	p2Vec2 GetLinearVelocity();
	
	void SetLinearVelocity(p2Vec2 velocity);

	void addForce(p2Vec2 force);

	float GetAngularVelocity();
	
	p2Vec2 GetPosition();

	float GetMass();

	void SetMass(float mass);

	void addBody(p2Body* body);

	void setPosition(p2Vec2 position);
	/**
	* \brief Factory method creating a p2Collider
	* \param colliderDef p2ColliderDef definition of the collider
	* \return p2Collider collider attached to the p2Body
	*/
	p2Collider* CreateCollider(p2ColliderDef* colliderDef);

private:

	std::list <p2Body> bodies;
	float mass;
	p2Vec2 force;
	p2AABB aabb;
	p2BodyType type;
	p2Vec2 position;
	p2Vec2 linearVelocity;
	float angularVelocity;
	p2Collider* collider;
};

#endif