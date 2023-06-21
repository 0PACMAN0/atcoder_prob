#include <bits/stdc++.h>
using namespace std;

struct BIT {
    long long UNITY_SUM = 0;
    vector<long long> dat;

    void init(int n, long long unity = 0) {
        UNITY_SUM = unity;
        dat.assign(n, unity);
    }

    void add(int a, long long x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1)
            dat[i] = dat[i] + x;
    }

    long long sum(int a) {
        long long res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i=(i&(i+1))-1)
            res = res + dat[i];
        return res;
    }

    long long sum(int a, int b) {
        return sum(b) - sum(a);
    }

    void print() {
        for (int i = 0; i < (int)dat.size(); ++i)
            cout << sum(i, i + 1) ;
        cout << endl;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    BIT bit;
    bit.init(N);

    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        bit.add(i, a);
    }

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            long long p, x;
            cin >> p >> x;
            bit.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }
}
