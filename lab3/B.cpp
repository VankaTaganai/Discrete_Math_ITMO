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
    freopen("gray.in", "r", stdin);
    freopen("gray.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> v = {"0", "1"};
    for (int i = 0; i < n - 1; i++) {
        vector<string> res;
        for (int j = 0; j < v.size(); j++) {
            res.push_back("0" + v[j]);
        }
        for (int j = v.size() - 1; j >= 0; j--) {
            res.push_back("1" + v[j]);
        }
        v = res;
    }

    for (string i : v) {
        cout << i << "\n";
    }

    return 0;
}
