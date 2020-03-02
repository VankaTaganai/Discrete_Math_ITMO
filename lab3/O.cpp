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

ll C(int n, int k) {
    if (k <= n) {
        if (k == 0) {
            return 1;
        } else {
            return C(n - 1, k - 1) + C(n - 1, k);
        }
    } else {
        return 0;
    }
}

int n, k;
ll m;

bool used[maxn];

vector<int> ans;

int cnt;

void gen(int len, int prev) {
    if (len == 0) {
        for (int i : ans) {
            cout << i << " ";
        }
        return;
    }

    for (int i = prev + 1; i <= n; i++) {
        ll num = C(n - i, len - 1);
        if (m < num) {
            ans.push_back(i);
            cnt--;
            gen(len - 1, i);
            return;
        } else {
            m -= num;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("num2choose.in", "r", stdin);
    freopen("num2choose.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    cnt = n;
    gen(k, 0);

    return 0;
}
