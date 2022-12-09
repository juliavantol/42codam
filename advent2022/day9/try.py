S = [s.split(" ") for s in open("input.txt").read().split("\n")]
Mvts = {"R":[1, 0], "L":[-1,0], "D":[0,-1], "U":[0,1]}

def simulate(nknots):
    knots, visitedPositions = [[0,0] for _ in range(nknots)], set()
    Update = lambda hx,hy,tx,ty: [tx, ty] if (tx - hx)**2+(ty-hy)**2 < 3 else [hx + int((tx-hx)/2.0), hy + int((ty-hy)/2.0)]

    for mvt, moves in S:
        for _ in range(int(moves)):
            knots[0] = [knots[0][0]+Mvts[mvt][0], knots[0][1]+Mvts[mvt][1]]
            for i in range(1, len(knots)): knots[i] = Update(*knots[i-1], *knots[i])
            visitedPositions.add(tuple(knots[-1]))
    return len(visitedPositions)

print(f"Part1 = {simulate(2)}, Part2 = {simulate(10)}")