/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/29901004
 * Submitted at: 2022-03-05 22:59:23
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_d
 * Result: WA
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<char> A = {'B','C'};
vector<char> B = {'C','A'};
vector<char> C = {'A','B'};

int main() {
    string s; int q; cin >> s >> q;
    rep(i,q){
        ll t,k; cin >> t >> k;
        k--;
        int num = (t >= 64 ? 0 : k/(ll)pow(2,t));
        k %= (ll)pow(2,t%64);

        char tmp = s[num];
        bool frag = true;
        for(int j=t-1;j>=0;j--){
            int p = (k & (1LL << j) ? 1 : 0);
            if(tmp == 'A')tmp = A[p];
            else if(tmp == 'B')tmp = B[p];
            else if(tmp == 'C')tmp = C[p];
        }
        cout << tmp << '\n';
    }
    return 0;
}