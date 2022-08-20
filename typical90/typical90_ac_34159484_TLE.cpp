/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34159484
 * Submitted at: 2022-08-20 17:58:24
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

//operator(作用素)
int op(int a,int b){
    //☆ここでの演算は二分木おける子から親へ伝搬して計算するイメージ
    return max(a,b);
}

// 写像 f(x) を返す (☆遅延されているデータを下層に反映)
int v;
int mapping(bool f,int x){
    if(f == 0) return x;
    return max(x,v);
}

// 合成写像 f o g を返す (非可換な場合に注。 g -> f の順番で処理。上層の遅延データを下層の遅延データに反映する際の処理。上書きの場合はfのみ処理。)
// 今回はfが反転する操作よりgをやった後にfをやるという合成写像は、g^fに一致。
bool composition(bool f,bool g){ return f|g; }

int e(){ return 0; } // 単位元 (op(e, a) = op(a, e) = a)
bool id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int w,n; cin >> w >> n;
    lazy_segtree<int,op,e,bool,mapping,composition,id> sg(w);
    while(n--){
        int l,r; cin >> l >> r; l--;
        v = sg.prod(l,r)+1;
        sg.apply(l,r,true);
        rep(i,w)sg.get(i);
        cout << v << endl;
    }
    
    return 0;
}