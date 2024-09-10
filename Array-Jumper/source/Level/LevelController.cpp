#include "Level/LevelController.h"
#include "Level/LevelView.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_view = new LevelView(this);
		level_model = new LevelModel();
	}

	LevelController::~LevelController() 
	{

	}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	BlockType LevelController::getCurrentBoxValue(int currentPosition)
	{
		return level_model->getCurrentBoxValue(currentPosition);
	}

	BoxDimensions LevelController::getBoxDimensions()
	{
		return level_view->getBoxDimensions();
	}
}