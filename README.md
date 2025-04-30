# Analysis and Design of Algorithms (ADA)


##  Algorithm Checklist

###  Sorting Algorithms
- [x] **Merge Sort** – Implements the Merge Sort algorithm.
>
- [x] **Quick Sort** – Implements the Quick Sort algorithm.
>

###  Divide and Conquer
- [x] **Convex Hull** – Implements the Convex Hull algorithm using the Divide and Conquer approach.
> The convex hull of a set of points is the smallest convex polygon that encloses all the points.
> 
> Find the point with the minimum x-coordinate (let’s call it A) and the point with the maximum x-coordinate (B).
>
> These two points are part of the convex hull.
>
> Split the remaining points into two subsets:
>
> Points on the left side of the line AB.
>
> Points on the right side of the line AB.
>
> For each subset, find the point P that is farthest from the line segment.
>
> P forms a triangle with A and B.
>
> Recursively repeat the process on:
>
> Points on the outside of triangle ABP.
>
> This continues until no more outside points remain.
>
> The remaining boundary points from each recursive call make up the convex hull.
- [x] **Matrix Multiplication** – Performs matrix multiplication using the Divide and Conquer technique.
- [x] **Peak Finding** – Finds a peak element in a 1D or 2D array using binary search.

###  Greedy Algorithms
- [x] **Fractional Knapsack** – Solves the Knapsack problem allowing fractional item inclusion.
- [x] **Prim's Algorithm** – Finds the Minimum Spanning Tree using Prim's approach.
- [x] **Kruskal's Algorithm** – Constructs the Minimum Spanning Tree using Kruskal's method.
- [x] **Dijkstra's Algorithm** – Computes the shortest path from a single source to all vertices in a graph.

###  Dynamic Programming
- [x] **Longest Common Subsequence (LCS)** – Computes the longest subsequence common to two sequences.
- [x] **Matrix Chain Multiplication** – Determines the most efficient way to multiply a sequence of matrices.
- [x] **All-Pairs Shortest Path (Floyd-Warshall)** – Finds shortest paths between all pairs of vertices in a weighted graph.
- [x] **0/1 Knapsack** – Solves the 0/1 Knapsack problem using dynamic programming.
- [x] **Multistage Graph (Forward Approach)** – Finds the shortest path in a multistage graph using a forward approach.
- [x] **Multistage Graph (Backward Approach)** – Determines the shortest path in a multistage graph using a backward approach.

###  Backtracking
- [ ] **N-Queens Problem** – Solves the N-Queens problem using backtracking.
- [ ] **Subset Sum Problem** – Determines if there's a subset with a sum equal to a given number.
- [ ] **m-color graph**
- [ ] **Hamiltonian Cycle**




