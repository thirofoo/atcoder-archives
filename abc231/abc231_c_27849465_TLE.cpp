/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/27849465
 * Submitted at: 2021-12-11 22:32:10
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_c
 * Result: TLE
 * Execution Time: 2206 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,q;
    cin >> n >> q;
    vector<ll> sintyo(n);
    vector<ll> sihyo(q);
    rep(i,n)cin >> sintyo[i];
    rep(i,q)cin >> sihyo[i];
    sort(sintyo.begin(),sintyo.end(),[](int a,int b){
        return a > b;
    });
    rep(i,q){
        int count = 0;
        rep(j,n){
            if(sintyo[j] >= sihyo[i])count++;
            else{
                cout << count << endl;
                break;
            }
            if(count == n)cout << count << endl;
        }
    }
    return 0;
}