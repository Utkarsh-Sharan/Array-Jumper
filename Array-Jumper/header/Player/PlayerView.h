#pragma once
#include "UI/UIElement/ImageView.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;
		PlayerController* player_controller;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer(); 
		void loadPlayer(); 
		void calculatePlayerDimensions();
		void updatePlayerPosition(); 
		sf::Vector2f calculatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}