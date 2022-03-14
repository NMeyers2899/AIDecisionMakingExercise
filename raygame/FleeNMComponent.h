#pragma once
#include "SteeringComponent.h"
class FleeNMComponent : public SteeringComponent
{
public:
	FleeNMComponent(float steeringForce) : SteeringComponent(nullptr, steeringForce) {}

	MathLibrary::Vector2 calculateForce() override;
};

