#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n + 2][m + 2];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        ll dp[n + 2][m + 2];
        for (i = 0; i < m; i++)
        {
            dp[0][i] = a[0][i];
        }
        ll Max = -inf;
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                dp[i][j] = a[i][j] + max(dp[i - 1][j], max((j == 0 ? 0 : dp[i - 1][j - 1]), (j == m - 1 ? 0 : dp[i - 1][j + 1])));
            }
            
        }

        for(i=0; i<m; i++)
           Max = max(Max,dp[n-1][i]);
        cout << Max << "\n";
    }

    return (0);
}