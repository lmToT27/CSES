#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    ll x, y;
    cin >> x >> y;
    if (x > y) {
        if (x & 1) cout << (x - 1) * (x - 1) + y << '\n';
        else cout << x * x - y + 1 << '\n';
    } else {
        if (y & 1) cout << y * y - x + 1 << '\n';
        else cout << (y - 1) * (y - 1) + x << '\n';
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

    int TEST = 1; cin >> TEST; while (TEST--) Solve();

    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}