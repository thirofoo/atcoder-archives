/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc162/submissions/42722087
 * Submitted at: 2023-06-18 21:45:09
 * Problem URL: https://atcoder.jp/contests/arc162/tasks/arc162_b
 * Result: RE
 * Execution Time: 116 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> p(n+1),place(n+1);
    rep(i,n){
        input(p[i+1]);
        place[p[i+1]] = i+1;
    }
    vector<P> answer;
    for(ll i=n;i>2;i--){

        // print();
        // for(auto ele:p)cout << ele << " ";
        // print();
        // for(auto ele:place)cout << ele << " ";
        // print();

        ll now = place[i];
        if(now == i){
            p.pop_back();
            continue;
        }

        vector<ll> next;
        next.push_back(0);
        for(ll j=1;j<=i;j++){
            if(j == now || j == now+1)continue;
            next.push_back(p[j]);
            place[p[j]] = j;
        }

        next.push_back(p[now]);
        place[p[now]] = i-1;
        next.push_back(p[now+1]);
        place[p[now+1]] = i;
        answer.push_back(P(now,i-2));


        answer.push_back(P(i-2,i-2));
        ll e1 = next.back(); next.pop_back();
        ll e2 = next.back(); next.pop_back();
        ll e3 = next.back(); next.pop_back();
        next.push_back(e1);
        next.push_back(e3);

        place[e1] = i-2;
        place[e3] = i-1;
        place[e2] = i;
        swap(p,next);
        // for(auto ele:p)cout << ele << " ";
        // print();
        // for(auto ele:place)cout << ele << " ";
        // print();
        // print();
    }

    // print(p[1],p[2]);
    if(p[1] == 1 && p[2] == 2){
        print("Yes");
        print(answer.size());
        for(auto [i,j]:answer)print(i,j);
    }
    else print("No");
    
    return 0;
}