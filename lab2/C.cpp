#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;

int ind[30];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);
#endif

    string a;
    cin >> a;
    for (int i = 0; i < 26; i++) {
        ind[i] = i + 1;
    }

    for (int i = 0; i < a.size(); i++) {
        int x = ind[a[i] - 'a'];
        cout << x << " ";
        for (int j = 0; j < 26; j++) {
            if (ind[j] < x) {
                ind[j]++;
            }
        }
        ind[a[i] - 'a'] = 1;
    }

}