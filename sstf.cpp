// LOOK
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sdisk = 199;
    int nr = 8;
    int flag[nr];

    for(int i=0; i<nr; i++)
        flag[i]=0;
    
    int req[nr] = {95, 180, 34, 119, 11, 123, 62, 64};
    int head = 50;

    sort(req, req+nr);

    cout << head << " -> ";
    int here = head;


    int sum = 0;
    for(int i=0; i<nr; i++)
    {
        int min = sdisk;
        int minpos = -1;
        for(int j=0; j<nr; j++)
        {
            if(flag[j]!=1)
            {
                minpos = j;
                break;
            }
        } 
        if(minpos == -1)
        {
            break;
        }

        for(int j=0; j<nr; j++)
        {
            if(min > abs(here-req[j]) && flag[j]!=1)
            {
                min = abs(here-req[j]);
                minpos = j;
            }
        }
        flag[minpos] = 1;
        sum += abs(here-req[minpos]);
        cout << req[minpos] << "-> ";
        here = req[minpos];
    }

    cout << endl << "Head mov : " << sum << endl;
}