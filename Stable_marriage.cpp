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
  return v1[0] < v2[0];
}

int main(){
	fastio;

    int n;
    cin >> n;
    int women[n+1][n+1], men[n+1][n+1];
    forf(n,i)
    {
      forf(n,j)
      {
        cin >> men[i+1][j+1];
        men[i+1][j+1] -= n-1;
      }
    }
    forf(n,i)
    {
      forf(n,j)
      {
        cin >> women[i+1][j+1];
        women[i+1][j+1]++;
      }
    }

    int pair[n+1] = {0};
    int wife[n+1] = {0};
    //ini(pair,-1);
    //ini(wife,-1);
    int allMar = 0;

  while(!allMar)
  {
    int w,l,paired;
    fori(n+1,i,1)
    {
      if(wife[i])
        continue;
      fori(n+1,j,1)
      {
        w = men[i][j];
        if(!pair[w])
        {
          pair[w] = i;
          wife[i] = w;
          break;
        }
        else
        {
          l = 0;
          paired = pair[w];
          fori(n+1,k,1)
          {
            if(women[w][k] == i)
            {
              l=1;
              break;
            }

            if(women[w][k] == paired)
              break;
          }
          if(l)
          {
            pair[w] = i;
            wife[i] = w;
            wife[paired] = 0;
            break;
          }
        }
      }
    }
    allMar = 1;
    forf(n,i)
    {
      if(!pair[i+1] || !wife[i+1])
      {
        allMar = 0;
        break;
      }
    }
  }

  vector< vector<int> > final(n);
  forf(n,i)
  {
    final[i].pb(wife[i+1] + n -1);
    final[i].pb(i);
  }

  sort(all(final), sortcol);

  cout<<"WOMEN MEN\n";
    forf(n,i)
    {
      cout<<final[i][0]<<"\t"<<final[i][1]<<"\n";
    }

	return 0;
}
