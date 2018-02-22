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

#ifndef SFGE_PYCOMPONENT_H_
#define SFGE_PYCOMPONENT_H_

#include <engine/component.h>
#include <utility/python_utility.h>
//STL
#include <memory>

namespace sfge
{

/**
 * \brief Python abstraction of Component
 */
class PyComponent : public Component
{
public:
	using Component::Component;
	~PyComponent();

	void Init() override;
	void Update(float dt) override;
	static PyComponent* LoadPythonScript(Engine& engine, json& componentJson, GameObject* gameObject);

	void OnCollisionEnter(Collider* collider) override;
	void OnTriggerEnter(Collider * collider) override;
	void OnCollisionExit(Collider* collider) override;
	void OnTriggerExit(Collider * collider) override;

	unsigned int GetInstanceId() const;
	void SetInstanceId(unsigned int instanceId = 0U);

private:
	unsigned int instanceId = 0U;
};

}


#endif /* INCLUDE_PYTHON_PYCOMPONENT_H_ */
