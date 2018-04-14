#ifndef GSM_SPLASHSTATE_H
#define GSM_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"
#include "menuState.h"

class SplashState : public State {
private:
	sf::CircleShape ball;
	sf::Vector2f ballPosition, ballVelocity;
    sf::Font font;
    sf::Text text;
public:
    SplashState(sf::RenderWindow& _window);

    void init() override;
    void update() override;
    void render() const override;
    void cleanUp() override;
};


#endif //GSM_SPLASHSTATE_H
