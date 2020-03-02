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

bool used[10];

vector<int> tmp;

void gen(int k) {
    if (k == 0) {
        for (int i : tmp) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            tmp.push_back(i);
            used[i] = true;
            gen(k - 1);
            used[i] = false;
            tmp.pop_back();
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("permutations.in", "r", stdin);
    freopen("permutations.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    gen(n);


    return 0;
}
