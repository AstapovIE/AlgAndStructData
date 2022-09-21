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


void bfs(int v, const std::vector<std::vector<int>>& g)
{
    q.pop();

    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (visited[u] == Color::White) {
            q.push(u);
            visited[u] = Color::Gray;
        }
    }
    visited[v] = Color::Black;
    std::cout << "Visited Vertex: " << v << std::endl;
    while (!q.empty()) {
        bfs(q.front(), g);
    }
}

int main()
{
    int n; // how much vertex
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);

    int size;   //how much way from vertex
    int t;  //enumeration this ways

    for (int i = 0; i < n; ++i) {
        std::cin >> size;
        for (int j = 0; j < size; ++j) {
            std::cin >> t;
            graph[i].push_back(t);
        }
        visited.push_back(Color::White);
    }

    q.push(0);
    visited[0] = Color::Gray;
    bfs(0, graph);

}
