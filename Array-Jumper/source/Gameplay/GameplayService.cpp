#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		gameplay_controller = nullptr;

		delete(gameplay_controller);
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::onPositionChanged(int position)
	{
		gameplay_controller->onPositionChanged(position);
	}

	void GameplayService::onDeath()
	{
		gameplay_controller->onDeath();
	}
}