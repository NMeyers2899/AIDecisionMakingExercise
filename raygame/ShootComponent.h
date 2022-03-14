#pragma once
#include "Component.h"
class ShootComponent :
	public Component
{
	ShootComponent(Actor* target, float cooldown);
	~ShootComponent() {};

	void update(float deltaTime) override;

private: 
	Actor* m_target;

	float m_timer;
	float m_cooldown;
};

