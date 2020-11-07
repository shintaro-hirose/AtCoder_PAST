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
    string S;
    bool isNum = true;
    cin >> S;
    for(int i = 0; i < (int)S.size(); i++){
        char c = S[i];
        if(c < '0' || c > '9'){
            isNum = false;
            break;
        }
    }
    if(isNum){
        cout << stoi(S) * 2 << endl;
    } else {
        cout << "error" << endl;
    }
    
    
    return 0;
}
