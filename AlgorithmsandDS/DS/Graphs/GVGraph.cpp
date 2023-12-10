#ifndef __GVG__
#define __GVG__

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

namespace MYDS
{
    class Graph
    {
    public:
        // Ctor Dtor
        Graph() {}
        Graph(int VertexCount) : graph_(std::vector<std::vector<int>>(VertexCount)) {}
        Graph(const Graph &other)
        {
            graph_ = other.graph_;
        }
        ~Graph() {}

        // Operators
        Graph &operator=(const Graph &rhs)
        {
            graph_ = rhs.graph_;
        }
        // Public Methods

        bool addEdge(int v, int u)
        {
            if (v < 0 || u < 0 || v >= graph_.size() || u >= graph_[v].size())
            {
                throw std::invalid_argument("Invalid arguments for addEdge");
            }

            graph_[v].push_back(u);
            graph_[u].push_back(v);
            return true;
        }
        bool addVertex(int count)
        {
            std::vector<std::vector<int>> newVertexes(count);
            graph_.insert(graph_.end(), newVertexes.begin(), newVertexes.end());
            return true;
        }
        void bfs(void visit(int i), int source = 0)
        {
            std::vector<bool> visited(graph_.size(), false);
            for (int i = 0; i < visited.size(); ++i)
            {
                if (!visited[i])
                {
                    std::queue<int> q;
                    q.push(i);
                    while (!q.empty())
                    {
                        int tmp = q.front();
                        q.pop();
                        if (!visited[tmp])
                        {
                            visit(tmp);
                            visited[tmp] = true;
                        }
                        for (int i : graph_[tmp])
                        {
                            if (!visited[i])
                            {
                                q.push(i);
                            }
                        }
                    }
                }
            }
        }
        void dfs(void visit(int i))
        {
            std::vector<bool> visted(graph_.size(), false);
            dfshelper(visit, 0, visted);
        }
        void transpose()
        {
            std::vector<std::vector<int>> transposed(graph_.size());
            for (size_t i = 0; i < graph_.size(); i++)
            {
                for (size_t j = 0; j < graph_[i].size(); j++) // This line has the issue
                {
                    transposed[graph_[i][j]].push_back(i);
                }
            }
            graph_ = transposed;
        }
        int countOfNodeAtLevel(int source, int level)
        {
            std::vector<bool> visited(graph_.size(), false);
            std::queue<int> q;
            q.push(source);
            visited[source] = true;
            int count = 0;
            int currentLevel = 0;

            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; ++i)
                {
                    int tmp = q.front();
                    q.pop();

                    if (currentLevel == level)
                    {
                        ++count;
                    }

                    for (int neighbor : graph_[tmp])
                    {
                        if (!visited[neighbor])
                        {
                            q.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }

                if (currentLevel == level)
                {
                    break; // No need to go further if we've reached the target level
                }

                ++currentLevel;
            }

            return count;
        }

        std::vector<int> shortestPath(int v, int u);
        std::vector<std::vector<int>> allPathsBeetwen(int v, int u);

    private:
        std::vector<std::vector<int>> graph_;

        void dfshelper(void visit(int i), int source, std::vector<bool> &visited)
        {
            for (size_t i = 0; i < visited.size(); i++)
            {
                if (!visited[i])
                {
                    source = i;

                    visit(source);
                    visited[source] = true;

                    for (int ver : graph_[source])
                    {
                        if (!visited[ver])
                        {
                            dfshelper(visit, ver, visited);
                        }
                    }
                }
            }
        }
    };
}
#endif
