# shotdown
Assingment for the Videogames and Entertainment Software 20/21 subject of the University of Oviedo.

This little project intends to be a very light local multiplayer game based on Duck Game.

TBI - Game logo

The game will feature an array of different scenarios where both
players will fight to kill the other one and get a showdown point.
At the end, the player with more wins will be the winner. Each scenario offers walls and platforms to jump and weapon spawners to pick different weapons.

The game is developed in C++ only using the SDL2 library for handling audio and grahpics, tinyxml2 to handle XML readings and Chipmunk2D as the physics engine, that's all. Everything else will be pure manfactured C++. Scenarios were created using Tiled.

TBI - Screenshot

# Controls

## Player 1

The first player will control its character with the keyboard.

* WASD for movement
* Space to jump
* E to pick a weapon

## Player 2

TBI

## Other

Other controls to know of are:

* Escape to exit the game
* Key 1 to make the game fullscreen
* Key 2 to replace the characters (bug safety measure) - TBI

# Mechanics

Each game will consist on 5 different scenarios aka showdowns.
Both players will be placed in the scenario and they will fight to death. The players will be able to move throughout the scenarios, jump, double jump, sliding in and jumping from walls and, why not, also dash. Oh, and of course, pick and use weapons.

There are a pletora of different unique weapons with their own rarity
and mechanics. Those weapons will have a very limited ammo so there
will be a need to change weapons quickly to not find yourself on a
bad position without any way to attack your enemies.

# Weapons

Currently the game features the next weapons:

* **Ak-47**, common, clip size: 10, extra ammo: 10. Automatic weapon with medium recoil and low reload time.

# Resources

Almost all the graphic and sound assets of the game are from third-party creative common sources. I modified some of it but the big work is not mine.

* Characters: https://ipixl.itch.io/pixel-art-animated-characters-pack
* Music: https://tallbeard.itch.io/music-loop-bundle
* Tileset: https://ansimuz.itch.io/warped-city
