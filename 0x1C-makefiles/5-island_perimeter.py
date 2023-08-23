#!/usr/bin/python3
""" module to calculate perimeter """

def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in grid.

    Args:
    grid (list of list of integers): The grid representing the island.

    Returns:
    int: The perimeter of the island.
    """
    rows = len(grid)
    cols = len(grid[0])
    
    perimeter = 0
    
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4  # Every land cell contributes 4 sides to the perimeter
                
                # Check adjacent cells and subtract 1 for each adjacent land cell
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1
    
    return perimeter

