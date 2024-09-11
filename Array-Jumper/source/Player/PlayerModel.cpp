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

	float PlayerModel::getPosition()
	{
		return current_position;
	}

	void PlayerModel::setPosition(float new_position)
	{
		current_position = new_position;
	}

	int PlayerModel::getCurrentLives()
	{
		return current_lives;
	}

	void PlayerModel::decrementLife()
	{
		current_lives--;
	}

	void PlayerModel::resetPosition()
	{
		setPosition(0.0f);
	}

	void PlayerModel::resetPlayer()
	{
		setPlayerState(PlayerState::ALIVE);
		setPosition(0.0f);
		current_lives = max_lives;
	}
}