/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc140/submissions/31727828
 * Submitted at: 2022-05-15 22:46:31
 * Problem URL: https://atcoder.jp/contests/arc140/tasks/arc140_c
 * Result: WA
 * Execution Time: 26 ms
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

    deque<int> ans;
    ans.push_back(x);
    int cnt = 1;
    used[x-1] = true;

    while(true){
        if(next){
            if(x-cnt <= 0)break;
            x -= cnt;
            used[x-1] = true;
            ans.push_back(x);
            cnt++;
            next = false;
        }
        else{
            if(x+cnt > n)break;
            x += cnt;
            used[x-1] = true;
            ans.push_back(x);
            cnt++;
            next = true;
        }
    }

    while(true){
        bool f = true;
        while(true){
            int t1 = ans.back(); ans.pop_back();
            int t2 = ans.back(); ans.push_back(t1);
            if(next){
                if(t1+abs(t1-t2)+1 <= n && !used[t1+abs(t1-t2)+1 - 1]){
                    used[t1+abs(t1-t2)+1 - 1] = true;
                    ans.push_back(t1+abs(t1-t2)+1);
                    f = false;
                }
                else break;
            }
            else{
                if(t1-abs(t1-t2)-1 > 0 && !used[t1-abs(t1-t2)-1 - 1]){
                    used[t1-abs(t1-t2)-1 - 1] = true;
                    ans.push_back(t1-abs(t1-t2)-1);
                    f = false;
                }
                else break;
            }
        }
        if(!f){
            if(next)next = false;
            else next = true;
        }
        else break;
    }

    rep(i,n)if(!used[i])ans.push_back(i+1);

    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cout << endl;

    return 0;
}