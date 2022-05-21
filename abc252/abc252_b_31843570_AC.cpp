/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31843570
 * Submitted at: 2022-05-21 21:08:40
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_b
 * Result: AC
 * Execution Time: 7 ms
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
    
    int n,k; cin >> n >> k;
    vector<int> food(n),no(k),ok;
    rep(i,n)cin >> food[i];
    rep(i,k){
        int b; cin >> b;
        no[i] = b-1;
    }

    int m = -INT_MAX;
    rep(i,n)m = max(m,food[i]);
    rep(i,n)if(food[i] == m)ok.push_back(i);
    for(auto l:ok){
        if(count(no.begin(),no.end(),l)){
            return cout << "Yes" << endl,0;
        }
    }
    cout << "No" << endl;
    return 0;
}