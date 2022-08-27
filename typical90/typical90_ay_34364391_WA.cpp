/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34364391
 * Submitted at: 2022-08-27 19:17:37
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ay
 * Result: WA
 * Execution Time: 271 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    //解説AC。制約から半分全列挙は分かるが、やったことない為初めて実装。
    ll n,k,p; cin >> n >> k >> p;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<ll>> num1(n/2 + 1),num2(n - n/2 + 1);

    //二つのグループに分けてbit全探索
    int cnt,tmp;
    rep(i,(1LL << (n/2))){
        cnt = 0,tmp = 0;
        rep(j,n/2){
            if(i & (1LL << j)){
                tmp += a[j];
                cnt++;
            }
        }
        if(cnt <= k)num1[cnt].push_back(tmp);
    }
    rep(i,(1LL << (n - n/2))){
        cnt = 0,tmp = 0;
        rep(j,n - n/2){
            if(i & (1LL << j)){
                tmp += a[j+n/2];
                cnt++;
            }
        }
        if(cnt <= k)num2[cnt].push_back(tmp);
    }
    
    //各グループにおける値段の後継をsortしておく。
    rep(i,n/2+1)sort(num1[i].begin(),num1[i].end());
    rep(i,n-n/2+1)sort(num2[i].begin(),num2[i].end());

    //これらでうまく二部探索して答えを求める。
    ll ans = 0;
    for(int i=0;i<=n/2;i++){
        for(auto l:num1[i]){
            if(k-i > n-n/2 || num2[k-i].empty() || l+num2[k-i][0] > p)continue;
            auto itr = upper_bound(num2[k-i].begin(),num2[k-i].end(),p-l);
            ans += itr - num2[k-i].begin();
        }
    }
    cout << ans << endl;
    
    return 0;
}