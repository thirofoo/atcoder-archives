/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33096033
 * Submitted at: 2022-07-09 21:40:20
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_c
 * Result: AC
 * Execution Time: 22 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, char> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s,t; cin >> s >> t;
    char tmp = ' ';
    int size1 = s.size(),size2 = t.size(),cnt = 0;
    vector<P> sch,tch;

    cnt = 1;
    tmp = s[0];
    for(int i=1;i<size1;i++){
        if(tmp == s[i])cnt++;
        else{
            sch.push_back(P(cnt,tmp));
            tmp = s[i];
            cnt = 1;
        }
    }
    if(cnt == 1)sch.push_back(P(cnt,tmp));

    cnt = 1;
    tmp = t[0];
    for(int i=1;i<size2;i++){
        if(tmp == t[i])cnt++;
        else{
            tch.push_back(P(cnt,tmp));
            tmp = t[i];
            cnt = 1;
        }
    }
    if(cnt == 1)tch.push_back(P(cnt,tmp));

    if(sch.size() != tch.size())return cout << "No" << endl,0;
    int S = sch.size();
    rep(i,S){
        auto [st,sc] = sch[i];
        auto [tt,tc] = tch[i];
        if(sc != tc)return cout << "No" << endl,0;
        if( (st == 1 && tt >= 2) || (st >= 2 && tt == 1) )return cout << "No" << endl,0;
        if( st > tt)return cout << "No" << endl,0;
    }
    cout << "Yes" << endl;
    
    return 0;
}