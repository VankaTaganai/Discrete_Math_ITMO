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
    freopen("allvectors.in", "r", stdin);
    freopen("allvectors.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int x = i;
        vector<int> out;
        while (x != 0 || out.size() < n) {
            out.push_back(x % 2);
            x /= 2;
        }

        reverse(out.begin(), out.end());
        for (int j : out) {
            cout << j;
        }
        cout << "\n";
    }


    return 0;
}
