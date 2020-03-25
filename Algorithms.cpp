//
// Created by Maria Caldeira on 25/03/2020.
//

#include <list>
#include "Algorithms.h"

using namespace std;

void bfs(Board board, int s)
{
    // Mark all the vertices as not visited
    int N = board.getNumCols() * board.getNumRows();
    bool *visited = new bool[N];
    for(int i = 0; i < N; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        /*for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }*/
    }
}