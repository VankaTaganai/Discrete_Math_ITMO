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
    freopen("nextbrackets.in", "r", stdin);
    freopen("nextbrackets.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for (auto i : s) {
        if (i == '(') {
            a++;
        } else {
            b++;
        }
    }

    int ind = s.size() - 1;
    while (ind >= 0) {
        if (s[ind] == '(') {
            a--;
            if (a > b) {
                break;
            }
        } else {
            b--;
        }
        ind--;
    }

    if (ind == -1) {
        cout << "-";
        return 0;
    }

    while (s.size() > ind) {
        s.pop_back();
    }
    s.push_back(')');
    a--;
    int t = ((n - ind - 1) - (a - b)) / 2;
    b = t + (a - b);
    a = t;

    cout << s;
    for (int i = 0; i < a; i++) {
        cout << '(';
    }
    for (int i = 0; i < b; i++) {
        cout << ')';
    }

    return 0;
}
