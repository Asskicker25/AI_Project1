#pragma once

#include "BaseState.h"

class SeekState : public BaseState
{
public:

	// Inherited via BaseState
	void Start() override;
	void Update() override;
	void Cleanup() override;
};

