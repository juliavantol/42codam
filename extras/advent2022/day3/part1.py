def split_str(line):
	str_len = len(line)
	list1 = line[slice(0, str_len//2)]
	list2 = line[slice(str_len//2, str_len)]
	return [list1, list2]

def search(left, right):
	for i in left:
		for j in right:
			if i == j:
				return (i)

sum = 0
with open("input.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		output = split_str(line)
		duplicate = search(output[0], output[1])
		if duplicate.islower() == True:
			c = ord(duplicate) - 96
		else:
			c = ord(duplicate) - 38
		sum += c
print(sum)