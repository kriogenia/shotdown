#include "Player.h"

Player::Player(PlayerTag tag, Game* game)
	:Actor(ActorType::PLAYER, "res/players/p1.png", 0, 0, PLAYER_SIZE, PLAYER_SIZE, game)
{
	this->tag = tag;
}

Player::~Player()
{
}

void Player::update()
{
	// Gets the calculated position
	position.x = static_cast<float>(cpBodyGetPosition(body).x);
	position.y = static_cast<float>(cpBodyGetPosition(body).y);
}

/* Resets the player to starts a new scenario */
void Player::clear()
{
}

/* Creates the physics of the object */
void Player::configureChipmunkSpace(cpSpace* chipSpace)
{
	// Create the body
	body = cpBodyNew(PLAYER_BODY_WEIGHT, INFINITY);
	cpBodySetPosition(body, cpv(position.x, position.y));
	cpSpaceAddBody(chipSpace, body);
	// Create the shape
	shape = cpBoxShapeNew(body, width, height, 0.0);
	cpShapeSetElasticity(shape, 0);
	cpShapeSetFriction(shape, PLAYER_SHAPE_FRICTION);
	cpSpaceAddShape(chipSpace, shape);
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
}