#include "Player.h"

#include "StateFactory.h"

Player::Player(PlayerTag tag, Game* game)
	:Actor(ActorType::PLAYER, "res/players/p1.png", 0, 0, PLAYER_SIZE, PLAYER_SIZE, game)
{
	this->tag = tag;
	init();
}

Player::~Player()
{
	states.clear();
}

void Player::update()
{
	// Gets the calculated position
	position.x = static_cast<float>(cpBodyGetPosition(body).x);
	position.y = static_cast<float>(cpBodyGetPosition(body).y);
}

/* Init the player to start a new scenario */
void Player::init()
{
	// Set the state
	initStates();
	state = states[ePlayerStates::IDLE];
	state->enter();
}

/* Create the physics of the object */
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

/* Manage the horizontal movement input */
void Player::moveX(int axis) 
{
	if (axis > 0 && cpBodyGetVelocity(body).x < PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(body, cpv(PLAYER_SPEED, 0), cpv(0, 0));
	}
	if (axis< 0 && cpBodyGetVelocity(body).x > -PLAYER_SPEED) {
		cpBodyApplyImpulseAtLocalPoint(body, cpv(-PLAYER_SPEED, 0), cpv(0, 0));
	}
}

/* Changes the player state */
void Player::setState(ePlayerStates id)
{
	state->exit();
	state = states[id];
	state->enter();
}

/* Init the player states */
void Player::initStates()
{
	states.clear();
	StateFactory* factory = StateFactory::getInstance();
	states.insert_or_assign(ePlayerStates::IDLE, factory->getState(ePlayerStates::IDLE, this));
	states.insert_or_assign(ePlayerStates::MOVING, factory->getState(ePlayerStates::MOVING, this));
}