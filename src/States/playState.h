#ifndef GSM_PLAYSTATE_H
#define GSM_PLAYSTATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "state.h"
#include "splashState.h"

class PlayState : public State{
private:
    int count = 0;
    sf::CircleShape shape;
public:
    PlayState(sf::RenderWindow& _window);

    void init() override;
    void update() override;
    void render() override;
    void cleanUp() override;
};


#endif //GSM_PLAYSTATE_H
