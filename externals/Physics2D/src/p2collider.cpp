#include "..\include\p2collider.h"


p2Collider::p2Collider(p2ColliderDef colliderDef)
{
	userData = colliderDef.userData;
	isSensor = colliderDef.isSensor;
	restitution = colliderDef.restitution;
	shape = colliderDef.shape;
}

bool p2Collider::IsSensor()
{
	return isSensor;
}

void * p2Collider::GetUserData()
{
	return userData;
}

p2Shape * p2Collider::GetShape()
{
	return shape;
}

float p2Collider::GetRestitution()
{
	return restitution;
}
