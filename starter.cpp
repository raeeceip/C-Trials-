#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game");

    // load the player texture
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png"))
    {
        std::cout << "Failed to load player texture!" << std::endl;
        return -1;
    }

    // create the player sprite
    sf::Sprite playerSprite(playerTexture);
    playerSprite.setPosition(400, 300);

    // game loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // move the player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerSprite.move(-5, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerSprite.move(5, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerSprite.move(0, -5);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerSprite.move(0, 5);
        }

        // draw the player sprite
        window.clear();
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}
