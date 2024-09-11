#include "Player/PlayerController.h"
#include "Player/PlayerModel.h"
#include "Player/PlayerView.h"

#include "Global/ServiceLocator.h"

#include "Level/LevelData.h"

namespace Player
{
	using namespace Global;
	using namespace Sound;
	using namespace Level;
	using namespace Event;

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

		event_service = ServiceLocator::getInstance()->getEventService();
	}

	void PlayerController::update()
	{
		player_model->update();
		player_view->update();

		readInput();
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			move(MovementDirection::BACKWARD);
		}
	}

	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = getCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->setPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}

	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
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

	int PlayerController::getCurrentPosition()
	{
		return player_model->getPosition();
	}

	void PlayerController::destroy()
	{
		player_model = nullptr;
		player_view = nullptr;

		delete(player_model);
		delete(player_view);
	}
}