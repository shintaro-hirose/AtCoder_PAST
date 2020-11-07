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

string str_tolower(string s) {
    transform(s.begin(), s.end(), s.begin(), 
                // static_cast<int(*)(int)>(std::tolower)         // wrong
                // [](int c){ return std::tolower(c); }           // wrong
                // [](char c){ return std::tolower(c); }          // wrong
                   [](unsigned char c){ return tolower(c); } // correct
                  );
    return s;
}

int main() {
    string S;
    string ans;
    int cap;
    int cnt;
    vector<string> data;
    
    cin >> S;
    cap = 0;
    while((int)S.size() > 0){
        cnt = 1;
        for(char c: S){
            if(c >= 'A' && c <= 'Z'){
                cap++;
                if(cap % 2 == 0){
                    data.push_back(str_tolower(S.substr(0,cnt)));
                    S.erase(0, cnt);
                    break;
                }
            }
            cnt++;
        }
    }
    sort(data.begin(), data.end());

    ans = "";
    for(string s: data){
        s[0] += 'A' - 'a';
        s[s.size() - 1] += 'A' - 'a';
        ans += s;
    }
    cout << ans << endl;
    
    return 0;
}
