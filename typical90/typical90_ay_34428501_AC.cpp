/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34428501
 * Submitted at: 2022-08-28 22:33:09
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ay
 * Result: AC
 * Execution Time: 258 ms
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
    auto a1 = vector<ll>(a.begin(),a.begin()+n/2);
    auto a2 = vector<ll>(a.begin()+n/2,a.begin()+n);

    //二つのグループに分けてbit全探索
    ll cnt,tmp,s1 = a1.size(),s2 = a2.size();
    vector<vector<ll>> num1(s1+1),num2(s2+1);
    rep(i,(1LL << s1)){
        cnt = 0,tmp = 0;
        rep(j,s1){
            if(i & (1LL << j)){
                tmp += a[j];
                cnt++;
            }
        }
        if(cnt <= k)num1[cnt].push_back(tmp);
    }
    rep(i,(1LL << s2)){
        cnt = 0,tmp = 0;
        rep(j,s2){
            if(i & (1LL << j)){
                tmp += a[j+s1];
                cnt++;
            }
        }
        if(cnt <= k)num2[cnt].push_back(tmp);
    }
    
    //各グループにおける値段の後継をsortしておく。
    rep(i,s1+1)sort(num1[i].begin(),num1[i].end());
    rep(i,s2+1)sort(num2[i].begin(),num2[i].end());

    //これらでうまく二部探索して答えを求める。
    ll ans = 0;
    for(int i=0;i<=s1;i++){
        for(auto l:num1[i]){
            if(k-i > s2 || num2[k-i].empty() || l+num2[k-i][0] > p)continue;
            auto itr = upper_bound(num2[k-i].begin(),num2[k-i].end(),p-l);
            ans += itr - num2[k-i].begin();
        }
    }
    cout << ans << endl;
    
    return 0;
}