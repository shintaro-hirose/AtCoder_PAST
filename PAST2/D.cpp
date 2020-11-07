#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    string S;
    cin >> S;

    unordered_set<int> us1;
    unordered_set<int> us2;
    unordered_set<int> us3;

    int N = S.size();
    rep(i, N) {
        char cur = S[i];
        int num;
        num = cur - 'a';
        us1.insert(num);
        us1.insert(26);
    }
    rep(i, N-1){
        char cur1, cur2;
        int num1, num2;
        cur1 = S[i]; cur2 = S[i+1];
        num1 = cur1 - 'a'; num2 = cur2 - 'a';
        us2.insert(num1+num2*27);
        us2.insert(26+num2*27);
        us2.insert(num1+26*27);
        us2.insert(26+26*27);
    }
    
    rep(i, N-2){
        char cur1, cur2, cur3;
        int num1, num2, num3;
        cur1 = S[i]; cur2 = S[i+1]; cur3 = S[i+2];
        num1 = cur1 - 'a'; num2 = cur2 - 'a'; num3 = cur3 - 'a';
        us3.insert(num1+num2*27+num3*27*27);
        us3.insert(26+num2*27+num3*27*27);
        us3.insert(num1+26*27+num3*27*27);
        us3.insert(num1+num2*27+26*27*27);
        us3.insert(26+26*27+num3*27*27);
        us3.insert(num1+26*27+26*27*27);
        us3.insert(26+num2*27+26*27*27);
        us3.insert(26+26*27+26*27*27);
    }
    cout << us1.size() + us2.size() + us3.size() << endl;
    return 0;
}