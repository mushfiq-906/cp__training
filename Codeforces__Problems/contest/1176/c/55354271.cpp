/*Author : Abdallah Hemdan */
/**************************/
/*Dear online judge:
* I've read the problem, and tried to solve it.
* Even if you don't accept my solution, you should respect my effort.
* I hope my code coMpiles and gets accepted.
*  ___   __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define		  MP							make_pair
#define		  PB					     	push_back
#define		 endl			                  '\n'
#define		  Fir							  first
#define		  Sec							  second
#define       sz							  size()
#define       len							 length()
#define       vi                             vector<int>
#define       vll                            vector<ll>
#define       vs                         	vector<string>
#define       si                              set<int>
#define       sll                             set<ll>
#define       ss                             set<string>
#define       IO 			ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define     all(v)	      			((v).begin()), ((v).end())
#define    rall(v)                  ((v).rbegin()), ((v).rend())
#define   Ceil(x,y)						    ((x+y-1)/y)
#define	  lop(i,init,n)		     	 for(ll i=init;i<n;++i)
#define     Even(Num) 						Num % 2 == 0
#define   mms(Arr,Val)           memset(Arr,Val,sizeof(Arr))
#define   SetPre(Res,num)	     fixed << setprecision(num) << (Res)
typedef   long long int                     ll;
typedef   long double                       ld;

const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 9;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

// ll GCD(ll a, ll b) {
// 	if (b == 0) return a;
// 	return GCD(b, a%b);
// }
// ll LCM(ll a, ll b) {
// 	return a / (GCD(a, b))* b;
// }
// ll nCr(ll n, ll r) {
//  	if (n < r) return 0;
//  	if (r == 0) return 1;
//  	return n * nCr(n - 1, r - 1) / r;
// }
// ll PowMod(ll base, ll exp,ll M) {
// 	if (exp == 0) return 1;
// 	ll p = POWMOD((base * base) % M, exp >> 1, M);
// 	return (exp & 1) ? (p * base) % M : p;
// }
//bool isPrime(ll n) {
//	if (n == 2) return true;
//	if (n<2 || n % 2 == 0) return false;
//	for (ll i = 3; i*i <= n; i += 2) if (n%i == 0) return false;
//	return true;
//}

const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

using namespace std;
unordered_map<int, int> Mp;
int n;
vector<int> Arr;
void Check() {

	lop(i, 0, n) {
		if (Arr[i] == 4)
			Mp[4]++;
		else if (Arr[i] == 8) {
			if (Mp[4]>0) {
				Mp[4]--;
				Mp[8]++;
			}
		}
		else if (Arr[i] == 15) {
			if (Mp[8]>0) {
				Mp[8]--;
				Mp[15]++;
			}
		}
		else if (Arr[i] == 16) {
			if (Mp[15]>0) {
				Mp[15]--;
				Mp[16]++;
			}
		}
		else if (Arr[i] == 23)
		{
			if (Mp[16]>0)
			{
				Mp[16]--;
				Mp[23]++;
			}
		}
		else
		{
			if (Mp[23]>0)
			{
				Mp[23]--;
				Mp[42]++;
			}
		}
	}
}
void Solve() {
	cin >> n;
	Arr.resize(n);
	lop(i,0,n)
		cin >> Arr[i];
	Check();
	cout << n - 6 * Mp[42] << endl;
}
int main() {
	IO;
	Solve();
}