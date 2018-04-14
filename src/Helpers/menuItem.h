#pragma once

#include <functional>
#include <SFML\Graphics.hpp>

/**
* @class MenuItem
* @file MenuItem.h
* @brief Class to be used with the Menu helper class
*
* @details
* This class can be given to the Menu to make a button.
* It contains a action that gets called when it is pressed and render function to draw it self on a window.
*
*/
class MenuItem {
private:
	/**
	* @brief SFML window to draw on
	*/
	sf::RenderWindow& window;
	/**
	* @brief Function that gets called when the menuItem is pressed
	*/
	std::function<void()> action;
	/**
	* @brief Shape of the button
	*/
	sf::RectangleShape button;
	/**
	* @brief Shape of the button when selected
	*/
	sf::RectangleShape selectedButton;
	/**
	* @brief Button label
	*/
	sf::Text text;
public:
	/**
	* @brief constructor
	* @param window SFML window to draw on
	* @param action Function that gets called when the menuItem is pressed
	* @param size Size of the button shape
	* @param position Position of the menuItem
	* @param text SFML text object used as the label for the menuItem
	*
	*/
	MenuItem(sf::RenderWindow& window, std::function<void()> action, sf::Vector2f size, sf::Vector2f position, sf::Text text);

	/**
	* @brief Getter for shape bounding box
	* @return The bounding box
	*/
	sf::FloatRect getBounds() const { return button.getGlobalBounds(); }

	/**
	* @brief Calls the action
	*/
	void onPress();
	/**
	* @brief Renders button with label inside
	*/
	void render() const;
	/**
	* @brief Uses render function to render button/label but with a different color
	*/
	void renderSelected() const;
	/**
	* @brief Renders the label for the menuItem
	*/
	void renderText() const;
};

