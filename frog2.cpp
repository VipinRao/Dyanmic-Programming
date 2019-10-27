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
 

const int INF=1e9+5;
using ll=long long;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int height[n];
	for(int i = 0; i < n; ++i) {
		cin >> height[i];
	}
	vector<int> dp(n,INF);
	dp[0] = 0; //dp[i] - > min cost to reach stone i
	for(int stone = 0; stone < n; ++stone) {
		for(int x = 1; x <= k; ++x) {
			if(stone + x < n) {
			 dp[stone + x] = min(dp[stone + x], dp[stone] + abs(height[stone]- height[stone + x]));
		}
		}
	}
	printf("%d\n", dp[n-1]);
}
