#include "Player/PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel()
	{

	}

	PlayerModel::~PlayerModel()
	{

	}

	void PlayerModel::initialize()
	{

	}

	void PlayerModel::update()
	{

	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState new_player_state)
	{
		player_state = new_player_state;
	}

	int PlayerModel::getPosition()
	{
		return current_position;
	}

	void PlayerModel::setPosition(int new_position)
	{
		current_position = new_position;
	}
}