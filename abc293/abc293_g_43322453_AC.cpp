/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/43322453
 * Submitted at: 2023-07-08 08:58:48
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_g
 * Result: AC
 * Execution Time: 541 ms
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
    
    ll n, q; input(n,q);
    vector<ll> a(n), l(q), r(q), query(q);
    rep(i,n) {
        input(a[i]);
        a[i]--;
    }
    rep(i,q){
        input(l[i], r[i]);
        l[i]--;
    }

    ll sq = sqrt(n);
    iota(query.begin(), query.end(), 0);
    sort(query.begin(),query.end(),[&](ll a,ll b){
        if(l[a]/sq != l[b]/sq){
            return l[a] < l[b];
        }
        if(l[a]/sq %2 == 1){
            return r[a] > r[b];
        }
        return r[a] < r[b];
    });

    auto nCr = [&](ll n,ll r){
        ll res = 1;
        rep(i,r) res *= (n-i);
        rep(i,r) res /= (i+1);
        return res;
    };

    // Mo's algorithm
    vector<ll> ans(q), cnt(200005,0);
    ll now_lr = 0, now_ud = 0, now_answer = 0;
    auto left = [&](){
        now_lr--;
        if( cnt[a[now_lr]] >= 3 )now_answer -= nCr(cnt[a[now_lr]],3);
        if( ++cnt[a[now_lr]] >= 3 )now_answer += nCr(cnt[a[now_lr]],3);
        // print("left!");
    };
    auto right = [&](){
        if( cnt[a[now_lr]] >= 3 )now_answer -= nCr(cnt[a[now_lr]],3);
        if( --cnt[a[now_lr]] >= 3 )now_answer += nCr(cnt[a[now_lr]],3);
        now_lr++;
        // print("right!");
    };
    auto down = [&](){
        now_ud--;
        if( cnt[a[now_ud]] >= 3 )now_answer -= nCr(cnt[a[now_ud]],3);
        if( --cnt[a[now_ud]] >= 3 )now_answer += nCr(cnt[a[now_ud]],3);
        // print("down!");
    };
    auto up = [&](){
        if( cnt[a[now_ud]] >= 3 )now_answer -= nCr(cnt[a[now_ud]],3);
        if( ++cnt[a[now_ud]] >= 3 )now_answer += nCr(cnt[a[now_ud]],3);
        now_ud++;
        // print("up!");
    };

    rep(i,q){
        while(now_ud > r[query[i]]) down();
        while(now_ud < r[query[i]]) up();
        while(now_lr > l[query[i]]) left();
        while(now_lr < l[query[i]]) right();
        ans[query[i]] = now_answer;
    }
    rep(i,q) print( ans[i] );
    
    return 0;
}