#pragma once

#include "Entity.h"
#include "EnemyFactory.h"
#include "Serializable.h"
#include <memory>

class EnemyBase
	: public Entity
	, public Serializable
{
public:
	using Pointer = std::shared_ptr<EnemyBase>;
	
private:
	EnemyType m_type;
	bool m_alive{ true };

public:
	EnemyBase(EnemyType type)
		: m_type{ type }
		, Serializable (serializableId)
	{

	}

	EnemyType GetType() const
	{
		return m_type;
	}

	bool IsAlive() const
	{
		return m_alive;
	}

	void Kill()
	{
		m_alive = false;
	}

	virtual void OnSave(std::ofstream& file)
	{
		file << m_alive;
	}

	virtual OnLoad(std::ifstream& file)
	{
		file >> m_alive;
	}
};

Enemy* CreatedEnemy(EnemyType enemyType)
{
	Enemy* pEnemy = nullptr;

	switch (enemyType)
	{
	case EnemyType::Dragon:
		pEnemy = new Enemy(EnemyType::Dragon);
		break;

	case EnemyType::Orc:
		pEnemy = new Enemy(EnemyType::Orc);
		break;

	default:
		assert(false);
		break;
	}

	return pEnemy;
}