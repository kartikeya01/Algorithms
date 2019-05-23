## Project 1

Write a **mergesort function which makes three recursive calls of length n/3** on an array of size n, and then merges three sorted arrays into one:
void mergesort(int a, int aux, int length);

## Project 2

Take the height-balanced tree code, and add a function
int depth distribution(tree node t tree);
which **prints the total number of leaves, and a table giving the number of leaves at
different depths**. The depth of a tree node is the distance from the root, so the root
has depth 0. 

## Project 3

Write a **function that finds the shortest path through a maze**, from start point s to target t, using Breadth First Search. The function declaration is:
void BFS(int n, int maze);
Here n is the sidelength of the maze, ∗maze is an n ×n array representing the maze, with entry 0 representing a blocked point, entry 1 representing an open point, and entries 2 and 3 representing the start and target points. Your function sets all the entries for fields on the shortest path to 4.

## Project 4

Write **code that finds a maximum flow in a directed graph**, using the Ford-Fulkerson
algorithm. The graph is given as adjacency matrix with cap[i][j] being the capacity
of the directed edge from i to j. The function received another argument, the matrix
flow[][], which is used to return the flow values in the maximum flow from s to t
void maximum flow(int n, int s, int t, int cap, int flow)
Your function has the following arguments:
- n: the number of vertices of the graph,
- s: the start vertex,
- t: the target vertex
- cap: the matrix of edge capacities.
- flow: the matrix used to return the maximum flow.
The vertices are numbered from 0 to n-1, so s and t are numbers in that range.
capacity, flow are a pointers to n × n matrices of nonnegative integers; in standard
C the size of a matrix cannot be a variable, so we use pointer arithmetic, and treat
the matrix as a one-dimensional matrix. The array element cap[i][j] can be accessed
as (cap + i*n + j). Your function should return in the matrix flow the flow values
of the maximum flow from s to t. The flow variable of your function points to space
allocated for the flow matrix.
Your function will need at least the following auxiliary arrays:
- an n × n matrix to hold the current flow,
- an n × n matrix to hold the current residual capacities,
- an array to maintain which vertices are already visited in the search of an augmenting
path from s to t with positive residual capacity.
You have to allocate and deallocate the auxiliary arrays in your function. Do not use
global variables. You can use either BFS or DFS for the search of the augmenting path.
