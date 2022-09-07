#include<bits/stdc++.h>
using namespace std;

#define NPP 5
#define NRR 3

struct proc
{
    int np = NPP;
    int flag[NPP];
    int allocated[NPP][NRR] = { {0, 1, 0},
					  {2, 0, 0},
					  {3, 0, 2},
					  {2, 1, 1},
					  {0, 0, 2} };

    int maxneed[NPP][NRR]= { {7, 5, 3},
					 {3, 2, 2},
					 {9, 0, 2},
					 {4, 2, 2},
					 {5, 3, 3} };

    int tobefilled[NPP][NRR]; // const = max need - allocated 

    proc()
    {
        for (int i = 0; i < NPP; i++)
        {
            for (int j = 0; j < NRR; j++)
                tobefilled[i][j] = maxneed[i][j] - allocated[i][j];
        }
        for(int i=0; i<np; i++)
            flag[i] = 0;
    }
};

struct reso
{
    // int maxhave[NRR];
    int available[NRR] = { 3, 3, 2 }; // r1.available = r1.maxhave - sum(p1.allocated); 
};

// void add(int inp1[NRR][NPP], int inp2[NRR][NPP], int out[NRR][NPP], int x, int y)
// {
//     for(int i=0; i<x; i++)
//     {
//         for(int j=0; j<y; j++)
//         {
//             out[x][y] = inp1[x][y] + inp2[x][y];
//         }
//     }
// }

// void sub(int inp1[NRR][NPP], int inp2[NRR][NPP], int out[NRR][NPP], int x, int y)
// {
//     for(int i=0; i<x; i++)
//     {
//         for(int j=0; j<y; j++)
//         {
//             out[x][y] = inp1[x][y] - inp2[x][y];
//         }
//     }
// }

int main()
{
    // intput all values;
    // input finishes
    struct reso r1;
    struct proc p1;


    bool fullfilled = false;

    while(!fullfilled)
    {
        for(int i=0; i<NPP; i++)
        {
            if (p1.flag[i] == 0)
            {
                bool ans = (p1.tobefilled[i][0] < r1.available[0]) && (p1.tobefilled[i][1] < r1.available[1]) && (p1.tobefilled[i][2] < r1.available[2]);
                cout << ans << endl;
                if(ans)
                {
                    cout << "P" << i+1 << "->";

                    p1.flag[i] = 1;
                    r1.available[0] += p1.allocated[i][0];
                    r1.available[1] += p1.allocated[i][1];
                    r1.available[2] += p1.allocated[i][2];
                }
            }       
        }

        fullfilled = true;
        for(int i=0; i<p1.np; i++)
        {
            if(p1.flag[i] == 0)
            {
                fullfilled = false;
                break;
            }
        }

    }
}

