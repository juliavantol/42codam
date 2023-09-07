with open("input.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		index = 0
		while index < len(line):
			marker = []
			i = index
			while i < (index + 4) and (index + 4) < len(line):
				if line[i] not in marker:
					marker.append(line[i])
				i += 1
			if len(marker) == 4:
				print(marker)
				print("marker after:", index + 4)
				break
			index += 1


