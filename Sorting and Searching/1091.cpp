#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    int n, m;
    cin >> n >> m;
    multiset <int> tickets;
    vector <int> t(m);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        tickets.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto p = tickets.upper_bound(x);
        if (p != tickets.begin()) {
            p = prev(p);
            cout << *p << '\n';
            tickets.erase(p);
        } else cout << -1 << '\n';
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