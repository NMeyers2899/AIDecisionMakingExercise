#include "Agent1.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "GameManager.h"
#include "SeekCGComponent.h"
#include "SteeringComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "WanderCGComponent.h"
#include "ShieldCGComponent.h"


Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
	
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);

	if (actor->getName() == "Agent2")
		dynamic_cast<Character*>(actor)->takeDamage();
}

void Agent1::start()
{
	Character::start();
	
	m_seekComponent = new SeekCGComponent(1000);
	m_wanderComponent = new WanderCGComponent(200, 50, 600);
	//add steering behaviours
	addComponent(m_seekComponent);
	addComponent(m_wanderComponent);
	
}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);
	
	switch (m_currentState)
	{
	case SEEK_BALL:
		m_seekComponent->setTarget(GameManager::getInstance()->getBall());
		if (getHasBall())
			m_currentState = SEEK_GOAL;
		else if (GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEK_PLAYER;
		break;

	case SEEK_PLAYER:
		m_seekComponent->setTarget(GameManager::getInstance()->getAgent2());
		if (!GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEK_BALL;
		break;

	case SEEK_GOAL:
		m_seekComponent->setTarget(GameManager::getInstance()->getRightGoal());
		if (!getHasBall())
			m_currentState = SEEK_BALL;
		break;
	}
}

void Agent1::onDeath()
{
	Character::onDeath();

}
