#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void Solve() {
    int n; cin >> n;
    vector <vector <int>> vs(n, vector <int> (n, -1));
    vs[0][0] = 0;
    queue <pair <int, int>> q;
    q.push({0, 0});
    while (q.size()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int u = i + dx[k], v = j + dy[k];
            if (u < 0 || u >= n || v < 0 || v >= n) continue;
            if (vs[u][v] != -1) continue;
            vs[u][v] = vs[i][j] + 1;
            q.push({u, v});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vs[i][j] << ' ';
        }
        cout << '\n';
    }
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