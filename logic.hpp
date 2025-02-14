#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "draw.hpp"

std::vector<sf::CircleShape> circles_list;
std::vector<sf::RectangleShape> crosses_list;

std::pair<int, int> cell_selector(int x, int y)
{
    int col = x / cell_size;
    int row = y / cell_size;

    float center_x = col * cell_size + (cell_size / 2);
    float center_y = row * cell_size + (cell_size / 2);

    std::cout << "Cell [" << row << "," << col << "] selected" 
              << " | P1 Turn: " << std::boolalpha << p1_turn 
              << " | P2 Turn: " << p2_turn << std::endl;

    // Place the correct shape
    if (p1_turn)
    {
        create_circle(center_x, center_y);
        circles_list.push_back(create_circle(center_x, center_y));
        p1_turn = false;
        p2_turn = true;
    }
    else
    {
        create_cross(center_x, center_y);
        
        p1_turn = true;
        p2_turn = false;
    }

    return {col, row};  // Now returning std::pair<int, int>
}

#endif // LOGIC_HPP
