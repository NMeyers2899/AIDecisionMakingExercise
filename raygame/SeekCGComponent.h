#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
class SeekCGComponent :
	public SteeringComponent
{
public:
	SeekCGComponent(float steeringForce) : SteeringComponent(nullptr, steeringForce) {}

	MathLibrary::Vector2 calculateForce() override;


};

