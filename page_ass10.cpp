#include<iostream>
using namespace std;

int main()
{
        int ms;
        cout << "MemorySize? :";
        cin >> ms;
        
        int ps;
        cout << "PageSize?: ";
        cin >> ps;

        int nop = ms/ps;

        int np;
        cout << "No. Pocesses: ";
        cin >> np;

        int rems = nop;

        int ppp[10];
        int pt[10][10];
        for(int i=0; i<np; i++)
        {
            cout << "P" << i << " pages req.: ";
            cin >> ppp[i];
            if(rems<ppp[i])
            {
                cout << "mem full\n";
                break; 
            }
            rems-=ppp[i];
            cout << "pg table for P" << i << ":";
            for(int j=0; j<ppp[i]; j++)
            {
                cin >> pt[i][j];
            }
        }

        int x, y, z;
        cout << "Enter the logical add: \n";
        cout << "Enter the process number: ";
        cin >> x;
        cout << "Enter page number: ";
        cin >> y;
        cout << "Enter offset: ";
        cin >> z;

        int padd=(pt[x][y]*ps)+z;
        cout << padd << endl;
}