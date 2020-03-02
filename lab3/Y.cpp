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
    freopen("nextchoose.in", "r", stdin);
    freopen("nextchoose.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    a.push_back(n + 1);
    int ind = -1;
    for (int i = k - 1; i >= 0; i--) {
        if (a[i + 1] - a[i] > 1) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        cout << ind;
        return 0;
    }

    a[ind]++;

    for (int i = ind + 1; i < k; i++) {
        a[i] = a[i - 1] + 1;
    }

    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
