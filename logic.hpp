#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "draw.hpp"
#include <random>
#include <map>
#include <string>

bool t;
int bestScore;
int bestMove[2] = {-1, -1};
std::map<std::string, int> scores = {{"O", -1}, {"X", +1}, {"T", 0}};

// ✅ Check if the game is a draw
bool is_draw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == '0')
                return false; // Empty cell found, game is not a draw
    return true;              // No empty cells, it's a draw
}

// ✅ Check if the game has been won
char win_condition() {
    // Check horizontal wins
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == 'X' || grid[i][0] == 'O') &&
            grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            return grid[i][0];  // Winner on this row
    }
    // Check vertical wins
    for (int i = 0; i < 3; i++) {
        if ((grid[0][i] == 'X' || grid[0][i] == 'O') &&
            grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
            return grid[0][i];  // Winner on this column
    }
    // Check diagonal wins
    if ((grid[0][0] == 'X' || grid[0][0] == 'O') &&
         grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
        return grid[0][0];  // Diagonal win
    if ((grid[0][2] == 'X' || grid[0][2] == 'O') &&
         grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return grid[0][2];  // Anti-diagonal win

    if (is_draw())
        return 'T';  // Tie game

    return '0';  // No winner yet
}
// ✅ Minimax function
int minimax(char grid[3][3], int depth, bool isMaximizing)
{
    char winner = win_condition();
    if (winner == 'X')
        return 1;
    if (winner == 'O')
        return -1;
    if (winner == 'T')
        return 0;

    if (isMaximizing)
    { // AI's turn (maximize score)
        int bestScore = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == '0')
                {                     // Empty cell
                    grid[i][j] = 'X'; // AI move
                    int score = minimax(grid, depth + 1, false);
                    grid[i][j] = '0'; // Undo move
                    bestScore = std::max(bestScore, score);
                }
            }
        }
        return bestScore;
    }
    else
    { // Player's turn (minimize score)
        int bestScore = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == '0')
                {                     // Empty cell
                    grid[i][j] = 'O'; // Player move
                    int score = minimax(grid, depth + 1, true);
                    grid[i][j] = '0'; // Undo move
                    bestScore = std::min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

std::vector<sf::CircleShape> circles_list;
std::vector<sf::RectangleShape> crosses_list;

// ✅ AI Player Function
void ai_player()
{
    if (end_game)
        return; // Stop AI if the game is over

    bestScore = -1000;
    bestMove[0] = -1;
    bestMove[1] = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == '0')
            {                     // Empty cell
                grid[i][j] = 'X'; // AI move
                int score = minimax(grid, 0, false);
                grid[i][j] = '0'; // Undo move

                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove[0] = i;
                    bestMove[1] = j;
                }
            }
        }
    }

    if (bestMove[0] != -1 && bestMove[1] != -1)
    {
        float center_x = bestMove[1] * cell_size + (cell_size / 2);
        float center_y = bestMove[0] * cell_size + (cell_size / 2);
        std::vector<sf::RectangleShape> newCross = create_cross(center_x, center_y);
        crosses_list.insert(crosses_list.end(), newCross.begin(), newCross.end());
        grid[bestMove[0]][bestMove[1]] = 'X'; // AI places 'X'
        p1_turn = true;
        p2_turn = false;
    }
}

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
    if (p1_turn && grid[row][col] == '0' && grid[row][col] != 'X' && grid[row][col] != 'O')
    {
        circles_list.push_back(create_circle(center_x, center_y));
        p1_turn = false;
        p2_turn = true;
        grid[row][col] = 'O';
        win_condition();
    }
    else if (p2_turn && grid[row][col] == '0' && grid[row][col] != 'X' && grid[row][col] != 'O')
    {
        // std::vector<sf::RectangleShape> newCross = create_cross(center_x, center_y);
        // crosses_list.insert(crosses_list.end(), newCross.begin(), newCross.end());
        // p1_turn = true;
        // p2_turn = false;
        // grid[row][col] = 'X';
        ai_player();
        win_condition();
    }
    else
    {
        std::cout << "Cell [" << row << "," << col << "] is already occupied" << std::endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return {col, row}; // Return the selected cell position
}

#endif // LOGIC_HPP
