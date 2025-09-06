class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int i = str.size()-2;
        while(i>=0 and str[i] >= str[i+1]){
            i--;
        }
        if(i==-1) return -1;
		
        else{
            for(int j = str.size()-1;j>i;j--){
                if(str[j] > str[i]){
                    swap(str[j],str[i]);
                    break;
                }
            }
        }
        i++;
        sort(str.begin()+i,str.end());
        return stoll(str)>INT_MAX?-1:stoi(str);
    }
};