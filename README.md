# Analysis and Design of Algorithms (ADA)


##  Algorithm Checklist

###  Sorting Algorithms
- [x] **Merge Sort** – Implements the Merge Sort algorithm.
>
- [x] **Quick Sort** – Implements the Quick Sort algorithm.
>

###  Divide and Conquer
- [x] **Convex Hull** – Implements the Convex Hull algorithm using the Divide and Conquer approach.
> - QuickHull is a divide-and-conquer algorithm that finds the convex hull by:
> - Starting with the leftmost and rightmost points, recursively finding the farthest outer points, discarding interior ones, and combining outer points to form the convex boundary.
- [x] **Matrix Multiplication** – Performs matrix multiplication using the Divide and Conquer technique.
> - Matrix Multiplication (Divide and Conquer) splits two matrices into submatrices, recursively multiplies them, and combines the results to form the final product.It reduces large matrix multiplication into smaller ones for better efficiency, especially useful for large square matrices.
- [x] **Peak Finding** – Finds a peak element in a 1D or 2D array using binary search.
> - Peak Finding (1D/2D using Binary Search) locates an element that is greater than or equal to its neighbors by repeatedly dividing the array (or matrix) and checking mid elements.
> -It uses binary search to efficiently find a peak in O(log n) (1D) or O(n log m) (2D) time.
###  Greedy Algorithms
- [x] **Fractional Knapsack** – Solves the Knapsack problem allowing fractional item inclusion.
> - Fractional Knapsack solves the knapsack problem by sorting items by value-to-weight ratio and greedily taking as much of the highest ratio items as possible — including fractions — to maximize profit.
- [x] **Prim's Algorithm** – Finds the Minimum Spanning Tree using Prim's approach.
> - Prim’s Algorithm builds a Minimum Spanning Tree by starting from any node and repeatedly adding the smallest edge that connects a new vertex to the growing tree, until all vertices are included.
- [x] **Kruskal's Algorithm** – Constructs the Minimum Spanning Tree using Kruskal's method.
> - Kruskal’s Algorithm constructs a Minimum Spanning Tree by sorting all edges by weight and adding the smallest edge that doesn't form a cycle, using a disjoint-set (union-find) to manage components.
- [x] **Dijkstra's Algorithm** – Computes the shortest path from a single source to all vertices in a graph.
> - Dijkstra’s Algorithm computes the shortest path from a single source to all other vertices by greedily selecting the nearest unvisited vertex and updating the distances of its neighbors.

###  Dynamic Programming
- [x] **Longest Common Subsequence (LCS)** – Computes the longest subsequence common to two sequences.
> - Longest Common Subsequence (LCS) finds the longest sequence that appears in the same order in both strings (not necessarily contiguously), using dynamic programming to build solutions to subproblems.
- [x] **Matrix Chain Multiplication** – Determines the most efficient way to multiply a sequence of matrices.
> -Matrix Chain Multiplication is a dynamic programming algorithm that determines the most efficient way to multiply a sequence of matrices by choosing the optimal order of multiplication.
> - It minimizes the total number of scalar multiplications needed by evaluating all possible parenthesizations.
- [x] **All-Pairs Shortest Path (Floyd-Warshall)** – Finds shortest paths between all pairs of vertices in a weighted graph.
> - Floyd-Warshall Algorithm is a dynamic programming method used to find the shortest paths between all pairs of vertices in a weighted graph.
> - It works by considering each vertex as an intermediate point and repeatedly updating the shortest distances between every pair of nodes, even for graphs with negative edge weights (but no negative cycles).
- [x] **0/1 Knapsack** – Solves the 0/1 Knapsack problem using dynamic programming.
> - 0/1 Knapsack uses dynamic programming to find the maximum total value that can be carried in a knapsack without exceeding its weight capacity, where each item can be included at most once (either 0 or 1).
> - It builds a DP table to evaluate the best value achievable for each item and capacity combination.
- [x] **Multistage Graph (Forward Approach)** – Finds the shortest path in a multistage graph using a forward approach.
> - Multistage Graph Shortest Path uses a forward dynamic programming approach to find the shortest path from the source to the destination in a graph divided into stages.
> - It calculates the minimum cost from each vertex to the destination by processing stages in reverse order, ensuring the most efficient path is chosen through each stage.
- [x] **Multistage Graph (Backward Approach)** – Determines the shortest path in a multistage graph using a backward approach.
> - Multistage Graph (Backward Approach) finds the shortest path from source to destination by processing the graph backward, starting from the destination node.
> - It uses dynamic programming to compute the minimum cost to reach the destination from each node by considering all possible outgoing edges stage by stage in reverse.

###  Backtracking
- [ ] **N-Queens Problem** – Solves the N-Queens problem using backtracking.
> - The N-Queens problem is a classic backtracking challenge where you must place N queens on an N×N chessboard such that:
> - No two queens attack each other.

>   - This means:

>    No two queens can be in the same row,

>    No two queens can be in the same column, and

>    No two queens can be on the same diagonal.
- [ ] **Subset Sum Problem** – Determines if there's a subset with a sum equal to a given number.
> - Subset Sum Problem uses dynamic programming or backtracking to determine if there exists a subset of a given set whose sum equals a specified target value.
> - It builds a DP table (or explores possibilities recursively) to check if the sum can be formed using some elements of the set.
- [ ] **M-color Graph** - To determine if a graph can be colored using at most M colors such that no two adjacent vertices share the same color.
> - Try assigning colors (1 to M) to each vertex using backtracking, ensuring no two adjacent vertices have the same color.
> - Backtrack if a conflict occurs, and repeat until all vertices are colored or no solution exists.
- [ ] **Hamiltonian Cycle** - To find a cycle in a graph that visits every vertex exactly once and returns to the starting vertex.
> - Start at any vertex and use backtracking to build a path that visits every vertex exactly once.
> - If the path forms a cycle by returning to the starting vertex, it's a Hamiltonian Cycle; otherwise, backtrack and try other paths.




