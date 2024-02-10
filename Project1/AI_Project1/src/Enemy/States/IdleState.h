#pragma once
#include "BaseState.h"

class IdleState : public BaseState
{
public:

	// Inherited via BaseState
	void Start() override;
	void Update() override;
	void Cleanup() override;

	// Inherited via BaseState
	void OnStateChanged() override;
};

