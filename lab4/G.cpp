#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 7;

int g1[MAXN][26];
int g2[MAXN][26];
bool term1[MAXN];
bool term2[MAXN];
bool used[MAXN][MAXN];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term1[x] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g1[a][c - 'a'] = b;
    }

    int nn, mm, kk;
    cin >> nn >> mm >> kk;

    for (int i = 0; i < kk; i++) {
        int x;
        cin >> x;
        term2[x] = true;
    }

    for (int i = 0; i < mm; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g2[a][c - 'a'] = b;
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    used[1][1] = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (term1[v.ff] != term2[v.ss]) {
            cout << "NO";
            return 0;
        }
        used[v.ff][v.ss] = true;
        for (int i = 0; i < 26; i++) {
            int to1 = g1[v.ff][i];
            int to2 = g2[v.ss][i];
            if (!used[to1][to2]) {
                q.push({to1, to2});
            }
        }
    }

    cout << "YES";
    return 0;
}