#include <bits/stdc++.h>
#include <atcoder/all>

/////////////////////////////////////////////////

using namespace std;
using namespace atcoder;

// aliases
using ll = long long;
using Vi = vector<int>;
using Vll = vector<ll>;
using Pi = pair<int, int>;
using Pll = pair<ll, ll>;

// constants
constexpr int INF = numeric_limits<int>::max();
constexpr ll LINF = numeric_limits<ll>::max();

// repeat
#define REP(i, n) for (ll i = 0; i < ll(n); ++i)
#define REP3(i, m, n) for (ll i = (m); i < ll(n); ++i)
#define REPR(i, n) for (ll i = ll(n) - 1; i >= 0; --i)
#define REP3R(i, m, n) for (ll i = (n) - 1; i >= ll(m); --i)

// container
#define ALL(x) (x).begin(), (x).end()
#define EACH(e, x) for (auto &&e : x)
inline ll SZ(auto &x) {return (ll) x.size();}
void sort_all(auto &x) {sort(x.begin(), x.end());}
void reverse_all(auto &x) {reverse(x.begin(), x.end());}
void print_all(auto &x, char delimiter = '\n') {for (auto &&e : x) cout << e << delimiter;}

#define FI first
#define SE second

// local
#ifdef LOCAL
#define ASSERT(x) assert(x)
#else
#define ASSERT(x) 0
#endif

/////////////////////////////////////////////////

int main () {
}
