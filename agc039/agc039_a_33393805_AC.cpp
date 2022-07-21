/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc039/submissions/33393805
 * Submitted at: 2022-07-21 19:26:10
 * Problem URL: https://atcoder.jp/contests/agc039/tasks/agc039_a
 * Result: AC
 * Execution Time: 10 ms
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s,s1;ll k; cin >> s >> k;
    s1 = s;
    bool flag = true,flag2 = true;
    char tmp2 = s[0];
    rep(i,s.size()){
        if(tmp2 != s[i]){
            flag2 = false;
            break;
        }
    }
    if(flag2)return cout << (s.size()*k)/2 << endl,0;

    string tmp = "";
    char t = s.back();
    rep(i,s.size()){
        if(flag && s[i] == t){
            s += s[i];
        }
        else{
            flag = false;
            tmp += s[i];
        }
    }
    queue<ll> c;
    int cnt = 1; t = tmp[0];
    for(int i=1;i<tmp.size();i++){
        if(t == tmp[i]){
            cnt++;
        }
        else{
            c.push(cnt);
            t = tmp[i];
            cnt = 1;
        }
    }
    c.push(cnt);
    ll ans = 0;
    while(!c.empty()){
        ll p = c.front(); c.pop();
        ans += (p/2)*(k-1);
    }
    cnt = 1; t = s1[0];
    for(int i=1;i<s1.size();i++){
        if(s1[i] == t)cnt++;
        else {
            ans += cnt/2;
            cnt = 1;
            t = s1[i];
        }
    }
    ans += cnt/2;
    cout << ans << endl;
    return 0;
}