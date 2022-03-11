#pragma once
#include "SteeringComponent.h"

class SeekNMComponent : public SteeringComponent
{
public:
	MathLibrary::Vector2 calculateForce() override;

private:
	Actor* m_target;
	float m_force;
};

