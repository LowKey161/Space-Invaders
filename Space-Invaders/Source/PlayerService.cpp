#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

//init
void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService(); //get the event service object created in service locator

	if (event_service->isKeyboardEvent())
	{
		if (event_service->pressedLeftKey())
		{
			moveLeft();
		}

		if (event_service->pressedRightKey())
		{
			moveRight();
		}
	}
}


void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::moveLeft()
{
	position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::moveRight()
{
	position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void PlayerService::move(float offsetX) {
	position.x += offsetX * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();;
}

//helper functions
sf::Vector2f PlayerService::getPlayerPosition() { return position; }
int PlayerService::getMoveSpeed() { return movement_speed; }