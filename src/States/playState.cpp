#include "playState.h"
#include "../Helpers/gameStateManager.h"

PlayState::PlayState(sf::RenderWindow& _window):
    State(_window),
    shape(50)
{};

void PlayState::init() {
    shape.setFillColor(sf::Color(87, 154, 179));
}

void PlayState::update() {
    shape.setPosition({count, window.getSize().y / 2 - 25});

    if (count++ > window.getSize().x) {
        GameStateManager::popState();
        GameStateManager::popState();
        GameStateManager::pushState(new SplashState(window));
    }
}

void PlayState::render() const {
    window.draw(shape);
}

void PlayState::cleanUp() {
    // Free heap
    std::cout << "PlayState: Clean up" << std::endl;
}