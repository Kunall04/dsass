//Time Complexity: O(n^2) where n is the size of the input vector 

class Solution {
  public:
    void selectionSort(vector<int> &arr) {

        for(int i=0;i<arr.size()-1;i++){
            int min_idx=i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[min_idx]>arr[j])
                    min_idx=j; 
            }
                swap(arr[i],arr[min_idx]);
        }
    }
};