#pragma once
#include "SteeringComponent.h"

class SeekNMComponent : public SteeringComponent
{
public:
	SeekNMComponent(MathLibrary::Vector2 targetPos, float steeringForce);

	MathLibrary::Vector2 calculateForce() override;

private:
	MathLibrary::Vector2 m_targetPos;
};

