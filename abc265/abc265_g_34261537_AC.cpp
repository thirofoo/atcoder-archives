/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/34261537
 * Submitted at: 2022-08-22 12:17:35
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_g
 * Result: AC
 * Execution Time: 803 ms
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

// S が data, F が lazy
using S = array<ll,6>;
using F = array<ll,3>;

//operator(作用素)
S op(S a,S b){
    auto [z1,o1,t1,zo1,ot1,zt1] = a;
    auto [z2,o2,t2,zo2,ot2,zt2] = b;
    //以下3つ：01,12,02の転倒数(過去の転倒数の和 + 子ノードを合成することで出来た転倒数)
    ll t01 = zo1+zo2+o1*z2, t12 = ot1+ot2+t1*o2, t02 = zt1+zt2+t1*z2;
    return {z1+z2,o1+o2,t1+t2,t01,t12,t02};
}
// 写像 f(x) を返す(☆遅延されているデータを下層に反映)
S mapping(F f,S x){
    //☆ここの転倒数の更新設定が難しい。
    auto [z,o,t,zo,ot,zt] = x;
    auto [nz,no,nt] = f;
    S tmp = {0,0,0,0,0,0};
    tmp[nz] += z;
    tmp[no] += o;
    tmp[nt] += t;

    //模範解答参考(fによって何が何に更新されたかの場合分け面倒臭い => 3*3配列を用意して転倒数をぶち込む&更新)
    //cnt[i][j] : iの後ろにjが何個あるか
    vector cnt(3,vector<ll>(3,0));
    cnt[no][nz] += zo;
    cnt[nt][no] += ot;
    cnt[nt][nz] += zt;
    //元の0->1の数 => 01の選び方の総数-10の転倒数 みたいにやる、
    cnt[nz][no] += z*o - zo;
    cnt[no][nt] += o*t - ot;
    cnt[nz][nt] += z*t - zt;

    tmp[3] = cnt[1][0];
    tmp[4] = cnt[2][1];
    tmp[5] = cnt[2][0];

    return tmp;
}
// 合成写像 f o g を返す(非可換な場合に注。 g -> f の順番で処理。上層の遅延データを下層の遅延データに反映する際の処理。上書きの場合はfのみ処理。)
F composition(F f,F g){
    return {f[g[0]],f[g[1]],f[g[2]]};
}

S e(){ return {0,0,0,0,0,0}; } // 単位元 (op(e, a) = op(a, e) = a)
//mapingによる合成写像が変わらないのは、{0,1,2}
F id(){ return {0,1,2}; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    //方針：遅延セグ木。構造体自作でなく、固定長配列でノードを管理することで遷移による合成関数が超作りやすい。
    // ※vectorでは固定長配列を作れないため、arrayで固定長配列を作成する。
    ll n,q; cin >> n >> q;
    vector<S> a(n);
    rep(i,n){
        ll tmp; cin >> tmp;
        if(tmp == 0)a[i] = {1,0,0,0,0,0};
        else if(tmp == 1)a[i] = {0,1,0,0,0,0};
        else a[i] = {0,0,1,0,0,0};
    }
    lazy_segtree<S,op,e,F,mapping,composition,id> sg(a);
    while(q--){
        ll T,l,r; cin >> T >> l >> r; l--;
        if(T == 1){
            auto [z,o,t,zo,ot,zt] = sg.prod(l,r);
            cout << zo + ot + zt << endl;
        }
        else{
            ll s,t,u; cin >> s >> t >> u;
            sg.apply(l,r,{s,t,u});
        }
    }
    
    return 0;
}