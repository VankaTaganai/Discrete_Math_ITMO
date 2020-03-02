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

vector<vector<int>> v;

vector<int> tmp;

int n;

void gen() {
    if (tmp.size() == n) {
        v.push_back(tmp);
        return;
    }
    for (int i = 0; i < 3; i++) {
        tmp.push_back(i);
        gen();
        tmp.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("antigray.in", "r", stdin);
    freopen("antigray.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    gen();
    int pw = pow(3, n - 1);
    for (int i = 0; i < pw; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < v[i].size(); k++) {
                cout << v[i][k];
                v[i][k] = (v[i][k] + 1) % 3;
            }
            cout << "\n";
        }
    }

    return 0;
}
