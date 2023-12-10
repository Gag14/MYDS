    #include <iostream>
    #include <vector>
    #include <string>
    #include <queue>
    #include <stack>
    #include <limits>
    #include <functional>
    #include <climits>

    class Graph
    {
    private:
        std::vector<std::vector<std::pair<int, int>>> graph_;

    public:
        Graph(int vertex) : graph_(vertex) {}

        ~Graph() {}

        void addEdge(int u, int v, int w = 0)
        {
            std::pair<int, int> p = std::make_pair(v, w);
            graph_[u].push_back(p);
        }
        void addVertex(int count)
        {
            std::vector<std::pair<int, int>> v;
            for (size_t i = 0; i < count; i++)
            {
                graph_.push_back(v);
            }
        }
        size_t size() { return graph_.size(); }
    void bfs(void visit(int vertex))
    {
        std::vector<bool> visited(graph_.size(), false);
        for (size_t i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                int s = i;
                std::queue<int> q;
                q.push(s);
                while (!q.empty())
                {           
                    int tmp = q.front();
                    q.pop();
                    visit(tmp);
                    visited[tmp] = true;
                    for (auto u : graph_[tmp])
                    {
                        if (!visited[u.first])
                        {
                            q.push(u.first);
                        }
                    }
                }
            }
        }
    }
    void dfs(void visit(int vertex), int s, std::vector<bool> &visited)
    {

        visit(s);
        visited[s] = true;
        for (auto u : graph_[s])
        {
            if (!visited[u.first])
            {
                dfs(visit, u.first, visited);
            }
        }
    }
    std::vector<int> KahnAlgorithm()
    {
        int V = graph_.size();
        std::vector<int> inDergree(V);
        for (int i = 0; i < V; ++i)
        {
            for (auto u : graph_[i])
            {
                ++inDergree[u.first];
            }
        }
        std::vector<int> result;
        std::queue<int> q;
        for (size_t i = 0; i < V; i++)
        {
            if (inDergree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int tmp = q.front();
            result.push_back(tmp);
            q.pop();
            for (auto u : graph_[tmp])
            {
                if (--inDergree[u.first] == 0)
                {
                    q.push(u.first);
                }
            }
        }
        return result;
    }
    Graph transposed()
    {

        Graph T(graph_.size());
        for (int i = 0; i < T.size(); ++i)
        {
            for (auto u : graph_[i])
            {
                T.graph_[u.first].push_back(std::make_pair(i, u.second));
            }
        }
        return T;
    }
    void dfsK1(int s, std::stack<int> &st, std::vector<bool> &visited)
    {
        visited[s] = true;
        for (auto u : graph_[s])
        {
            if (!visited[u.first])
            {
                dfsK1(u.first, st, visited);
            }
        }
        st.push(s);
    }
    void dfsK2(int s, std::vector<bool> &visited, std::vector<int> &component, Graph &T)
    {

        visited[s] = true;
        component.push_back(s);
        for (auto u : T.graph_[s])
        {
            if (!visited[u.first])
            {
                dfsK2(u.first, visited, component, T);
            }
        }
    }
    std::vector<std::vector<int>> KosarajuAlgorithm()
    {
        size_t V = graph_.size();
        std::vector<bool> visited(V);
        std::stack<int> st;
        std::vector<std::vector<int>> SCC;
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                dfsK1(i, st, visited);
            }
        }
        Graph T = transposed();
        visited.assign(V, false);
        while (!st.empty())
        {

            std::vector<int> component;
            int tmp = st.top();
            st.pop();
            if (!visited[tmp])
            {
                dfsK2(tmp, visited, component, T);
                SCC.push_back(component);
            }
        }
        return SCC;
    }
    void dfsth(int s, std::vector<bool> visited, std::stack<int> &st, std::vector<bool> &onStack, std::vector<int> &ids, std::vector<int> &low, std::vector<std::vector<int>> &SCC, int &id)
    {
        visited[s] = true;
        onStack[s] = true;
        st.push(s);
        ids[s] = low[s] = ++id;
        for (auto u : graph_[s])
        {
            if (ids[u.first] == -1)
            {
                dfsth(u.first, visited, st, onStack, ids, low, SCC, id);
                low[s] = std::min(low[u.first], low[s]);
            }
            else if (onStack[u.first])
            {
                low[s] = std::min(low[u.first], low[s]);
            }
        }

        if (low[s] == ids[s])
        {
            std::vector<int> component;
            int c;
            do
            {
                onStack[s] = false;
                c = st.top();
                st.pop();
                component.push_back(c); 
            } while (c != s);
            SCC.push_back(component);
        }
    }
    std::vector<std::vector<int>> TarjanAlgorithm()
    {
        int V = graph_.size();
        std::vector<bool> visited(V, false);
        std::vector<bool> onStack(V, false);
        std::stack<int> st;
        std::vector<int> ids(V, -1);
        std::vector<int> low(V, -1);
        std::vector<std::vector<int>> SCC;
        int id = 0;
        for (size_t i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsth(i, visited, st, onStack, ids, low, SCC, id);
            }
        }
        return SCC;
    }

    void Dijkstra(int s, std::vector<int> &dist)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        dist.assign(dist.size(), std::numeric_limits<int>::max());
        dist[s] = 0;
        pq.push(std::make_pair(0, s));

        while (!pq.empty())
        {
            int v = pq.top().second;
            int current_distance = pq.top().first;
            pq.pop();
            for (auto &neigh : graph_[v])
            {
                int u = neigh.first;
                int w = neigh.second;
                if (dist[u] > dist[v] + w) // Corrected the condition here
                {
                    dist[u] = dist[v] + w;
                    pq.push(std::make_pair(dist[u], u));
                }
            }
        }
    }
  void BellmanFordAlgorithm(int s, std::vector<int> &SP)
{
    int V = graph_.size();
    int INF = INT_MAX;
    std::vector<int> dist(V, INF);
    dist[s] = 0;

    for (size_t i = 1; i < V; i++)
    {
        for (int u = 0; u < V; ++u)
        {
            for (auto &neig : graph_[u])
            {
                int v = neig.first;
                int w = neig.second;
                if (dist[u] != INF && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < V; ++u)
    {
        for (auto &neig : graph_[u])
        {
            int v = neig.first;
            int w = neig.second;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                std::cout << "Negative cycle detected." << std::endl;
                return;
            }
        }
    }
}

}; // End Of Graph

void visitVertex(int vertex)
{
    std::cout << vertex << " ";
}
void printVec(const std::vector<int> &vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
}
int main()
{
    Graph graph(9); // Create a graph with 6 vertices

    graph.addEdge(0, 1, 8);
    graph.addEdge(1, 2, 6);
    graph.addEdge(2, 1, -87);
    graph.addEdge(3, 4, 0);
    graph.addEdge(4, 5, 8);
    graph.addEdge(5, 2, 3);
    graph.addEdge(6, 2, 3);
    graph.addEdge(7, 2, 3);
    graph.addEdge(8, 2, 3);

    graph.addEdge(7, 0, -99);
    std::cout << "BFS Traversal: ";
    graph.bfs(visitVertex);
    std::cout << std::endl;
    // // // return 0;
    std::vector<bool> visited(graph.size(), false); // Initialize visited vector

    std::cout << "DFS Traversal: ";
    for (size_t i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            graph.dfs(visitVertex, i, visited);
        }
    }
    std::cout << std::endl;

    std::vector<int> topsort = graph.KahnAlgorithm();
    std::cout << "Khan Algorithm : ";
    for (int i : topsort)
    {
        std::cout << i << " ";
    }
    if (topsort.size() != graph.size())
    {
        std::cout << " | Cycle Detected ";
    }
    std::cout << std::endl;
    std::vector<std::vector<int>> SCC = graph.KosarajuAlgorithm();
    std::cout << "SCC Kosaraju are below:" << std::endl;
    int i = 1;

    for (auto &component : SCC)
    {
        std::cout << i++ << " - ";
        printVec(component);
        std::cout << std::endl;
    }

    SCC = graph.TarjanAlgorithm();
    std::cout << "SCC Tarjan are below:" << std::endl;
    i = 1;

    for (auto &component : SCC)
    {
        std::cout << i++ << " - ";
        printVec(component);
        std::cout << std::endl;
    }
    std::vector<int> SP(graph.size(), std::numeric_limits<int>::max());
    graph.Dijkstra(0, SP);
    std::cout << "Shortest paths Dijkstra: " << std::endl;
    for (int i = 0; i < SP.size(); ++i)
    {
        std::cout << "To " << i << " Distance is: " << SP[i] << std::endl;
    }
    SP.assign(graph.size(), std::numeric_limits<int>::max());
    graph.Dijkstra(0, SP);
    std::cout << "Shortest paths Bellman Ford: " << std::endl;
    for (int i = 0; i < SP.size(); ++i)
    {
        std::cout << "To " << i << " Distance is: " << SP[i] << std::endl;
    }
    return 0;
}
