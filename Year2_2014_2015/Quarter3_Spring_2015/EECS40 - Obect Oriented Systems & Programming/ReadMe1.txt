Kevin Ngo	25092065
Jack Melcher	67574625

4/17/2015

EECS40 - Assignment 1 - BubbleShooter Game

Features:
Bubbles are organized in a square type grid.

A line appears where you touch down or move your finger on the screen to indicate the trajectory of the shooter ball.

The shooting bubble moves in the driection of the line when you lift the finger up from the screen.

Player cannot shoot a bubble downward.

Explodes bubbles when shooter bubble collides with one or more adjacent bubbles of same color in the grid
Bubbles of the same color that are diagonal to each other do not explode.

Bubbles of any color can attach to each other diagonally.

If an explosion occurs, bubbles of same color adjacent to the explosion also explode.

If a bubble has no neighbor north (up, up-left, and up-right) and left or right of itself after an explosion, it is considered floating and it too explodes.

Bubbles in an explosion fade away, while floating bubbles just immediately disappear.

Game Restarts when all bubbles on screen have been cleared.

Game Restarts if a bubble occupies the row just above the shooting bubble.

Collision Method:
Our collision method was based on the explanation the professor gave in lecture.
He recommended we use the predicted path of bubble to determine if anything was going to its path.
And if there is, assign the bubble to the array.

Explosion Method:
Used recursion in order to spread the explosion.

Glitch:
Because the way bubbles are considered floating, the shooter bubble cannot attach to a loaction on the grid
where it has a no neighbors to its north and either one neighbor only to its left but not its right, or a neighbor only to its right and not its left.
This results in the shooter bubble being destoryed and a new shooter bubble spawning.
You can use this method to get a bubble color you want.
