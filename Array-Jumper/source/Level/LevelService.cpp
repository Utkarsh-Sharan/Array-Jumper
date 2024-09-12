#include "Level/LevelService.h"

namespace Level
{
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService() 
	{ 
		destroy(); 
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	void LevelService::loadNextLevel()
	{
		level_controller->loadNextLevel();
	}

	int LevelService::getCurrentLevelNumber()
	{
		return level_controller->getCurrentLevelNumber();
	}

	bool LevelService::isLastLevel()
	{
		return level_controller->isLastLevel();
	}

	BoxDimensions LevelService::getBoxDimensions()
	{
		return level_controller->getBoxDimensions();
	}

	BlockType LevelService::getCurrentBoxValue(int currentPosition)
	{
		return level_controller->getCurrentBoxValue(currentPosition);
	}

	void LevelService::reset()
	{
		level_controller->reset();
	}

	void LevelService::destroy()
	{
		level_controller = nullptr;

		delete(level_controller);
	}
}