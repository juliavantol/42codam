rock = { "symbols": ["A", "X"], "beats": "C", "score": 1}
paper = {"symbols": ["B", "Y"], "beats": "A", "score": 2 }
scissors = {"symbols": ["C", "Z"], "beats": "B", "score": 3}

def move_name(choice):
	if choice in rock["symbols"]:
		return rock
	if choice in paper["symbols"]:
		return paper
	if choice in scissors["symbols"]:
		return scissors

def outcome(elf, me):
	if elf in me["symbols"]:
		return 3 + me["score"]
	if elf in me["beats"]:
		return 6 + me["score"]
	return 0 + me["score"]

score = 0
with open("julia.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		elf = line[0]
		me = line[2]
		me = move_name(me)
		score = score + outcome(elf, me)
print(score)
