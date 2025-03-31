#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "logic.hpp"
#include <thread>
#include <chrono>
#include <SFML/Audio.hpp>

int main()
{
    sf::SoundBuffer buffer("p1.wav");
    sf::SoundBuffer buffer2("p2.wav");
    sf::Music Defeat("GameOver.wav");
    sf::Music Victory("GameWon.wav");
    sf::Music Draw("Draw.wav");
    sf::Sound playerO(buffer);
    sf::Sound playerX(buffer2);
    std::vector<sf::RectangleShape> rectangles = create_grid();

    sf::RenderWindow window(sf::VideoMode({win_width, win_height}), "Tic Tac Toe");
    
    while (window.isOpen() && !end_game)
    {
        char result = win_condition();
        if (result != '0')
        {
            end_game = true;
            if (result == 'T'){
                Draw.play();
                std::cout << "It's a tie!" << std::endl;
                while( Draw.getStatus() == sf::Music::Status::Playing){sf::sleep(sf::milliseconds(100));}
            }
            else {
                if(result == 'X'){
                    Defeat.play();
                }
                else if(result == 'O'){
                    Victory.play();
                }
                std::cout << "Player " << result << " wins!" << std::endl;
                // Wait until whichever music is playing finishes
                while (Defeat.getStatus() == sf::Music::Status::Playing || Victory.getStatus() == sf::Music::Status::Playing) {
                    sf::sleep(sf::milliseconds(100));
                }
            }
        }
        
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    playerO.play();
                    std::cout << "Mouse x: " << mouseButtonPressed->position.x << std::endl;
                    std::cout << "Mouse y: " << mouseButtonPressed->position.y << std::endl;
                    std::pair<int, int> cellPos = cell_selector(mouseButtonPressed->position.x, mouseButtonPressed->position.y);
                }
            }
            else if (p2_turn)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(450));
                playerX.play();
                ai_player();
                p2_turn = false;
                p1_turn = true;
            }
        }

        window.clear();
        for (const auto &rectangle : rectangles)
            window.draw(rectangle);
        for (const auto &cir : circles_list)
            window.draw(cir);
        for (const auto &cross : crosses_list)
            window.draw(cross);
        window.display();
    }

    return 0;
}
