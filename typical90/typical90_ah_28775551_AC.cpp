/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28775551
 * Submitted at: 2022-01-24 19:12:29
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ah
 * Result: AC
 * Execution Time: 118 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define chmax(i,j) i = i >= j ? i : j
#define chmin(i,j) i = i <= j ? i : j
#define rep(i, n) for(ll i = 0; i < n; i++)

int n,k,ans = 0,cnt = 0;

int main(){
    cin >> n >> k;
    map<int,int> vary;
    vector<int> num(n);
    rep(i,n)cin >> num[i];
    int right = 0;
    rep(i,n){
        while(right < n){
            if(vary[num[right]] == 0 && cnt == k)break;
            else if(vary[num[right]] == 0)cnt++;
            vary[num[right]]++;
            right++;
        }
        chmax(ans,right-i);
        if(vary[num[i]] == 1)cnt--;
        vary[num[i]]--;
    }
    cout << ans << endl;
}