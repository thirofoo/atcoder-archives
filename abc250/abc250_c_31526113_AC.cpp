/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/31526113
 * Submitted at: 2022-05-08 21:22:37
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_c
 * Result: AC
 * Execution Time: 326 ms
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
    
    int n,q; cin >> n >> q;
    map<int,int> a;
    vector<int> A(n);
    iota(A.begin(),A.end(),1);
    for(int i=1;i<=n;i++)a[i] = i-1;
    rep(i,q){
        int x; cin >> x;
        if(a[x] == n-1){
            int left = A[a[x]-1];
            swap(A[a[x]],A[a[x]-1]);
            swap(a[x],a[left]);
        }
        else{
            int right = A[a[x]+1];
            swap(A[a[x]],A[a[x]+1]);
            swap(a[x],a[right]);
        }
    }
    rep(i,n)cout << A[i] << " ";
    cout << endl;
    return 0;
}