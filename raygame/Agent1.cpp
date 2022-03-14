#include "Agent1.h"
#include "SpriteComponent.h"
#include "Goal.h"
#include "GameManager.h"
#include "SeekCGComponent.h"
#include "SteeringComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Character.h"


Agent1::Agent1(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/player.png"));
	
}

void Agent1::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent1::start()
{
	Character::start();
	
	m_seekComponent->setTarget(GameManager::getInstance()->getAgent2());

	addComponent(m_seekComponent);
	
}

void Agent1::update(float deltaTime)
{
	Character::update(deltaTime);
	
	switch (m_currentState)
	{
	case SEEK_BALL:
		m_seekComponent->setTarget(GameManager::getInstance()->getBallPosition);
		if (getHasBall())
			m_currentState = SEEK_GOAL;
		else if (GameManager::getInstance()->getAgent1()->getHasBall())
			m_currentState = SEEK_PLAYER;
		break;

	case SEEK_PLAYER:
		m_seekComponent->setTarget(GameManager::getInstance()->getAgent2());
		if (!GameManager::getInstance()->getAgent2()->getHasBall())
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
