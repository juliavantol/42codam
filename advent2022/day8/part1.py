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
	print(grid[row][c])

row = 0
c = 0
while row < len(grid):
	c = 0
	while c < len(grid[row]):
		print(grid[row][c], end="")
		c += 1
	print("\n")
	row += 1

# for row in grid:
# 	for c in row:
# 		if 
# 		print(c, end="")
# 	print("\n")
