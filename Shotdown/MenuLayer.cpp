#include "MenuLayer.h"

#include "AudioPlayer.h"

MenuLayer::MenuLayer(Game* game) :
	Layer(game)
{
	/* Add vehicle filenames */
	vehicles.push_back("res/backgrounds/v-police.png");
	vehicles.push_back("res/backgrounds/v-red.png");
	vehicles.push_back("res/backgrounds/v-truck.png");
	vehicles.push_back("res/backgrounds/v-yellow.png");
	/* Init */
	init();
}

void MenuLayer::init()
{
	background = new Actor(ActorType::BACKGROUND, "res/backgrounds/menu.png",
		WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, game);
	buildings = new Parallax("res/backgrounds/near-buildings.png", WIDTH, HEIGHT, game);
	generateVehicle();
	newVehicle = VEHICLE_SPAWN_TIME;
	AudioPlayer::getInstance()->start();
}

void MenuLayer::tick()
{
	vehicle->position.x -= VEHICLE_SPEED;
	newVehicle--;
	if (newVehicle <= 0) {
		newVehicle = VEHICLE_SPAWN_TIME;
		generateVehicle();
	}
}

void MenuLayer::render()
{
	background->render();
	vehicle->render();
	buildings->render();
}

void MenuLayer::keysToControl(SDL_Event event)
{

}

void MenuLayer::mouseToControl(SDL_Event event)
{

}

void MenuLayer::padToControl(SDL_Event event)
{

}

void MenuLayer::generateVehicle()
{
	string file = vehicles[rand() % vehicles.size()];
	float y = rand() % 400 + 40;
	vehicle =  new Actor(ActorType::BACKGROUND, file, WIDTH + 61, y, 96, 61, game);
}