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

vector<int> ans;

void gen(int last) {
    for (int i = last + 1; i <= n; i++) {
        ans.push_back(i);
        for (int j : ans) {
            cout << j << " ";
        }
        cout << "\n";
        gen(i);
        ans.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("subsets.in", "r", stdin);
    freopen("subsets.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << "\n";
    gen(0);

    return 0;
}
