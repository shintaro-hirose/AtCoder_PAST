#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI 3.141592653589

const ll mod = 1000000007;

int main() {
    int N;
    int prev;
    cin >> N;
    cin >> prev;

    rep(i, N - 1){
        int num;
        cin >> num;
        if(num == prev){
            cout << "stay" << endl;
        } else if(num > prev){
            cout << "up " << num - prev << endl;
        } else {
            cout << "down " << prev - num << endl;
        }
        prev = num;
    }
    
    return 0;
}
