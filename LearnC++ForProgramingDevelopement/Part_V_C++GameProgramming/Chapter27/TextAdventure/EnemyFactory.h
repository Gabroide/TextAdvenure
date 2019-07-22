#pragma once

#include "EnemyBase.h"

namespace
{
#if PLATFORM_WINDOWS
#include "WindowsEnemy.h"
	using Enemy = WindowsEnemy;
#elif PLATFORM_ANDROID
#include "AndroidEnemy.h"
	using Enemy = AndroidEnemy;
#elif PLATFORM_IOS
#include "iOSEnemy.h"
	using Enemy = iOSEnemy;
#endif
}

EnemyBase* CreateEnemy(EnemyType enemyType, const uint32_t serializableId)
{
	Enemy* pEnemy = nullptr;

	switch (enemyType)
	{
	case EnemyType::Dragon:
		pEnemy = new Enemy(EnemyType::Dragon, serializable);
		break;

	case EnemyType::Orc:
		pEnemy = new Enemy(EnemyType::Orc, serializable);
		break;

	default:
		assert(false); // Unknown enemy type
		break;
	}

	return pEnemy;
}