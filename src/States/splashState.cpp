#include "splashState.h"
#include "../Helpers/gameStateManager.h"

SplashState::SplashState(sf::RenderWindow& _window):
    State(_window),
	ball(30),
	ballPosition(50, 50),
	ballVelocity(1, 1)
{
};

void SplashState::init() {
	std::cout << "SplashState: Init" << std::endl;
	
	if (!font.loadFromFile("Resources/Font/Camouflage.ttf")) {
		std::cout << "Could not load Camouflage.ttf" << std::endl;
	}
    text.setFont(font);
    text.setString("Press Enter to start");
	// TODO: Better center d;)
    text.setPosition({static_cast<float>(window.getSize().x) / 2 - 7 * 24, static_cast<float>(window.getSize().y) / 2 - 24});
	
	ball.setFillColor(sf::Color(200, 20, 150));
}

void SplashState::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        GameStateManager::pushState(std::make_unique<PlayState>(window));
    }

	if (ballPosition.x + ball.getRadius() / 2 < 0 || ballPosition.x + ball.getRadius() / 2 >= window.getSize().x) {
		ballVelocity.x *= -1;
	}
	if (ballPosition.y + ball.getRadius() / 2 < 0 || ballPosition.y + ball.getRadius() / 2 >= window.getSize().y) {
		ballVelocity.y *= -1;
	}

	ballPosition += ballVelocity;
	ball.setPosition(ballPosition);
}

void SplashState::render() const {
    window.draw(text);
	window.draw(ball);
}

void SplashState::cleanUp() {
    // Free heap
    std::cout << "SplashState: Clean up" << std::endl;
}