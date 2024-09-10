#include "Level/LevelView.h"
#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Level
{
	using namespace Global;
	using namespace UI::UIElement;

	LevelView::LevelView(LevelController* controller)
	{
		game_window = nullptr;
		level_controller = controller;

		createImages();
	}

	LevelView::~LevelView()
	{
		deleteImages();
	}

	void LevelView::createImages()
	{
		background_image = new ImageView();
		box_image = new ImageView();
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		calculateBoxDimensions();
		initializeImages();
	}

	void LevelView::calculateBoxDimensions()
	{
		if (!game_window)
			return;

		box_dimensions.box_width = 300.f;
		box_dimensions.box_height = 300.f;
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);

		box_image->initialize(Config::box_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::updateImages()
	{
		background_image->update();
		box_image->update();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::drawLevel()
	{
		background_image->render();
		box_image->render();
	}

	void LevelView::deleteImages()
	{
		background_image = nullptr;
		box_image = nullptr;

		delete(background_image);
		delete(box_image);
	}
}