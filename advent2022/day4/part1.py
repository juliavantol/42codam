import re

def convert(low, high):
	num = []
	while low < (high + 1):
		num.append(str(low))
		low += 1
	return num

def compare(first, second):
	index = 0
	for num in first:
		if num in second:
			index += 1
	if index == len(first):
		return 1
	return 0

count = 0
with open("input.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		line = line.strip("\n")
		line = re.split('[- ,]', line)
		first = convert(int(line[0]), int(line[1]))
		second = convert(int(line[2]), int(line[3]))
		if compare(first, second) == 1:
			count += 1
		elif compare(second, first) == 1:
			count += 1
print("count:", count)