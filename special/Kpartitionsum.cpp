#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& a,int sum){
    int n=a.size();
    vector<vector<bool>> t(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;i++) t[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]>j) t[i][j]=t[i-1][j];
            else t[i][j]=t[i-1][j]||t[i-1][j-a[i-1]];
        }
    }
    return t[n][sum];
}

bool partition(vector<int>& a){
    int sum=0;
    for(int x:a) sum+=x;
    if(sum&1) return false;
    return subsetSum(a,sum/2);
}

int main(){
    vector<int> a={7,3,1,5,4,8};
    if(partition(a)) cout<<"Set can be partitioned";
    else cout<<"Set cannot be partitioned";
}
