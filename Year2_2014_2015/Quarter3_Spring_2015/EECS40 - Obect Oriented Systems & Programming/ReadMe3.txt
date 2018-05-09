Kevin Ngo	25092065
Jack Melcher	67574625

5/18/2015

EECS40 - Assignment 3 - Super Mario Bros. Game

Features:
Mario:	He collides with blocks as expected and can kill enemies by jumping on them. Can destroy brick blocks when big. and can shoot fireballs when in fireflower mode.
Mario Animtations: Mario changes sprites for idle,moving, and jumping.
2 Blocks: two types of blocks, one that spawns items when hit from underneath and another one that breaks when hit from underneath as super mario.
3 Items: Mario can collect coins for extra points, the mushroom to become super mario and break brick blocks or the fireflower to become fire mario and shoot fireballs.
Score: Get points for getting coins, killing enemies, running through the level.
3 Levels: There are three levels you can play through.
Level Factory: game objects of levels are created and stored by in this class.
Time Limit: When time hits 0 you die.
Lives and Time Settings: Tap the time or lives to change how many you have per level.
Transistion from one level to the next after completing a level. Completing level 3 brings you back to start screen.
Level Restarts when you lose a life. When you lose all lives you go back to Start Screen.

Added Features:
Level Select Screen: 	Tap once to start a specific level. At anytime you win or lose the level you return to this screen.

Controls:
Tap dpad right to move right and left to move left
Tap and hold A to jump at max height. Release A early to jump at lower heights
Tap B while fire mario to shoot a fire ball

Leftout Features:
No Unique enemies: the goombas and koopas operate in the same fashion, nand no gravity for enemies.
No star power.
You die in one hit from enemies no matter what transformation you are in

Unknown Errors:
The project for some reason could not run on the emulator at all. Would immediately crash.
Works fine on Android devices.
Occasional glitching with how the block collision behaves.
Occasionally the countdown timer thread starts twice for one level session.