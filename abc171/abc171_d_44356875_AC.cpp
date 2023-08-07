/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc171/submissions/44356875
 * Submitted at: 2023-08-07 15:46:39
 * Problem URL: https://atcoder.jp/contests/abc171/tasks/abc171_d
 * Result: AC
 * Execution Time: 299 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    map<int,int> cnt;
    ll sum=0;
    rep(i,n){
        cin >> a[i];
        cnt[a[i]]++;
        sum += a[i];
    }

    int q; cin >> q;
    rep(i,q){
        int b,c; cin >> b >> c;
        cnt[c] += cnt[b];
        sum+=(c-b)*cnt.at(b);
        cnt[b] = 0;
        cout << sum << endl;
    }
    return 0;
}