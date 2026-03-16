#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    multiset <int> s;
    for (int &x : a) cin >> x;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    sort(all(a));
    for (int &x : a) {
        auto p = s.lower_bound(x - k);
        if (p != s.end() && abs(*p - x) <= k) {
            s.erase(p);
            continue;
        }
        p = s.upper_bound(x - k);
        if (p != s.begin()) {
            p = prev(p);
            if (abs(*p - x) <= k) {
                s.erase(p);
                continue;
            }
        } 
    }
    cout << m - (int)s.size();
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