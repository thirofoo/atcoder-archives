/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31685075
 * Submitted at: 2022-05-14 22:15:32
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_d
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int w; cin >> w;
    vector<int> ans,answer;

    ll tmp = 1;
    while(tmp <= w){
        ans.push_back(tmp);
        tmp <<= 1;
        tmp += 1;
    }
    
    int size = ans.size();
    rep(i,size){
        tmp = ans[i];
        while(tmp <= w){
            answer.push_back(tmp);
            tmp <<= 1;
        }
    }

    cout << answer.size() << endl;
    for(auto k:answer)cout << k << " ";
    cout << endl;
    
    return 0;
}