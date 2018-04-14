#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include "menuItem.h"

/**
* @class Menu
* @file Menu.h
* @brief Helper class to make menu's
*
* @details
* This class can be used to create menu's.
* It has functionality for selecting menuItem by mouse or keyboard and Calls the MenuItem action when it is pressed.
*
*/
class Menu {
private:
	/**
	* @brief SFML window to draw on
	*/
	sf::RenderWindow& window;
	/**
	* @brief std vector with all menuItems
	*/
	std::vector<MenuItem> menuItems;
	/**
	* @brief Index of currently selected menu item
	*/
	int8_t selectedIndex = -1;
public:
	/**
	* @brief Constructor
	* @param window SFML window to draw on
	* @param menuItems Vector with menuItems (menu options)
	*/
	Menu(sf::RenderWindow& window, std::vector<MenuItem> menuItems);

	/**
	* @brief selects the next menu item
	*
	* @details
	* Selects the next menu item, when the select index is larger than the number of items it wraps back to 0
	*/
	void selectNext();
	/**
	* @brief selects the previous menu item
	*
	* @details
	* Select the previous menu item, when the selected index is smaller than zero it wraps back to the last menu item
	*/
	void selectPrevious();
	/**
	* @brief Calls onPress function of selected menu item
	*/
	void onPress();
	/**
	* @brief Selects menu item based on mouse position
	*/
	void onMouseMoved(sf::Event evt);
	/**
	* @brief Renders all menu items
	*/
	void render() const;
};
