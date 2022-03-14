#pragma once
#include "Character.h"

class NMShield : public Character
{
public:
	NMShield(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health) {};

	void onCollision(Actor* actor) override;
};

