#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    string st;
    cin >> st;
    int n = (int)st.size();
    vector <int> cnt(26, 0);
    for (char &c : st) cnt[c - 'A']++;
    int mx = *max_element(all(cnt));
    if (mx > (n + 1) / 2) return void(cout << -1);
    string res = "";
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 0 || c == prev) continue;
            bool ok = true;
            for (int nxt = 0; nxt < 26; nxt++) {
                if (nxt != c && cnt[nxt] > (n - i) / 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                best = c;
                break;
            }
        }
        res += char(best + 'A');
        cnt[best]--;
        prev = best;
    }
    cout << res;
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