#include <bits/stdc++.h> 
using namespace std; 
int pageFaults(int *pageString, int pageSlots, int n) {
    int faults = 0;
    
    
    unordered_set<int> set;
    
    queue<int> q;
    
    
    for (int i = 0; i < n; i++) {
        
        if (q.size() < pageSlots) {
            if (set.find(pageString[i]) == set.end()) {
                
                
                set.insert(pageString[i]);
                
                q.push(pageString[i]);
                
                faults++;
            }
        } else {
            
            if (set.find(pageString[i]) == set.end()) {
                
                int removedPage = q.front();
                q.pop();
                
                set.erase(removedPage);
                
                
                set.insert(pageString[i]);
                
                q.push(pageString[i]);
                
                
                faults++;
            }
        }
    }
    
    return faults;
}
int main() {
    
    int pageString[] = {1, 0, 1, 2, 5, 7, 3, 4, 3, 4, 1};
    int pageSlots = 4;
    cout<<pageFaults(pageString, pageSlots, sizeof(pageString) / sizeof(pageString[0]))<<endl;
    
    return 0;
}