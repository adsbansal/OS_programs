// LOOK
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sdisk = 199;
    int nr = 8;
    int req[nr] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;

    sort(req, req+nr);

    int mid=0;
    for(int i=0; i<nr; i++)
    {
        if(req[i]>head)
        {
            mid = i;
            break;
        }
    }

    cout << mid << endl;
    
    int dis = (req[nr-1] - head) + (req[nr-1] - req[0]);
    

    cout << head << " -> ";
    for(int i=mid; i<nr; i++)
    {
        cout << req[i] << "-> ";
    }

    for(int i=(mid-1); i>-1; i--)
    {
        cout << req[i] << "-> ";
    }

    cout << endl << "Head mov : " << dis << endl;
}