/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32242827
 * Submitted at: 2022-06-04 22:36:08
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_f
 * Result: RE
 * Execution Time: 2257 ms
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
    return euclid(a,b);
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
    vector<segtree<int,op,e>> sg(n,segtree<int,op,e>(n));
    rep(i,n)rep(j,n)sg[i].set(j,a[i]+b[j]);

    while(q--){
        int h1,h2,w1,w2; cin >> h1 >> h2 >> w1 >> w2;
        h1--; h2--; w1--; w2--;
        int ans = a[h1]+b[w1];
        E = ans;
        for(int i=h1;i<=h2;i++)ans = euclid(ans,sg[i].prod(w1,w2+1));
        cout << ans << endl;
    }

    return 0;
}