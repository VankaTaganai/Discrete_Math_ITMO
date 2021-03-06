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
const int maxn = 40 + 7;

ll dp[maxn][maxn];

int n;

ll k;

string ans;

string st;

void gen(int len, int bal) {
    if (len == 0) {
        cout << k;
        return;
    }

    ll num = (dp[len - 1][bal + 1] << (len - bal - 2) / 2);
    if (ans[2 * n - len] == '(') {
        ans.push_back('(');
        st.push_back('(');
        gen(len - 1, bal + 1);
        return;
    }
    k += num;
    num = 0;
    if (st.size() > 0 && st.back() == '(' && bal > 0) {
        num = (dp[len - 1][bal - 1] << (len - bal) / 2);
    }
    if (ans[2 * n - len] == ')') {
        ans.push_back(')');
        st.pop_back();
        gen(len - 1, bal - 1);
        return;
    }
    k += num;
    num = (dp[len - 1][bal + 1] << (len - bal - 2) / 2);
    if (ans[2 * n - len] == '[') {
        ans.push_back('[');
        st.push_back('[');
        gen(len - 1, bal + 1);
        return;
    }
    k += num;
    ans.push_back(']');
    st.pop_back();
    gen(len - 1, bal - 1);
    return;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("brackets2num2.in", "r", stdin);
    freopen("brackets2num2.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ans;

    n = ans.size() / 2;

    dp[0][0] = 1;

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    gen(2 * n, 0);

    return 0;
}
