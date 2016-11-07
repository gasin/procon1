#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define SIZE 1000
using namespace std;
typedef long long ll;

ll saw[SIZE];
ll a[SIZE], b[SIZE];
ll board[SIZE][SIZE];

int main(){
    mt19937 mt(114514);
    rep(i,SIZE) rep(j,SIZE) board[i][j] = mt()%1000000;
    rep(i,SIZE) board[i][i] = 0;
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    rep(i,SIZE){
        cin >> a[i] >> b[i];
    }
    rep(i,SIZE){
        if(0 > a[i] || a[i] >= SIZE || 0 > b[i] || b[i] >= SIZE){
            cout << "invalid input" << endl;
            return 0;
        }
        if(i != SIZE-1){
            if(b[i] != a[i+1]){
                cout << "invalid input" << endl;
                return 0;
            }
        } else{
            if(b[i] != a[0]){
                cout << "invalid input" << endl;
                return 0;
            }
        }
        saw[a[i]]++;
        saw[b[i]]++;
    }
    rep(i,SIZE){
        if(saw[i] != 2){
            cout << "invalid input" << endl;
            return 0;
        }
    }
    if(a[0] != 0){
        cout << "invalid input" << endl;
        return 0;
    }
    ll score = 0;
    rep(i,SIZE) score += board[a[i]][b[i]];
    cout << score << endl;
}
