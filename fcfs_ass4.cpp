#include<bits/stdc++.h>
using namespace std;

int main()
{
    int at[10], bt[10], wt[10], tt[10], n;
    int burst=0, cmp;
    float avgwt, avgtt, total=0;

    cout << "No. of processes: ";
    cin >> n;
    cout << "AT\t BT" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> at[i] >> bt[i];
    }

    for(int i=0; i<n; i++)
    {
        if(i==0)
            wt[i]=at[i];
        else
            wt[i]=burst-at[i];
        burst+=bt[i];
        total+=wt[i];
    }
    avgwt=total/n;

    cmp=0;
    total=0;
    for(int i=0; i<n; i++)
    {
        cmp += bt[i];
        tt[i]=cmp-at[i];
        total+=tt[i];
    }

    avgtt=total/n;


    cout << "process \t wt \t ta" << endl;
    for(int i=0;i<n;i++)
    {
        cout << i << "\t" << wt[i] << "\t" << tt[i] << endl;
    }
    cout << "avg wt" << avgwt << endl;
    cout << "avg tt" << avgtt << endl;
    return 0;
}