#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define vvi vector<vector<int>>
#define pii pair<int, int>

using namespace std;

vvi grid(11, vector<int>(11, -1));
vector<vector<bool>> vis(11, vector<bool>(11, false));

pii find_cor(int num) {
    int r = ((num - 1) / 10) + 1;
    int c = ((num - 1) % 10) + 1
    return {r, c};
}

int SnakeAndLadder() {
    queue<int> q;
    q.push(1);
    vis[1][1] = true;
    int steps = 0;

    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            int x = q.front();
            q.pop();
            if (x == 100)
                return steps;
            rep(i, 1, 7) {
                if (x + i > 100)
                    break;
                pii p = find_cor(x + i);
                int r = p.first;
                int c = p.second;

                if (vis[r][c])
                    continue;

                vis[r][c] = true;
                if (grid[r][c] == -1) {
                    q.push(i + x);
                }
                else {
                    q.push(grid[r][c]);
                }
            }
        }

        steps++;
    }
    return -1;
}

int main() {
    int n_l, n_s;
    cin >> n_l;
    rep(i, 0, n_l) {
        int s, d;
        cin >> s >> d;
        pii p = find_cor(s);
        grid[p.first][p.second] = d;
    }
    cin >> n_s;
    rep(i, 0, n_s) {
        int s, d;
        cin >> s >> d;
        pii p = find_cor(s);
        grid[p.first][p.second] = d;
    }
    int moves = SnakeAndLadder();
    cout << moves << endl;

    return 0;
}