import heapq

class Node:
    def __init__(self, state, parent=None, cost=0, heuristic=0):
        self.state = state
        self.parent = parentjnbjhb hjvhgbjhvhgchgvjhcgfc
        self.cost = cost
        self.heuristic = heuristic

    def __lt__(self, other):
        return (self.cost + self.heuristic) < (other.cost + other.heuristic)

def a_star(start_state, goal_state, get_neighbors_func, heuristic_func):
    open_set = [Node(start_state, None, 0, heuristic_func(start_state))]
    closed_set = set()

    while open_set:
        current_node = heapq.heappop(open_set)

        if current_node.state == goal_state:
            path = []
            while current_node:
                path.insert(0, current_node.state)
                current_node = current_node.parent
            return path

        closed_set.add(current_node.state)

        for neighbor_state, step_cost in get_neighbors_func(current_node.state):
            if neighbor_state in closed_set:
                continue

            cost = current_node.cost + step_cost
            heuristic = heuristic_func(neighbor_state)
            new_node = Node(neighbor_state, current_node, cost, heuristic)

            if any(node.cost <= cost and node.state == neighbor_state for node in open_set):
                continue

            heapq.heappush(open_set, new_node)

    return None  # No path found

# Example usage:
# Define your game state, goal state, and functions to get neighbors and heuristic
start_state = (0, 0)
goal_state = (4, 4)

def get_neighbors(state):
    x, y = state
    neighbors = [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]  # Assuming 4-connected grid
    return [(neighbor, 1) for neighbor in neighbors if 0 <= neighbor[0] <= 4 and 0 <= neighbor[1] <= 4]

def heuristic(state):
    gx, gy = goal_state
    x, y = state
    return abs(gx - x) + abs(gy - y)

result = a_star(start_state, goal_state, get_neighbors, heuristic)
print(result)
