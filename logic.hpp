#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "draw.hpp"
#include <random>

//check if the game has been won
void win_condition(){
    //checking for horizontal win
    for (int i = 0; i < 3; i++){
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '0'){
            std::cout << "Player " << grid[i][0] << " wins!" << std::endl;
            end_game = true;
        }
        
    }
    //checking for vertical win
    for (int i = 0; i < 3; i++){
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '0'){
            std::cout << "Player " << grid[0][i] << " wins!" << std::endl;
            end_game = true;
        }
        
    }
    //checking for diagonal win
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '0'){
        std::cout << "Player " << grid[0][0] << " wins!" << std::endl;
        end_game = true;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '0'){
        std::cout << "Player " << grid[0][2] << " wins!" << std::endl;
        end_game = true;
    }   
    //checking for draw
    int count = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i][j] != '0' && !end_game){
                count++;
            }
        }
    }
    if (count == 9){
        std::cout << "It's a draw!" << std::endl;
        end_game = true;
    }

}
std::vector<sf::CircleShape> circles_list;
std::vector<sf::RectangleShape> crosses_list;
void ai_player(){
    srand(time(0));
    int row = rand() % 3;
    int col = rand() % 3;
    while (grid[row][col] != '0'){
        row = rand() % 3;
        col = rand() % 3;
    }
    float center_x = col * cell_size + (cell_size / 2);
    float center_y = row * cell_size + (cell_size / 2);
    std::vector<sf::RectangleShape> newCross = create_cross(center_x, center_y);
    crosses_list.insert(crosses_list.end(), newCross.begin(), newCross.end());
    p1_turn = true;
    p2_turn = false;
    grid[row][col] = 'X';
    win_condition();

}
// Lists to store drawn shapes


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
        win_condition();
    } 
    else if (p2_turn && grid[row][col] == '0' && grid[row][col] != 'X' && grid[row][col] != 'O') {
        // std::vector<sf::RectangleShape> newCross = create_cross(center_x, center_y);
        // crosses_list.insert(crosses_list.end(), newCross.begin(), newCross.end());
        // p1_turn = true;
        // p2_turn = false;
        // grid[row][col] = 'X';
        ai_player();
        win_condition();
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

    