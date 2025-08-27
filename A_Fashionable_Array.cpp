/*
Problem Link
https://codeforces.com/problemset/problem/2110/A
*/


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

        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);
        int mn = a[0];
        int mx = a[n-1];

        //Checking if both of mininum and maximum are even or orr; couse (even+even)=even & (odd+odd)=even;
        //Counting how manu operations we need to make a fashionable array;
        if(mn%2 == mx%2)
            cout << 0 << endl;
        else
        {
            int i = 0, cnt1 = 0;
            while(a[i]%2 != mx%2)
            {
                i++;
                cnt1++;
            }

            int j = n-1, cnt2 = 0;
            while(a[j]%2 != mn%2)
            {
                j--;
                cnt2++;
            }

            cout << min(cnt1, cnt2) << endl;

        }

    }
    return 0;
}
