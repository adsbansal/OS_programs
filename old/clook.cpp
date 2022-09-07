// c-LOOK
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sdisk = 199;
    int nr = 8;
    int req[nr] = {95, 180, 34, 119, 11, 123, 62, 64};
    int head = 50;

    sort(req, req+nr);

    // for(int i=0; i < nr; i++)
    // {
    //     cout << req[i] << endl;
    // }

    int mid=0;
    for(int i=0; i<nr; i++)
    {
        if(req[i]>head)
        {
            mid = i;
            break;
        }
    }

    // cout << mid << endl;
    
    int dis = (req[nr-1] - head) + (req[nr-1] - req[0]) + (req[mid-1] - req[0]);
    

    cout << head << " -> ";
    for(int i=mid; i<nr; i++)
    {
        cout << req[i] << " -> ";
    }

    // come to end 

    for(int i=0; i<mid; i++)
    {
        cout << req[i] << " -> ";
    }

    cout << " end";
    cout << endl << "Head mov : " << dis << endl;
}