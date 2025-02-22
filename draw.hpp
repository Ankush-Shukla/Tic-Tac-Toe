#ifndef DRAW_HPP
#define DRAW_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "global.hpp"  // Ensure p1_turn, p2_turn are declared here

std::vector<sf::RectangleShape> create_grid()
{
    std::vector<sf::RectangleShape> grid_lines;

    // Horizontal lines
    for (int i = 1; i < grid_size; i++)
    {
        sf::RectangleShape line(sf::Vector2f(win_width, 2));
        line.setFillColor(sf::Color::White);
        line.setPosition(sf::Vector2f(0, i * cell_size));
        grid_lines.push_back(line);
    
    }

    // Vertical lines
    for (int j = 1; j < grid_size; j++)
    {
        sf::RectangleShape line(sf::Vector2f(2, win_height));
        line.setFillColor(sf::Color::White);
        line.setPosition(sf::Vector2f(j * cell_size, 0));
        grid_lines.push_back(line);
    }

    return grid_lines;
}

sf::CircleShape create_circle(float x, float y) {
    sf::CircleShape circle(120);  // Corrected radius to match your main.cpp
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(5);
    circle.setOutlineColor(sf::Color::White);
    
    circle.setOrigin({120, 120});  // Centering properly
    circle.setPosition({x, y});  

    return circle;  // ✅ Ensure it returns a single `sf::CircleShape`
}


std::vector<sf::RectangleShape> create_cross(float x, float y)
{
    std::vector<sf::RectangleShape> cross;

    sf::RectangleShape line1(sf::Vector2f(240, 5)); // Width, thickness
    line1.setFillColor(sf::Color::White);
    line1.setOrigin({120, 2.5}); // Center it
    line1.setPosition({x, y});
    line1.setRotation(sf::degrees(45)); // 45 degrees
    cross.push_back(line1);

    sf::RectangleShape line2(sf::Vector2f(240, 5));
    line2.setFillColor(sf::Color::White);
    line2.setOrigin({120, 2.5});
    line2.setPosition({x, y});
    line2.setRotation(sf::degrees(-45)); // -45 degrees
    cross.push_back(line2);

    return cross;
}

#endif // DRAW_HPP
