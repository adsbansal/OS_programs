#include<bits/stdc++.h>
using namespace std;
#define MAX 10

// input mainmemory and it's numbeer and size of block 
// input processes and their size and number 

struct mainmem{
    int store[MAX];
    // int flag[MAX];
    int size[MAX];
    int nb;

    mainmem()
    {
        cout << "Enter the number of blocks in mainmem : ";
        cin >> nb;

        cout << "Enter the size of each block in mainmem : ";
        for(int i=0; i<nb; i++)
        {
            store[i] = 0;
            cin >> size[i];
        }
    }
};

struct process{
    int store[MAX];
    int np;

    process()
    {
        cout << "Enter the number of process : ";
        cin >> np;

        cout << "Enter the size of each process : ";
        for(int i=0; i<np; i++)
        {
            cin >> store[i];
        }
    }
};


int main()
{
    struct mainmem mem1;
    struct process ps1;
    
    for(int p=0; p<ps1.np; p++)
    {
        int sizep = ps1.store[p];

        int minpos = 0;
        int mindis = 10000;
        int dis;
        for(int m=0; m<mem1.nb; m++)
        {
            dis = mem1.size[m] - sizep;
            if(dis > 0 && mindis > dis)
            {
                mindis = dis;
                minpos = m;
            }

        }

        mem1.store[minpos] = p + 1;
        mem1.size[minpos] -= ps1.store[p];

    }

    for(int m=0; m<mem1.nb; m++)
    {
        cout << mem1.store[m] << "\t\t";
    }
    cout << endl;
}