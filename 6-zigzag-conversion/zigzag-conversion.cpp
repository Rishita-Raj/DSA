class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) return s;
        vector<string> row(numRows);
        int currentRow =0;
        bool goingDown = false;
        for(char c: s){
            row[currentRow] += c;
            if(currentRow == 0 || currentRow == numRows-1)
            goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;}
            string result;
            for(string& rows :row)
            result += rows;
        
            return result; 
    }
};