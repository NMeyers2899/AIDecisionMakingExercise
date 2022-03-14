#include "Agent2.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "Goal.h"
#include "SeekNMComponent.h"
#include "Transform2D.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);
}

void Agent2::start()
{
	Character::start(); Character::start();
	SeekNMComponent* seekComponent = new SeekNMComponent(GameManager::getInstance()->getBallPosition(), 50);
	
	//add steering behaviours here
	addComponent(seekComponent);
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);

	switch (m_currentState) 
	{
	case CHASE_BALL:
		if (getHasBall())
			m_currentState = SEEK_GOAL;
		else if (GameManager::getInstance()->getAgent2()->getHasBall())
			m_currentState = CHASE_PLAYER;
		break;

	case CHASE_PLAYER:
		seekComponent->setTarget(GameManager::getInstance()->getAgent2());
		if (!GameManager::getInstance()->getAgent2()->getHasBall())
			m_currentState = CHASE_BALL;
		break;

	case SEEK_GOAL:
		seekComponent->setTarget(GameManager::getInstance()->getLeftGoal());
		if (!getHasBall())
			m_currentState = CHASE_BALL;
		break;
	}
}

void Agent2::onDeath()
{
	Character::onDeath();

}