/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29400354
 * Submitted at: 2022-02-18 15:31:19
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 59 ms
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
string p1do = "RuRlRldRlRlRlRldRlRlRlRldRlRlRlRldRlRlRlRldRlRlRlRldRlRlRlRlRulDuDDuLrLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLruLr";
string p50do = "LuLrLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLruDuDDuRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRulRl";
string p2do = "LuLrLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLrLrLrdLrLruDuDDuRlRldRlRlRlRldRlRlRlRldRlRlRlRldRlRlRlRldRlRluRlRlRlRlRlRlRulRl";
string p10do = "LLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrLrDuDDuRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRlRulRl";
 
string go01 = "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUUDDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUUDDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
string go23 = "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUDDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUUDDDDDDDDDDDDDDDDDDDDDDDDDDDDDUUUUUUUUUUUUUUUUUUUUUUUUUUUUUDDDDDDDDDDDDDDDDDDDDDDDDDDDDD";
 
 
 
vector<vector<int>> field(32,vector<int>(32,0));
vector<string> player_action;
vector<vector<int>> pet_cnt(305,vector<int>(11,0));
vector<int> player_bif1(10,0);
vector<int> player_bif2(10,1);
vector<bool> p_num(5,true);
vector<bool> go(6,false);
vector<T> pet;
vector<P> people;
int n,m,cnt,last_cnt = 1;
vector<int> mx = {0,0,1,-1};
vector<int> my = {1,-1,0,0};
 
 
//petのfield-update(人は行動するときに別で更新)
void pet_field_update(int x,int y,int dx,int dy){
    field[x][y]--;
    field[x+dx][y+dy]++;
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
    if(3 <= y+dy && y+dy <= 28){
        pet_cnt[cnt][(x+dx)/3]++;
    }
}
 
//人の行動決定(横一列に並べる為の初期位置への移動)
void people_action_deciding(){
    rep(i,m){
        string tmp = ".";
        auto[x,y] = people[i];
        //5分割中どこにいるか
        int place = i%5;
 
        if(x >= 2+place*6)rep(i,x-(2+place*6))tmp += "U";
        else rep(i,2+place*6-x)tmp += "D";
        if(i%5 == 1 || i%5 == 3)rep(i,y-1)tmp += "L";
        else rep(i,30-y)tmp += "R";
        while(tmp.size() <= 55)tmp += ".";
 
        if(i%5 == 1 || i%5 == 3)tmp += p1do;
        else if(i%5 == 2) tmp += p2do;
        else if(i%5 == 4) tmp += p50do;
        else tmp += p10do;
 
        if(i == 0)tmp += "UUUU";
        else if(i == 1)tmp += "UUUUUUUUUU";
        else if(i == 2)tmp += "DDDDDDDDDDDDD";
        else if(i == 3)tmp += "DDDDDDD";
        else if(i == 4)tmp += "UUUUUUUUUUUUUU";
        else if(i == 5)tmp += "DDDDDDDDDDD";
        else if(i == 6)tmp += "DDDDD";
        else if(i == 7)tmp += "UU";
        else if(i == 8)tmp += "UUUUUUUU";
        else if(i == 9)tmp += "UUUUUUUUUUUUUU";
 
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
 
        if(cnt >= 150 && player_action[0][cnt] == '.' && player_action[1][cnt] == '.'){
            player_action[0].insert(cnt+1,go01);
            player_action[1].insert(cnt+1,go01);
            go[0] = true;
        }
        if(cnt >= 150 && player_action[2][cnt] == '.' && player_action[3][cnt] == '.'){
            player_action[2].insert(cnt+1,go23);
            player_action[3].insert(cnt+1,go23);
            go[1] = true;
        }
 
        if(go[i/2] && ((pet_cnt[cnt-1][x/3] >= 3 && cnt <= 210) || (pet_cnt[cnt-1][x/3] >= 2 && cnt <= 240) || (pet_cnt[cnt-1][x/3] >= 1 && cnt <= 300)) && (field[x][y-1] == 0 || field[x][y+1] == 0)){
            if(i%2 == 0){ action = 'l';}
            else { action = 'r';}
        }
 
        if     (action == 'U' || action == 'u') dx--; 
        else if(action == 'D' || action == 'd') dx++;
        else if(action == 'L' || action == 'l') dy--;
        else if(action == 'R' || action == 'r') dy++;
 
        //2回目の分岐
        // if(player_bif1[i] && player_bif2[i] && cnt >= 220){
        //     if(player_bif1[i] == 100)player_bif2[i] = 0;
        //     else{
        //         int v = player_bif1[i]-1;
        //         string last = ".";
        //         if((pet_cnt[cnt-1][v].first >= pet_cnt[cnt-1][v].second) && field[x][y-1] == 0){
        //             last = "l";
        //             player_bif2[i] = 0;
        //         }
        //         else if((pet_cnt[cnt-1][v].first < pet_cnt[cnt-1][v].second) && field[x][y+1] == 0){
        //             last = "r";
        //             player_bif2[i] = 0;
        //         }
        //         todo += last;
        //         continue;
        //     }
        // }
 
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
        field[x][y]++;
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