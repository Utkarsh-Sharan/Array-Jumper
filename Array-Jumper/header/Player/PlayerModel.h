#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:
		PlayerState player_state;
		int current_position;

	public:
		PlayerModel();
		~PlayerModel();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getPosition();
		void setPosition(int new_position);
	};
}