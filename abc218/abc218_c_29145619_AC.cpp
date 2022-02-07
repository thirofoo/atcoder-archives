/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/29145619
 * Submitted at: 2022-02-07 19:45:52
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_c
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

void lotate(int n,vector<string> &a){
    vector<string> lotate_90;
    rep(i,n){
        string tmp = "";
        rep(j,n)tmp += a[j][n-1-i];
        lotate_90.push_back(tmp);
    }
    rep(i,n)a[i] = lotate_90[i];
}

void shift(int n,vector<string> &a){
    int up,left; bool frag = false;
    rep(i,n){
        rep(j,n)if(a[i][j] == '#'){up = i; frag = true;}
        if(frag)break;
    }
    frag = false;
    rep(i,n){
        rep(j,n)if(a[j][i] == '#'){left = i; frag = true;}
        if(frag)break;
    }
    rep(i,n)rep(j,n){
        if(i+up < n && j+left < n)a[i][j] = a[i+up][j+left];
        else a[i][j] = '.';
    }
}

int main() {
    int n; cin >> n;
    vector<string> s(n),t(n); 
    rep(i,n)cin >> s[i];
    rep(i,n)cin >> t[i];
    shift(n,t);
    rep(i,4){
        lotate(n,s);
        shift(n,s);
        if(s == t)return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
    return 0;
}