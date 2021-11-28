/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc032/submissions/27581139
 * Submitted at: 2021-11-29 01:41:18
 * Problem URL: https://atcoder.jp/contests/abc032/tasks/abc032_c
 * Result: AC
 * Execution Time: 41 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

int main(){
    int N,K;
    int length = 0;
    int right = 0;
    int scale = 0;
    ll multi = 1;
    cin >> N >> K;
    vector<int> Q(N);
    rep(i,N){
        cin >> Q[i];
        if(Q[i] == 0)return cout << N << endl,0;
    }
    for(int left=0;left<N;left++){
        for(right;right < N;right++){
            if(multi*Q[right] <= K ){
                multi*=Q[right];
                scale++;
                continue;
            }
            break;
        }
        length = max(length,scale);
        scale--;
        if(multi % Q[left] == 0)multi/=Q[left];
    }
    cout << length << endl;
    return 0;
}