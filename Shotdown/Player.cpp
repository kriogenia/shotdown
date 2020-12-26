#include "Player.h"

#include "StateFactory.h"

Player::Player(PlayerTag tag, Game* game)
	:Actor(ActorType::PLAYER, "res/players/p1.png", 0, 0, PLAYER_SIZE, PLAYER_SIZE, game)
{
	this->tag = tag;
	this->orientation = (tag == PlayerTag::P1) ?
		PlayerOrientation::LEFT :
		PlayerOrientation::RIGHT;
	init();
}

Player::~Player()
{
	states.clear();
}

void Player::tick()
{
	// Update cooldowns
	dashCd--;
	// Limit player fall velocity
	if (cpBodyGetVelocity(body).y > PLAYER_MAX_FALL_SPEED) {
		cpBodySetVelocity(body, cpv(cpBodyGetVelocity(body).x, PLAYER_MAX_FALL_SPEED));
	}
	// Update state
	state->tick();
	// Set calculated position
	position.x = static_cast<float>(cpBodyGetPosition(body).x);
	position.y = static_cast<float>(cpBodyGetPosition(body).y);
}

/* Init the player to start a new scenario */
void Player::init()
{
	// Set the states
	initStates();
	prevState = states[ePlayerStates::IDLE];
	state = states[ePlayerStates::IDLE];
}

/* Create the physics of the object */
void Player::configureChipmunkSpace(cpSpace* chipSpace)
{
	// Create the body
	body = cpBodyNew(PLAYER_BODY_WEIGHT, INFINITY);
	cpBodySetPosition(body, cpv(position.x, position.y));
	cpSpaceAddBody(chipSpace, body);
	// Create the shape
	shape = cpBoxShapeNew(body, 8, height, 0.0);
	cpShapeSetCollisionType(shape, static_cast<int>(type));
	cpShapeSetElasticity(shape, 0);
	cpShapeSetFriction(shape, PLAYER_SHAPE_FRICTION);
	cpSpaceAddShape(chipSpace, shape);
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
}

/* Manage the horizontal movement input */
void Player::move(int direction)
{
	state->move(direction);
}

/* Manage the jump input */
void Player::jump()
{
	state->jump();
}

/* Manage the dash input */
void Player::dash()
{
	state->dash();
}

/* Changes the player state */
void Player::setState(ePlayerStates id)
{
	state->exit();
	prevState = state;
	state = states[id];
	state->enter();
}

/* Manage the collision with a Tile */
void Player::collisioned(Point collisionedPosition)
{
	float orientationX = collisionedPosition.x - position.x;
	float orientationY = collisionedPosition.y - position.y;
	if (abs(orientationX) >= abs(orientationY)) {
		if (orientationX > 0)
			state->hitRight();
		else
			state->hitLeft();
	}
	else {
		if (orientationY > 0)
			state->hitGround();
		else
			state->hitTop();
	}
}

/* Init the player states */
void Player::initStates()
{
	states.clear();
	StateFactory* factory = StateFactory::getInstance();
	states.insert_or_assign(ePlayerStates::IDLE, factory->getState(ePlayerStates::IDLE, this));
	states.insert_or_assign(ePlayerStates::MOVING, factory->getState(ePlayerStates::MOVING, this));
	states.insert_or_assign(ePlayerStates::JUMPING, factory->getState(ePlayerStates::JUMPING, this));
	states.insert_or_assign(ePlayerStates::DOUBLE_JUMPING, factory->getState(ePlayerStates::DOUBLE_JUMPING, this));
	states.insert_or_assign(ePlayerStates::FALLING, factory->getState(ePlayerStates::FALLING, this));
	states.insert_or_assign(ePlayerStates::SLIDING, factory->getState(ePlayerStates::SLIDING, this));
	states.insert_or_assign(ePlayerStates::DASHING, factory->getState(ePlayerStates::DASHING, this));
}