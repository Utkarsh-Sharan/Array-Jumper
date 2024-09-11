#include "Gameplay/GameplayController.h"

#include "Global/ServiceLocator.h"
#include "Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Sound;
	using namespace Level;
	using namespace Main;

	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{

	}

	void GameplayController::onPositionChanged(int position)
	{
		BlockType value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
			processObstacle();

		if (isEndBlock(value))
			processEndBlock();
	}

	bool GameplayController::isObstacle(BlockType value)
	{
		if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
			return true;

		return false;
	}

	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	bool GameplayController::isEndBlock(BlockType value)
	{
		if (value == BlockType::TARGET)
			return true;

		return false;
	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);
		GameService::setGameState(GameState::CREDITS);
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}

	void GameplayController::gameOver()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}
}