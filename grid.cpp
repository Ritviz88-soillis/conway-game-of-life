#include "grid.hpp"
#include <raylib.h>


void Grid::Draw()
{
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            //some error encountered here but fixed
            Color color  = cells[row][col] ? GREEN : Color{55, 55, 55, 255};
            DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize  -1 , color);
           
        }
    }
}

void Grid::SetValue(int row, int col, int value)
{
    if(row >= 0 && row < rows && col >= 0 && col < columns) {
        cells[row][col] = value;
    }
}

void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < columns; col++) {
            int randomValue = GetRandomValue(0, 4); // Randomly set to 0 or 1
            cells[row][col] = (randomValue == 2) ? 1: 0; // Randomly set to 0 or 1
        }
    }
}

void Grid::Clear()
{
    for(int row = 0; row <rows; row++)
    {
        for(int col = 0; col <columns; col++) 
        {
            cells[row][col] = 0;
        }
    }
}
