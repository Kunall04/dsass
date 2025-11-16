vector<int> findRepeatingElements(int arr[],int n){
    unordered_map<int,int> freq;
    vector<int>res;
    for(int ele:arr)
        freq[ele]++;
    for(auto it:freq)
        if(it.second>1)
            res.push_back(it.first);
    return res;
}