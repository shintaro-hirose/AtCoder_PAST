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
    string ans;
    cin >> N;
    string s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;

    ans = "";
    rep(i, N){
        if(s2.substr(4 * i + 1, 3) == "#.#" && s3.substr(4 * i + 1, 3) == "#.#"){
            ans += "0";
        } else if(s1.substr(4 * i + 1, 3) == ".#."){
            ans += "1";
        } else if(s2.substr(4 * i + 1, 3) == "..#" && s4.substr(4 * i + 1, 3) == "#.."){
            ans += "2";
        } else if(s2.substr(4 * i + 1, 3) == "..#"  && s3.substr(4 * i + 1, 3) == "###"  && s4.substr(4 * i + 1, 3) == "..#"){
            ans += "3";
        } else if(s1.substr(4 * i + 1, 3) == "#.#"){
            ans += "4";
        } else if(s2.substr(4 * i + 1, 3) == "#.." && s4.substr(4 * i + 1, 3) == "..#"){
            ans += "5";
        } else if(s2.substr(4 * i + 1, 3) == "#.." && s4.substr(4 * i + 1, 3) == "#.#"){
            ans += "6";
        } else if(s3.substr(4 * i + 1, 3) == "..#"){
            ans += "7";
        } else if(s2.substr(4 * i + 1, 3) == "#.#"  && s3.substr(4 * i + 1, 3) == "###"  && s4.substr(4 * i + 1, 3) == "#.#"){
            ans += "8";
        } else {
            ans += "9";
        }
    }
    cout << ans << endl;

    return 0;
}
