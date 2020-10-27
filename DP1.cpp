#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define PI 3.1415926
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define forf(n,x) for(int x = 0; x < n; ++x)
#define forb(n,x) for(int x = n-1; x >= 0; --x)

#define all(c) c.begin(), c.end()
#define itr(c,it) for( auto it = c.begin(); it != c.end(); ++it)

typedef priority_queue <int> pq;

int calc(char str[], int n, int memo[])
{
    cout<<str<<"\n";
    cout<<n<<" "<<memo[n];

	if(memo[n] > -1)
		return memo[n];

	memo[n] = 0;

	cout<<n<<" "<<memo[n];

	if(str[n] > '0')
		memo[n] = calc(str,n-1, memo);

	if(str[n-1] == '1' || (str[n-1] == '2'&& str[n] < '7' ) )
	{
		memo[n] += calc(str,n-2, memo);
	}

	  cout<<memo[n];
	return memo[n];
}

int main(){
	fastio;

	int quer;
	cin>>quer;
	forf(quer,qe)
	{
		int n;
		cin>>n;
		char str[n+1];
		cin>>str;

		if (n)
		int memo[n+1];
		forf(n+1,i)
			memo[i] = -1;

		memo[0] = 1;
		memo[1] = 1;

		cout<<calc(str,n,memo)<<"\n";
	}

	return 0;
}
