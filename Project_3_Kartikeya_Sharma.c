// Algorithms 220 - Peter Brass
// Homework - Project 3
// Created by Kartikeya Sharma

void BFS (int n, int *maze) {

    int tracker[n*n]; // Keeps track of all the positions and their availabilities
    int bfs[n*n]; // Keeps track of the shortest path
    int toTarget = 0;
    int fromStart = 0;

    // First, we must locate the start point "2" within maze
    for (int i = 0; i < (n*n); i++) {
        tracker[i] = 1; // Initialize all other values in tracker as 1
        if (maze[i] == 2) {
            bfs[0] = i;
            tracker[i] = 2; // Initialize start position as 2
            fromStart++;
        }
    }

    // Second, we must locate the target point "3" within maze : Check N-E-S-W
    while (fromStart - toTarget > 0) { // While there is still a path to be found from start -> target

        int row = bfs[toTarget] / n; // To stay within bounds of maze
        int col = bfs[toTarget] % n;

        // North
        if (row != 0) { // Entry 0 representing a blocked point
            int nPosition = (row - 1)*n + col; // Calculate North coordinate (position)

            if (tracker[nPosition] == 1) { // If not currently at start and have reached target, finish loop
                if (maze[nPosition] == 3) break;

                else if (maze[nPosition] == 1) { // Entry 1 representing an open point
                    bfs[fromStart] = nPosition; // Record position of next possible position path
                    tracker[nPosition] = bfs[toTarget];
                    fromStart++;
                }
            }
        }

        // East
        if (col != n - 1) { // Entry 0 representing a blocked point
            int ePosition = row*n + (col + 1); // Calculate East coordinate (position)

            if (tracker[ePosition] == 1) { // If not currently at start and have reached target, finish loop
                if (maze[ePosition] == 3) break;

                else if (maze[ePosition] == 1) { // Entry 1 representing an open point
                    bfs[fromStart] = ePosition; // Record position of next possible position path
                    tracker[ePosition] = bfs[toTarget];
                    fromStart++;
                }
            }
        }

        // South
        if (row != n - 1) { // Entry 0 representing a blocked point
            int sPosition = (row + 1)*n + col; // Calculate South coordinate (position)

            if (tracker[sPosition] == 1) { // If not currently at start and have reached target, finish loop
                if (maze[sPosition] == 3) break;

                else if (maze[sPosition] == 1) { // Entry 1 representing an open point
                    bfs[fromStart] = sPosition; // Record position of next possible position path
                    tracker[sPosition] = bfs[toTarget];
                    fromStart++;
                }
            }
        }

        // West
        if (col != 0) { // Entry 0 representing a blocked point
            int wPosition = row*n + (col - 1); // Calculate West coordinate (position)

            if (tracker[wPosition] == 1) { // If not currently at start and have reached target, finish loop
                if (maze[wPosition] == 3) break;

                else if (maze[wPosition] == 1) { // Entry 1 representing an open point
                    bfs[fromStart] = wPosition; // Record position of next possible position path
                    tracker[wPosition] = bfs[toTarget];
                    fromStart++;
                }
            }
        }

        toTarget++; // Once all directions are checked, we need to increment this to keep track of
                    // the distance between start and target
    }

    toTarget = bfs[toTarget];
    while (tracker[toTarget] != 2) { // While starting position is not reached...
        maze[toTarget] = 4; // Your function sets all the entries for fields on the shortest path to 4
        toTarget = tracker[toTarget];
    }
}