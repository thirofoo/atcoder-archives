/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc170/submissions/37266486
 * Submitted at: 2022-12-14 17:39:00
 * Problem URL: https://atcoder.jp/contests/abc170/tasks/abc170_e
 * Result: AC
 * Execution Time: 312 ms
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
    
    ll n,q; input(n,q);
    vector<ll> school(n),rate(n); // 生徒iの幼稚園・rate
    vector<priority_queue<P>> s_info(2e5+5); // 幼稚園iの園児情報
    rep(i,n){
        ll a,b; input(a,b); b--;
        rate[i] = a;
        school[i] = b;
    }

    // 座標圧縮
    vector<ll> comp,c_rate(n);
    rep(i,n)comp.push_back(rate[i]);
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    rep(i,n)c_rate[i] = lower_bound(comp.begin(),comp.end(),rate[i])-comp.begin();

    // 幼稚園 & 各最大rate 更新
    rep(i,n)s_info[school[i]].push(P(rate[i],i));
    fenwick_tree<ll> fw(n);
    rep(i,2e5+5){
        if(s_info[i].size() == 0)continue;
        fw.add(c_rate[s_info[i].top().second],1);
    }

    while(q--){
        ll c,d; input(c,d); c--; d--;
            
        ll pre = school[c];
        school[c] = d;

        // 移動前の情報更新
        {
            fw.add(c_rate[s_info[pre].top().second],-1);
            // 移動前の幼稚園の rate-top を求めるpart
            while(!s_info[pre].empty() && school[ s_info[pre].top().second ] != pre)s_info[pre].pop();
            if(!s_info[pre].empty()){
                fw.add(c_rate[s_info[pre].top().second],1);
                // print(pre,"'s top : ",c_rate[s_info[pre].top().second]);
            }
        }

        // 移動後の情報更新
        {
            if(!s_info[d].empty())fw.add(c_rate[s_info[d].top().second],-1);
            s_info[d].push(P(rate[c],c));

            // 移動後の幼稚園の rate-top を求めるpart
            while(!s_info[d].empty() && school[ s_info[d].top().second ] != d)s_info[d].pop();
            if(!s_info[d].empty()){
                fw.add(c_rate[s_info[d].top().second],1);
                // print(d,"'s top : ",c_rate[s_info[d].top().second]);
            }
        }

        // rep(i,n)cout << fw.sum(i,i+1) << " ";
        // print();

        // fw上で二分探索
        ll left = 0,right = n;
        while(right-left > 1){
            ll mid = (right+left)/2;
            if(!fw.sum(0,mid))left = mid;
            else right = mid;
        }
        print(comp[left]);
    }
    
    return 0;
}