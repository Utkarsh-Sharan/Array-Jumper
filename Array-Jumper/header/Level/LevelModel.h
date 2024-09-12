#pragma once
#include "Level/LevelData.h"
#include "Level/LevelConfiguration.h"

namespace Level
{
	struct BoxDimensions
	{
		float box_width;
		float box_height;
		float box_spacing;

		float box_spacing_percentage = 0.3f;
		float bottom_offset = 200.f;
	};

	class LevelModel
	{
	private:
		LevelConfiguration level_configuration;
		int current_level_index;

	public:
		LevelModel();
		~LevelModel();

		void loadNextLevel();
		int getCurrentLevelNumber();
		bool isLastLevel();

		BlockType getCurrentBoxValue(int currentPosition);

		void reset();
	};
}