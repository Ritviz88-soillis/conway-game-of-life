#include "simulation.hpp"
#include <raylib.h>
void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbour(int row, int col)
{
    int count = 0;
    std::vector<std::pair<int, int>> directions = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},          
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    for(const auto& dir : directions) {
        int newRow = (row + dir.first + grid.GetRows()) % grid.GetRows(); // Wrap around for toroidal effect
        int newCol = (col + dir.second + grid.GetColumns()) % grid.GetColumns(); // Wrap around for toroidal effect
        
        if(grid.GetValue(newRow, newCol) == 1) {
            count++;
        }
    }
    return count;
}

void Simulation::ClearGrid()
{
    if(!isRunning()) 
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if(!isRunning()) 
    {
        grid.FillRandom();
    }
}

void Simulation::Update()
{
    if(isRunning()) 
    {
        tempGrid.FillRandom(); // Fill the temporary grid with random values
    
        for(int row = 0; row < grid.GetRows(); row++) 
        {

            for(int col = 0; col < grid.GetColumns(); col++) 

            {
                int liveNeighbours = CountLiveNeighbour(row, col);

                if(grid.GetValue(row, col) == 1) 
                {

                    if(liveNeighbours < 2 || liveNeighbours > 3) 
                    {
                        tempGrid.SetValue(row, col, 0); // Cell dies
                    }
                    else 
                    {
                        tempGrid.SetValue(row, col, 1); // Cell lives
                    }
                } 

                else 
                {
                    if(liveNeighbours == 3) 
                    {
                        tempGrid.SetValue(row, col, 1); // Cell becomes alive
                    }

                    else 
                    {
                        tempGrid.SetValue(row, col, 0); // Cell remains dead
                    }
                }
            }

            for(int row = 0; row < grid.GetRows(); row++) 
            {
                for(int col = 0; col < grid.GetColumns(); col++)
                {  
                    grid.SetValue(row, col, tempGrid.GetValue(row, col));
                }
            }
        }
            
    }   
}
