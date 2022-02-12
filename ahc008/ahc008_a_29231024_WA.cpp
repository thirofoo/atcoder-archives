/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29231024
 * Submitted at: 2022-02-12 12:32:30
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: WA
 * Execution Time: 12 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

int main(){
    int n; cin >> n;
    vector<T> pet;
    rep(i,n){
        int x,y,t; cin >> x >> y >> t;
        pet.push_back(T(x,y,t));
    }
    int m; cin >> m;
    vector<P> people;
    rep(i,m){
        int x,y; cin >> x >> y;
        people.push_back(P(x,y));
    }

    //移動処理
    int cnt = 300;
    while(cnt--){
        string per_do = "";
        rep(i,m){
            //人間の移動処理の処理の出力部分
            per_do += ".";
        }
        cout << per_do << " " << cnt << endl;
        fflush(stdout);
        rep(i,n){
            //ペットの行動処理
            string pet_do; cin >> pet_do;
            rep(j,pet_do.size()){
                //ペット一体ずつの処理
                break;
            }
        }
    }
    return 0;
}