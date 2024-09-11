#pragma once

#include "Player/MovementDirection.h"
#include "Event/EventService.h"

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

		Event::EventService* event_service;

		void readInput();
		void move(MovementDirection direction);
		void jump(MovementDirection direction);
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