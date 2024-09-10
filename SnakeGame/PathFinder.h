#pragma once

#include "HamCycle.h"
#include "AStar.h"
#include "Snake.h"
#include "DataTypes.h"

typedef std::vector<cords> CordList;

class PathFinder
{
public:
	// Dimentions are needed to create the hamilton cycle
	PathFinder(int width, int height);

	// Returns set of directions for snake to follow
	std::vector<Direction>* FindPath(Snake* snake, cords goal);

	void Delete();

private:
	AStar star;
	int width, height, max;
	Snake* snake;
	cords goal;
	int** cycle;

	// This will make a copy of the snake for my pathfinders to use
	void UpdateSnake(Snake* snake);

	// This will simulate the snakes moves on the given set of directions
	// and then check to see if the snake can continue on the hamilton cycle
	bool safe(std::vector<Direction>* path);

	//// This function gives the cordinates of the cell that is next in the cycle
	//cords nextCycleNode(cords);

	// This will keep attempting to rejoing the cycle at the nearest node and if
	// it fails it will try the next nearest and so on untill it succeeds
	std::vector<Direction>* RejoinCycle(Snake* snake, int radius);

	// This will make a copy of the active snake and make that snake 
	// move through the given path for the purposes of testing if its safe
	Snake* SimulateMove(std::vector<Direction>* path);

	int distance(cords a, cords b);

	// Follows cycle for a given number of nodes
	std::vector<Direction>* FollowPath(int num);

	// This generates a hamilton cycle with maximum turns of given size
	// With the requirnment that width and height are divisible by four
	// and width and height are the same value
	int** GenerateCycle();

	// This will get the path
	std::vector<Direction>* CycleToGoal(Snake* snake, cords goal);

	// This shifts cells in the given direction
	void Shift(Direction dir, int& y, int& x);

	// Given the grid "grid" has dimentions (height, width) this will find the 
	// preceeding and next cells and store them in the variables dir1 for the 
	// previous direction, and dir2 for the next direciton. If dir2 or dir2 are
	// the return will represent if they are accurate
	// This also assumes that the node is not empty (grid[y][x] != -1)
	bool GetDirection(int** grid, int y, int x, Direction* dir1, Direction* dir2, int height, int width, int max, int min = 0);

	// returns the next direction for a given location
	Direction nextDir(cords cords);

	// returns the direction you have to go for the previous node
	Direction prevDir(cords cords);

};

