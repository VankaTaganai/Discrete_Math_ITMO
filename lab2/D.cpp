#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    freopen("lzw.in", "r", stdin);
    freopen("lzw.out", "w", stdout);
#endif

    map<string, int> mp;

    string a, t;
    cin >> a;
    for (int i = 0; i < 26; i++) {
        string tmp;
        tmp.push_back('a' + i);
        mp[tmp] = i;
    }

    int nxt = 26;
    a.push_back('$');
    t.push_back(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == '$') {
            cout << mp[t] << "\n";
        }
        else if (mp.find(t + a[i]) != mp.end()) {
            t.push_back(a[i]);
        } else {
            cout << mp[t] << " ";
            mp[t + a[i]] = nxt++;
            t = a[i];
        }
    }

}