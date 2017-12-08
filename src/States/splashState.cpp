#include "splashState.h"
#include "../Helpers/gameStateManager.h"

SplashState::SplashState(sf::RenderWindow& _window):
        State(_window)
{
    if(!font.loadFromFile("Resources/Font/Camouflage.ttf")) {
        std::cout << "Could not load Camouflage.ttf" << std::endl;
    }
};

void SplashState::init() {
    text.setFont(font);
    text.setString("Press Enter to start");
    // TODO: Better center d;)
    text.setPosition({window.getSize().x / 2 - 7 * 24, window.getSize().y / 2 - 24});
}

void SplashState::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        GameStateManager::pushState(std::make_unique<PlayState>(window));
    }
}

void SplashState::render() const {
    window.draw(text);
}

void SplashState::cleanUp() {
    // Free heap
    std::cout << "SplashState: Clean up" << std::endl;
}