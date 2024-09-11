#pragma once
#include "Level/LevelData.h"
#include "Level/LevelModel.h"

namespace Level
{
	class LevelView;

	class LevelController
	{
	private:
		LevelView* level_view;
		LevelModel* level_model;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		BlockType getCurrentBoxValue(int currentPosition);
		BoxDimensions getBoxDimensions();
	};
}