import sys


def LLI():
    return [list(map(int, l.split())) for l in sys.stdin.readlines().strip()]


def LI_():
    return [int(x) - 1 for x in sys.stdin.readline().strip().split()]


def LF():
    return [float(x) for x in sys.stdin.readline().strip().split()]


def MI():
    return map(int, sys.stdin.readline().strip().split())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def LS():
    return sys.stdin.readline().strip().split()


def I():
    return int(sys.stdin.readline().strip())


# Matrix representation
# m = [[0 for i in range(node_count)] for j in range(node_count)]

# Adjacency List representation
# adj_list = m = [[] for j in range(node_count)]


class Edge:
    def __new__(cls, *args, **kwargs):
        return super().__new__(cls)

    def __init__(self, destiny_node, edge_weight):
        self.destiny_node = destiny_node
        self.edge_weight = edge_weight

    def __repr__(self) -> str:
        return f"{type(self).__name__}(x={self.destiny_node}, y={self.edge_weight})"


def print_matrix_representation(g, n):

    print("Graph with matrix representation: ")
    print("* \t", end="")
    for node_from in range(1, n + 1):
        print(str(node_from) + "\t", end="")
    print()
    for node_from in range(1, n + 1):
        print(str(node_from) + " : \t", end="")
        for node_to in range(1, n + 1):
            str_to_print = "-" if g[node_from][node_to] == 0 else str(g[node_from][node_to])
            print(str_to_print + "\t", end="")
        print()

    for node_from in range(1, n + 1):
        print(str(node_from) + " => ", end="")
        for node_to in range(1, n + 1):
            if g[node_from][node_to] == 0:
                continue
            print("(" + str(node_to) + " , " + str(g[node_from][node_to]) + ")", end="")
        print()
    print()


def print_adj_list_representation(g, n):
    print("Graph with adjacency list representation: ")
    for node_from in range(1, n + 1):
        print(str(node_from) + " => ", end="")
        for pair in g[node_from]:
            destiny_node = pair[0]
            edge_weight = pair[1]
            print("(" + str(destiny_node) + " , " + str(edge_weight) + ")", end="")
        print()


def print_edge_adj_list_representation(g, n):
    print("Graph with adjacency list representation and edge class: ")
    for node_from in range(1, n + 1):
        print(str(node_from) + " => ", end="")
        for edge in g[node_from]:
            print("(" + str(edge.destiny_node) + " , " + str(edge.edge_weight) + ")", end="")
        print()


def read_and_build_graph():

    # There will be "n" nodes and "m" edges
    n, m = MI()

    g_matrix = [[0 for i in range(n + 1)] for j in range(n + 1)]
    adj_list = [[] for j in range(n + 1)]
    edges_adj_list = [[] for j in range(n + 1)]

    # Read "m" edges of the form "a w b" where "a" and "b" are nodes 1 <= a,b <= n, and w is a positive weight
    for _ in range(m):
        a, w, b = MI()
        g_matrix[a][b] = w
        adj_list[a].append((b, w))
        edges_adj_list[a].append(Edge(b, w))

    print_matrix_representation(g_matrix, n)
    print_adj_list_representation(adj_list, n)
    print_edge_adj_list_representation(edges_adj_list, n)
    print()


def main():
    test_count = I()
    for i in range(test_count):
        print("GRAPH EXAMPLE " + str(i))
        read_and_build_graph()


if __name__ == "__main__":
    main()
