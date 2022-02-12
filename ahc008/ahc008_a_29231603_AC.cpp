/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29231603
 * Submitted at: 2022-02-12 13:06:48
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 63 ms
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

vector<vector<int>> field(30,vector<int>(30,0));

// void pet_do(string m){
//     rep(i,m.size()){

//     }
// }

// void per_todo(){

// }

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
    vector<string> ans(300);
    rep(i,300){
        string per_do = "";
        rep(i,m){
            //人間の移動処理の処理の出力部分
            per_do += ".";
        }
        ans[i] = per_do;
        cout << per_do << endl;
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

    // rep(i,300){
    //     cout << ans[i] << endl;
    // }
    return 0;
}