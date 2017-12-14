#include "gameStateManager.h"

GameStateManager::GameStateManager(){};

// Static member variables must be declared
std::vector<std::shared_ptr<State>> GameStateManager::states;

std::shared_ptr<State> GameStateManager::getCurrentState() {
    return states.back();
}

void GameStateManager::popState() {
    if (states.size() > 0) {
        states.back()->cleanUp();
        states.pop_back();
    }
}

void GameStateManager::pushState(std::shared_ptr<State> state) {
    states.push_back(state);
    state->init();
}