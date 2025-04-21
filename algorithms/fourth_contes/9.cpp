#include <iostream>
#include <vector>
#include <queue>


#define INF 1000000

int main() {
    int rows, columns; std::cin >> rows >> columns;
    std::vector<std::vector<int>> v(rows);
    for (int i = 0; i != v.size(); ++i) v[i].resize(columns, -1);
    int startx, starty, finishx, finishy;
    std::vector<std::vector<bool>> visited(rows);
    std::vector<std::vector<char>> origin(rows);
    for (int i = 0; i != visited.size(); ++i) {
        visited[i].resize(columns, false);
        origin[i].resize(columns);
    }
    
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != columns; ++j) {
            char c; std::cin >> c;
            origin[i][j] = c;
            if (c == 'S') {
                startx = i; starty = j;
                visited[i][j] = true;
                v[i][j] = 0;
            }
            else if (c == '#') {
                visited[i][j] = true;
            }
            else if (c == 'F') {
                finishx = i; finishy = j;
                visited[i][j] = false;
            }
            else visited[i][j] = false;
        }
    }

    std::cout << "Initial labyrinth:\n";
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != columns; ++j) {
            std::cout << origin[i][j];
        }
        std::cout << '\n';
    }

    std::cout << "Graph:\n";
    for (int i = 0; i != rows * columns; ++i) {
        std::cout << i << " - ";
        int cnt = 0;
        if (origin[i/columns][i%columns] == '#') {
            std::cout << "None\n";
            continue;
        }    
        for (int dx = -1; dx != 2; ++dx) {
            for (int dy = -1; dy != 2; ++dy) {
                if (!(dx + i/columns >= 0 && dx + i/columns < rows && dy + (i%columns) >= 0 && dy + (i % columns) < columns) 
                || !(abs(dx) + abs(dy) == 1) || origin[dx + i/columns][dy + (i%columns)] == '#') continue;
                std::cout << i + dx*columns + dy << ' ';
                ++cnt;
            }
        }
        if (cnt == 0) std::cout << "None";
        std::cout << '\n';
    }
    std::cout << "BFS result is:\n";
    q.push({startx, starty});
    // std::cout << "1";
    while (!q.empty()) {
        auto pr = q.front(); q.pop();
        int cur_x = pr.first, cur_y = pr.second;
        if (cur_x == finishx && cur_y== finishy) {
            break;
            
        }

        for (int dx = -1; dx != 2; ++dx) {
            for (int dy = -1; dy != 2; ++dy) {
                if (dy == 0 && dx == 0) continue;
                if (!(dx + cur_x >= 0 && dx + cur_x < rows && dy + cur_y >= 0 && dy + cur_y < columns) 
                || !(abs(dx) + abs(dy) == 1)) continue;
                
                if (!visited[dx + cur_x][dy + cur_y]) {
                    visited[dx + cur_x][dy + cur_y] = true;
                    v[dx + cur_x][dy+cur_y] = v[cur_x][cur_y] + 1;
                    q.push({dx+cur_x, dy+cur_y});
                }
            }
        }
    }
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != columns; ++j) {
            if (j != 0) std::cout << ' ';
            std::cout << v[i][j];
        }
        std::cout << '\n';
    }
}