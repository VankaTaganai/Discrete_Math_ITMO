#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;
typedef unsigned int uint;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;
const int ALPH = 26;

int n, m, k;
int all = 3;
bool term[MAXN];
int g[MAXN][ALPH];
int cls[MAXN];
vector<int> rg[MAXN][ALPH];
map<int, set<int>> mp;
bool was[MAXN];
bool to_term[MAXN];

void make_split() {
    set<int> t;
    set<int> nt;
    for (int i = 0; i <= n; i++) {
        if (term[i]) {
            cls[i] = 2;
            t.insert(i);
        } else {
            cls[i] = 1;
            nt.insert(i);
        }
    }

    mp[1] = nt;
    mp[2] = t;

    queue<pair<int, int>> q;

    for (int i = 0; i < ALPH; i++) {
        q.emplace(1, i);
        q.emplace(2, i);
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        map<int, set<int>> involved;
        set<int> el = mp[v.ff];
        for (int from : el) {
            for (int to : rg[from][v.ss]) {
                int col = cls[to];
                if (involved.count(col) == 0) {
                    involved[col] = {};
                }
                involved[col].insert(to);
            }
        }
        for (const auto& p : involved) {
            if (p.ss.size() < mp[p.ff].size()) {
                for (int vert : p.ss) {
                    mp[p.ff].erase(vert);
                    mp[all].insert(vert);
                }
                if (mp[all].size() > mp[p.ff].size()) {
                    swap(mp[all], mp[p.ff]);
                }
                for (int r : mp[all]) {
                    cls[r] = all;
                }
                for (int c = 0; c < ALPH; c++) {
                    q.emplace(all, c);
                }
                all++;
            }
        }
    }
}

void dfs(int v) {
    was[v] = true;
    for (int i = 0; i < ALPH; i++) {
        int to = g[v][i];
        if (to != 0 && !was[to]) {
            dfs(to);
        }
    }
}

void get(int v) {
    to_term[v] = true;
    for (int i = 0; i < ALPH; i++) {
        for (int to : rg[v][i]) {
            if (!to_term[to]) {
                get(to);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("fastminimization.in", "r", stdin);
    freopen("fastminimization.out", "w", stdout);
#endif

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
        rg[b][c - 'a'].push_back(a);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < ALPH; j++) {
            rg[g[i][j]][j].push_back(i);
        }
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (term[i] && !to_term[i]) {
            get(i);
        }
    }

    make_split();

    int s1 = cls[1];
    int s2 = 1;

    for (int i = 1; i <= n; i++) {
        if (cls[i] == s1) {
            cls[i] = s2;
        } else if (cls[i] == s2) {
            cls[i] = s1;
        }
    }

    map<int, set<pair<int, char>>> ng;
    set<int> nterm;
    set<int> total;
    for (int i = 1; i <= n; i++) {
        if (cls[i] == 0 || !was[i] || !to_term[i]) {
            continue;
        }
        total.insert(cls[i]);
        for (int c = 0; c < ALPH; c++) {
            int to = g[i][c];
            if (to != 0 && cls[to] != 0 && was[to] && to_term[to]) {
                ng[cls[i]].insert({cls[to], char(c + 'a')});
            }
        }
        if (term[i]) {
            nterm.insert(cls[i]);
        }
    }

    map<int, int> to_index;
    int ind = 1;
    for (int i : total) {
        to_index[i] = ind++;
    }

    int nm = 0;
    for (int i : total) {
        nm += ng[i].size();
    }

    cout << total.size() << ' ' << nm << ' ' << nterm.size() << '\n';
    for (int i : nterm) {
        cout << to_index[i] << ' ';
    }
    cout << '\n';

    for (int i : total) {
        for (auto v : ng[i]) {
            cout << to_index[i] << ' ' << to_index[v.ff] << ' ' << v.ss << '\n';
        }
    }

    return 0;
}