def search(one, two, three):
	d = set(one) & set(two) & set(three)
	output = list(d).pop()
	return output

def score(duplicate, sum):
	if duplicate.islower() == True:
		c = ord(duplicate) - 96
	else:
		c = ord(duplicate) - 38
	return sum + c

sum = 0
loop = 0
group = []
sum = 0
with open("input.txt") as file:
	while True:
		line = file.readline()
		if not line:
			duplicate = search(group[0], group[1], group[2])
			sum = score(duplicate, sum)
			break
		if loop == 3:
			loop = 0
			duplicate = search(group[0], group[1], group[2])
			sum = score(duplicate, sum)
			group = []
			group.append(line.strip("\n"))
		else:
			group.append(line.strip("\n"))
		loop += 1
print(sum)