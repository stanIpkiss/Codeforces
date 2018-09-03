#include<bits/stdc++.h>

#define ssync ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const long double PI = 3.14159265;

ll powerWithMod(ll base, ll exponent, ll modulus = LLONG_MAX)
{
	ll result = 1;
	base %= modulus;
	while(exponent > 0)
	{
		if(exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent >>= 1;
		base = (base * base) % modulus;
	}
	return result;
}

ll modInverse(ll a, ll m = MOD)
{
	return powerWithMod(a, m-2, m);
}

int n, a[1234], ans=1;

bool check(int curr)
{
	if(a[1] <= curr || a[n] <= curr)
		return false;
	int cnt = 0;
	for(int i = 2; i <= n; i++)
	{
		if(a[i] > curr)
			cnt = 0;
		else
		{
			cnt++;
			if(cnt > 1)
				return false;
		}
	}
	return true;
}

int main()
{
	ssync;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	while(check(ans))
		ans++;
	cout << ans << "\n";
	return 0;
}
