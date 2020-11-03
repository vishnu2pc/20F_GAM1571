# Hyperdot Clone

#### Feature List

* Level Editor
  * Control of Game Arena, player and enemy parameters
  * Made a bunch of abstraction to get control of all the gameobject parameters
* Interpolated Player Movement
* Multi-layered player and arena mesh
* Game Arena reacts to player movement (slight position offset in the direction opposite to player movement)


#### Gameplay Loop

* Has three levels
* Each level has a duration that the player needs to survive for
* Collision with enemy respawns the player in a random area inside the circle and resets the level timer.
* Beating the third level shows the Win screen and pressing 'R' restarts the game.
