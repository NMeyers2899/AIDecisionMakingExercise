#include "WanderNMComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Agent.h"
#include <random>
#include <time.h>

WanderNMComponent::WanderNMComponent(float distance, float radius, float force) : SteeringComponent(nullptr, force)
{
	m_force = force;
	m_circleDistance = distance;

	srand(time(NULL));
}

MathLibrary::Vector2 WanderNMComponent::calculateForce()
{
	// Find the agent's position and heading.
	MathLibrary::Vector2 ownerPosition = getOwner()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 heading = getAgent()->getMoveComponent()->getVelocity().getNormalized();

	// Find the circle's position in front of the agent.
	m_circlePosition = ownerPosition + (heading * m_circleDistance);

	// Find two random points and then plot them on the circle.
	float randNum = (rand() % 201);

	MathLibrary::Vector2 randomDirection = MathLibrary::Vector2{ cos(randNum), sin(randNum) } *m_radius;

	m_target = randomDirection + m_circlePosition;

	// Tell the agent to seek the point on the circle.
	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPosition) * getSteeringForce();
	MathLibrary::Vector2 wanderForce = desiredVelocity - getAgent()->getMoveComponent()->getVelocity();

	return wanderForce;
}
