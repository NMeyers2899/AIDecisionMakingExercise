#include "SeekNMComponent.h"
#include "Agent.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "Engine.h"

SeekNMComponent::SeekNMComponent(MathLibrary::Vector2 targetPos, float steeringForce) : SteeringComponent(nullptr, steeringForce)
{
	Actor* target = new Actor();
	target->getTransform()->setWorldPostion(targetPos);
	setTarget(target);
	Engine::getCurrentScene()->addActor(target);
}

MathLibrary::Vector2 SeekNMComponent::calculateForce()
{
	MathLibrary::Vector2 targetPos;

	if (getOwner() && getTarget())
	{
		MathLibrary::Vector2 directionToTarget = getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition();

		MathLibrary::Vector2 desiredVelocity = directionToTarget.getNormalized() * getSteeringForce();
		MathLibrary::Vector2 seekForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

		return seekForce;
	}

	return { 0, 0 };
}
