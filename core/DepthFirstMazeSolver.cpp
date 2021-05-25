//DepthFirstMazeSolver.cpp

#include <ics46/factory/DynamicFactory.hpp>
#include <vector>
#include "Maze.hpp"
#include "MazeSolver.hpp"
#include "MazeSolution.hpp"
#include "DepthFirstMazeSolver.hpp"

ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, MyMazeSolver, "Depth First Algorthm (Required)");

//implement constructor
MyMazeSolver::MyMazeSolver(){}

//implement solveMaze
void MyMazeSolver::solveMaze(const Maze& maze, MazeSolution& mazeSolution){
    mazeSolution.restart();

    const unsigned int width = maze.getWidth();
    const unsigned int height = maze.getHeight();

    int x = 0;
    int y = 0;

    //create 2d vector size of maze
    //initialize to 0 for unvisited
    std::vector<std::vector<int>>visit(width,std::vector<int>(height,0));

    MyMazeSolver::findPath(x,y,width,height,visit,maze,mazeSolution);
}

//recursive function
void MyMazeSolver::findPath(int x, int y, const unsigned int width, const unsigned int height, std::vector<std::vector<int>> &visit, const Maze& maze, MazeSolution& mazeSolution){
    if(x==width-1 && y==height-1) return;//mazeSolution.isComplete()) return;

    //else{
        //down
        else if(y<height-1 && visit[x][y+1]==0 && !maze.wallExists(x,y,Direction::down)){
            visit[x][y]=1;
            mazeSolution.extend(Direction::down);
            findPath(x,y+1,width,height,visit,maze,mazeSolution);
        }

        //up
        else if(y>0 && visit[x][y-1]==0 && !maze.wallExists(x,y,Direction::up)){
            visit[x][y]=1;
            mazeSolution.extend(Direction::up);
            findPath(x,y-1,width,height,visit,maze,mazeSolution);
        }

        //right
        else if(x<width-1 && visit[x+1][y]==0 && !maze.wallExists(x,y,Direction::right)){
            visit[x][y]=1;
            mazeSolution.extend(Direction::right);
            findPath(x+1,y,width,height,visit,maze,mazeSolution);
        }

        //left
        else if(x>0 && visit[x-1][y]==0 && !maze.wallExists(x,y,Direction::left)){
            visit[x][y]=1;
            mazeSolution.extend(Direction::left);
            findPath(x-1,y,width,height,visit,maze,mazeSolution);
        }
    else{
        visit[x][y]=0;
        mazeSolution.backUp();
        return;
    }
}














