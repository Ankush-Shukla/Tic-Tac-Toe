#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "logic.hpp"

extern std::vector<sf::CircleShape> circles_list;
extern std::vector<sf::RectangleShape> crosses_list;

int main() {
    std::vector<sf::RectangleShape> rectangles = create_grid();

    sf::RenderWindow window(sf::VideoMode({win_width, win_height}), "Tic Tac Toe");

    while (window.isOpen() && !end_game) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) 
                window.close();

            // Handle left mouse button press
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                    std::cout << "Mouse x: " << mouseButtonPressed->position.x << std::endl;
                    std::cout << "Mouse y: " << mouseButtonPressed->position.y << std::endl;

                    // ✅ Get cell position from `cell_selector`
                    std::pair<int, int> cellPos = cell_selector(mouseButtonPressed->position.x, mouseButtonPressed->position.y);
                }
            }
        }

        // Draw everything
        window.clear();
        for (const auto& rectangle : rectangles) {
            window.draw(rectangle);
        }
        for (const auto& cir : circles_list) {
            window.draw(cir);
        }
        for (const auto& cross : crosses_list) {
            window.draw(cross);
        }
        window.display();
    }

    return 0;
}
