#include "gameStateManager.h"

GameStateManager::GameStateManager(){};

// Static member variables must be declared
std::vector<State*> GameStateManager::states;

State* GameStateManager::getCurrentState() {
    return (states.size() > 0) ? states.back() : nullptr;
}

void GameStateManager::popState() {
    if (states.size() > 0) {
        states.back()->cleanUp();
        // Is this necessary?
        delete states.back();
        states.pop_back();
    }
}

void GameStateManager::pushState(State* state) {
    states.push_back(state);
    state->init();
}