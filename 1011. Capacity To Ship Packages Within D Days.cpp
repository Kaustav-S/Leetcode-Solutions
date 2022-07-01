class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(possible(weights,mid,days))
            {
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    bool possible(vector<int>& weights,int x,int days)
    {
        int d=1,currcap=0;
        for(int i=0;i<weights.size();i++)
        {
            currcap+=weights[i];
            if(currcap>x)
            {
                d+=1;
                currcap=weights[i];
            }
        }
        if(d<=days)
        {
            return true;
        }
        else {
            return false;
        }
    }
};