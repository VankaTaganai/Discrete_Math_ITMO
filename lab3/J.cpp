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

void gen(int k, int last) {
    if (k == 0) {
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) {
                cout << '+';
            }
            cout << to_string(ans[i]);
        }
        cout << "\n";
        return;
    }

    for (int i = last; i <= k; i++) {
        ans.push_back(i);
        gen(k - i, i);
        ans.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    gen(n, 1);


    return 0;
}
