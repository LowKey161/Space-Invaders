
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Gameservice.h"


/*

//Player Class
class Player
{
private:
    int playerScore = 0;
    int health = 3;
    int movementSpeed = 2;
    sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);

public:

    sf::Texture player_texture;
    sf::Sprite player_sprite;
    
    int getScore()
    {
        return playerScore;
    }

    void setScore(int newScore) 
    {
        playerScore = newScore;
    }

    void move(float offsetX)
    {
        position.x += offsetX;
    }

    int getMoveSpeed()
    {
        return movementSpeed;
    }

    sf::Vector2f getPosition()
    {
        return position;
    }

    void takeDamage(){}
    void shoot(){}

};

*/

int main()
{

/*

    sf::VideoMode videoMode = sf::VideoMode(800, 600); 

    sf::RenderWindow window(videoMode, "SFML Window"); 

    Player player; 

    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture); 
    //player.setPosition(200, 100);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
        {
            player.move(-1.0f*player.getMoveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        {
            player.move(1.0f * player.getMoveSpeed());
        }

        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(player.getPosition());

        window.draw(player.player_sprite);

        window.display();

    } 

    */


    GameService* game_service = new GameService;

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    return 0;
}