#include "Player/PlayerView.h"
#include "Player/PlayerController.h"
#include "Player/PlayerModel.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Level;

	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;

		game_window = nullptr;
		player_image = new ImageView();
	}

	PlayerView::~PlayerView()
	{
		game_window = nullptr;
		player_image = nullptr;

		delete(game_window);
		delete(player_image);
	}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		loadPlayer();
	}

	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}

	void PlayerView::calculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}

	void PlayerView::initializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(0, 0));
	}

	void PlayerView::update()
	{
		updatePlayerPosition();
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
	}

	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		//printf("x: %f, y: %f", xPosition, yPosition);

		return sf::Vector2f(xPosition, yPosition);
	}

	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		}
	}

	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}