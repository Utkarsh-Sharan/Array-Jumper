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
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		initializeImages();
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::updateImages()
	{
		background_image->update();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::drawLevel()
	{
		background_image->render();
	}

	void LevelView::deleteImages()
	{
		background_image = nullptr;

		delete(background_image);
	}
}