class Solution {
public:
    
	long long smallestNumber(long long num) {
        bool negative = false;
        if(num < 0)
            negative = true;
        
        vector<int> v(10,0);
        long long temp = abs(num);
        while(temp)
        {
            int rem = temp%10;
            v[rem]++;
            temp = temp/10;
        }
        if(negative == true)
        {
            for(int i=9;i>=0;i--)
            {
                while(v[i]>0)
                {
                    temp = temp*10 + i;
                    v[i]--;
                }
            }
        }
        
        else
        {
            vector<int> pos;
            for(int i=0;i<10;i++)
            {
                while(v[i]>0)
                {
                   pos.push_back(i);
                   v[i]--;
                }
            }
            
            for(int i=0;i<pos.size();i++)
            {
                if(pos[i]!=0)
                {
                    swap(pos[i],pos[0]);
                    break;
                }
            }
            for(int i=0;i<pos.size();i++)
            {
                temp = temp*10 + pos[i];
            }
            
        
        }
        
        return negative?0-temp:temp;  
    }
	
};