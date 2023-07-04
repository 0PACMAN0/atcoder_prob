#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int lo, hi;
    cin >> lo >> hi;
    vector<int> a(n - 2);
    for (int &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i + m <= a.size(); i++) {
        ans = min(ans, max(0, lo - a[i]) + max(0, a[i + m - 1] - hi));
    }
    cout << ans << "\n";
    return 0;
}