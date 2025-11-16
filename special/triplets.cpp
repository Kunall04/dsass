void triplets(vector<int>& a,int sum){
    sort(a.begin(),a.end());
    int n=a.size();
    for(int i=0;i<=n-3;i++){
        int low=i+1,high=n-1;
        while(low<high){
            if(a[i]+a[low]+a[high]>sum){
                high--;
            }
            else{
                for(int x=low+1;x<=high;x++){
                    cout<<"("<<a[i]<<","<<a[low]<<","<<a[x]<<")\n";
                }
                low++;
            }
        }
    }
}
