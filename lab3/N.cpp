#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#define ff first
#define ss second

const double eps = 1e-6;
const int inf = 1e9 + 7;
const ll mod = 999999937;
const int maxn = 20 + 7;

ll fac(int n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int n;
ll k = 0;

vector<int> ans;

bool used[maxn];

void gen(int len) {
    if (len == 0) {
        cout << k;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }
        ll num = fac(len - 1);
        if (i == ans[n - len]) {
            used[i] = true;
            gen(len - 1);
            return;
        } else {
            k += num;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("perm2num.in", "r", stdin);
    freopen("perm2num.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans.push_back(x);
    }
    gen(n);

    return 0;
}
