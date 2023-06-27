#include<iostream>
#include<vector>
#include<bitset>
#include<array>

using namespace std;
const int N = 1001;

int n, k;
int a[N];
bool hask[N];
int cntempty[N];
vector<int> g[N];
bool ANS;
int sz[N];
bool used[N];

void dfs1(int v) {
    sz[v] = 1;
    if (a[v] == -1) {
        cntempty[v] = 1;
    }
    if (a[v] == k) {
        hask[v] = true;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        dfs1(u);
        cntempty[v] += cntempty[u];
        hask[v] |= hask[u];
        sz[v] += sz[u];
    }
}

void dfsmark(int v) {
    if (a[v] != -1) {
        used[a[v]] = true;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        dfsmark(u);
    }
}

void dfs2(int v) {
    if (sz[v] < k) {
        return;
    }
    if (hask[v] || cntempty[v] >= 2) {
        for(int i = 0; i < g[v].size(); ++i) {
            int u = g[v][i];
            dfs2(u);
        }
    } else {
        for(int i = 0; i < k; i++) {
            used[i] = false;
        }
        dfsmark(v);
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += !used[i];
        }
        if (cnt <= cntempty[v]) {
            ANS = true;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            hask[i] = false;
            cntempty[i] = 0;
        }
        for(int v = 1; v < n; v++) {
            int p;
            cin >> p;
            p--;
            g[p].push_back(v);
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        dfs1(0);
        ANS = false;
        dfs2(0);
        if (ANS) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    return 0;
}
