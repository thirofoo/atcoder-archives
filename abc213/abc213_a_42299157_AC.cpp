/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/42299157
 * Submitted at: 2023-06-17 00:08:23
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int a,b,c; cin>>a>>b;
    string bita,bitb,bitc;
    int two=a;
    // while(two>3){
    while(two > 1){
        if(two%2==0){
            bita+='0';
            two=two/2;
        }
        else{
            bita+=to_string(two%2);
            two=two/2;
        }
    }
    // if(two==3) bita+="11";
    // else bita+="01";
    if(two == 1) bita += "1";
    else bita += "0";

    two=b;
    // while(two>3){
    while(two > 1){
        if(two%2==0){
            bitb+='0';
            two=two/2;
        }
        else{
            bitb+=to_string(two%2);
            two=two/2;
        }
    }
    // if(two==3) bitb+="11";
    // else bitb+="01";
    if(two == 1) bitb += "1";
    else bitb += "0";

    // if(bitb.size()>bita.size()) bita+='0';
    // else if(bita.size()>bitb.size()) bitb+='0';

    // ~~ 桁数が2以上違う時も考慮 ~~ //
    while(bita.size() != bitb.size()){
        if(bitb.size() > bita.size()) bita += '0';
        else bitb += '0';
    }

    reverse(bita.begin(),bita.end());
    reverse(bitb.begin(),bitb.end());

    int size=bitb.size();
    for(int i=0;i<size;i++){
        if(bitb.at(i)=='1'){
            if(bita.at(i)=='1'){
                bitc+='0';
            }
            else if(bita.at(i)=='0'){
                bitc+='1';
            }
        }
        else if(bitb.at(i)=='0'){
            if(bita.at(i)=='1'){
                bitc+='1';
            }
            else if(bita.at(i)=='0'){
                bitc+='0';
            }
        }
    }

    int ans=0;
    size=bitc.size();
    for(int i=0;i<size;i++){
        c = int(bitc.at(i)-'0');
        ans += std::pow(2,bitc.size()-i-1)*c;
    }

    cout<<ans<<endl;
}