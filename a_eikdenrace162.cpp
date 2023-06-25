#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int x = n+1;
        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        int ans = -1; // Initialize ans to -1
        for (int i = n-1; i >= 0; i--)
        {
            if(a[i] < x)
                {ans++;// Update ans only if a[i] < x
            x=a[i];
        }
        }
        cout << ans << endl;
    }
    return 0;
}