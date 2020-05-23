#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;
const int P = 20;

vector<int> ing[MAXN];

bool pos[MAXN];
int used[MAXN];

int g[MAXN][28];

void dfs(int v) {
    pos[v] = true;
    for (int to : ing[v]) {
        if (!pos[to]) {
            dfs(to);
        }
    }
}

void circle(int v) {
    used[v] = 1;
    for (int i = 0; i < 26; i++) {
        int to = g[v][i];
        if (to == 0) {
            continue;
        }
        if (!used[to]) {
            circle(to);
        } else if (pos[to] && used[to] == 1) {
            cout << -1;
            exit(0);
        }
    }
    used[v] = 2;
}
bool term[MAXN];
ll dp[MAXN];
bool was[MAXN];

void get(int v) {
    was[v] = true;
    for (int to : ing[v]) {
        if (was[to]) {
            dp[v] = (dp[v] + dp[to]) % MOD;
            continue;
        }
        get(to);
        dp[v] = (dp[v] + dp[to]) % MOD;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term[x] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g[a][c - 'a'] = b;
        ing[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (term[i] && !used[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }

    circle(1);
    dp[1] = 1;

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (term[i]) {
            if (!was[i]) {
                get(i);
            }
            ans = (ans + dp[i]) % MOD;
        }
    }

    cout << ans;
    return 0;
}
