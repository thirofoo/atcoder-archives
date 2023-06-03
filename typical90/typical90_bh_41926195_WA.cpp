/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41926195
 * Submitted at: 2023-06-03 15:39:08
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Result: WA
 * Execution Time: 87 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    // 境界全探索 → 左右の境界未満の数の種類 + 1 が候補
    ll ans = 0;
    vector<ll> cnt1(n+1,0),cnt2(n+1,0);
    fenwick_tree<ll> fw1(n+1),fw2(n+1);
    for(ll i=1;i<n;i++){
        if(!cnt2[a[i]])fw2.add(a[i],1);
        cnt2[a[i]]++;
    }
    rep(i,n){
        ll cand = fw1.sum(0,a[i]) + fw2.sum(0,a[i]) + 1;
        ans = max(cand,ans);
        if(i == n-1)break;

        if(!cnt1[a[i]])fw1.add(a[i],1);
        cnt1[a[i]]++;
        cnt2[a[i+1]]--;
        if(!cnt2[a[i+1]])fw2.add(a[i+1],-1);
    }
    print(ans);

    return 0;
}