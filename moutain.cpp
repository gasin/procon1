#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define SIZE 1000
using namespace std;
typedef long long ll;
const long long int INF = 1000000000000000000;

const unsigned long long int cycle_per_sec = 2650000000;

unsigned long long int getCycle() {
    unsigned int low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((unsigned long long int)low) | ((unsigned long long int)high << 32);
}

double getTime (unsigned long long int begin_cycle) {
    return (double)(getCycle() - begin_cycle) / cycle_per_sec;
}

class XorShift {
public:
    static unsigned int x;
    static unsigned int y;
    static unsigned int z;
    static unsigned int w;
    static unsigned int t;
    
    static int rand() {
        t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
        return w & 0x7fffffff;
    }
} engine;
unsigned int XorShift::x = 123456789;
unsigned int XorShift::y = 362436069;
unsigned int XorShift::z = 521288629;
unsigned int XorShift::w = 88675123;
unsigned int XorShift::t = 1; 

ll board[SIZE][SIZE];
int ans[SIZE];
int pos[SIZE];
bool used[SIZE];

void init() {
    memset(used, false, sizeof(used));
    ans[0] = 0;
    pos[0] = 0;
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
        pos[ind] = i+1;
        used[ind] = true;
    }
}

void mountain() {
    auto start = getCycle();
    while (getTime(start) < 10) {
        int r1 = engine.rand()%SIZE, r2 = engine.rand()%SIZE;
        if (r1 == 0 || r2 == 0) continue;
        if (r1 == r2) continue;
        int p1 = pos[r1], p2 = pos[r2];
        int c1 = board[ans[p1-1]][ans[p1]]+board[ans[p1]][ans[(p1+1)%SIZE]];
        int c2 = board[ans[p2-1]][ans[p2]]+board[ans[p2]][ans[(p2+1)%SIZE]];
        int d1 = board[ans[p1-1]][ans[p2]]+board[ans[p2]][ans[(p1+1)%SIZE]];
        int d2 = board[ans[p2-1]][ans[p1]]+board[ans[p1]][ans[(p2+1)%SIZE]];
        if (c1+c2 > d1+d2) {
            ans[p1] = r2; ans[p2] = r1;
            pos[r1] = p2; pos[r2] = p1;
        }
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
    mountain();
    output();
}
