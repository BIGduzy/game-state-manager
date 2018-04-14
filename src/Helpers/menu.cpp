#include "menu.h"

#include <iostream>

Menu::Menu(sf::RenderWindow& window, std::vector<MenuItem> menuItems):
	window(window),
	menuItems(menuItems) {}

void Menu::selectNext() {
	selectedIndex = (selectedIndex < static_cast<uint8_t>(menuItems.size()) - 1) ? selectedIndex + 1 : 0;
}

void Menu::selectPrevious() {
	selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : static_cast<uint8_t>(menuItems.size()) - 1;
}

void Menu::onPress() {
	if (selectedIndex >= 0) {
		menuItems[selectedIndex].onPress();
	}
}

void Menu::onMouseMoved(sf::Event evt) {
	selectedIndex = -1;
	for (uint8_t i = 0; i < menuItems.size(); ++i) {
		const auto& menuItem = menuItems[i];
		if (menuItem.getBounds().contains(static_cast<float>(evt.mouseMove.x), static_cast<float>(evt.mouseMove.y))) {
			selectedIndex = i;
			break;
		}
	}
}

void Menu::render() const {
	for (uint8_t i = 0; i < menuItems.size(); ++i) {
		const auto& menuItem = menuItems[i];
		if (i == selectedIndex) {
			menuItem.renderSelected();
		} else {
			menuItem.render();
		}
	}
}