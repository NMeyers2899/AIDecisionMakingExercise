#include "FleeNMComponent.h"
#include "Agent.h"
#include "Transform2D.h"
#include "MoveComponent.h"

MathLibrary::Vector2 FleeNMComponent::calculateForce()
{
	if (getOwner() && getTarget())
	{
		MathLibrary::Vector2 directionToTarget = getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition();

		MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
		MathLibrary::Vector2 fleeForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

		return fleeForce;
	}

	return { 0, 0 };
}
