#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    freopen("huffman.in", "r", stdin);
    freopen("huffman.out", "w", stdout);
#endif


    int n;
    cin >> n;
    multiset<ll> p;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        p.insert(x);
    }

    ll ans = 0;

    while (p.size() > 1) {
        ll a = *p.begin();
        p.erase(p.begin());
        ll b = *p.begin();
        p.erase(p.begin());

        ll tmp = a + b;
        ans += tmp;
        p.insert(tmp);
    }

    cout << ans;
}