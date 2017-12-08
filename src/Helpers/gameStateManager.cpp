#include <memory>
#include "gameStateManager.h"

GameStateManager::GameStateManager(){};

// Static member variables must be declared
std::vector<std::unique_ptr<State>> GameStateManager::states;

std::unique_ptr<State>& GameStateManager::getCurrentState() {
    return states.back();
}

void GameStateManager::popState() {
    if (states.size() > 0) {
        states.back()->cleanUp();
        states.pop_back();
    }
}

void GameStateManager::pushState(std::unique_ptr<State> state) {
    // TODO: This does not work
    states.push_back(state);
    state->init();
}