#include <bits/stdc++.h>
#define all(st) st.begin(), st.end()

using namespace std;

typedef long long ll;

void Solve() {
    int n; cin >> n;
    vector <int> l(n), r(n), unq;
    vector <int> f(2 * n + 3);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        unq.push_back(l[i]);
        unq.push_back(r[i]);
    }

    sort(all(unq));
    unq.erase(unique(all(unq)), unq.end());

    for (int i = 0; i < n; i++) {
        l[i] = lower_bound(all(unq), l[i]) - unq.begin();
        r[i] = lower_bound(all(unq), r[i]) - unq.begin();
        f[l[i]]++;
        f[r[i] + 1]--;
    }

    for (int i = 1; i < 2 * n + 3; i++) {
        f[i] += f[i - 1];
    }

    cout << *max_element(all(f));
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
