#!/usr/bin/python3
'''returns the perimeter of the island described in grid'''

'''
def island_perimeter(grid):
    #island_perimeter

    cell_per = 0
    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if grid[y][x] == 1:
                try:
                    if (y - 1) < 0 or grid[y - 1][x] == 0:
                        cell_per = cell_per + 1
                    if (x - 1) < 0 or grid[y][x - 1] == 0:
                        cell_per = cell_per + 1
                    if (x + 1) < 0 or grid[y][x + 1] == 0:
                        cell_per = cell_per + 1
                    if (y + 1) < 0 or grid[y + 1][x] == 0:
                        cell_per = cell_per + 1
                except IndexError:
                    cell_per = cell_per + 1
                    pass
    return (cell_per)
    '''


def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 0:
                continue
            perimeter += 4
            if i > 0:
                perimeter = perimeter - grid[i - 1][j]
            if i < len(grid) - 1:
                perimeter = perimeter - grid[i + 1][j]
            if j > 0:
                perimeter = perimeter - grid[i][j - 1]
            if j < len(grid[0]) - 1:
                perimeter = perimeter - grid[i][j + 1]
    return perimeter
