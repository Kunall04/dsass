//Method 1:

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int> freq;
// Store the frequencies of elements in a map
        for(int ele:nums){
            freq[ele]++;
        }

// Find the maximum frequency
        int maxi=0;
        for(auto &it:freq){
            if(it.second>maxi)
                maxi=it.second;
        }

// Find the result
        for(auto it:freq){
            if(it.second==maxi)
                res+=it.second;
        }
        return res;       
    }
};


//Method 2:

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,frequency=0;
        unordered_map<int,int> freq;

// Store the frequencies of elements in a map 
        for(int ele:nums){
            freq[ele]++;
        }

// Find the maximum frequency and the number of elements having that frequency
        for(auto& it:freq){
            if(it.second==frequency)
                cnt++;
            else if(it.second>frequency){
                frequency=it.second;
                cnt=1;
            }
        } 
        return cnt*frequency;      
    }
};
