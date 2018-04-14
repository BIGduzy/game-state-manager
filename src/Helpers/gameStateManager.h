#pragma once

#include <memory>
#include <vector>
#include "../states/State.h"

/**
* @class GameStateManager
* @file GameStateManager.h
* @brief Singleton class used to switch game states.
*
* @details
* The class behaves like a stack and returns a shared_ptr to the top state with the getCurrentState method.
* The game loop uses this class to update and render the top state.
* States can be switched by popping and pushing states.
*
*/
class GameStateManager {
private:
	// Disallow creating an instance of this object
	GameStateManager();

private:
	/**
	* @brief Std vector with shared_ptrs to the pushed States
	*/
	static std::vector<std::shared_ptr<State>> states;
public:
	/**
	* @brief Returns top of the stack
	*/
	static std::shared_ptr<State> getCurrentState();

	/**
	* @brief Pops top of the stack
	*
	* @details
	* Calls the cleanUp method of the State at the top of the stack and then pops it off
	*/
	static void popState();

	/**
	* @brief Pushes given shared_ptr of State to the states stack
	* @param state, shared_ptr that needs to be pushed
	*
	* @details
	* Pushes the State to the stack and then calls the States init method to initialize it
	*/
	static void pushState(std::shared_ptr<State> state);
};