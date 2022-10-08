#include <iostream>
#include <vector>
#include <stack>


enum class Color {
    White = 0,
    Gray = 1,
    Black = 2,
};

std::stack<int> s;
std::vector<Color> visited;
std::vector<int> in;
std::vector<int> up;


void dfs(int v, int p, const std::vector<std::vector<int>>& g, int k)
{
    in[v] = k;
    up[v] = in[v];
    s.push(v);
    visited[v] = Color::Gray;
    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (v == p) { continue;}
        if (visited[u] == Color::White) {
            dfs(u, p, g, k+1);
            up[v] = std::min(up[v], up[u]);
        }
        if (visited[u] == Color::Gray) {
            up[v] = std::min(up[v], in[u]);
        }

        //if up[v] > in[u];
    }

    visited[v] = Color::Black;
    std::cout << "Visited Vertex(out): " << v << std::endl;

    
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    int size;
    int t;
    for (int i = 0; i < n; ++i) {
        std::cin >> size;
        for (int j = 0; j < size; ++j) {
            std::cin >> t;
            graph[i].push_back(t);
        }
        visited.push_back(Color::White);

    }

    dfs(0, 0, graph, 0);

}