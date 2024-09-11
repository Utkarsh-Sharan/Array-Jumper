#include "Player/PlayerService.h"
#include "Player/PlayerController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::takeDamage()
	{
		player_controller->takeDamage();
	}

	void PlayerService::levelComplete()
	{
		player_controller->reset();
	}

	int PlayerService::getCurrentLives()
	{
		return player_controller->getCurrentLives();
	}

	void PlayerService::destroy()
	{
		player_controller = nullptr;

		delete(player_controller);
	}
}