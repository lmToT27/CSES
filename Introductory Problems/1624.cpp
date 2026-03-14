#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    vector <string> a(8);
    for (int i = 0; i < 8; i++) cin >> a[i];
    
    int ans = 0;
    vector <bool> row(8, 0), col(8, 0), diag(16, 0), rdiag(16, 0);

    auto Recursive = [&](auto &&self, int i) -> void {
        if (i == 8) {
            ans++;
            return;
        }
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == '.' && !row[i] && !col[j] && !diag[i + j] && !rdiag[i - j + 7]) {
                row[i] = col[j] = diag[i + j] = rdiag[i - j + 7] = 1;
                self(self, i + 1);
                row[i] = col[j] = diag[i + j] = rdiag[i - j + 7] = 0;
            }
        }
    };
    Recursive(Recursive, 0);
    cout << ans;
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