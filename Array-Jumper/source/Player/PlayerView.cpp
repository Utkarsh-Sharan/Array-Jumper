#include "Player/PlayerView.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;

	PlayerView::PlayerView(/*PlayerController* playerController*/)
	{
		game_window = nullptr;
		player_image = new ImageView();
	}

	PlayerView::~PlayerView()
	{

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
		drawPlayer();
	}

	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
}