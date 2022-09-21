#include <iostream>
#include <vector>
#include <queue>

enum class Color {
    White = 0,
    Gray = 1,
    Black = 2,
};

std::queue<int> q;
std::vector<Color> visited;
std::vector<int>topolog_sorted;

void dfs(int v, const std::vector<std::vector<int>>& g)
{
    visited[v] = Color::Gray;
    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (visited[u] == Color::White) {
            dfs(u, g);
        }

    }
    visited[v] = Color::Black;
    std::cout << "Visited Vertex: " << v << std::endl;
    topolog_sorted.push_back(v);

}


int main()
{
    int n;  //how much vertex
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    int size;   //how much ways from this vector
    int t;  //enumerating this ways
    for (int i = 0; i < n; ++i) {
        std::cin >> size;
        for (int j = 0; j < size; ++j) {
            std::cin >> t;
            graph[i].push_back(t);
        }
        visited.push_back(Color::White);
    }

    dfs(0, graph);

    std::cout << "TopologSort : ";

    for (int i = 0; i < n; ++i) {
        std::cout << topolog_sorted[n - i - 1] << " ";
    }
}
