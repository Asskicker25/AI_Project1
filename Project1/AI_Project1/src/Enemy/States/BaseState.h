#pragma once

#include "../Enemy.h"

class BaseState
{
public:

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Cleanup() = 0;

	Enemy* mEnemy = nullptr;
};

