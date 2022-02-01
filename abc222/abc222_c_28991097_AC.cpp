/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/28991097
 * Submitted at: 2022-02-01 20:25:11
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_c
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> T;
typedef pair<int,int> P;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)

int judge(char p1,char p2){
    if(p1 == 'C' && p2 == 'P' || p1 == 'P' && p2 == 'G' || p1 == 'G' && p2 == 'C' )return 1;
    else if(p1 == p2) return 0;
    else return -1;
}

int main() {
    int n,m; cin >> n >> m;
    vector<string> wep(2*n);
    rep(i,2*n)cin >> wep[i];
    priority_queue<T,vector<T>,greater<T>> rate;
    rep(i,2*n)rate.push(T(0,0,i));
    rep(i,m){
        rep(j,n){
            auto [a,pnt1,n1] = rate.top(); rate.pop();
            auto [b,pnt2,n2] = rate.top(); rate.pop();
            if(judge(wep[n1][i],wep[n2][i]) == 1)pnt1--;
            else if(judge(wep[n1][i],wep[n2][i]) == -1)pnt2--;
            rate.push(T(i+1,pnt1,n1));
            rate.push(T(i+1,pnt2,n2));
        }
    }
    priority_queue<P,vector<P>,greater<P>> ans;
    rep(i,2*n){
        auto [a,b,c] = rate.top(); rate.pop();
        cout << c+1 << endl;
    }
    return 0;
}