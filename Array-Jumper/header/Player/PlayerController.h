#pragma once

#include "Player/MovementDirection.h"

namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		void move(MovementDirection direction);
		bool isPositionInBound(int targetPosition);
		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
	};
}