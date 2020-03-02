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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("nextmultiperm.in", "r", stdin);
    freopen("nextmultiperm.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> ans = v;
    bool flag = true;

    for (int i = n - 2; i >= 0; i--) {
        if (ans[i] < ans[i + 1]) {
            int mn = i + 1;
            for (int j = i + 1; j < n; j++) {
                if (ans[j] > ans[i] && ans[j] < ans[mn]) {
                    mn = j;
                }
            }
            swap(ans[i], ans[mn]);
            sort(ans.begin() + i + 1, ans.end());
            flag = false;
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
    } else {
        for (int i : ans) {
            cout << i << " ";
        }
    }

    return 0;
}
