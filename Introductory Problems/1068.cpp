#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()
 
using namespace std;
 
typedef long long ll;
 
const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};
 
void Solve() {
    ll n; cin >> n;
    while (true) {
        cout << n << ' ';
        if (n == 1) break;
        if (n & 1) n = 3 * n + 1;
        else n /= 2;
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