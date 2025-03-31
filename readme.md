# Advanced Tic Tac Toe

## 🎮 About the Project
This is an advanced version of the classic Tic Tac Toe game, built using **SFML 3.0**. The game features:

🔹 A clean and interactive UI with smooth animations.  
🔹 AI opponent with strategic move selection.  
🔹 Sound effects for player moves and game outcomes.  
🔹 Proper event handling with SFML 3.0 compatibility.  

---

## 🛠️ How to Run

### **Prerequisites**
Make sure you have the following installed:
- **SFML 3.0**
- A C++ compiler that supports C++17 or later

### **Steps to Build and Run**
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/Advanced-Tic-Tac-Toe.git
   cd Advanced-Tic-Tac-Toe
   ```
2. Compile the project using `make`:
   ```sh
   make
   ```
3. Run the game:
   ```sh
   ./tic_tac_toe
   ```

---

## 🧠 Features Implemented

🔹 **Player vs AI Mode** – Play against an AI that makes strategic moves.  
🔹 **Sound Effects** – Audio feedback for moves and game outcomes.  
🔹 **Mouse Input Support** – Click to place your move.  
🔹 **SFML 3.0 Compatibility** – Proper event handling and rendering updates.  

---

## 🏗️ Code Overview

### **Core Files**
- `main.cpp` → Handles game loop, event processing, and rendering.
- `logic.hpp/.cpp` → Contains game logic like move validation and AI decisions.
- `draw.hpp/.cpp` → Handles drawing the grid, Xs, and Os.
- `global.hpp` → Stores global variables.

### **Key Functions**
🔹 `cell_selector(x, y)` – Determines the selected cell based on click coordinates.  
🔹 `ai_player()` – Controls AI move selection.  
🔹 `win_condition()` – Checks if a player has won or if it’s a tie.  

---

## 🎵 Audio Support
- **p1.wav** → Sound for Player 1 (O)
- **p2.wav** → Sound for Player 2 (X / AI)
- **GameOver.wav** → Defeat sound
- **GameWon.wav** → Victory sound
- **Draw.wav** → Tie sound

Ensure these files are placed in the same directory as the executable.

---

## 📌 Future Improvements
🔹 Improve AI strategy for a more challenging gameplay.  
🔹 Add a restart button for quick rematches.  
🔹 Enhance UI for a better user experience.  

---

## 🤝 Contributing
If you'd like to contribute, feel free to fork the repo and submit a pull request!

---

## 📜 License
This project is licensed under the MIT License.
