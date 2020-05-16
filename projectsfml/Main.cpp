#include <SFML/Graphics.hpp>
#include "Graphics.h"
#include "Paddle.h"
#include "Ball.h"
#include "Menu.h"
#include <iostream>
#include <fstream>

const unsigned WINDOW_WIDTH = 1920;
const unsigned WINDOW_HEIGHT = 1080;

const float BALL_RADIUS = 10;
const float BALL_VELOCITY_X = 20;
const float BALL_VELOCITY_Y = 5;

const float PADDLE_WIDTH = 10;
const float PADDLE_LENGTH = 180;

const float COURT_MARGIN = 10;


int main()
{
    Graphics* gameWindow = new Graphics();

// sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong"); ~ this is a simple creation of window
// till creation of menu everything is just for trying out resolutions   

    sf::VideoMode currentMode = sf::VideoMode::getDesktopMode();
    std::cout << currentMode.width << ',' << currentMode.height << '\n';

    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();


    sf::RenderWindow window;
    window.create(currentMode, "Title",
       // sf::Style::None
       // sf::Style::Fullscreen
       // sf::Style::Titlebar |
       // sf::Style::Resize |
       // sf::Style::Close
        sf::Style::Default 
    );

    Menu menu(window.getSize().x, window.getSize().y);

    window.setTitle("Pong");

    bool playing = false; // menu or ingame pause

    window.setVerticalSyncEnabled(true);

    Paddle paddleOne(PADDLE_WIDTH, PADDLE_LENGTH);
    paddleOne.SetPosition(COURT_MARGIN, WINDOW_HEIGHT/2);

    Paddle paddleTwo(PADDLE_WIDTH, PADDLE_LENGTH);
    paddleTwo.SetPosition(WINDOW_WIDTH-COURT_MARGIN, WINDOW_HEIGHT/2);

    Ball ball(BALL_RADIUS);
    ball.SetVelocity(BALL_VELOCITY_X, BALL_VELOCITY_Y);
    ball.SetPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

    // game loop
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {   
            
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
            }

            case sf::Event::KeyPressed:
                switch (event.key.code)
            case sf::Keyboard::Escape:
                playing = false;
                break;

            case sf::Event::KeyReleased:  //menu controls
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        playing = true;
                        break;
                    case 1:
                        
                        break;
                    case 2:
                    {
                        
                        std::ifstream InputFile("BESTSCORE.txt");

                        int best_score;
                        try
                        {
                            InputFile >> best_score;
                            if (best_score < 0) { throw - 1; }
                        }
                        catch (int x)
                        {
                            std::cout << "Setting best score to 0" << std::endl;
                            best_score = 0;
                        }

                        // creates it if it doesn't exist
                        std::ofstream OutputFile("BESTSCORE.txt");
                        if (!OutputFile.is_open())
                        {
                            std::cout << "Unable to read file" << std::endl;
                            return -1;
                        }

                        std::cout << "your previous best score is: " << best_score << std::endl;

                        if (paddleOne.GetScore() > best_score) { std::cout << "congratz on beating your highscore " << std::endl; OutputFile << paddleOne.GetScore(); }
                        else { OutputFile << best_score; }
                        std::cout << "Your current one is: " << paddleOne.GetScore();
                        OutputFile.close();
                        window.close();
                    }
                        break;
                    }
                    break;
                }
                break;
            }


            
        }
        if (playing) {
            paddleOne.UpdatePositionY(&window, paddleOne.PaddleOneControl());
            paddleTwo.UpdatePositionY(&window, paddleTwo.PaddleTwoControl());

            paddleOne.Update();
            paddleTwo.Update();

            ball.Update(&paddleOne, &paddleTwo, WINDOW_HEIGHT);

            if (ball.GetPositionX() > WINDOW_WIDTH) // player 1 scored
            {
                paddleOne.AddScore();
                ball.SetPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2); // reset the ball's position
            }

            if (ball.GetPositionX() < 0) // played 2 scored
            {
                paddleTwo.AddScore();
                ball.SetPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2); // reset the ball's position
            }

            
            gameWindow->Draw(&window, &paddleOne, &paddleTwo, &ball);
            
        }

        if (!playing)
        {
            window.clear(sf::Color::Black);
            menu.draw(window);
            window.display();
        }
    }

    return 0;
}