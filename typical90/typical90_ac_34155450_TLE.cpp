/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34155450
 * Submitted at: 2022-08-20 14:38:33
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ac
 * Result: TLE
 * Execution Time: 4411 ms
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
    
    ll w,n; cin >> w >> n;
    vector<ll> l(n),r(n),comp;
    rep(i,n){
        cin >> l[i] >> r[i];
        comp.push_back(l[i]);
        comp.push_back(r[i]);
    }
    //座標圧縮様に重複無し&昇順の配列を作成
    //ただこの時setを用いることは不可。setはイテレータの計算量がO(N)であるため、下記のfor文がO(N^2)になる。
    sort(comp.begin(),comp.end());
    //そもそもuniqueとは隣接する値において同じものが有ったらそれを末尾とswapして飛ばす関数。
    // => sort済みに対してやると、先頭がuniqueな値のみの配列となり、それ以降はゴミが詰まってる感じ。
    // => uniqueの返り値はゴミの初めのイテレータである為、そこから末尾までをeraseすることで、setのようなものを作成。
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    // ↑の計算量はトータルO(N) (unique O(N),erase O(N))

    rep(i,n){
        l[i] = lower_bound(comp.begin(),comp.end(),l[i])-comp.begin();
        r[i] = lower_bound(comp.begin(),comp.end(),r[i])-comp.begin();
    }

    vector<ll> h(comp.size(),0);
    rep(i,n){
        ll tmp = *max_element(h.begin()+l[i],h.begin()+r[i]+1) + 1;
        fill(h.begin()+l[i],h.begin()+r[i]+1,tmp);
        cout << tmp << endl;
    }

    return 0;
}