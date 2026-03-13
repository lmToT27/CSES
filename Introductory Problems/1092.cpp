#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    int n;
    cin >> n;
    ll sum = 1ll * n * (n + 1) / 2;
    if (sum & 1) return void(cout << "NO");
    vector <int> v1, v2;
    sum /= 2;
    for (int i = n; i >= 1; i--) {
        if (sum - i >= 0) {
            sum -= i;
            v1.push_back(i);
        } else v2.push_back(i);
    }
    if (sum == 0) {
        reverse(all(v1));
        reverse(all(v2));
        cout << "YES\n" << v1.size() << '\n';
        for (int x : v1) cout << x << ' ';
        cout << "\n" << v2.size() << '\n';
        for (int x : v2) cout << x << ' ';
    } else cout << "NO";
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