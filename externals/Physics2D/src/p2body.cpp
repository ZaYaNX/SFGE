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
#include <p2body.h>
#include <p2collider.h>



p2Body::p2Body(p2BodyDef *p2BodyDef)
{
	position = p2BodyDef->position;

	/*switch(p2BodyType)
	{
	case p2BodyType::STATIC:
		p2BodyDef.type = p2BodyType::STATIC;
		break;
	case p2BodyType::KINEMATIC:
		p2BodyDef.type = p2BodyType::KINEMATIC;
		break;
	case p2BodyType::DYNAMIC:
		p2BodyDef.type = p2BodyType::DYNAMIC;
		break;


	}*/
	mass = p2BodyDef->mass;
	linearVelocity = p2BodyDef->linearVelocity;
	type = p2BodyDef->type;

}

p2Vec2 p2Body::GetLinearVelocity()
{
	return linearVelocity;
}

void p2Body::SetLinearVelocity(p2Vec2 velocity)
{
	linearVelocity = velocity;
}
void p2Body::addForce(p2Vec2 force)
{
}
float p2Body::GetAngularVelocity()
{
	return angularVelocity;
}

p2Vec2 p2Body::GetPosition()
{
	return position;
}

float p2Body::GetMass()
{
	return 0.0f;
}

void p2Body::SetMass(float mass)
{
}

void p2Body::addBody(p2Body * body)
{
	bodies.push_front(*body);
}

void p2Body::setPosition(p2Vec2 p)
{
	this->position = position + p;
}

p2Collider * p2Body::CreateCollider(p2ColliderDef * colliderDef)
{
	collider = new p2Collider(*colliderDef);
	return nullptr;
}
