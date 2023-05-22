//  collaborated with Alanna Anna Shibu a1867096 and Armaan Bahree a1843711
#include <bits/stdc++.h>
#include <vector>
using namespace std;
  

int kth_largest(vector<int> values, int k){
    priority_queue<int> pq(values.begin(), values.end());
    for (int i=0;i<k-1;i++){
        pq.pop(); 
    }
    return pq.top();
}