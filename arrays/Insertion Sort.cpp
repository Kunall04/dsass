//Time Complexity: O(n^2) in the worst case and
//                 O(n) in the best case
//where n is the size of the input vector

class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            int ele=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>ele){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=ele;
        }
    }
};