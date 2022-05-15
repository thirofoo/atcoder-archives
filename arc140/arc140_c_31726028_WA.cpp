/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc140/submissions/31726028
 * Submitted at: 2022-05-15 22:29:24
 * Problem URL: https://atcoder.jp/contests/arc140/tasks/arc140_c
 * Result: WA
 * Execution Time: 24 ms
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
    
    int n,x; cin >> n >> x;
    vector<bool> used(n,false);
    //ジグザグ行く戦法。

    //nextがtrueなら下からいき、falseなら上から行く。
    bool next = (x-1 > n-x ? true : false);

    queue<int> ans;
    ans.push(x);
    int cnt = 1;
    used[x-1] = true;

    while(true){
        if(next){
            if(x-cnt <= 0)break;
            x -= cnt;
            used[x-1] = true;
            ans.push(x);
            cnt++;
            next = false;
        }
        else{
            if(x+cnt > n)break;
            x += cnt;
            used[x-1] = true;
            ans.push(x);
            cnt++;
            next = true;
        }
    }

    rep(i,n)if(!used[i])ans.push(i+1);

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}