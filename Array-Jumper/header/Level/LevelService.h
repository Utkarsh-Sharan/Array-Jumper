#pragma once
#include "Level/LevelController.h"

namespace Level
{
	class LevelService
	{
	private:
		LevelController* level_controller;

		void destroy();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void loadNextLevel();
		int getCurrentLevelNumber();
		bool isLastLevel();

		BoxDimensions getBoxDimensions();
		BlockType getCurrentBoxValue(int currentPosition);

		void reset();
	};
}