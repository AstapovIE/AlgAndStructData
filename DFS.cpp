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
bool destroyer = false;


void dfs(int v, const std::vector<std::vector<int>>& g)
{
    if (destroyer) { return; }
    visited[v] = Color::Gray;
    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (visited[u] == Color::White) {
            dfs(u, g);
        }
        if (visited[u] == Color::Gray) {
            std::cout << "Circle here!!! Reverse edge :" << v << "->" << u << std::endl;
            destroyer = true;
            break;
        }
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

    dfs(0, graph);

    if (destroyer == false) { std::cout << "No circle" << std::endl; }

}
