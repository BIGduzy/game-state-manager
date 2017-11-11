#include <iostream>
#include <SFML/Graphics.hpp>
#include "Helpers/gameStateManager.h"
#include "States/splashState.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Game State Manager");
    sf::Event event;

    SplashState splashState(window);
    GameStateManager::pushState(&splashState);

    while(window.isOpen()) {
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        State* cur = GameStateManager::getCurrentState();
        if (cur == nullptr) continue; // No state

        /**********/
        /**UPDATE**/
        /**********/
        // TODO: game loop
        // Update the active state
        cur->update();
        /**********/
        /**RENDER**/
        /**********/
        window.clear(sf::Color(200, 200, 200));
        // Draw the active state
        cur->render();
        window.display();
    }

    return 0;
}