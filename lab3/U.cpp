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
const int maxn = 200 + 7;

ll dp[maxn][maxn];

int n;

ll k;

vector<int> ans;

void gen(int sum, int last) {
    if (sum == n) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i + 1 < ans.size()) {
                cout << "+";
            }
        }
        return;
    }
    for (int i = last; i <= n; i++) {
        ll num = dp[sum + i][i];
        if (k < num) {
            ans.push_back(i);
            gen(sum + i, i);
            return;
        } else {
            k -= num;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("num2part.in", "r", stdin);
    freopen("num2part.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    dp[n][n] = 1;

    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            dp[i][j] += dp[i][j + 1] + dp[i + j][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    gen(0, 1);

    return 0;
}
