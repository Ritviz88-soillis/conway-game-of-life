#pragma once
#include <vector>

class Grid 
{
    public:
        Grid(int width, int height, int cellSize)
        : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) 
        {
            // Initialized the grid with dead cells (0)
        }

        void Draw();
        void SetValue(int row, int col, int value);

        int GetRows()  { return rows; }
        int GetColumns()  { return columns; }

        void FillRandom();

        int GetValue(int row, int col) const {
            if(row >= 0 && row < rows && col >= 0 && col < columns) {
                return cells[row][col];
            }
            return -1; 
        }

       void Clear();

        
    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
};