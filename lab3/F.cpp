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

vector<string> ans;

string tmp;

void gen(int n) {
    if (n == 0) {
        ans.push_back(tmp);
        return;
    }

    tmp.push_back('0');
    gen(n - 1);
    tmp.pop_back();
    if (tmp.size() == 0 || tmp.back() == '0') {
        tmp.push_back('1');
        gen(n - 1);
        tmp.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("vectors.in", "r", stdin);
    freopen("vectors.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    gen(n);

    cout << ans.size() << "\n";

    for (string i : ans) {
        cout << i << "\n";
    }

    return 0;
}
