#pragma once

#include <unordered_map>
#include <Graphics/Model.h>

#include "States/eEnemyState.h"

class BaseState;

class Enemy : public Model
{
public:
	Enemy(Entity* target, eEnemyState currentState,const std::string& modelPath);

	void AddState(eEnemyState stateKey, BaseState* state);
	void RemoveState(eEnemyState stateKey);
	void ChangeState(eEnemyState state);

	BaseState* GetCurrentState();

	// Inherited via Entity
	void Start() override;
	void Update(float deltaTime) override;
	void Render() override;
	void OnDestroy() override;
	virtual void OnPropertyDraw();

	Entity* mTarget = nullptr;

	const char* items[6] = { "IDLE", "SEEK", "FLEE", "PURSUE", "EVADE", "APPROACH" };

	float mBaseSpeed = 2;
	float mRunSpeed = 4;

	glm::vec4 mSeekColor = glm::vec4(1, 0, 0, 1);
	glm::vec4 mFleeColor = glm::vec4(0, 1, 0, 1);
	glm::vec4 mPursueColor = glm::vec4(0, 0, 1, 1);
	glm::vec4 mEvadeColor = glm::vec4(0, 0, 0, 1);
	glm::vec4 mApproachColor = glm::vec4(1, 1, 1, 1);

private:

	std::unordered_map<eEnemyState, BaseState*> mListOfStates;

	eEnemyState mCurrentState = IDLE;


};

