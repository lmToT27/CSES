#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (int &x : a) cin >> x;
    ll tot = accumulate(all(a), 0LL);
    ll ans = tot;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) if (mask >> i & 1) sum += a[i];
        ans = min(ans, abs(tot - 2 * sum));
    }
    return void(cout << ans << '\n');
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