#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "draw.hpp"


// Lists to store drawn shapes
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

    // Only place a circle or cross if it's the player's turn
    if (p1_turn && grid[row][col] == '0' && grid[row][col] != 'X' && grid[row][col] != 'O') {
        circles_list.push_back(create_circle(center_x, center_y));
        p1_turn = false;
        p2_turn = true;
        grid[row][col] = 'O';
    } 
    else if (p2_turn && grid[row][col] == '0' && grid[row][col] != 'X' && grid[row][col] != 'O') {
        std::vector<sf::RectangleShape> newCross = create_cross(center_x, center_y);
        crosses_list.insert(crosses_list.end(), newCross.begin(), newCross.end());
        p1_turn = true;
        p2_turn = false;
        grid[row][col] = 'X';
    }
    else {
        std::cout << "Cell [" << row << "," << col << "] is already occupied" << std::endl;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
return {col, row};  // Return the selected cell position
}



#endif // LOGIC_HPP

    