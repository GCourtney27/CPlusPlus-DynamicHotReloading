#pragma once
#include <string>
#include "Vector2.h"

class Entity
{
public:
	Entity() { transform = new Vector2(); }
	~Entity() {}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual const char* GetName() = 0;
	Vector2* GetTransform() { return transform; }

private:
	Vector2* transform = nullptr;

};