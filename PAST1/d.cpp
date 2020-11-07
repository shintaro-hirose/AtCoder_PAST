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
    int sum = 0;
     int n1, n2;
    bool isCorrect = true;
    cin >> N;
    vector<int> cnt(N);

rep(i, N){
    int num;
    cin >> num;
    cnt[num - 1]++;
    sum += num;
}
rep(i ,N){
    if(cnt[i] == 0){
        n1 = i + 1;
        isCorrect = false;
    } else if(cnt[i] == 2){
        n2 = i + 1;
    }
}
if(isCorrect){
    cout << "Correct" << endl;
} else {
    cout << n2 << " " << n1 << endl;
}

    return 0;
}
