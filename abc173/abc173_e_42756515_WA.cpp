/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc173/submissions/42756515
 * Submitted at: 2023-06-20 10:44:55
 * Problem URL: https://atcoder.jp/contests/abc173/tasks/abc173_e
 * Result: WA
 * Execution Time: 54 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // 賢く貪欲法。(コーナーが詰め切れなかった)
    // 絶対値順にとる → 積が正なら終了
    // → 積が負なら 1. 選択済正を1つ除いて未選択負 2. 選択済負を1つ除いて未選択正
    // → ただ ↑ は全て負の時にバグる為、別途コーナーを用意

    // ※ 全て負以外の時は全部ok
    // k = n はどうしようもない為全部選ぶ。
    // k != n なら必ず 積が正 || 積が負かつ上記二択のいずれか が当てはまる。

    ll n,k; input(n,k);
    vector<ll> a(n);
    vector<P> abst;
    bool all_minus = true;
    rep(i,n){
        input(a[i]);
        all_minus &= (a[i] < 0);
        abst.push_back(P(abs(a[i]),(a[i] >= 0)));
    }
    if(all_minus){
        mint ans = 1;
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        rep(i,k)ans *= a[i];
        print(ans.val());
        return 0;
    }
    sort(abst.begin(),abst.end(),[](P a,P b){
        return a > b;
    });

    bool minus = false;
    mint ans = 1;
    ll used_minus = 1e9+1,used_plus = 1e9+1,unused_minus = -1,unused_plus = -1;
    rep(i,n){
        if(i < k){
            ans *= abst[i].first;
            if(!abst[i].second){
                used_minus = min(used_minus,abst[i].first);
                minus = !minus;
            }
            else used_plus = min(used_plus,abst[i].first);
        }
        else{
            if(!abst[i].second) unused_minus = max(unused_minus,abst[i].first);
            else unused_plus = max(unused_plus,abst[i].first);
        }
    }
    if(!minus){
        print(ans.val());
        return 0;
    }
    print(used_minus,used_plus,unused_minus,unused_plus);
    if( unused_minus != -1 && used_plus != 1e9+1 && unused_minus*used_minus >= used_plus*unused_plus ){
        ans = ans * unused_minus / used_plus;
    }
    if( unused_plus != -1 && used_minus != 1e9+1 && unused_minus*used_minus < used_plus*unused_plus ){
        ans = ans * unused_plus  / used_minus;
    }
    print( (ans * (k == n ? -1 : 1)).val() );
    
    return 0;
}