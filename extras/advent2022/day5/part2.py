from collections import OrderedDict

stack = {}
index = 1
stop = 0
instructions = []
with open("input.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		try:
			if line[1] is '1':
				stop = 1
			if stop is not 1:
				c = 0
				crate = ""
				index = 1
				while (c + 2) < len(line):
					crate = line[c] + line[c + 1] + line[c + 2]
					c = c + 4
					if index in stack:
						crates = stack[index]
					else:
						crates = []
					if crate[0] is "[":
						crates.append(crate)
						stack[index] = crates
					index += 1
		except:
			pass
		if "move" in line:
			instructions.append(line)

print("before:")
stack = OrderedDict(sorted(stack.items()))
for key, value in stack.items():
	print(key, ':', value)


for instruction in instructions:
	moves = [int(s) for s in instruction.split() if s.isdigit()]
	amount = moves[0]
	source = moves[1]
	destination = moves[2]
	source_crate = stack[source]
	dest_crate = stack[destination]
	index = 0
	adds = []
	while index < amount:
		try:
			temp = source_crate.pop(0)
			adds.append(temp)
		except:
			pass
		index += 1
	adds.reverse()
	for t in adds:
		dest_crate.insert(0, t)
final_stack = OrderedDict(sorted(stack.items()))
print("after:")
output = ""
for key, value in final_stack.items():
	print(key, ':', value)
	output += value[0][1]
print("Answer:", output)