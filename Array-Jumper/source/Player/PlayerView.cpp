#include "Player/PlayerView.h"
#include "Player/PlayerController.h"
#include "Player/PlayerModel.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;

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
		player_width = 1000.0f;
		player_height = 1000.0f;
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
		return sf::Vector2f(0, 0);
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