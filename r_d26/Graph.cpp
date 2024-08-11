#include "Graph.h"
#include <queue>
#include <unordered_map>
#include <vector>

//TODO, STUDENTS: Implement this func
void Graph::addEdge(unsigned x, unsigned y)
{
    adjacencyList[x].push_back(y);
    adjacencyList[y].push_back(x);

}

//TODO, STUDENTS: Implement modified BFS algo to return path from start to destination only
//no need to traverse the whole Graph
std::vector<unsigned> Graph::bfs(unsigned start, unsigned destination)
{
    std::vector<bool> visited(numVertices, false);
    std::vector<unsigned> parent(numVertices, -1);
    std::queue<unsigned> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
    {
        unsigned currentVertex = queue.front();
        queue.pop();

        if (currentVertex == destination) {
            std::vector<unsigned> path;

            for (unsigned v = destination; v != start; v = parent[v]) {
                path.push_back(v);
            }

            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (unsigned adjVertex : adjacencyList[currentVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                parent[adjVertex] = currentVertex;
                queue.push(adjVertex);
            }
        }

    }


    return {}; // Return an empty path if no path is found
}
