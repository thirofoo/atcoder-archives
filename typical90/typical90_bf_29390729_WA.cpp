/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29390729
 * Submitted at: 2022-02-17 22:58:03
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bf
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
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k; cin >> n >> k;
    vector<int> num(100001,0);
    int a = n,ans = 0;
    while(!num[a]){
        ans++; num[a] = ans;
        int b = a,cnt = 0;
        while(b != 0){
            cnt += b%10; b /= 10;
        }
        cnt += b;
        a = (a+cnt)%100000;
    }
    int T = ans-num[a]+1;
    if(k <= num[a])cout << find(num.begin(),num.end(),k+1)-num.begin() << endl; 
    else cout << find(num.begin(),num.end(),((k-num[a]+1)%T)+num[a])-num.begin() << endl; 
    return 0;
}