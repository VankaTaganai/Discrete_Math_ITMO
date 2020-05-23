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

bool term[MAXN];
int g[MAXN][28];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
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
        g[a][c - 'a'] = b;
    }

    int start = 1;
    for (char i : s) {
        if (g[start][i - 'a'] == 0) {
            cout << "Rejects\n";
            return 0;
        }
        start = g[start][i - 'a'];
    }
    if (term[start]) {
        cout << "Accepts\n";
    } else {
        cout << "Rejects\n";
    }

    return 0;
}
