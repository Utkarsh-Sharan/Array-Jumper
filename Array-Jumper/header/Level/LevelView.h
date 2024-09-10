#pragma once
#include "UI/UIElement/ImageView.h"
#include "Level/LevelModel.h"

namespace Level
{
	class LevelController;

	class LevelView
	{
	private:
		sf::RenderWindow* game_window;
		LevelController* level_controller;

		UI::UIElement::ImageView* background_image;
		const float background_alpha = 110.f;

		UI::UIElement::ImageView* box_image;
		BoxDimensions box_dimensions;

		void calculateBoxDimensions();
		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void deleteImages();

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void initialize();
		void update();
		void render();
	};
}