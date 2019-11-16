/*Given string select any palindrome and remove it. it cost 1 step. Find the minimum steps to completely remove the whole string*/

#include "bits/stdc++.h"
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

const int INF = 1e9 + 5;

void mini(int &a, int b) { a = min(a, b);}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n ,vector<int>(n, n));
    for(int L = n - 1; L >= 0; --L) {
		for(int R = L ; R < n; ++R) {
		//~ cout << L << "  " << R << endl;
			if(L == R){
				dp[L][R] = 1;
			}
			else if(L + 1 == R){
				dp[L][R] = 2;
				if(s[L] == s[R]) {
					dp[L][R] = 1;
				}
			}
			else {
				dp[L][R] = dp[L + 1][R - 1] + (s[L] == s[R] ? 0 : 2);
				mini(dp[L][R], dp[L + 1][R] + 1);
				mini(dp[L][R], dp[L][R - 1] + 1);
				for(int i = L; i < R; ++i) {
					mini(dp[L][R], dp[L][i] + dp[i + 1][R]);
				}
			}
		}
	}
	printf("%d\n", dp[0][n - 1]);
}

