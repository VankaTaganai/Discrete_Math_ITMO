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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("telemetry.in", "r", stdin);
    freopen("telemetry.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(to_string(i));
    }

    for (int i = 0; i < n - 1; i++) {
        vector<string> tmp;
        for (int j = 0; j < k; j++) {
            if (j % 2 == 0) {
                for (int t = 0; t < ans.size(); t++) {
                    tmp.push_back(to_string(j) + ans[t]);
                }
            } else {
                for (int t = ans.size() - 1; t >= 0; t--) {
                    tmp.push_back(to_string(j) + ans[t]);
                }
            }
        }
        ans = tmp;
    }

    for (auto i : ans) {
        cout << i << "\n";
    }

    return 0;
}
