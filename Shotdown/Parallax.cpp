#include "Parallax.h"

Parallax::Parallax(string filename, int fileWidth, int fileHeight, Game* game) :
	Actor(ActorType::BACKGROUND,filename, WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, fileWidth, fileHeight, game)
{

}