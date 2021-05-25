//DepthFirstMazeGenerator.hpp

#ifndef DEPTHFIRSTMAZEGENERATOR_HPP
#define DEPTHFIRSTMAZEGENERATOR_HPP

#include "MazeGenerator.hpp"
#include "Maze.hpp"

class MyMazeGenerator : public MazeGenerator {
public:
    MyMazeGenerator();
    void generateMaze(Maze& maze);
    void createPath(int x, int y, const unsigned int width, const unsigned int height, std::vector<std::vector<int>> &visit, Maze& maze);
};

#endif
