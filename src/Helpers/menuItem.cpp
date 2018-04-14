#include "menuItem.h"

#include <iostream>

MenuItem::MenuItem(sf::RenderWindow& window, std::function<void()> action, sf::Vector2f size, sf::Vector2f position, sf::Text text):
	window(window),
	action(action),
	button(size),
	selectedButton(size),
	text(text) {
	button.setPosition(position);
	selectedButton.setPosition(position);
	selectedButton.setFillColor({200,0,0});
	this->text.setFillColor(sf::Color{0,0,0});
}

void MenuItem::onPress() {
	action();
}

void MenuItem::render() const {
	window.draw(button);
	renderText();
}

void MenuItem::renderSelected() const {
	window.draw(selectedButton);
	renderText();
}

void MenuItem::renderText() const {
	// For some reason we can't get the globalBounds in the constructor so we need to create a new Text object
	// Center the text inside the button
	sf::FloatRect textRect = text.getGlobalBounds();
	sf::Text t(text);
	t.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	t.setPosition({button.getPosition().x + button.getSize().x / 2, button.getPosition().y + button.getSize().y / 2});
	window.draw(t);
}