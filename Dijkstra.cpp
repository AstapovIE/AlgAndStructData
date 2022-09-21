#include <iostream>
#include <vector>
#include <queue>
#include <limits>


enum class Color {
    White = 0,
    Gray = 1,
    Black = 2,
};

std::queue<int> q;
std::vector<Color> visited;
std::vector<int>fordextra;


int mini(std::vector<int> mas) {
    int res = mas.size()-1;
    int mini = INT_MAX;
    for (int i = 0; i < mas.size(); ++i) {
        if (mas[i] < mini) {
            res = i;
            mini = mas[i];
        }
    }
    return res;
}

void dextra(int v, const std::vector<std::vector<std::pair<int, int>>>& g, std::vector<int>& mass, int x)
{
    int size = g[v].size();
    for (int i = 0; i < size; ++i) {
        int u = g[v][i].first;
        if (visited[u] != Color::Black) {
            int k = g[v][i].second;
            mass[u] = std::min(mass[u], mass[v] + k);
        }

    }
    visited[v] = Color::Black;
    std::cout << "Visited Vertex: " << v << " Cost: " << mass[v] << std::endl;
    mass[v] = INT_MAX;
    if (x != v) {
        dextra(mini(mass), g, mass, x);
    }
}

int main()
{
    int n; //how much vertex
    std::cin >> n;

    int start;
    std::cin >> start;

    int aim;
    std::cin >> aim;

    std::vector<int>fordextra(n);
    for (int i = 0; i < n; ++i) {
        fordextra[i] = INT_MAX;
    }
    fordextra[start] = 0;

    std::vector<std::vector<std::pair<int, int>>> graphfordextra(n);
    std::pair<int, int> temp;
    int size; //how much ways from this vertex
    int a; // number possible verter
    int b; // price
    for (int i = 0; i < n; ++i) {
        std::cin >> size;
        for (int j = 0; j < size; ++j) {
            std::cin >> a;
            std::cin >> b;
            temp.first = a;
            temp.second = b;
            graphfordextra[i].push_back(temp);
        }
        visited.push_back(Color::White);
    }

    dextra(start, graphfordextra, fordextra, aim);


}/*
9
0
8
3
1
4
6
1
3
23
2
2
10
4
8
2
3
5
4
3
1
8
2
1
8
11
1
5
7
2
5
2
7
16
1
8
4
0
*/
