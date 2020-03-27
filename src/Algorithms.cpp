//
// Created by Maria Caldeira on 25/03/2020.
//

#include <list>
#include "Algorithms.h"

using namespace std;

void bfs(Board board)
{
    // Mark all the vertices as not visited
    /*int N = board.getNumCols() * board.getNumRows();

    for (int i = 0; i < board.getBoard().getBoard().size(); i++)
        {
            for (int j = 0; j < board.getBoard().getBoard().at(i).size(); j++)
            {
                vector<vector<int>> possibleMoves = game.possibleMovesList(i, j);
                if (possibleMoves.size() > 0)
                {
                    for (unsigned int w = 0; w < possibleMoves.size(); w++)
                    {
                        vector<int> from = {i, j};
                        vector<int> to = possibleMoves.at(w);
                        struct node *newNode = new node();
                        newNode->from = from;
                        newNode->to = to;
                        newNode->prevGame = game;
                        if (currNode == NULL)
                        {
                            newNode->father = NULL;
                            newNode->level = 1;
                        }
                        else
                        {
                            newNode->father = currNode;
                            newNode->level = currNode->level + 1;
                        }
                        bfsTree.push(newNode);
                    }
                }
            }


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
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }*/
}

/*Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
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
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}*/