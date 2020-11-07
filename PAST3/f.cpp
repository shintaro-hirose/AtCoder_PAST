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
    int hasCorrespond = false;
    string ans;
    cin >> N;
    vector<string> data(N);

    rep(i, N){
        string s;
        cin >> s;
        data[i] = s; 
    }
    ans = "";
    if(N % 2 == 0){
        int r1, r2;
        r1 = N / 2 - 1;
        r2 = N / 2;
        rep(i, N / 2){
            hasCorrespond = false;
            for(char c: data[r1]){
                if(data[r2].find(c) != string::npos){
                    ans = c + ans + c;
                    hasCorrespond = true;
                    break;
                }
            }
            if(!hasCorrespond){
                cout << "-1" << endl;
                return 0;
            }
            r1--;
            r2++; 
        }
    } else {
        int m = (N - 1) / 2;
        ans += data[m][0];
        int r1, r2;
        r1 = m - 1;
        r2 = m + 1;
        rep(i, (N - 1) / 2){
            hasCorrespond = false;
            for(char c: data[r1]){
                if(data[r2].find(c) != string::npos){
                    ans = c + ans + c;
                    hasCorrespond = true;
                    break;
                }
            }
            if(!hasCorrespond){
                cout << "-1" << endl;
                return 0;
            }
            r1--;
            r2++; 
        }
    }
    cout << ans << endl;

    return 0;
}
