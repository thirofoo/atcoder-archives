/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc140/submissions/30623516
 * Submitted at: 2022-04-02 19:33:16
 * Problem URL: https://atcoder.jp/contests/abc140/tasks/abc140_d
 * Result: AC
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
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {    
    int n,k; string s; cin >> n >> k >> s;
    priority_queue<int> c1,c2;
    
    ll ans = 0; string tmp = "";
    int cnt = 0; char ch;
    rep(i,n){
        if(cnt == 0){
            cnt++; ch = s[i];
            continue;
        }

        if(s[i] == ch)cnt++;
        else ans += cnt-1,cnt = 1,tmp += ch,ch = s[i];
    }
    ans += cnt-1; tmp += ch;

    if(tmp.size() == 1)return cout << ans << endl,0;

    else if(tmp[0] == tmp.back()){
        c1.push(1); c1.push(1);
        rep(i,(tmp.size()+1)/2-2)c1.push(2);
        rep(i,(tmp.size()-1)/2)c2.push(2);
    }
    else{
        c1.push(1); c2.push(1);
        rep(i,tmp.size()/2-1){
            c1.push(2); c2.push(2);
        }
    }

    int p1 = 0,p2 = 0,x = k;
    while(!c1.empty() && x--){
        p1 += c1.top(); c1.pop();
    }
    x = k;
    while(!c2.empty() && x--){
        p2 += c2.top(); c2.pop();
    }

    cout << ans+max(p1,p2) << endl;


    return 0;
}