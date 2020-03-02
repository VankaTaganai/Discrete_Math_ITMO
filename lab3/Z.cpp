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
    freopen("nextsetpartition.in", "r", stdin);
    freopen("nextsetpartition.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    while (cin >> n) {
        cin >> k;
        if (n == 0 && k == 0) {
            break;
        }
        vector<vector<int>> a(k, vector<int>());
        for (int i = 0; i < k; i++) {
            string s;
            getline(cin, s);
            if (s.size() == 0) {
                i--;
                continue;
            }
            int x = 0;
            for (char j : s) {
                if (j >= '0' && j <= '9') {
                    x = x * 10 + j - '0';
                } else {
                    a[i].push_back(x);
                    x = 0;
                }
            }
            if (x != 0) {
                a[i].push_back(x);
            }
        }

        set<int> elem;
        for (int i = k - 1; i >= 0; i--) {
            auto it = elem.upper_bound(a[i].back());
            if (!elem.empty() && it != elem.end()) {
                a[i].push_back((*it));
                elem.erase(it);
                break;
            }
            bool flag = false;
            for (int j = a[i].size() - 1; j >= 0; j--) {
                if (j == 0) {
                    elem.insert(a[i][j]);
                    a.pop_back();
                    continue;
                }
                it = elem.upper_bound(a[i][j]);
                if (!elem.empty() && *it > a[i][j]) {
                    elem.insert(a[i][j]);
                    a[i][j] = *it;;
                    elem.erase(it);
                    flag = true;
                    break;
                }
                elem.insert(a[i][j]);
                a[i].pop_back();
            }
            if (flag) {
                break;
            }
        }
        for (auto it : elem) {
            a.push_back({it});
        }

        cout << n << " " << a.size() << "\n";

        sort(a.begin(), a.end());
        for (auto i : a) {
            for (int j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
