class Solution {
  public:
    struct Choice{
        char dir;
        int dy,dx;
    };
  
    bool isSolved(int x,int y,int n) {
        if(x==n-1 && y==n-1) return true;
        else return false;
    }
    
    bool isValid(int x,int y,int n, const vector<vector<int>>& arr) {
        return x>=0 && x<n && y>=0 && y<n && arr[x][y]==1;
    }
  
    void solve(int x,int y,const int n, vector<string>&res, string& path, vector<vector<int>>&arr, const vector<Choice>& choices) {
        if(isSolved(x,y,n)) {
            res.push_back(path);
            return;
        }
        
        for(const auto& choice: choices) {
            int newx=x+choice.dy;
            int newy=y+choice.dx;
            
            if(isValid(newx,newy,n,arr)) {
                arr[x][y]=0;
                path.push_back(choice.dir);
                
                solve(newx,newy,n,res,path,arr,choices);
                
                arr[x][y]=1;
                path.pop_back();
            }
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<string>res;
        string path="";
        vector<Choice> choices={
            {'D', 1, 0},
            {'L', 0, -1},
            {'R', 0, 1},
            {'U', -1, 0}
        };
        
        if(arr[0][0]==1) 
            solve(0,0,n,res,path,arr,choices);
            
        return res;
    }
};