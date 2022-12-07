moves = {
	"rock": { "symbols": "A", "beats": "C", "score": 1},
	"paper": {"symbols": "B", "beats": "A", "score": 2 },
	"scissors": {"symbols": "C", "beats": "B", "score": 3}
}

def search_win(elf, symbol):
	for move in moves:
		if elf in moves[move]["beats"]:
			return moves[move]["score"]

def search_lose(elf, symbol):
	for move in moves:
		if elf in moves[move]["symbols"]:
			score = move_name(moves[move]["beats"])
			return score["score"]

def search_draw(elf, symbol):
	for move in moves:
		if elf in moves[move]["symbols"]:
			return moves[move]["score"]

def move_name(choice):
	if choice in moves["rock"]["symbols"]:
		return moves["rock"]
	if choice in moves["paper"]["symbols"]:
		return moves["paper"]
	if choice in moves["scissors"]["symbols"]:
		return moves["scissors"]

def outcome(elf, me):
	if me == "Z":
		return 6 + search_win(elf["symbols"][0], me)
	elif me == "X":
		return 0 + search_lose(elf["symbols"][0], me)
	elif me == "Y":
		return 3 + search_draw(elf["symbols"][0], me)

score = 0
with open("paris.txt") as file:
	while True:
		line = file.readline()
		if not line:
			break
		elf = line[0]
		me = line[2]
		elf = move_name(elf)
		score = score + outcome(elf, me)
print(score)