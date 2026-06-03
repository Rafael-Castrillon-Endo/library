#include <bits/stdc++.h>
using namespace std;

#define ff first
#define endl '\n'
#define ss second
#define pb push_back
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define fastIO ios::sync_with_stdio(false); cin.tie(nullptr);

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
#define ran(a, b) uniform_int_distribution<int>(a,b)(gen)

typedef long long ll;
typedef long double ld;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    os << "[";
    for(int i = 0; i < sz(v); i++){
        os << v[i] << (i + 1 < sz(v) ? ", " : "");
    }
    return os << "]";
}

const int MOD = 0, oo = 0, MX = 0;

int main(){
    fastIO;

    cout << ran(1, 3) << endl;

}