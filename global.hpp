#ifndef GLOBAL_H
#define GLOBAL_H
// Window settings
unsigned int win_width = 900;
unsigned int win_height = 900;
int cell_size = 300;
int grid_size = 3;

// Game state
bool p1_turn = true;
bool p2_turn = false;
bool end_game = false;

// Grid Status
char grid[3][3] = {'0', '0', '0',
                   '0', '0', '0',
                   '0', '0', '0'};
//Game Sounds

#endif // GLOBAL_H
