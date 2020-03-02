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
    freopen("nextvector.in", "r", stdin);
    freopen("nextvector.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string a = s;
    bool flag = true;
    for (int i = a.size(); i >= 0; i--) {
        if (a[i] == '1') {
            a[i] = '0';
            flag = false;
            break;
        }
        a[i] = '1';
    }

    if (flag) {
        cout << "-";
    } else {
        cout << a;
    }
    cout << "\n";

    a = s;
    flag = true;
    for (int i = a.size(); i >= 0; i--) {
        if (a[i] == '0') {
            a[i] = '1';
            flag = false;
            break;
        }
        a[i] = '0';
    }

    if (flag) {
        cout << "-";
    } else {
        cout << a;
    }
    cout << "\n";

    return 0;
}
