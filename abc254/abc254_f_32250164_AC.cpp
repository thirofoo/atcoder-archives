/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32250164
 * Submitted at: 2022-06-05 00:21:32
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_f
 * Result: AC
 * Execution Time: 682 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

//SegmentTreeはモノイドというものを埋め込むことで扱える。
//モノイド：二項演算と単位素をもつ代数的構造。
int op(int a,int b){
    //operater
    //二項演算は結合則が成り立つ必要あり。
    //基本的には最小値、最大値、足し算、掛け算など。
    return euclid(abs(a),abs(b));
}

int E;
int e(){
    //単位元。掛け算でいう1みたいに、演算前後で値が変わらないような値を入れる。足し算なら0みたいな。
    //今回はどんな値と比較しても、それが大きい方になるように負の数を入れている。
    return E;
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,q; cin >> n >> q;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    segtree<int,op,e> sga(n),sgb(n);
    rep(i,n-1)sga.set(i+1,a[i+1]-a[i]);
    rep(i,n-1)sgb.set(i+1,b[i+1]-b[i]);
    sga.set(0,a[0]); sgb.set(0,b[0]);

    while(q--){
        int h1,h2,w1,w2; cin >> h1 >> h2 >> w1 >> w2;
        h1--; h2--; w1--; w2--;
        int ans = a[h1]+b[w1];
        E = ans;
        ans = euclid(ans,sga.prod(h1+1,h2+1));
        ans = euclid(ans,sgb.prod(w1+1,w2+1));
        cout << ans << endl;
    }

    return 0;
}