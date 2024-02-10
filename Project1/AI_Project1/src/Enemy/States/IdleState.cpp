#include <iostream>
#include <Graphics/Timer.h>

#include "IdleState.h"


void IdleState::Start()
{
}

void IdleState::Update()
{
	
}

void IdleState::Cleanup()
{
}

void IdleState::OnStateChanged()
{
	mEnemy->meshes[2]->material->AsMaterial()->SetBaseColor(mEnemy->mEvadeColor);
	mEnemy->meshes[3]->material->AsMaterial()->SetBaseColor(mEnemy->mEvadeColor);
}
