#ifndef GSM_SPLASHSTATE_H
#define GSM_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"
#include "playState.h"

class SplashState : public State{
public:
    SplashState(sf::RenderWindow& _window);
    sf::Font font;
    sf::Text text;

    void init() override;
    void update() override;
    void render() override;
    void cleanUp() override;
};


#endif //GSM_SPLASHSTATE_H
