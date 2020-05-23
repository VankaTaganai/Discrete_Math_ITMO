#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 100 + 7;
const int P = 20;

vector<int> g[MAXN];
ll dp[MAXN][1007];
bool term[MAXN];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
#endif

    int n, m, k, l;
    cin >> n >> m >> k >> l;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g[b].push_back(a);
    }

    dp[1][0] = 1;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= n; j++) {
            for (int from : g[j]) {
                dp[j][i] = (dp[j][i] + dp[from][i - 1]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (term[i]) {
            ans = (ans + dp[i][l]) % MOD;
        }
    }

    cout << ans;

    return 0;
}
