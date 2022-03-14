#pragma once
#include "SteeringComponent.h"

class SeekNMComponent : public SteeringComponent
{
public:
	SeekNMComponent(float steeringForce) : SteeringComponent(nullptr, steeringForce) {}

	MathLibrary::Vector2 calculateForce() override;
};

