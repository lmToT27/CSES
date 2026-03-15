#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()
 
using namespace std;
 
typedef long long ll;
 
const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};
 
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int id[49], res;
bool vs[9][9];
 
void Try(int i, int x, int y) {
    if (i == 48) {
        ++res;
        return;
    }
    if (x == 7 && y == 1) return;
    if (i) {
        int straight = id[i - 1];
        int turn1 = (id[i - 1] + 1) % 4;
        int turn2 = (id[i - 1] + 3) % 4;
        if (vs[x + dx[straight]][y + dy[straight]] && !vs[x + dx[turn1]][y + dy[turn1]] && !vs[x + dx[turn2]][y + dy[turn2]]) return;
    }
    if (id[i] != -1) {
        int nxt_x = x + dx[id[i]];
        int nxt_y = y + dy[id[i]];
        if (vs[nxt_x][nxt_y]) return;
        vs[nxt_x][nxt_y] = 1;
        Try(i + 1, nxt_x, nxt_y);
        vs[nxt_x][nxt_y] = 0;
    } else {
        int nxt_x, nxt_y;
        for (int k = 0; k < 4; k++) {
            nxt_x = x + dx[k];
            nxt_y = y + dy[k];
            if (!vs[nxt_x][nxt_y]) {
                id[i] = k;
                vs[nxt_x][nxt_y] = 1;
                Try(i + 1, nxt_x, nxt_y);
                id[i] = -1;
                vs[nxt_x][nxt_y] = 0;
            }
        }
    }
}
 
void Solve() {
    string st;
    cin >> st; 
    for (int i = 0; i < 48; i++) {
        id[i] = -1;
        if (st[i] == 'L') id[i] = 0;
        if (st[i] == 'U') id[i] = 1;
        if (st[i] == 'R') id[i] = 2;
        if (st[i] == 'D') id[i] = 3;
    }
    for (int i = 0; i < 9; i++) {
        vs[0][i] = vs[8][i] = vs[i][0] = vs[i][8] = 1;
    }
    vs[1][1] = 1;
    Try(0, 1, 1);
    cout << res;
}
 
int32_t main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
 
    #define TASK ""
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }
 
    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }
 
    /* int TEST = 1; cin >> TEST; while (TEST--) */ Solve();
 
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}