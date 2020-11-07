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
    string s, t;
    bool isSame = true;
    bool isCaseSame = true;
    cin >> s >> t;
    rep(i, 3){
        if(s[i] != t[i]){
            isSame = false;
            if(tolower(s[i]) != tolower(t[i])){
                isCaseSame = false;
            }
        }
    }
    if(isSame){
        cout << "same" << endl;
    } else if(isCaseSame){
        cout << "case-insensitive" << endl;
    } else {
        cout << "different" << endl;
    }

    return 0;
}
