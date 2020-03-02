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
    freopen("nextpartition.in", "r", stdin);
    freopen("nextpartition.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = 0;
    int ind = 0;
    while (s[ind] != '=') {
        n = (n * 10) + s[ind] - '0';
        ind++;
    }
    ind++;
    int x = 0;
    vector<int> a;
    while (ind < s.size()) {
        if (s[ind] == '+') {
            a.push_back(x);
            x = 0;
        } else {
            x = x * 10 + s[ind] - '0';
        }
        ind++;
    }
    a.push_back(x);

    if (a.size() == 1) {
        cout << "No solution";
        return 0;
    }

    a[a.size() - 2]++;
    a.back()--;
    if (a[a.size() - 2] > a.back()) {
        int x = a.back();
        a.pop_back();
        a.back() += x;
    } else {
        while (a.back() >= a[a.size() - 2] * 2) {
            int s = a.back();
            a.pop_back();
            int x = a.back();
            a.push_back(x);
            if (s - x != 0) {
                a.push_back(s - x);
            }
        }
    }


    cout << n << "=";

    for (int i = 0; i < a.size(); i++) {
        if (i != 0) {
            cout << "+";
        }
        cout << a[i];
    }


    return 0;
}
