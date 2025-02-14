#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "logic.hpp"
extern std::vector<sf::CircleShape> circles_list;
extern std::vector<sf::RectangleShape> crosses_list;
int main() {
    std::vector<sf::RectangleShape> rectangles = create_grid();
    std::vector<sf::CircleShape> circles;  

    sf::RenderWindow window(sf::VideoMode({win_width, win_height}), "Tic Tac Toe");

    while (window.isOpen()) {
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

                    // ✅ Create a circle at the center of the selected cell
                    sf::CircleShape newCircle(60);  // Radius = 60
                    newCircle.setFillColor(sf::Color::Transparent);
                    newCircle.setOutlineThickness(5);
                    newCircle.setOutlineColor(sf::Color::White);
                    newCircle.setPosition({cellPos.first - 60, cellPos.second - 60});  // Centering

                    // ✅ Add the circle to the list
                    circles.push_back(newCircle);
                }
            }
        }

        // Draw everything
        window.clear();
        for (const auto& rectangle : rectangles) {
            window.draw(rectangle);
        }
        for (const auto& cir : circles) {
            window.draw(cir);
        }
        window.display();
    }

    return 0;
}
