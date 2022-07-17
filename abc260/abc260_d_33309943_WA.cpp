/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/33309943
 * Submitted at: 2022-07-17 21:49:09
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_d
 * Result: WA
 * Execution Time: 2210 ms
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
    
    ll n,k; cin >> n >> k;
    set<ll> field;
    queue<ll> card;
    vector<ll> top(n+1,-LLONG_MAX);
    vector<stack<ll>> save(n+1);
    rep(i,n){
        ll tmp; cin >> tmp;
        card.push(tmp);
    }

    if(k == 1){
        ll cnt = 1;
        while(!card.empty()){
            cout << card.front() << endl;
            card.pop();
        }
        return 0;
    }

    vector<ll> ans(n+1,-1);
    ll turn = 1;
    while(!card.empty()){
        ll now = card.front(); card.pop();
        auto itr = field.lower_bound(now);
        if(itr == field.end()){
            field.insert(now);
            top[now] = -1;
            save[now].push(now);
        }
        else{
            top[now] = *itr;
            ll saki = now;
            while(top[saki] != -1){
                saki = top[saki];
            }
            
            save[saki].push(now);

            field.erase(itr);
            if(save[saki].size() == k){
                while(!save[saki].empty()){
                    ans[save[saki].top()] = turn;
                    save[saki].pop();
                }
            }
            else field.insert(now);
        }
        turn++;
    }

    rep(i,n)cout << ans[i+1] << " ";
    cout << endl;
    
    return 0;
}