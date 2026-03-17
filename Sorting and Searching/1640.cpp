#include <bits/stdc++.h>
#define all(st) st.begin(), st.end()

using namespace std;

typedef long long ll;

void Solve() {
    int n; int x;
    cin >> n >> x;
    set <pair <int, int>> f;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        auto p = f.lower_bound(make_pair(x - a, -1));
        if (p != f.end() && p -> first == x - a) {
            return void(cout << p -> second + 1 << ' ' << i + 1 << '\n');
        }
        f.insert({a, i});
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("TASK.INP", "r")) {
        freopen("TASK.INP", "r", stdin);
        freopen("TASK.OUT", "w", stdout);
    }

    Solve();

    return 0;
}
