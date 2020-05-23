#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 100 + 7;
const int LEN = 1e6 + 7;
const int P = 20;

vector<int> g[MAXN][26];
int last = 1;
ll dp[LEN][2];
bool term[MAXN];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
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
        g[a][c - 'a'].push_back(b);
    }

    map<int, bool> nterm;
    map<set<int>, int> was;
    queue<set<int>> q;
    set<int> cur = {1};
    vector<vector<int>> ng = {{}, {}};
    q.push(cur);
    was[cur] = last++;
    
    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        int num = was[v];

        for (int u : v) {
            if (term[u]) {
                nterm[num] = true;
                break;
            }
        }

        for (int i = 0; i < 26; i++) {
            cur.clear();
            for (int u : v) {
                for (int to : g[u][i]) {
                    cur.insert(to);
                }
            }
            if (cur.empty()) {
                continue;
            }
            if (was[cur] == 0) {
                q.push(cur);
                was[cur] = last++;
                ng.emplace_back();
                out.emplace_back();
            }
            ng[num].push_back(was[cur]);
        }
    }

    dp[1][0] = 1;

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j < last; j++) {
            for (int to : ng[j]) {
                dp[to][1] = (dp[to][1] + dp[j][0]) % MOD;
            }
        }
        for (int j = 1; j < last; j++) {
            dp[j][0] = dp[j][1];
            dp[j][1] = 0;
        }
    }

    ll ans = 0;
    for (int i = 1; i < last; i++) {
        if (nterm[i]) {
            ans = (ans + dp[i][0]) % MOD;
        }
    }

    cout << ans;

    return 0;
}