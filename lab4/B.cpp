#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e2 + 7;
const int P = 20;

bool term[MAXN];
vector<int> g[MAXN][28];
bool dp[MAXN][MAXN * MAXN];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
#endif

    string s;
    cin >> s;
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
        g[a][c - 'a'].push_back(b);
    }

    dp[1][0] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v.ss == s.size()) {
            continue;
        }
        for (int to : g[v.ff][s[v.ss] - 'a']) {
            if (!dp[to][v.ss + 1]) {
                dp[to][v.ss + 1] = true;
                q.push({to, v.ss + 1});
            }
        }

    }

    for (int i = 1; i <= n; i++) {
        if (term[i] && dp[i][s.size()]) {
            cout << "Accepts";
            return 0;
        }
    }

    cout << "Rejects";

    return 0;
}
