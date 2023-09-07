import sys

if len(sys.argv) == 2:
	file = sys.argv[1]
else:
	file = "test.txt"

moves = {
	"U": [-1, 0], "D": [1, 0], "L": [0, -1], "R": [0, 1]
}

def check_position(head, tail, prev_head):
	line = tail[0]
	row = tail[1]
	if head[0] == tail[0]:
		row = int(tail[1]) + int(head[1] - 1)
	elif head[1] == tail[1]:
		line = int(tail[0]) + int(head[0] - 1)
	else:
		# row change
		if prev_head[0] == head[0]:
			if prev_head[1] > head[1]:
				places = (prev_head[1] - head[1]) * -1
			else:
				places = head[1] - prev_head[1]
			print("places:", places)
			row1 = head[1] + places
	
		# line change
		elif prev_head[1] == head[1]:
			if prev_head[0] > head[0]:
				places = head[0] - prev_head[0]
				if places < 0:
					line = prev_head[0] + places + 1
			else:
				places = prev_head[0] - head[0]
			print("places:", places)
	tail = [line, row]
	return tail

head_position = [0, 0]
tail_position = [0, 0]
try:
	with open(file) as f:
		while True:
			l = f.readline()
			if not l:
				break
			parse = l.split(" ")
			direction = parse[0]
			move = int(parse[1].strip("\n"))

			prev_head = head_position
			print("before:", prev_head)
			line = head_position[0] + move * int(moves[direction][0])
			row =  head_position[1] + move * int(moves[direction][1])
			head_position = [line, row]
			tail_position = check_position(head_position, tail_position, prev_head)
			print("head:", head_position)
			print("tail:", tail_position)
			print()

except:
	print("File couldn't be opened")
