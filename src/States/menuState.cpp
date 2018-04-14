#include "menuState.h"
#include "../helpers/GameStateManager.h"

MenuState::MenuState(sf::RenderWindow& window):
	State(window),
	menu(window, {{
			window,
			std::function<void()>([&window]() { GameStateManager::pushState(std::make_unique<PlayState>(window)); }),
			{250, 75},
			{static_cast<float>(window.getSize().x) / 2 - 250 / 2, 150},
			{"Play game", font, 20}
		},{
			window,
			std::function<void()>([&window]() { window.close(); }),
			{250, 75},
			{static_cast<float>(window.getSize().x) / 2 - 250 / 2, 350},
			{"Exit game", font, 20}
		}
	}),
	text("Game state manager", font, 72)
{}

void MenuState::init() {
	if (!font.loadFromFile("resources/Font/Camouflage.ttf")) {
		std::cout << "Could not load Camouflage.ttf" << std::endl;
	}
	sf::FloatRect textRect = text.getGlobalBounds();
	text.setOrigin({textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f});
	text.setPosition({static_cast<float>(window.getSize().x) / 2, 46.0f});
}

void MenuState::update() {}

void MenuState::render() const {
	window.draw(text);

	menu.render();
}

void MenuState::cleanUp() {}

void MenuState::onKeyPressed(sf::Event& evt) {
	switch (evt.key.code) {
	case sf::Keyboard::Return:
		menu.onPress();
		break;
	case sf::Keyboard::Up:
		menu.selectNext();
		break;
	case sf::Keyboard::Down:
		menu.selectPrevious();
		break;
	}
}

void MenuState::onMouseButtonPressed(sf::Event& evt) {
	menu.onPress();
}

void MenuState::onMouseMoved(sf::Event& evt) {
	menu.onMouseMoved(evt);
}