#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

ll pw10[20], f[20];

int DigitSum(ll k) {
    int res = 0;
    while (k) {
        k /= 10;
        res++;
    }
    return res;
}

ll Calc(ll k) {
    int p = DigitSum(k);
    return (k - pw10[p - 1] + 1) * p + f[p - 1];
}

void Solve() {
    ll n; cin >> n;
    ll res = 0, cur = 0;
    ll l = 1, r = 1e17;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (Calc(mid) >= n) {
            res = Calc(mid);
            cur = mid;
            r = mid - 1;
        } else l = mid + 1;
    } 
    while (res > n) {
        res--;
        cur /= 10;
    }
    cout << cur % 10 << '\n';
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

    pw10[0] = 1;
    for (int i = 1; i < 20; i++) {
        pw10[i] = pw10[i - 1] * 10;
        f[i] = f[i - 1] + pw10[i - 1] * 9 * i;
    }
    int TEST = 1; cin >> TEST; while (TEST--) Solve();

    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}