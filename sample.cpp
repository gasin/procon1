#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define SIZE 1000
using namespace std;
typedef long long ll;

ll board[SIZE][SIZE];

int main(){
    mt19937 mt(114514);
    rep(i,SIZE) rep(j,SIZE) board[i][j] = mt()%1000000;
    rep(i,SIZE) board[i][i] = 0;
    rep(i,SIZE){
        if(i != SIZE-1) cout << i << " " << i+1 << endl;
        else cout << i << " " << 0 << endl;
    }
}
