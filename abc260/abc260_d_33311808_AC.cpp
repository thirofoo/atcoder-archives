/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/33311808
 * Submitted at: 2022-07-17 21:57:51
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_d
 * Result: AC
 * Execution Time: 442 ms
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
    vector<ll> s(n+1,0);
    rep(i,n){
        ll tmp; cin >> tmp;
        card.push(tmp);
    }

    vector<ll> ans(n+1,-1);
    if(k == 1){
        ll cnt = 1;
        while(!card.empty()){
            ans[card.front()] = cnt;
            card.pop();
            cnt++;
        }
        rep(i,n)cout << ans[i+1] << endl;
        return 0;
    }

    ll turn = 1;
    while(!card.empty()){
        ll now = card.front(); card.pop();
        auto itr = field.lower_bound(now);
        if(itr == field.end()){
            field.insert(now);
            top[now] = -1;
            save[now].push(now);
            s[now]++;
        }
        else{
            if(top[*itr] == -1)top[now] = *itr;
            else top[now] = top[*itr];
            ll saki = top[now];
            
            save[saki].push(now);
            s[saki]++;

            field.erase(itr);
            if(s[saki] == k){
                while(!save[saki].empty()){
                    ans[save[saki].top()] = turn;
                    save[saki].pop();
                }
                s[saki] = 0;
            }
            else field.insert(now);
        }
        turn++;
    }

    rep(i,n)cout << ans[i+1] << endl;
    
    return 0;
}