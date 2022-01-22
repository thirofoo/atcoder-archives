/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc133/submissions/28696528
 * Submitted at: 2022-01-22 22:51:53
 * Problem URL: https://atcoder.jp/contests/arc133/tasks/arc133_a
 * Result: WA
 * Execution Time: 138 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,No; cin >> n;
    set<int> type;
    queue<int> v,ans;
    bool frag = true;
    int min1 = 200000,min2 = 200000,max1 = 0,max2 = 0,count = 0;
    rep(i,n){
        int a; cin >> a;
        v.push(a);
        type.insert(a);
        min1 = min(min1,a);
        max1 = max(max1,a);
        if(count < 2 && a != min2){
            count++;
            min2 = min(min2,a);
            max2 = max(max2,a);
        }
    }
    if(min2 == min1)No = max1;
    else No = max2;
    // cout << max1 << " " << min1 << " " << max2 << " " << min2 << " " << No << endl;
    if(type.size() == 1)return cout << endl,0;
    while(!v.empty()){
        int a = v.front();
        v.pop();
        if(a == No)continue;
        ans.push(a);
    }
    while(!ans.empty()){
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;
    return 0;
}