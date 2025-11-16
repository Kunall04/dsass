//Time Complexity: O(n^2) in the worst case and
//                 O(n) in the best case
//where n is the size of the input vector

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){ //number of passes (Each pass push the biggest element to the last)
            bool swapped=false;
            for(int j=0;j<n-i-1;j++){ //traversing the array
                if(arr[j]>arr[j+1]){
                    swap(arr[j+1],arr[j]);
                    swapped=true;
                }
            }
            if(!swapped)
                return;
        }
    }
};