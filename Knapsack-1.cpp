#include<bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ll = long long;
const ll INF = 1e18L + 5;
const ll MOD = 1e9 + 7;
const int res = 0;


int main(){
	int n, c;
	scanf("%d%d", &n, &c);
	vector<ll> dp(c+1, 0); // 0....c
	for(int item = 0; item < n; ++item) {
		int w;
		ll v;
		cin >> w >> v;
		for(int upto = c - w; upto >= 0; --upto) {
			dp[upto + w] = max(dp[upto + w], dp[upto] + v);
		}
	}
	printf("%lld\n", dp[c]);
	
}

