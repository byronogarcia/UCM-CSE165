#include "Level.h"

#include <fstream>
#include <sstream>
#include <iostream>

void Level::load(const char *file, float levelWidth, float levelHeight){
    // Clear old data
    
    this->bricks.clear();
    // Load from file
    int tileCode;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<int> > tileData;
    if (fstream){
	// Read each line from level file
        while (std::getline(fstream, line)) {
            std::istringstream sstream(line);
            std::vector<int> row;
	    // Read each word seperated by spaces
            while (sstream >> tileCode)
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->init(tileData, levelWidth, levelHeight);
    }
}

void Level::draw(){
    for (int i = 0; i < bricks.size(); i++)
        if (!bricks[i].isDestroyed())
            bricks[i].draw();
}

bool Level::isCompleted(){
    for (Brick &block : this->bricks)
        if (!block.isSolid() && !block.isDestroyed())
            return false;
    return true;
}

void Level::init(std::vector<std::vector<int> > tileData, float levelWidth, float levelHeight){
    // Calculate dimensions
    float height = tileData.size();
    float width = tileData[0].size(); // Note we can index vector at [0] since this function is only called if height > 0
    float unit_width = 2.0 / width;
    float unit_height = 1.0 / height; 
    // Initialize level tiles based on tileData		
    for (int y = 0; y < height; ++y){
        for (int x = 0; x < width; ++x){
            // Check block type from level data (2D level array)
	    // Solid
            if (tileData[y][x] == 1) {
		float blockX = -1 + unit_width * x;
		float blockY = 1 - unit_height * y;
		float blockW = unit_width;
		float blockH = unit_height;
        /* This is where the bric image is placed onto the rectangle, I didn't use brick solid since it wasn't working
            but this is where the images go */
               /* Brick brick("images/block_solid.png", blockX, blockY, blockW, blockH, 0.8f, 0.8f, 0.7f);
                brick.setSolid(true);
                this->bricks.push_back(brick);*/
            }
	    // Non-solid; now determine its color based on level data
            else if (tileData[y][x] > 1){
		float r, g, b = 1.0f; // original: white
        //If you look at the level files thats where we go to create the levels
        // 2 makes the block the original color and breaks in one hit for example
                if (tileData[y][x] == 2){
		    r = 1.0f;
		    g = 1.0f;
		    b = 1.0f;
            //this->bricks.push_back(Brick("images/brick_1.png", blockX, blockY, blockW, blockH, r, g, b));
            //count = 1;
		}
                else if (tileData[y][x] == 3){
		    r = 0.2f;
		    g = 0.7f;
		    b = 0.2f;
            //this->bricks.push_back(Brick("images/brick_4.png", blockX, blockY, blockW, blockH, r, g, b));
            //count = 2;
		}
                else if (tileData[y][x] == 4){
		    r = 0.1f;
		    g = 0.6f;
		    b = 0.1f;
            //this->bricks.push_back(Brick("images/brick_9.png", blockX, blockY, blockW, blockH, r, g, b));
            //count = 3;
		}
                else if (tileData[y][x] == 5){
		    r = 1.0f;
		    g = 0.5f;
		    b = 0.0f;
		}
                float blockX = -1 + unit_width * x;
		float blockY = 1 - unit_height * y;
		float blockW = unit_width;
		float blockH = unit_height;
        //this is where I put the file brick but I have changed it to a different image to make it plain and understandable
               // this->bricks.push_back(Brick("images/brick.png", blockX, blockY, blockW, blockH, r, g, b));
        this->bricks.push_back(Brick("images/brick_1.png", blockX, blockY, blockW, blockH, r, g, b)); //add count at the end in the brick
        //this->bricks.push_back(Brick("images/brick.png", blockX, blockY, blockW, blockH, r, g, b));
            }
        }
    }
}
