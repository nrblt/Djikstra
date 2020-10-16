
#include<bits/stdc++.h>


#define us using namespace std;
#define re return 0;
#define ll long long
#define st string
#define cnn(n) cin >>n;
//#define cni(a[i]) cin>>a[i];
const int maxn = (int)1e5 + 7;
const int INF = (int)1e9 + 7;

us
int  n,  b ,a[200][200],cur,u[222],s,f,mn;
int   cost[222];

int main () {
      //freopen("dijkstra.in","r",stdin);
      //freopen("dijkstra.out","w",stdout);

      cin >> n >> s >> f;

      //vector < vector < pair<int,int> > > g (n);
      for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                  cin >> a[i][j];
            }
      }

      for (int i = 1; i <= n; ++i) {
            cost[i] = INF;
      }
      cost[s] = 0;
      for (int i = 1; i <= n; ++i) {
            mn = INF;
            for (int j = 1; j <= n; ++j) {
                  if (!u[j] && cost[j] < mn) {
                        mn = cost[j];
                        cur = j;
                  }
            }

            u[cur] = 1;
            for (int to = 1; to <= n; ++to) {
                  if (a[cur][to] > 0 && !u[to]) {
                        cost[to] = min(cost[to], cost[cur] + a[cur][to]);
                  }
            }
      }
      if (cost[f] == INF) {
            cout << -1;
            re
      }
      cout << cost[f];

      re
}
