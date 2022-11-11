/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/36372913
 * Submitted at: 2022-11-11 09:41:35
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_f
 * Result: AC
 * Execution Time: 1178 ms
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
    
    // セグ木では1回の区間mregeにO(N)かかってしまう
    // => この時もし以下を満たすならMo's algorithm(クエリ平方分割)
    //　①更新クエリが無い
    //　②[l,r)から[l±1,r),[l,r±1)が高速に求まる
    //　③オフラインで処理出来る(クエリの順番を問わない)

    // 上記ならうまくやれば、今回はクエリがO(N√Q)で求まる！ 

    ll n,q; input(n,q);
    vector<ll> c(n+1),l(q),r(q);
    rep(i,n)input(c[i+1]);
    rep(i,q)input(l[i],r[i]);
    ll sq = sqrt(q);

    // queryを実行する順番を決めるpart
    vector<ll> query(q);
    iota(query.begin(),query.end(),0);
    sort(query.begin(),query.end(),[&](ll a,ll b){
        if(l[a]/sq != l[b]/sq){
            // a,b個目のクエリが同じ区間に無い時
            // => leftが小さい方が先
            return l[a] < l[b];
        }
        if(l[a]/sq %2 == 1){
            // 同じ区間にいて、それが偶数個目の区間の時(初項が0だから%2 = 1は偶数個目)
            // => ↓に行く為、rightが大きい方が先
            return r[a] > r[b];
        }
        // 奇数個目の区間の時
        // => ↑に行くため、rightが小さい方が先
        return r[a] < r[b];
    });

    // クエリ処理part
    vector<ll> ans(q),cnt(n+1,0);
    int nl = 1,nr = 1,now_ans = 1;
    cnt[c[nl]]++; // この初期値忘れがち
    rep(i,q){
        // 次のクエリの点まで移動
        while(nl > l[query[i]]){
            // lが小さい方に進む時
            // => [l,r]は広がる
            nl--;
            if(!cnt[c[nl]])now_ans++;
            cnt[c[nl]]++;
        }
        while(nl < l[query[i]]){
            // lが大きい方に進む時
            // => [l,r]は狭まる
            cnt[c[nl]]--;
            if(!cnt[c[nl]])now_ans--;
            nl++;
        }
        while(nr > r[query[i]]){
            // rが小さい方に進む時
            // => [l,r]は狭まる
            cnt[c[nr]]--;
            if(!cnt[c[nr]])now_ans--;
            nr--;
        }
        while(nr < r[query[i]]){
            // rが大きい方に進む時
            // => [l,r]は広がる
            nr++;
            if(!cnt[c[nr]])now_ans++;
            cnt[c[nr]]++;
        }
        ans[query[i]] = now_ans;
    }
    rep(i,q)print(ans[i]);
    
    return 0;
}