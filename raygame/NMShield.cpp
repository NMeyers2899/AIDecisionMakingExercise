#include "NMShield.h"
#include "Transform2D.h"

void NMShield::onCollision(Actor* other)
{
	Actor::onCollision(other);

	if (other->getName() != "Ball" || other->getName() != "Agent1" || other->getName() != "Agent2" || other->getName() != "LeftGoal" || other->getName() != "RightGoal")
		delete other;
}
