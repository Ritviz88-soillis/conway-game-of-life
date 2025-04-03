#pragma once
#include "grid.hpp"

class Simulation {
    public:
        Simulation(int width, int height, int cellSize)
        : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false) {}; 


        int GetRows()  { return grid.GetRows(); }
        int GetColumns() { return grid.GetColumns(); }

        void Draw();
        void SetCellValue(int row, int col, int value);
        int CountLiveNeighbour(int row, int col);


        void ClearGrid();
        void CreateRandomState();

        void FillRandom() { grid.FillRandom(); } // Fill the grid with random values
        void Update();

        bool isRunning() { return run; } // Check if the simulation is running

        void Start() { run = true; } // Start the simulation
        void Stop() { run = false; } // Stop the simulation
        
    private:    
        Grid grid;
        Grid tempGrid;
        bool run;
};