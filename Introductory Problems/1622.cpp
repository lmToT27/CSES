#include <bits/stdc++.h>
#define all(dataStructure) dataStructure.begin(),dataStructure.end()

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 3;
const int MOD[] = {1000000007, 998244353};

void Solve() {
    string st;
    cin >> st;
    int n = st.size();
    vector <int> cnt(26, 0);
    for (char &c : st) cnt[c - 'a']++;
    vector <string> ans;
    string tmp = "";    
    auto Gen = [&](auto &&self, int id) -> void {
        if (id == n) {
            ans.push_back(tmp);
            return;
        } else {
            for (int i = 0; i < 26; i++) {
                if (cnt[i]) {
                    cnt[i]--;
                    tmp.push_back(i + 'a');
                    self(self, id + 1);
                    tmp.pop_back();
                    cnt[i]++;
                }
            }
        }
    };
    Gen(Gen, 0);
    sort(all(ans));
    cout << ans.size() << '\n';
    for (string &s : ans) cout << s << '\n';
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