#include <iostream>
#include <vector>
#include <queue>
#include <stack>


enum class Color {
    White = 0,
    Gray = 1,
    Black = 2,
};

std::queue<int> q;
std::vector<Color> visited;
std::vector<Color> visitedForInv;
std::stack<int> s;

void finding_out_time(int v, const std::vector<std::vector<int>>& g)
{
    visited[v] = Color::Gray;
    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (visited[u] == Color::White) {
            finding_out_time(u, g);
        }

    }
    visited[v] = Color::Black;
    std::cout << "Visited Vertex(out): " << v << std::endl;
    s.push(v);
}

void dfs(int v, const std::vector<std::vector<int>>& g, std::vector<int>& checked)
{
    visitedForInv[v] = Color::Gray;
    checked[v] = 1;

    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (visitedForInv[u] == Color::White) {
            dfs(u, g, checked);
        }

    }
    visitedForInv[v] = Color::Black;
    std::cout << v << " ";
}

void bypass(const std::vector<std::vector<int>>& g, std::vector<int>& checked)
{
    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (checked[v] != 1) {
            std::cout << std::endl;
            std::cout << "<<< ";
            dfs(v, g, checked);
            std::cout << ">>>";
        }
    }
}


int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    std::vector<std::vector<int>> invgraph(n);
    int size;
    int t;
    for (int i = 0; i < n; ++i) {
        std::cin >> size;
        for (int j = 0; j < size; ++j) {
            std::cin >> t;
            graph[i].push_back(t);
            invgraph[t].push_back(i);
        }
        visited.push_back(Color::White);
        visitedForInv.push_back(Color::White);
    }
    finding_out_time(0, graph);

    std::vector<int> checked(n);
    bypass(invgraph, checked);

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}
/*
8
1
1
2
2
3
0
2
0
4
1
6
1
4
2
5
7
1
5
*/