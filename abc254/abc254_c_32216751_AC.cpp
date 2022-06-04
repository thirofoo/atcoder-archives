/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32216751
 * Submitted at: 2022-06-04 21:18:58
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_c
 * Result: AC
 * Execution Time: 65 ms
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
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    b = a;
    priority_queue<int,vector<int>,greater<int>> q;
    rep(i,k){
        for(int j=i;j<n;j+=k)q.push(a[j]);
        for(int j=i;j<n;j+=k){
            a[j] = q.top();
            q.pop();
        }
    }
    sort(b.begin(),b.end());
    if(a == b)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}