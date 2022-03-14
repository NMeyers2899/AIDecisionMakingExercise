#pragma once
#include "SteeringComponent.h"

class WanderNMComponent : public SteeringComponent
{
public:
	WanderNMComponent(float distance, float radius, float force);

	MathLibrary::Vector2 calculateForce() override;

private:
	float m_force;
	float m_radius;
	float m_circleDistance = 0;

	MathLibrary::Vector2 m_target;
	MathLibrary::Vector2 m_circlePosition;
};

