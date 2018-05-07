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

#include <p2contact.h>

p2Contact::p2Contact(p2Collider* colliderA, p2Collider* colliderB)
{
	this->colliderA = colliderA;
	this->colliderB = colliderB;
}

p2Collider * p2Contact::GetColliderA()
{
	return colliderA;
}

p2Collider * p2Contact::GetColliderB()
{
	return colliderB;
}

void p2ContactManager::CreateContact(p2Contact* contact)
{
	contacts.push_front(*contact);
}

void p2ContactManager::DeleteContact(p2Contact * contact)
{
	for (std::list<p2Contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
	{
		if (it->GetColliderA() == contact->GetColliderA() && it->GetColliderB() == contact->GetColliderB())
		{
			contacts.erase(it);
		}
	}
}

bool p2ContactManager::IsInContact(p2Contact * contact)
{
	for (std::list<p2Contact>::iterator it = contacts.begin(); it != contacts.end(); it++)
	{
		if (it->GetColliderA() == contact->GetColliderA() && it->GetColliderB() == contact->GetColliderB())
		{
			return true;
		}
		else
			return false;
	}
}