/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/47047679
 * Submitted at: 2023-10-29 00:04:47
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_c
 * Result: WA
 * Execution Time: 423 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> aa(n);
    map<ll,ll> map;
    for(int i=0;i<n;i++){
        cin >> aa[i].first;
    }
    for(int i=0;i<n;i++){
        map[aa[i].first]=0;
    }
    for(int i=0;i<n;i++){
        map[aa[i].first]++;
        aa[i].second=map[aa[i].first];
    }
    sort(aa.begin(), aa.end(), greater<pair<ll,ll>>());
    vector<pair<ll,ll>> a(n,make_pair(0,0));
    set<ll> set;
    for(int i=0;i<n;i++){
        if(set.count(aa[i].first)==0){
            a[i].first=aa[i].first;
            a[i].second=aa[i].second;
        }
        set.insert(a[i].first);
    }
    vector<pair<ll,ll>> b(0);
    for(int i=0;i<n;i++){
        if(a[i].first!=0){
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    // for(auto [e1,e2]:b) cout << e1 << " " << e2 << endl;
 
    ll c=0,ans=0,x=0;
    for(int i=0;i<b.size();){
        if(b[i].first >= b[x].first+m){
            if(c>b[x-1].second) c-=b[x-1].second;
            else c=0;
            x++;
        }
        else {
            c+=b[i].second;
            i++;
        }
        //cout << i<<" "<<b[i].first <<" "<<b[x].first+m<<" "<<c<< endl;
        ans=max(ans,c);
    }

    cout << ans << endl;
}
    // vector<ll> a();
    // for(int i=0;i<n;i++){}

    //vector<vector<ll>> 変数名(n, vector<ll>(m, 0));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //     }
    // }

    // int 関数名(ll x, ll y) {}
    
    // sort(a.begin(), a.end(), greater<ll>());
    
    // do{
    // }while(next_permutation(a.begin(),a.end()));

    //cout << fixed << setprecision(15) << ans << endl;

    //deque<型> 変数名;
    // d.push_back(value) d.push_front(value)
    // d.front() d.back()d.at(i)
    // d.pop_back() d.pop_front()
    // d.size() d.empty()
    
    // for(ll bit=0;bit<(1<<n);bit++){
    //     for(ll i=0;i<n;i++){
    //         if(bit&(1<<i)){
    //         }                
    //     }
    // }

    //     ll c=0;
    //     std::reverse(s.begin(), s.end());
    //    for(int i=0;i<s.size();i++){
    //     int x;
    //         if(s[i]=='0') x=0;
    //         if(s[i]=='1') x=1;
    //         if(s[i]=='2') x=2;
    //         if(s[i]=='3') x=3;
    //         if(s[i]=='4') x=4;
    //         if(s[i]=='5') x=5;
    //         if(s[i]=='6') x=6;
    //         if(s[i]=='7') x=7;
    //         if(s[i]=='8') x=8;
    //         if(s[i]=='9') x=9;
    //     int y=1;
    //     for(int j=0;j<i;j++) y*=10;
    //     c+=x*y;
    //    }