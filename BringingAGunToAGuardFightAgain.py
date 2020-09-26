from math import atan2

def getDistance(x, y, your_position):
    return (x - your_position[0]) * (x - your_position[0]) + (y - your_position[1]) * (y - your_position[1])

def getAllMirrorPoints(position, your_position, dimensions, distance):
    horizontal_points = []

    diffx = [ 0 for i in range(2) ]
    diffy = [ 0 for i in range(2) ]
    diffx[0] = 2 * (position[0])
    diffx[1] = 2 * (dimensions[0] - position[0])
    diffy[0] = 2 * (position[1])
    diffy[1] = 2 * (dimensions[1] - position[1])

    # print(position)
    # print(diffx)
    # print(diffy)

    curr_x = position[0] - diffx[0]
    curr_y = position[1]
    i = 1
    while(getDistance(curr_x, curr_y, your_position) <= (distance * distance)):
        horizontal_points.append(curr_x)
        curr_x -= diffx[i % 2]
        i = i + 1

    horizontal_points.reverse()
    horizontal_points.append(position[0])

    curr_x = position[0] + diffx[1]
    curr_y = position[1]
    i = 0
    while(getDistance(curr_x, curr_y, your_position) <= (distance * distance)):
        horizontal_points.append(curr_x)
        curr_x += diffx[i % 2]
        i = i + 1


    vertical_points = []

    curr_x = position[0]
    curr_y = position[1] - diffy[0]
    i = 1
    while(getDistance(curr_x, curr_y, your_position) <= (distance * distance)):
        vertical_points.append(curr_y)
        curr_y -= diffy[i % 2]
        i = i + 1

    vertical_points.reverse()
    vertical_points.append(position[1])

    curr_x = position[0]
    curr_y = position[1] + diffy[1]
    i = 0
    while(getDistance(curr_x, curr_y, your_position) <= (distance * distance)):
        vertical_points.append(curr_y)
        curr_y += diffy[i % 2]
        i = i + 1

    return horizontal_points, vertical_points

def solution(dimensions, your_position, guard_position, distance):
    your_horizontal_position, your_vertical_position = getAllMirrorPoints(your_position, your_position, dimensions, distance)
    guard_horizontal_position, guard_vertical_position = getAllMirrorPoints(guard_position, your_position, dimensions, distance)
    
    # print((your_horizontal_position))
    # print((your_vertical_position))
    # print((guard_horizontal_position))
    # print((guard_vertical_position))

    best = {}
    done = {}
    count = 0
    c1 = 0

    for x in your_horizontal_position:
        for y in your_vertical_position:
            if [x, y] == your_position:
                continue
            if getDistance(x, y, your_position) > (distance * distance):
                continue
            angle = atan2(x - your_position[0], y - your_position[1])
            # print(angle)
            if angle in best and best[angle] <= getDistance(x, y, your_position):
                continue
            c1 = c1 + 1
            # print(x, ", ", y, ", ", angle, sep="")
            best[angle] = getDistance(x, y, your_position)

    # print()
    # print(len(best))
    # print(c1)
    # print()


    for x in guard_horizontal_position:
        for y in guard_vertical_position:
            if getDistance(x, y, your_position) > (distance * distance):
                continue
            angle = atan2(x - your_position[0], y - your_position[1])
            # print(angle)
            if angle in done:
                continue
            if angle in best and best[angle] <= getDistance(x, y, your_position):
                continue
            # print(x, ", ", y, ", ", angle, sep="")
            count = count + 1
            done[angle] = 1
            best[angle] = getDistance(x, y, your_position)

    return count

    

# print(solution([3, 2], [1, 1], [2, 1], 4))
print(solution([10, 10], [4, 4], [3, 3], 5000))
# print(solution([300, 275], [150, 150], [185, 100], 500))
# print(solution([2, 5], [1, 2], [1, 4], 11))
# print(solution([23, 10], [6, 4], [3, 2], 23))