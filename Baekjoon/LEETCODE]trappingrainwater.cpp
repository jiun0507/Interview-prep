class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> wall;
        int water = 0;
        for(int i = 0;i<height.size();i++){
            while(!wall.empty() && height[i] > height[wall.top()]){
                int top = wall.top();
                wall.pop();
                int dist = 0;
                int boundHeight = 0;
                if(wall.empty()){
                    break;
                }
                dist = i - wall.top() - 1;
                boundHeight = min(height[i], height[wall.top()]) - height[top];
                water += dist * boundHeight;
            }
            wall.push(i);
        }
       return water;
    }
};