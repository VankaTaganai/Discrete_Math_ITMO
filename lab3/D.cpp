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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("chaincode.in", "r", stdin);
    freopen("chaincode.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    set<string> st;

    cin >> n;
    vector<string> ans;
    string last;

    for (int i = 0; i < n; i++) {
        last.push_back('0');
    }

    st.insert(last);

    ans.push_back(last);
    while (true) {
        string nxt = last.substr(1, last.size());
        if (st.count(nxt + "1") == 0) {
            nxt += "1";
        } else if (st.count(nxt + "0") == 0) {
            nxt += "0";
        } else {
            break;
        }
        st.insert(nxt);
        last = nxt;
        ans.push_back(last);
    }

    for (string i : ans) {
        cout << i << "\n";
    }

    return 0;
}
