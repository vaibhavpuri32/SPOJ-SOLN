#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, i, j;
    while (true)
    {
        string s;
        cin >> s;
        if (s == "0")
        {
            exit(0);
        }
        ll n = s.length();
        ll dp[n + 2];
        dp[0] = 1;
        dp[1] = 1;
        for (i = 2; i <= n; i++)
        {
            dp[i] = 0;
            char c1 = s[i - 2];
            int c2 = s[i - 1];
            if (c1 == '1' || (c1 == '2' && c2 <= '6'))
                { dp[i] = dp[i - 2]+dp[i];}
            if (c2 != '0')
                dp[i] = dp[i - 1] + dp[i];
        }
        cout << dp[n] << "\n";
    }
    return (0);
}
