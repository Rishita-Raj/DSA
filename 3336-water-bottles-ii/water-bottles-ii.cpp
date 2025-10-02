class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = 0;
        int empty = 0;

        while (numBottles > 0) {
            drank += numBottles;
            empty += numBottles;
            numBottles = 0;

            if (empty >= numExchange) {
                empty -= numExchange;  
                numBottles = 1;        
                numExchange++;        
            }
        }

        return drank;
    }
};