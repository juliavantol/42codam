import sys
import re

if len(sys.argv) == 2:
	file = sys.argv[1]
else:
	file = "test.txt"

lines = []
try:
	with open(file) as f:
		while True:
			line = f.readlines()
			lines.append(line)
			if not line:
				break
except:
	print("File couldn't be opened")

index = 0
lines = lines[0]
dirs = {}
while index < len(lines):
	if "$ ls" in lines[index]:
		content = []
		current = lines[index - 1][5]
		i = index + 1
		while (i + 1) <= len(lines) and "$" not in lines[i]:
			if "dir" not in lines[i]:
				size = int(re.sub(r'[^0-9]', '', lines[i]))
			else:
				size = lines[i][4]
			content.append(size)
			i += 1
		dirs[current] = content
	index += 1

def calculate_size(folder, sum):
	i = 0
	while i < len(folder):
		if isinstance(folder[i], int):
			sum += folder[i]
		i += 1
	return sum

folder_sizes = {}
for key in dirs:
	sum = calculate_size(dirs[key], 0)
	folder_sizes[key] = sum
	# print(key, "->", sum)
	# print(key, "->", dirs[key])

for key in dirs:
	for i in dirs[key]:
		if isinstance(i, str):
			sum = folder_sizes[key]
			# sum += calculate_size(i, sum)
			folder_sizes[key] = sum + folder_sizes[i]
			print(key, "->", i)

sum = 0
for size in folder_sizes:
	if (folder_sizes[size] <= 100000)
		sum += folder_sizes[size]
		print(folder_sizes[size])
print("sum", sum);