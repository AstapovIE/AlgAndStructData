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


void dfs(int v, int p, const std::vector<std::vector<int>>& g, int k, std::vector<int>& in, std::vector<int>& up)
{
    in[v] = k;
    up[v] = in[v];
    s.push(v);
    visited[v] = Color::Gray;
    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i];
        if (u == p) { continue;}       
        if (visited[u] == Color::White) {
            dfs(u, v, g, k+1, in, up);
            up[v] = std::min(up[v], up[u]);
        }
        if (visited[u] == Color::Gray) {
            up[v] = std::min(up[v], in[u]);
        }
    }

    if (up[v] == in[v]) {
        if (up[v] > 0) {
            std::cout << "Bridge: " << v << " - " << p << std::endl;
        }
        std::cout << "Component double related :";
        while (true){
            int x = s.top();
            std::cout << " " << x;
            s.pop();
            if (x == v) { break;}
        }
        std::cout << std::endl;
    }

    visited[v] = Color::Black;
    //std::cout << "Visited Vertex(out): " << v << std::endl;

    
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> in(n, 0);
    std::vector<int> up(n, 0);

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

    dfs(0, 0, graph, 0, in, up);

}
/*
10
2
1
5
3
2
5
0
3
3
1
4
2
2
4
2
3
2
3
1
0
6
3
5
7
9
3
6
8
9
2
7
9
3
7
8
6
*/