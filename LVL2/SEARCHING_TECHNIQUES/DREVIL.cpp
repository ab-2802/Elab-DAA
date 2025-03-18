#include <iostream>
#include <vector>

using namespace std;

char MOJO[]="MOJO";
bool findHiddenWord(const vector<string> &grid, int x, int y, int dx, int dy, vector<pair<int, int>> &pos) {
    int r = grid.size(), c = grid[0].size();
    pos.clear();
    for (int i = 0; i < 4; i++) {
        int nx = x + i * dx, ny = y + i * dy;
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] != MOJO[i])
            return false;
        pos.push_back({ny, nx});
    }
    return true;
}
int main() {
    vector<string> grid;
    string line;
    while (getline(cin, line) && !line.empty()) {
        grid.push_back(line);
    }
    int r = grid.size(), c = grid[0].size();
    int moves[2][2] = {{0, 1}, {1, 0}};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == MOJO[0]) {
                for (auto &m : moves) {
                    vector<pair<int, int>> pos;
                    if (findHiddenWord(grid, i, j, m[0], m[1], pos)) {
                        for (auto &p : pos) {
                            cout << MOJO[&p - &pos[0]] << ": " << p.first << "," << p.second << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Not Found" << endl;
    return 0;
}