/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/36381582
 * Submitted at: 2022-11-11 18:40:25
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_f
 * Result: AC
 * Execution Time: 282 ms
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
    
    // queryの順番を問わないことに着目
    // => 右端の昇順にqueryを処理する！
    // (右端で処理すると1連の流れで出来る)
    ll n,q; input(n,q);
    vector<ll> c(n);
    vector<vector<P>> query(n+1);
    rep(i,n)input(c[i]);
    rep(i,q){
        int l,r; input(l,r);
        query[r].push_back(P(i,l));
    }

    vector<int> ans(q),last(n+1,0);
    fenwick_tree<int> fw(n+2);
    for(int i=1;i<=n;i++){
        fw.add(i,1);
        // 天才point：ここでc[i-1]が被ってた時に最後尾にすり替えてあげている。
        // (右端を基準にしている為、ある種において現状最も右にあるもののみをカウントすればよい！)
        if(last[c[i-1]]!=-1)fw.add(last[c[i-1]],-1);
        last[c[i-1]] = i;
        for(auto p:query[i]){
            ans[p.first] = fw.sum(p.second,i+1);
        }
    }
    rep(i,q)print(ans[i]);
    
    return 0;
}