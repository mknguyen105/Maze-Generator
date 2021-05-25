//DepthFirstMazeSolver.hpp

#ifndef DEPTHFIRSTMAZESOLVER_HPP
#define DEPTHFIRSTMAZESOLVER_HPP

#include "MazeSolver.hpp"

class MyMazeSolver : public MazeSolver {
public:
    MyMazeSolver();
    void solveMaze(const Maze& maze, MazeSolution& mazeSolution);
    void findPath(int x, int y, const unsigned int width, const unsigned int height, std::vector<std::vector<int>> &visit, const Maze& maze, MazeSolution& mazeSolution);
};

#endif
