#include<bits/stdc++.h>
using namespace std;
#define max 10

struct mainmem
{
    int flags[max];
    int all[max];
    int blocks[max];
    int nb;

    mainmem()
    {
        for(int i=0; i<max; i++)
        {
            flags[i] = 0;
            all[i] = -1;
        }

        cout << "Enter the number of blocks: ";
        cin >> nb;
        
        cout << "Enter the size of each block: ";
        for(int i=0; i<nb; i++)
        {
            cin >> blocks[i];
        }
    }
};

struct process
{
    int pro[max];
    int np;

    process()
    {
        cout << "Enter number of processes to be put: ";
        cin >> np;

        cout << "Enter size of each process";
        for( int i=0; i< np; i++)
        {
            cin >> pro[i];
        }
    }

};

int main()
{
    cout << "FirstFit\n";
    struct mainmem mainmem1;
    struct process process1;

    for(int i=0; i<process1.np; i++)
    {
        for(int j=0; j<mainmem1.nb; j++)
        {
            if(mainmem1.flags[j] == 0 && mainmem1.blocks[j]>=process1.pro[i])
            {
                mainmem1.all[j] = i;
                mainmem1.flags[j] = 1;
                break;
            }
        }
    }

    cout << "\nBlock no.\tsize\tprocess no.\t\tsize";
    for(int i=0; i<mainmem1.nb; i++)
    {
        cout << "\n" << i+1 << "\t\t" << mainmem1.blocks[i] << "\t\t";
        if(mainmem1.flags[i] == 1)
        {
            cout << mainmem1.all[i]+1 << "\t\t" << process1.pro[mainmem1.all[i]];
        }
        else{
            cout << "Not allocated";
        } 
        cout << endl;
    }
}


// https://technicalpickout.com/c-code-first-fit-best-fit-worst-fit/