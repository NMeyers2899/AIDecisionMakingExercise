#pragma once
#include "SteeringComponent.h"
#include <Vector2.h>
class SeekCGComponent :
	public SteeringComponent
{
public:
	SeekCGComponent(MathLibrary::Vector2 targetPos, float steeringForce);

	MathLibrary::Vector2 calculateForce() override;

private:
	MathLibrary::Vector2 m_targetPos;
};

