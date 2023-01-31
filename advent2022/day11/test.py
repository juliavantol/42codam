with open("test.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		print(line)