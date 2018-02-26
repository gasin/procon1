#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define SIZE 1000
using namespace std;
typedef long long ll;
const long long int INF = 1000000000000000000;

ll board[SIZE][SIZE];
int ans[SIZE];
bool used[SIZE];

void init() {
    memset(used, false, sizeof(used));
    ans[0] = 0;
    used[0] = true;
    rep(i,SIZE-1) {
        ll mi = INF;
        int ind;
        rep(j,SIZE) {
            if (used[j]) continue;
            if (mi > board[ans[i]][j]) {
                mi = board[ans[i]][j];
                ind = j;
            }
        }
        ans[i+1] = ind;
        used[ind] = true;
    }
}

void output() {
    rep(i,SIZE) {
        if (i != SIZE-1) {
            cout << ans[i] << " " << ans[i+1] << endl;
        } else {
            cout << ans[i] << " " << ans[0] << endl;
        }
    }
}

int main(){
    mt19937 mt(114514);
    rep(i,SIZE) rep(j,SIZE) board[i][j] = mt()%1000000;
    rep(i,SIZE) board[i][i] = 0;
    
    init();
    output();
}
