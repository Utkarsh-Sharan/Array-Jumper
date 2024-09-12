#include "Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel()
	{

	}

	LevelModel::~LevelModel()
	{

	}

	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return level_configuration.levels[current_level_index].level_boxes[currentPosition];
	}
}