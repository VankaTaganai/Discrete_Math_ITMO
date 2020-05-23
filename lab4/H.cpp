#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 7;

int g[MAXN][26];
int term[MAXN];
vector<int> rev_g[MAXN][26];
bool was[MAXN];
bool to_term[MAXN];
bool neq[MAXN][MAXN];
int comp[MAXN];

void dfs(int v) {
    was[v] = true;
    for (int i = 0; i < 26; i++) {
        int to = g[v][i];
        if (to != 0 && !was[to]) {
            dfs(to);
        }
    }
}

bool used[MAXN];
void get(int v) {
    used[v] = true;
    for (int i = 0; i < 26; i++) {
        int to = g[v][i];
        if (to != 0 && !used[to]) {
            get(to);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("minimization.in", "r", stdin);
    freopen("minimization.out", "w", stdout);
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
    }

    for (int i = 0; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            rev_g[g[i][c]][c].push_back(i);
        }
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            used[j] = false;
        }
        get(i);
        to_term[i] = false;
        for (int j = 1; j <= n; j++) {
            if (used[j] && term[j]) {
                to_term[i] = true;
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (term[i] != term[j]) {
                neq[j][i] = neq[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            for (int a : rev_g[v.ff][i]) {
                for (int b : rev_g[v.ss][i]) {
                    if (!neq[a][b]) {
                        neq[a][b] = neq[b][a] = true;
                        q.push({a, b});
                    }
                }
            }
        }
    }

    int num = 1;
    for (int i = 1; i <= n; i++) {
        if (!neq[1][i]) {
            comp[i] = num;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!was[i] || !to_term[i]) {
            continue;
        }
        if (comp[i] == 0) {
            num++;
            comp[i] = num;
            for (int j = i + 1; j <= n; j++) {
                if (!neq[i][j]) {
                    comp[j] = num;
                }
            }
        }
    }

    vector<set<pair<int, char>>> ng(num + 1);
    set<int> nterm;
    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            continue;
        }
        for (int c = 0; c < 26; c++) {
            int to = g[i][c];
            if (to != 0 && comp[to] != 0) {
                ng[comp[i]].insert({comp[to], char(c + 'a')});
            }
        }
        if (term[i]) {
            nterm.insert(comp[i]);
        }
    }

    int nm = 0;
    for (int i = 1; i <= num; i++) {
        nm += ng[i].size();
    }

    cout << num << ' ' << nm << ' ' << nterm.size() << '\n';
    for (int i : nterm) {
        cout << i << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= num; i++) {
        for (auto v : ng[i]) {
            cout << i << ' ' << v.ff << ' ' << v.ss << '\n';
        }
    }

    return 0;
}