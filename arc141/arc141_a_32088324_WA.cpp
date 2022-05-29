/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc141/submissions/32088324
 * Submitted at: 2022-05-29 21:55:48
 * Problem URL: https://atcoder.jp/contests/arc141/tasks/arc141_a
 * Result: WA
 * Execution Time: 66 ms
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

void enum_div(ll n,vector<ll>& divisor){
    divisor.push_back(1);
    if(n != 1)divisor.push_back(n);
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        divisor.push_back(i);
        if(i != n/i)divisor.push_back(n/i);
    }
    sort(divisor.begin(),divisor.end());
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        vector<ll> divisor;
        string n,ans = "-1"; cin >> n;
        int size = n.size();
        enum_div(size,divisor);

        for(auto k:divisor){
            if(k == size)break;
            // cout << k << " ";
            string tmp1 = "",tmp2 = "";
            rep(i,k)tmp1 += n[i];

            bool flag = false;
            rep(i,size){
                tmp2 += n[i];
                if((i+1)%k == 0){
                    if(stoll(tmp1) < stoll(tmp2)){
                        break;
                    }
                    else if(stoll(tmp1) == stoll(tmp2)){
                        tmp2 = "";
                        continue;
                    }
                    else{
                        flag = true;
                        break;
                    }
                }
            }
            ll a = stoll(tmp1);
            if(flag)a -= 1;
            string cand = "";

            rep(i,size/k)cand += to_string(a);

            bool f = true;
            rep(i,cand.size())f &= (cand[i] == '9' || cand[i] == '0');
            if(f){
                cand = "";
                rep(i,size-1)cand += "9";
            }
            // cout << cand << endl;

            if(stoll(cand) > stoll(ans))ans = cand;
        }
        cout << ans << endl;
    }
    return 0;
}