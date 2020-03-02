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
const int maxn = 400 + 7;

int n;

string ans;

void gen(int k, int bal) {
    if (k == 0) {
        cout << ans << "\n";
        return;
    }
    if (bal + 1 <= k - 1) {
        ans.push_back('(');
        gen(k - 1, bal + 1);
        ans.pop_back();
    }
    if (bal > 0) {
        ans.push_back(')');
        gen(k - 1, bal - 1);
        ans.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    gen(2 * n, 0);


    return 0;
}
