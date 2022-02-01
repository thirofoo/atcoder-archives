/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/28990857
 * Submitted at: 2022-02-01 20:09:15
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_c
 * Result: WA
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef tuple<int,int,int> T;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int zyanken(int rnd,int p1,int p2,vector<string> &wep){
    if((wep[p1][rnd] == 'C' && wep[p2][rnd] == 'P') || 
       (wep[p1][rnd] == 'P' && wep[p2][rnd] == 'G') ||
       (wep[p1][rnd] == 'G' && wep[p2][rnd] == 'C') )return 1;
    else if(wep[p1][rnd] == wep[p2][rnd]) return 0;
    else return -1;
}

int main() {
    int n,m; cin >> n >> m;
    vector<string> wepon(2*n);
    rep(i,2*n)cin >> wepon[i];
    priority_queue<T,vector<T>,greater<T>> rate;
    rep(i,2*n)rate.push(T(0,0,i));
    rep(i,m){
        rep(j,n){
            auto [rnd1,pnt1,num1] = rate.top(); rate.pop();
            auto [rnd2,pnt2,num2] = rate.top(); rate.pop();
            if(zyanken(i,num1,num2,wepon) == 1)pnt1++;
            else if(zyanken(i,num1,num2,wepon) == -1)pnt2++;
            rnd1++; rnd2++;
            rate.push(T(rnd1,pnt1,num1));
            rate.push(T(rnd2,pnt2,num2));
        }
    }
    priority_queue<P,vector<P>,greater<P>> ans; int tmp = 0;
    rep(i,2*n){
        auto [a,b,c] = rate.top(); rate.pop();
        ans.push(P(-b,c+1));
    }
    rep(i,2*n){
        auto [a,b] = ans.top(); ans.pop();
        cout << b << endl;
    }
    return 0;
}