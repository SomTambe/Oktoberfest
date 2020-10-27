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

#define ini(a,i) memset(a, i, sizeof(a))

#define forf(n,x) for(int x = 0; x < n; ++x)
#define forb(n,x) for(int x = n-1; x >= 0; --x)
#define fori(n,x,i) for(int x=i; x<n; ++x)

#define all(c) c.begin(), c.end()
#define itr(c,it) for( auto it = c.begin(); it != c.end(); ++it)

typedef priority_queue <int> pq;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
  return v1[0]*v1[1] < v2[0]*v2[1];
}

int main()
{
	fastio;

  int n;
  cin>>n;
  vector < vector <int> > arr(3*n);
  int a,b,c,mini,maxi,midi;
  for(int i = 0; i < 3*n; i += 3)
  {
    cin>>a>>b>>c;
    midi = a+b+c;
    maxi = max(a,max(b,c));
    mini = min(a,min(b,c));
    midi -= mini + maxi;
    arr[i].pb(midi);arr[i].pb(mini); arr[i].pb(maxi);
    arr[i+1].pb(maxi);arr[i+1].pb(mini); arr[i+1].pb(midi);
    arr[i+2].pb(maxi);arr[i+2].pb(midi); arr[i+2].pb(mini);
  }

  n *= 3;

  sort(all(arr), sortcol);

  vector<int> maxHeight(n);
  forf(n,i)
  {
    maxHeight[i] = arr[i][2];
    forf(i,j)
    {
      if(arr[i][1] > arr[j][1] && arr[i][0] > arr[j][0] && maxHeight[i] < maxHeight[j] + arr[i][2])
        maxHeight[i] = maxHeight[j] + arr[i][2];
    }
  }

  sort(all(maxHeight));
  cout<<maxHeight[n-1]<<"\n";

  return 0;
}
