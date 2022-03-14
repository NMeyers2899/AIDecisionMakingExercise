#include "Agent2.h"
#include "SpriteComponent.h"
#include "GameManager.h"
#include "Goal.h"
#include "SeekNMComponent.h"
#include "FleeNMComponent.h"
#include "Transform2D.h"
#include "NMShield.h"

Agent2::Agent2(float x, float y, const char* name, float maxForce, float maxSpeed, float health) : Character(x, y, name, maxForce, maxSpeed, health)
{
	addComponent(new SpriteComponent("Images/enemy.png"));
}

void Agent2::onCollision(Actor* actor)
{
	Character::onCollision(actor);

	if (actor->getName() == "Agent1")
		dynamic_cast<Character*>(actor)->takeDamage();
}

void Agent2::start()
{
	Character::start(); Character::start();
	m_seekComponent = new SeekNMComponent(2000);
	m_fleeComponent = new FleeNMComponent(200);
	NMShield* agentShield = new NMShield(Engine::getScreenWidth() - 250.0f, 400, "Agent2", 50, 50, 3);
	getTransform()->addChild(agentShield->getTransform());
	
	//add steering behaviours here
	addComponent(m_seekComponent);
}

void Agent2::update(float deltaTime)
{
	Character::update(deltaTime);

	switch (m_currentState) 
	{
	case CHASE_BALL:
		m_seekComponent->setTarget(GameManager::getInstance()->getBall());
		m_fleeComponent->setTarget(GameManager::getInstance()->getAgent1());
		if (getHasBall())
			m_currentState = SEEK_GOAL;
		else if (GameManager::getInstance()->getAgent2()->getHasBall())
			m_currentState = CHASE_PLAYER;
		break;

	case CHASE_PLAYER:
		m_seekComponent->setTarget(GameManager::getInstance()->getAgent1());
		m_fleeComponent->setTarget(GameManager::getInstance()->getLeftGoal());
		if (!GameManager::getInstance()->getAgent2()->getHasBall())
			m_currentState = CHASE_BALL;
		break;

	case SEEK_GOAL:
		m_seekComponent->setTarget(GameManager::getInstance()->getLeftGoal());
		m_fleeComponent->setTarget(GameManager::getInstance()->getAgent1());
		if (!getHasBall())
			m_currentState = CHASE_BALL;
		break;
	}
}

void Agent2::onDeath()
{
	Character::onDeath();
	
}