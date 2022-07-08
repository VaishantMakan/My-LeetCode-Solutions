class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int>ans;
        
        stack<int>s;
        
        int n = asteroids.size();
        
        for(int i=0;i<n;i++)
        {
            if(asteroids[i] > 0)
                s.push(asteroids[i]);
            else
            {
                bool flag = 1;
                
                while(!s.empty())
                {
                    int temp = s.top();
                    if(temp < 0)
                    {
                        s.push(asteroids[i]);
                        break;
                    }
                    else if(temp == abs(asteroids[i]))
                    {
                        s.pop();
                        flag=0;
                        break;
                    }
                    else if(temp > abs(asteroids[i]))
                    {
                        break;
                    }
                    else if(temp < abs(asteroids[i]))
                    {
                        s.pop();
                    }
                }
                
                if(s.empty() &&  flag)
                    s.push(asteroids[i]);
            }
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};