def split_str(line):
	str_len = len(line)
	s1 = slice(0, str_len//2)
	s2 = slice(str_len//2, str_len)
	list1 = line[s1]
	list2 = line[s2]
	output = [list1, list2]
	return output

with open("test.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		print(split_str(line))