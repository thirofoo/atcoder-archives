/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29494246
 * Submitted at: 2022-02-20 15:43:08
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 53 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)
 
//横一列並べ用の移動文字列
string pdo = "DrDrDrDrDrDrDrDrDrDrDrDrDrDrDuDrDruDrDrDrDrDrDrDrDrDrDrDrDrLlUlUlUlUlUlUlUlUlUlUlUlUlUlUUlUlUlUlUlUlUlUlUlUlUlUlUlUlUd";
string go01 = "RRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLL";
string go23 = "LLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRR";


vector<vector<int>> field(32,vector<int>(32,0));
vector<string> player_action;
vector<vector<int>> pet_cnt(305,vector<int>(22,0));
vector<int> player_bif1(10,0);
vector<int> player_bif2(10,1);
vector<bool> p_num(5,true);
vector<bool> go(6,false);
vector<T> pet;
vector<P> people;
int n,m,cnt,last_cnt = 1,dog_cnt = 0,dog_base = 4,letgo = 0;
vector<int> mx = {0,0,1,-1};
vector<int> my = {1,-1,0,0};
bool F = true,frag2 = false;
 
 
//petのfield-update(人は行動するときに別で更新)
void pet_field_update(int x,int y,int dx,int dy){
    field[x][y] -= 10;
    field[x+dx][y+dy] += 10;
    rep(i,4)if(field[x+mx[i]][y+my[i]] != -2)field[x+mx[i]][y+my[i]]--;
    rep(i,4)if(field[x+dx+mx[i]][y+dy+my[i]] != -2)field[x+dx+mx[i]][y+dy+my[i]]++;
}
 
//petの位置情報更新
void pet_do(string m,int i){
    int dx = 0,dy = 0;
    rep(i,m.size()){
        if(m[i] == '.')continue;
        else if(m[i] == 'U') dx--;
        else if(m[i] == 'D') dx++;
        else if(m[i] == 'L') dy--;
        else                 dy++;
    }
    auto [x,y,t] = pet[i];
    pet[i] = {x+dx,y+dy,t};
    //field更新
    if(dx || dy)pet_field_update(x,y,dx,dy);
    //petが5分割中のどこいるか
    if(2 <= x+dx && x+dx <= 14){
        pet_cnt[cnt][(y+dy)/3]++;
    }
    else if(18 <= x+dx && x+dx <= 30){
        pet_cnt[cnt][11+(y+dy)/3]++;
    }
}
 
//人の行動決定(横一列に並べる為の初期位置への移動)
void people_action_deciding(){
    rep(i,m){
        string tmp = ".";
        auto[x,y] = people[i];
        //5分割中どこにいるか
        int place = i%5,left_cnt = 0;
 
        if(i <= 4){
            if(y%6 == 5){tmp += "L"; left_cnt++;}
            rep(i,x)tmp += "U";
            if(y >= 4+6*place+left_cnt)rep(i,y-(4+6*place+left_cnt))tmp += "L";
            else rep(i,4+6*place+left_cnt-y)tmp += "R";
            tmp += pdo;
            tmp += "..........";
            if(i == 4)tmp += ".....";
            if(place != 4)tmp += "RdRRdRd";
            else tmp += "Rd";
        }
        else{
            if(y%6 == 5)tmp += "L";
            rep(i,x)tmp += "U";
            rep(i,y)tmp += "L";
        }

        switch(i){
            case 0: tmp += "LLLLLL......"; break;
            case 1: tmp += "LLLLLLLLLLLL"; break;
            case 2: tmp += "RRRRRRRRRRR."; break;
            case 3: tmp += "RRRRR......."; break;
            case 4: tmp += "RR.........."; break;
            default : break;
        }

 
        while(tmp.size() <= 300)tmp += ".";
        //i人目の行動送信
        player_action.push_back(tmp);
    }
}
 
//人の行動処理
string people_do(){
    string todo = "";
    vector<P> tmp(m,P(0,0));
    rep(i,m){
        int dx = 0,dy = 0;
        char action = player_action[i][cnt];
 
        auto [x,y] = people[i];
 
        bool frag = true;
        rep(j,m){
            if(people[j].second == 1 || people[j].second == 30)continue;
            frag = false; break;
        }
        if(frag && F){
            if(!(field[1][1] >= 10 || field[2][1] >= 10 || field[3][1] >= 10 || field[1][30] >= 10 || field[2][30] >= 10 || field[3][30] >= 10 || field[1][2] || field[1][29])){
                frag2 = true;
                rep(j,m){
                    player_action[j].insert(cnt+1,"DDDDDDDDDDDDDDD");

                    switch(j){
                        case 0:player_action[j].insert(cnt+17,go01); break;
                        case 1:player_action[j].insert(cnt+24,go01); break;
                        case 2:player_action[j].insert(cnt+17,go01); break;
                        case 3:player_action[j].insert(cnt+24,go01); break;
                        case 4:player_action[j].insert(cnt+31,go01); break;
                        case 5:player_action[j].insert(cnt+31,go01); break;
                        case 6:player_action[j].insert(cnt+38,go01); break; 
                        case 7:player_action[j].insert(cnt+38,go01); break;
                        case 8:player_action[j].insert(cnt+45,go01); break;
                        case 9:player_action[j].insert(cnt+45,go01); break;
                    }
                }
                F = false;
                letgo = cnt+16;  
            }
        }
        if(frag2){
            if(i%5 <= 1)action = 'r';
            else action = 'l';
            if(i == m-1)frag2 = false;
        }

        if(cnt >= letgo && !F && ((y != 29 && pet_cnt[cnt-1][y/3]) || (y == 29 && pet_cnt[cnt-1][10]))){
            if(field[x-1][y] == 0)action = 'u';
        }
        if(cnt >= letgo && !F && ((y != 29 && pet_cnt[cnt-1][11+y/3]) || (y == 29 && pet_cnt[cnt-1][21]))){
            if(field[x+1][y] == 0)action = 'd';
        }

 
        if     (action == 'U' || action == 'u') dx--; 
        else if(action == 'D' || action == 'd') dx++;
        else if(action == 'L' || action == 'l') dy--;
        else if(action == 'R' || action == 'r') dy++;
 
        //操作先が柵もしくは操作がない時。
        if(field[x+dx][y+dy] == -2 || (dx == 0 && dy == 0)){todo += '.'; continue;}
        if('a' <= action && action <= 'z'){
            if(field[x+dx][y+dy] == 0){field[x+dx][y+dy] = -2; todo += action;}
            //操作先が何かある時に次の行動も置くに変更。
            else{
                string a = ""; a += action;
                player_action[i].insert(cnt+1,a);
                todo += '.'; continue;
            }
        }
        else{
            people[i] = {x+dx,y+dy};
            field[x+dx][y+dy]++;
            tmp[i] = P(dx,dy);
            todo += action;
        }
    }
    //そのターン開始に操作出来ない場所は操作不可→fieldの削除更新は最後。
    rep(i,m){
        auto [x,y] = people[i];
        auto [dx,dy] = tmp[i];
        char action = player_action[i][cnt];
        if('A' <= action && action <= 'Z' && (dx || dy))field[x-dx][y-dy]--;
    }
    return todo;
}
 
 
int main(){
    rep(i,32)rep(j,32)if(i == 0 || j == 0 || i == 31 || j == 31)field[i][j] = -2;
    //初期入力
    cin >> n;
    rep(i,n){
        int x,y,t; cin >> x >> y >> t;
        pet.push_back(T(x,y,t));
        if(t == 4)dog_cnt++;
        field[x][y] += 10;
        rep(j,4)if(field[x+mx[j]][y+my[j]] != -2)field[x+mx[j]][y+my[j]]++;
    }
    cin >> m;
    rep(i,m){
        int x,y; cin >> x >> y;
        people.push_back(P(x,y));
        field[x][y]++;
    }
    people_action_deciding();
 
    //移動処理
    vector<string> ans(305);
    for(cnt=1;cnt<=300;cnt++){
        //人間の行動出力部分
        string person = people_do();
        ans[cnt] = person;
        cout << person << endl;
        fflush(stdout);
        
        //人間の行動後のペットの行動処理
        rep(i,n){
            string tmp; cin >> tmp;
            pet_do(tmp,i);
        }
    }
}