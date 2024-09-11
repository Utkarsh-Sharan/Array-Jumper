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

		void initialize();
		void update();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		float getPosition();
		void setPosition(float new_position);

		void resetPlayer();
	};
}