/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc008/submissions/29238950
 * Submitted at: 2022-02-12 18:50:06
 * Problem URL: https://atcoder.jp/contests/ahc008/tasks/ahc008_a
 * Result: AC
 * Execution Time: 57 ms
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

// vector<char> pdo = {'u','R','u','R','u','R','u','r','D','r','D','r','D','r','d','L','d','L','d','L','d','l','U','l','U','l','U','l'};
vector<char> pdo = {'u','R','u','R','u','R','u','R','u','R','u','R','u','r','D','r','D','r','D','r','D','r','D','r','d','L','d','L','d','L','d','L','d','L','d','l','U','l','U','l','U','l','U','l','U','l'};

//ヒトpet問わず、その場or周辺にいる生物の数 外側は-2で、柵は-1になってる。
vector<vector<int>> field(32,vector<int>(32,0));
vector<T> pet;
vector<P> people;
int n,m,cnt;
vector<int> mx = {0,0,1,-1};
vector<int> my = {1,-1,0,0};

void pet_field_update(int x,int y,int dx,int dy){
    field[x][y]--;
    rep(i,4)if(field[x+mx[i]][y+my[i]] != -2)field[x+mx[i]][y+my[i]]--;
    field[x+dx][y+dy]++;
    rep(i,4)if(field[x+dx+mx[i]][y+dy+my[i]] != -2)field[x+dx+mx[i]][y+dy+my[i]]++;
}

void people_field_update(int x,int y,int dx,int dy){
    field[x][y]--;
    if(field[x+dx][y+dy] != -2)field[x+dx][y+dy]++;
}

//petの位置情報更新
void pet_do(string m,int i){
    int dx = 0,dy = 0;
    rep(i,m.size()){
        if(m[i] == '.')continue;
        else if(m[i] == 'U') dx--;
        else if(m[i] == 'D') dx++;
        else if(m[i] == 'L') dy--;
        else dy++;
    }
    auto [x,y,t] = pet[i];
    pet[i] = {x+dx,y+dy,t};
    //field更新
    if(dx || dy)pet_field_update(x,y,dx,dy);
    // cout << x+dx << " " << y+dy << " " << t << endl;
}

//ヒトの行動決定
string per_todo(){
    string todo = "";
    int dx = 0,dy = 0;
    char action = pdo[cnt%pdo.size()] ;
    if     (action == 'U' || action == 'u') dx--; 
    else if(action == 'D' || action == 'd') dx++;
    else if(action == 'L' || action == 'l') dy--;
    else if(action == 'R' || action == 'r') dy++;
    rep(i,m){
        auto [x,y] = people[i];

        if(i%2 == 0){
            if('a' <= action && action <= 'z'){
                if(!field[x+dx][y+dy])field[x+dx][y+dy] = -2;
                else{
                    //移動先が場外or何かいる時。
                    todo += '.';
                    continue;
                }
            }
            else{
                if(field[x+dx][y+dy] != -2){
                    people[i] = {x+dx,y+dy};
                    people_field_update(x,y,dx,dy);
                }
                else{
                    //移動先が場外の時。
                    todo += '.';
                    continue;
                }
            }
            todo += action; 
        }
        else todo += '.';
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

    //移動処理
    vector<string> ans(300);
    for(cnt=0;cnt<300;cnt++){
        //今のfield状況
        // rep(i,32){
        //     rep(j,32){
        //         cout << field[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        //人間の行動出力部分
        string person = per_todo();
        ans[cnt] = person;
        cout << person << endl;
        fflush(stdout);

        //人間の行動後のペットの行動処理
        rep(i,n){
            string tmp; cin >> tmp;
            pet_do(tmp,i);
        }
    }

    //ビジュアライザ出力用
    // rep(i,300){
    //     cout << ans[i] << endl;
    // }
    return 0;
}