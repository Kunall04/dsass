//Time Complexity: O(n-m) = O(n) where n is the size of the input array

void reverseArray(vector<int> &arr , int m) {
    int st=m+1;
    int end=arr.size()-1;
    while(st<=end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
}
