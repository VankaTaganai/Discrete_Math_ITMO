#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;

string shift(string a) {
    char ch = a.back();
    a.pop_back();
    return ch + a;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    freopen("bwt.in", "r", stdin);
    freopen("bwt.out", "w", stdout);
#endif

    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s);
        s = shift(s);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < s.size(); i++) {
        cout << v[i].back();
    }

}