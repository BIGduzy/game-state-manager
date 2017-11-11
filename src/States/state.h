#ifndef GSM_STATE_H
#define GSM_STATE_H

#include <SFML/Graphics.hpp>

class State {
protected:
    sf::RenderWindow& window;
public:
    State(sf::RenderWindow& _window): window(_window) {}

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void cleanUp() = 0;
};

#endif //GSM_STATE_H
