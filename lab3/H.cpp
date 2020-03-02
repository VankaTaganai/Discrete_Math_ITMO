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

int n, k;

vector<int> tmp;

void gen(int t, int last) {
    if (t == 0) {
        for (int i : tmp) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = last + 1; i <= n; i++) {
        if (n - i + 1 < t) {
            break;
        }
        tmp.push_back(i);
        gen(t - 1, i);
        tmp.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("choose.in", "r", stdin);
    freopen("choose.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    gen(k, 0);


    return 0;
}
