class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
    int ans = 0; 
    for(int i  = 0; i<tickets.size(); i++)
    {
        if(i!=k)
        {
            if(i<k)ans+= min(tickets[i], tickets[k]);
            else
                {
                    if(tickets[i]<tickets[k])ans+=tickets[i];
                    else if(tickets[i]==tickets[k])ans+= tickets[k]-1;
                    else ans+=tickets[k]-1;
                }
        }
        else
        {
            ans += tickets[k];
            cout<<ans;
        }
    }
    return ans;   
    }
};