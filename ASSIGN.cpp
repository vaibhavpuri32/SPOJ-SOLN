#include<bits/stdc++.h>
#define f first
#define ll long long int
#define s second
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX = (1<<20)+1;
const int MOD = 1e9+7;
int mat[21][21], n;
ll dp[MAX][21];
void init(int n)
{
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++)
            dp[i][j] = -1;
    }
}

ll get_num_ways(int mask, int i)
{
    if (mask == (1<<n)-1 && i == n)
        return 1;
    if (i == n)
        return 0;
    if (dp[mask][i] != -1)
        return dp[mask][i];
    dp[mask][i] = 0;
    for (int j=0;j<n;j++)
    {
        if (mat[i][j] && (mask&(1<<j)) == 0)
            dp[mask][i] += get_num_ways(mask|(1<<j), i+1);
    }
    return dp[mask][i];
}

int32_t main()
{
    fio;
    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        init(n);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                cin>>mat[i][j];
        }
        cout<<get_num_ways(0, 0)<<"\n";
    }
}
