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

int n, k;

vector<vector<vector<int>>> sub(11, vector<vector<int>>());

bool used[11];

vector<int> ans;

void gen(int last) {
    for (int i = last + 1; i <= n; i++) {
        ans.push_back(i);
        sub[(int)ans.size()].push_back(ans);
        gen(i);
        ans.pop_back();
    }
}

vector<vector<int>> kek;

vector<vector<int>> output;

void out(int prev_ind, int id) {
    if (id == ans.size()) {
        for (const auto& i : output) {
            for (int j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    if (id != 0 && ans[id - 1] == ans[id]) {
        for (int i = prev_ind + 1; i < sub[ans[id]].size(); i++) {
            bool flag = true;
            for (int j : sub[ans[id]][i]) {
                if (used[j]) {
                    flag = false;
                }
            }
            if (flag) {
                for (int j : sub[ans[id]][i]) {
                    used[j] = true;
                }
                output.push_back(sub[ans[id]][i]);
                out(i, id + 1);
                output.pop_back();
                for (int j : sub[ans[id]][i]) {
                    used[j] = false;
                }
            }
        }
    } else {
        for (int i = 0; i < sub[ans[id]].size(); i++) {
            bool flag = true;
            for (int j : sub[ans[id]][i]) {
                if (used[j]) {
                    flag = false;
                }
            }
            if (flag) {
                for (int j : sub[ans[id]][i]) {
                    used[j] = true;
                }
                output.push_back(sub[ans[id]][i]);
                out(i, id + 1);
                output.pop_back();
                for (int j : sub[ans[id]][i]) {
                    used[j] = false;
                }
            }
        }
    }
}

void gen_sum(int sum, int last) {
    if (sum == 0 && ans.size() == k) {
        int prev = 0, num = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (prev == ans[i]) {
                num++;
            } else {
                if (sub[prev].size() < num) {
                    return;
                }
                prev = ans[i];
                num = 1;
            }
        }
        if (sub[prev].size() < num) {
            return;
        }
        kek.push_back(ans);
        return;
    }
    if (sum == 0 || ans.size() == k) {
        return;
    }

    for (int i = last; i <= sum; i++) {
        ans.push_back(i);
        gen_sum(sum - i, i);
        ans.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("part2sets.in", "r", stdin);
    freopen("part2sets.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    gen(0);

    gen_sum(n, 1);

    for (int i = 0; i < kek.size(); i++) {
        ans = kek[i];
        out(0, 0);
    }

    return 0;
}
