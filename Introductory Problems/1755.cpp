#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    string st; cin >> st;
    char mid = '-';
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (char &c : st) cnt[c - 'A']++;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            if (mid != '-') return void(cout << "NO SOLUTION");
            mid = char(i + 'A');
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) cout << char(i + 'A');
    }
    if (mid != '-') cout << mid;
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < cnt[i] / 2; j++) cout << char(i + 'A');
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