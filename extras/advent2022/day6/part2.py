import sys

if len(sys.argv) == 2:
	input = sys.argv[1]
else:
	input = "test.txt"
try:
	with open(input) as file:
		while True:
			line = file.readline()
			if not line:
				break
			index = 0
			while index < len(line):
				marker = []
				i = index
				while i < (index + 14) and (index + 14) < len(line):
					if line[i] not in marker:
						marker.append(line[i])
					i += 1
				if len(marker) == 14:
					print(marker)
					print("marker after: ", index + 14)
					break
				index += 1
except:
	print("File couldn't be opened")