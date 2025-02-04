# Bully

This repository contains the code for "Bully In The Maze Of Life", a maze game developed in C. The game challenges the player to collect all the points in a 20x20 maze while avoiding a bear monster that's trying to eat him!

## Game Overview

The player controls Bully, who must navigate a maze and collect all the points scattered throughout it. The game is won when all points have been collected. However, a bear  is also present in the maze and is actively trying to catch Buli. If the bear reaches Buli, the game is lost.

## Game Instructions

1. **Download the Executable:** Download the `bully.exe` file from this repository.
2. **Run the Game:** Execute the `bully.exe` file. That's it! No further setup or installation is required.
3. **Input Maze Walls:** The game will first prompt you to enter the locations of the maze walls. Enter each wall segment as a pair of coordinates (row and column), separated by a space. Enter `0` for either the row or column to signal the end of the wall input.
4. **Input Starting Positions:** Next, you will be prompted to enter the starting row and column for Bully, followed by the starting row and column for the bear.
5. **Gameplay:**
    * Bully collects points by moving over them. Points disappear from the maze when collected.
    * The bear moves after each of Bully's turns, attempting to move closer to Bully in a straight line.
    * If the bear encounters a wall, it remains in its current position.

## Technical Details

* **Maze Representation:** The game uses a 2D array (20x20) to represent the maze.
* **Bear Movement:** The bear's movement is based on a simple "as-the-crow-flies" approach, attempting to minimize the Euclidean distance to Bully.
* **Game End Condition:** The game ends when either all points are collected (win) or the bear catches Bully (loss).
