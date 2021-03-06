#include "Player.h"

#include "StateFactory.h"

Player::Player(PlayerTag tag, Game* game)
	:Actor(ActorType::PLAYER, "res/players/p1.png", 0, 0, FRAME_WIDTH, FRAME_HEIGHT, game)
{
	this->tag = tag;
	this->orientation = (tag == PlayerTag::P1) ?
		Orientation::LEFT :
		Orientation::RIGHT;
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
	pushedBack--;
	// Update state
	state->tick();
	// Set calculated position
	position.x = static_cast<float>(cpBodyGetPosition(body).x);
	position.y = static_cast<float>(cpBodyGetPosition(body).y);
	// Update weapon
	if (weapon != nullptr) {
		weapon->tick();
	}
	// Fall check
	if (position.y > HEIGHT && state->tag != ePlayerStates::DYING) {
		printf("%s fell out\n", toString().c_str());
		pendingDestruction = true;
		// setState(ePlayerStates::DYING);
	}
}

void Player::render(float rotation)
{
	state->render(rotation);
	if (weapon != nullptr) {
		weapon->render();
	}
}

/* Inits the player to start a new scenario */
void Player::init()
{
	// Restore player
	hp = (game->options->oneHit) ? 1 : PLAYER_HP;
	pendingDestruction = false;
	// Set the states
	initStates();
	prevState = states[ePlayerStates::IDLE];
	state = states[ePlayerStates::IDLE];
	// Set the weapon
	weapon = nullptr;
}

/* Limits the max falling speed */
void limitFallingSpeed(cpBody* body, cpVect gravity, cpFloat damping, cpFloat dt)
{
	cpBodyUpdateVelocity(body, gravity, damping, dt);
	if (cpBodyGetVelocity(body).y > PLAYER_MAX_FALL_SPEED) {
		cpBodySetVelocity(body, cpv(cpBodyGetVelocity(body).x, PLAYER_MAX_FALL_SPEED));
	}
}

/* Create the physics of the object */
void Player::configureChipmunkSpace(cpSpace* chipSpace)
{
	/* Create the body */
	body = cpBodyNew(PLAYER_BODY_WEIGHT, INFINITY);
	cpBodySetPosition(body, cpv(position.x, position.y));
	// Falling Speed limitation
	cpBodySetVelocityUpdateFunc(body, limitFallingSpeed);		
	cpSpaceAddBody(chipSpace, body);
	/* Create the shape */
	shape = cpBoxShapeNew(body, PLAYER_BODY_WIDTH, PLAYER_BODY_HEIGHT, 0.0);
	// Collision type
	cpShapeSetCollisionType(shape, static_cast<int>(type));		
	cpShapeSetElasticity(shape, 0);
	cpShapeSetFriction(shape, PLAYER_SHAPE_FRICTION);
	// Collision filter
	cpShapeSetFilter(shape, cpShapeFilterNew(1, CP_ALL_CATEGORIES, CP_ALL_CATEGORIES));			
	// Reference to the Actor into the Shape
	cpShapeSetUserData(shape, cpDataPointer(this));
	cpSpaceAddShape(chipSpace, shape);
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

/* Manage the press trigger input */
void Player::pressTrigger()
{
	if (weapon != nullptr) {
		state->pressTrigger();
	}
}

/* Manage the release trigger input */
void Player::releaseTrigger()
{
	if (weapon != nullptr) {
		state->releaseTrigger();
	}
}

/* Changes the player state */
void Player::setState(ePlayerStates id)
{
	state->exit();
	prevState = state;
	state = states[id];
	state->enter();
}

/* Returns player as string */
string Player::toString()
{
	return "Player " + to_string(static_cast<int>(tag));
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

/* Manage the collision with a Projectile */
void Player::impacted(PlayerTag shooter, int damage, cpVect velocity)
{
	state->impacted(shooter, damage, velocity);
}

/* Manage the recoil force from shooting */
void Player::recoil(int force, cpVect point)
{
	state->recoil(force, point);
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
	states.insert_or_assign(ePlayerStates::DYING, factory->getState(ePlayerStates::DYING, this));
}