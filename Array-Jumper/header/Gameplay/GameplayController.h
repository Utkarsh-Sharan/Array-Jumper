#pragma once

#include "Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:
		bool isObstacle(Level::BlockType value);
		void processObstacle();

		bool isEndBlock(Level::BlockType value);
		void processEndBlock();

		void loadNextLevel();
		bool isLastLevel();

		void gameOver();
		void gameWon();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();

		void onPositionChanged(int position);

		void onDeath();
	};
}