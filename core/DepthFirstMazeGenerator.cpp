//DepthFirstMazeGenerator.cpp

#include <ics46/factory/DynamicFactory.hpp>
#include <random>
#include <vector>
#include <iostream>
#include "MazeGenerator.hpp"
#include "Maze.hpp"
#include "DepthFirstMazeGenerator.hpp"

ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, MyMazeGenerator, "Depth First Algorithm (Required)");

//implement constructor
MyMazeGenerator::MyMazeGenerator(){}

//implement generateMaze
void MyMazeGenerator::generateMaze(Maze& maze){
    //initialize random seed
    srand(time(NULL));

    maze.addAllWalls();

    const unsigned int width = maze.getWidth();
    const unsigned int height = maze.getHeight();

    int x = 0;
    int y = 0;

    //create 2d vector size of maze
    //initialize to 0 for unvisited
    std::vector<std::vector<int>>visit(width,std::vector<int>(height,0));

    visit[x][y]=1;

    MyMazeGenerator::createPath(x,y,width,height,visit,maze);
}

//reursive function
void MyMazeGenerator::createPath(int x, int y, const unsigned int width, const unsigned int height, std::vector<std::vector<int>> &visit, Maze& maze){
    //generate random number (1-4)
    int direction;
    std::vector<int>move={2,3,1,4};
    std::random_shuffle (move.begin(), move.end());
    for(int i=0; i<4;i++){
        direction =move[i];
    
    //std::cout<<direction<<std::endl;
    //up
    if(direction == 1){
        //if y=0, can't go up
        //next cell is unvisited
        //there is a wall between
        if(y>0 && visit[x][y-1]==0 && maze.wallExists(x,y,Direction::up)){
            maze.removeWall(x,y,Direction::up);
            //mark cell as visited
            visit[x][y-1]=1;
            //recursion
            createPath(x,y-1,width,height,visit,maze);
        }
    }

    //down
    else if(direction == 2){
        //if y=height-1, can't go down
        if(y<height-1 && visit[x][y+1]==0 && maze.wallExists(x,y,Direction::down)){
            maze.removeWall(x,y,Direction::down);
            visit[x][y+1]=1;
            createPath(x,y+1,width,height,visit,maze);
        }
     }

    //left
    else if(direction == 3){
        //if x=0, can't go left
        if(x>0 && visit[x-1][y]==0 && maze.wallExists(x,y,Direction::left)){
            maze.removeWall(x,y,Direction::left);
            visit[x-1][y]=1;
            createPath(x-1,y,width,height,visit,maze);
        }
    }

    //right
    else{
        //if x=width-1, can't go right
        if(x<width-1 && visit[x+1][y]==0 && maze.wallExists(x,y,Direction::right)){
            maze.removeWall(x,y,Direction::right);
            //x++;
            visit[x+1][y]=1;
            createPath(x+1,y,width,height,visit,maze);
        }
    }
}
}


