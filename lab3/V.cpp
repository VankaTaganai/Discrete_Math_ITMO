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

int n = 0;

ll k;

vector<int> ans;

void gen(int sum, int last, int id) {
    if (sum == n) {
        cout << k;
        return;
    }
    for (int i = last; i <= n; i++) {
        ll num = dp[sum + i][i];
        if (ans[id] == i) {
            gen(sum + i, i, id + 1);
            return;
        } else {
            k += num;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("part2num.in", "r", stdin);
    freopen("part2num.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a;
    cin >> a;
    string tmp;
    for (char i : a) {
        if (i == '+') {
            ans.push_back(stoi(tmp));
            n += ans.back();
            tmp.clear();
        } else {
            tmp.push_back(i);
        }
    }
    ans.push_back(stoi(tmp));
    n += ans.back();

    cin >> n >> k;

    dp[n][n] = 1;

    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            dp[i][j] += dp[i][j + 1] + dp[i + j][j];
        }
    }
    gen(0, 1, 0);

    return 0;
}
