/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc136/submissions/29757218
 * Submitted at: 2022-02-27 22:59:53
 * Problem URL: https://atcoder.jp/contests/arc136/tasks/arc136_b
 * Result: OLE
 * Execution Time: 2188 ms
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
    int n; cin >> n;
    vector<int> a(n),b(n);
    vector<int> a_cnt(5005,0),b_cnt(5005,0);
    rep(i,n){
        cin >> a[i];
        a_cnt[a[i]]++;
    }
    rep(i,n){
        cin >> b[i];
        b_cnt[b[i]]++;
    }
    if(a_cnt != b_cnt)return cout << "No" << endl,0;
    rep(i,n-2){
        if(a[i] == b[i])continue;
        int place = find(a.begin()+i,a.end(),b[i])-a.begin();
        while(place >= i+2){
            swap(a[place-2],a[place]);
            swap(a[place-1],a[place]);
            place -= 2;
            rep(j,n)cout << a[j] << " ";
            cout << endl;
        }
        if(place == i)continue;
        else{
            swap(a[place],a[place-1]);
            swap(a[place],a[place+1]);
        }
        rep(j,n)cout << a[j] << " ";
        cout << endl;
    }
    rep(i,3){
        swap(a[n-1],a[n-3]);
        swap(a[n-2],a[n-1]);
        if(a == b)return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
    return 0;
}