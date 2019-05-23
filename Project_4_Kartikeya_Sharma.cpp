// CSC220-Algorithms Fall 2019
// Created By: Kartikeya Sharma
// Professor: Peter Brass

#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool BFS (int *resCap, int n, int s, int t, int *visited) {

    int i;
    int j;
    int temp[n][n];
    queue <int> q;
    bool visit[n];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            temp[i][j] = *(resCap + i*n + j);
        }
    }

    for(i=0; i<n; i++) {
        visit[i] = false;
    }

    q.push(s);
    visit[s] = true;
    visited[s] = -1;

    while (!q.empty()) { // Unless the queue is empty

        int front = q.front();
        q.pop();

        for (i = 0; i < n; i++) { // Search all adjacent nodes
            if (!visit[i] && temp[front][i] > 0) {
                q.push(i);
                visited[i] = front;
                visit[i] = true;
            }
        }
    }
    return visit[t];
}

void maximum_flow (int n, int s, int t, int *cap, int *flow) {

    // n: the number of vertices of the graph
    // s: the start vertex
    // t: the target vertex
    // cap: the matrix of edge capacities
    // flow: the matrix used to return the maximum flow

    int i;
    int j;
    int currentFlow[n][n]; // An nxn matrix to hold the current flow
    int currentResCap[n][n]; // An nxn matrix to hold the current residual capacities
    int visited[n]; // An array to maintain which vertices are already visited

    for (i = 0; i < n; i++) { // Store in 2-D matrix
        for (j = 0; j < n; j++) {
            currentFlow[i][j] = *(flow + i*n + j); // The array element flow[i][j] can be accessed
        }
    }

    for(i = 0; i < n; i++) { // Store in 2-D matrix
        for(j = 0; j < n; j++) {
            currentResCap[i][j] = *(cap + i*n + j); // The array element cap[i][j] can be accessed
        }
    }

    // Used BFS for the search of the augmenting path
    while (BFS(&(currentResCap[0][0]), n, s, t, &(visited[0]))) {
        // Ford-Fulkerson's Algorithm
        int path_flow = 999999; // An infinitely large number

        for (i = t; i != s; i = visited[i]) { // To locate the minimum residual capacities
            j = visited[i];
            if (path_flow >= currentResCap[j][i]) {
                path_flow = currentResCap[j][i];
            }
            currentFlow[j][i] += path_flow;
        }

        for (i = t; i != s; i = visited[i]) { // Update Current residual capacities
            j = visited[i];
            currentResCap[i][j] = currentResCap[i][j] + path_flow;
            currentResCap[j][i] = currentResCap[j][i] - path_flow;
        }

    }

    for(i = 0; i < n; i++) { // Update to Current Flow
        for(j = 0; j < n; j++){
            *(flow + i*n + j) = currentFlow[i][j];
        }
    }
}