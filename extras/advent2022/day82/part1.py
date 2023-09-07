import sys


if len(sys.argv) == 2:
	file = sys.argv[1]
else:
	file = "test.txt"

grid = []
with open(file) as f:
	while True:
		line = f.readline()
		if not line:
			break
		row = []
		for c in line:
			if c != "\n":
				row.append(c)
		grid.append(row)

def look_down(grid, row, c):
	num = grid[row][c]
	row += 1
	while row < len(grid):
		if grid[row][c] >= num:
			return 0
		row += 1
	return 1

def look_up(grid, row, c):
	num = grid[row][c]
	row -= 1
	while row >= 0:
		if grid[row][c] >= num:
			return 0
		row -= 1
	return 1
def look_left(grid, row, c):
	num = grid[row][c]
	c -= 1
	while c >= 0:
		if grid[row][c] >= num:
			return 0
		c -= 1
	return 1
def look_right(grid, row, c):
	num = grid[row][c]
	c += 1
	while c < len(grid[row]):
		if grid[row][c] >= num:
			return 0
		c += 1
	return 1

visible = 0
row = 0
c = 0
while row < len(grid):
	c = 0
	while c < len(grid[row]):
		if row != 0 and c != 0 and c < len(grid[row]) - 1 and row < len(grid) - 1:
			if look_down(grid, row, c) == 1 or look_up(grid, row, c) == 1 or look_left(grid, row, c) == 1 or look_right(grid, row, c) == 1:
				visible += 1
		c += 1
	row += 1

sides = (2 * row) + (2 * (c - 2))
print(sides + visible)
