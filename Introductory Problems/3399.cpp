#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if ((a > 0) + (b > 0) == 1) return void(cout << "NO\n");
    if (a + b > n) return void(cout << "NO\n");
    vector <int> f, g;
    while (n > a + b) {
        f.push_back(n);
        g.push_back(n);
        n--;
    }
    for (int i = 1; i <= b; i++) {
        f.push_back(i);
        g.push_back(n - b + i);
    }
    for (int i = b + 1; i <= a + b; i++) {
        f.push_back(i);
        g.push_back(i - b);
    }
    cout << "YES\n";
    for (int &x : f) cout << x << ' ';
    cout << '\n';
    for (int &x : g) cout << x << ' ';
    cout << '\n';
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