#include "Player/PlayerController.h"
#include "Player/PlayerModel.h"
#include "Player/PlayerView.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
		destroy();
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize();

		setPlayerState(PlayerState::ALIVE);
	}

	void PlayerController::update()
	{
		//player_model->update();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}
	
	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	void PlayerController::destroy()
	{
		player_model = nullptr;
		player_view = nullptr;

		delete(player_model);
		delete(player_view);
	}
}