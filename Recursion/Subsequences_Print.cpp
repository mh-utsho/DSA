#include <bits/stdc++.h>
using namespace std;
 

void printF(int id,vector<int>&v,int n,int arr[]){
    if(id==n){
        cout<<"{"; 
        for(auto &x:v){
            cout<<x<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    // Include arr[id] in the subset
        v.push_back(arr[id]);
        printF(id+1,v,n,arr);

   // Exclude arr[id] from the subset
        v.pop_back();
        printF(id+1,v,n,arr);
    
}
 //----------------main---------------------------------
 signed main(){
     int n=4;
     int arr[4]={1,3,2,4};
     vector<int>v;
     printF(0,v,n,arr);
 }





 