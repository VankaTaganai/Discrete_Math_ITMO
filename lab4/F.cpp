#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;

int g1[MAXN][26];
int g2[MAXN][26];
bool term1[MAXN];
bool term2[MAXN];
int b1[MAXN];
int b2[MAXN];
bool used1[MAXN];
bool used2[MAXN];

void dfs(int v, int u) {
    used1[v] = true;
    used2[u] = true;
    for (int i = 0; i < 26; i++) {
        int to1 = g1[v][i];
        int to2 = g2[u][i];
        if (to1 == 0 && to2 == 0) {
            continue;
        }
        if ((to1 == 0 && to2 != 0) || (to2 == 0 && to1 != 0) || (used1[to1] ^ used2[to2])) {
            cout << "NO";
            exit(0);
        }
        if (used1[to1]) {
            if ((b1[to1] != to2) || b2[to2] != to1) {
                cout << "NO";
                exit(0);
            }
        } else {
            b1[to1] = to2;
            b2[to2] = to1;
            dfs(to1, to2);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
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
    if (nn != n || mm != m || kk != k) {
        cout << "NO";
        return 0;
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        term2[x] = true;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        g2[a][c - 'a'] = b;
    }

    b1[1] = b2[1] = 1;
    dfs(1, 1);

    for (int i = 1; i <= n; i++) {
        if (term1[i] != term2[b1[i]]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}