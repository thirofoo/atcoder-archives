/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc039/submissions/33393456
 * Submitted at: 2022-07-21 19:02:25
 * Problem URL: https://atcoder.jp/contests/agc039/tasks/agc039_a
 * Result: WA
 * Execution Time: 7 ms
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
    
    string s;ll k; cin >> s >> k;
    bool flag = true,flag2 = true;
    char tmp2 = s[0];
    rep(i,s.size()){
        if(tmp2 != s[i]){
            flag2 = false;
            break;
        }
    }
    if(flag2)return cout << (s.size()/2)*k << endl,0;

    string tmp = "";
    char t = s.back();
    int size = s.size();
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
    for(int i=1;i<s.size();i++){
        if(t == tmp[i]){
            cnt++;
        }
        else{
            c.push(cnt);
            t = tmp[i];
            cnt = 1;
        }
    }
    if(cnt)c.push(cnt);
    ll ans = 0;
    while(!c.empty()){
        ll p = c.front(); c.pop();
        ans += (p/2)*k;
    }
    cout << ans << endl;
    return 0;
}