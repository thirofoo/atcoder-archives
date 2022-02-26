/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/29648288
 * Submitted at: 2022-02-26 11:46:11
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_e
 * Result: AC
 * Execution Time: 44 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string x; cin >> x;
    vector<int> dig(x.size(),0);
    int cnt = 0;
    for(auto k:x){
        if(cnt != 0)dig[cnt] = dig[cnt-1]+k-'0';
        else dig[cnt] = k-'0';
        cnt++;
    }
    reverse(dig.begin(),dig.end());
    stack<int> ans;
    int c;
    rep(i,x.size()){
        ans.push(dig[i]%10);
        if(i != dig.size()-1)dig[i+1] += dig[i]/10;
        else c = dig[i]/10;
    }
    while(c != 0){
        ans.push(c%10);
        c /= 10;
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    return 0;
}