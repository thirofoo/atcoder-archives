/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/29828921
 * Submitted at: 2022-03-03 22:56:15
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_j
 * Result: AC
 * Execution Time: 397 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

//SegmentTreeはモノイドというものを埋め込むことで扱える。
//モノイド：二項演算と単位素をもつ代数的構造。
int op(int a,int b){
    //operater
    //二項演算は結合則が成り立つ必要あり。
    //基本的には最小値、最大値、足し算、掛け算など。
    return max(a,b);
}

int e(){
    //単位元。掛け算でいう1みたいに、演算前後で値が変わらないような値を入れる。足し算なら0みたいな。
    //今回はどんな値と比較しても、それが大きい方になるように負の数を入れている。
    return -1;
}

int V;
bool f(int a){
    return a < V;
}

int main() {
    int n,q; cin >> n >> q;
    segtree<int,op,e> sg(n);
    rep(i,n){
        int a; cin >> a;
        sg.set(i,a);
    }
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x,v; cin >> x >> v;
            sg.set(x-1,v);
        }
        else if(t == 2){
            int l,r; cin >> l >> r;
            //indexが[l,r)のものを求めている。
            cout << sg.prod(l-1,r) << '\n';
        }
        else{
            int x,v; cin >> x >> v;
            V = v;
            //fを定義して、指定した左端(今回はx)からの範囲内全てにおいてfが成り立つ様な右端のindexを返す。
            //今回は範囲を満たす最小のindexを求めたいため、あえてf内には要素がv未満の時にtrueにして、
            //初めてv以上の値が出てきた時にfalseにすることで、それ+1のところが最小のindexになる。
            cout << sg.max_right<f>(x-1)+1 << '\n';
        }
    }
    return 0;
}