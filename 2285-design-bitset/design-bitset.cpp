class Bitset {
       
private:
    vector<int> bit;
    int cnt;
    bool fl;
    
public:
    
    Bitset(int size) {
        bit.resize(size);
        cnt = 0;
        fl = false;
    }
    
    void fix(int idx) {
        if(!fl)
        {
            if(bit[idx] == 0)
            {
                bit[idx] = 1;
                cnt++;
            }
        }
        else
        {
            if(bit[idx] == 1)
            {
                bit[idx] = 0;
                cnt++;
            }
        }
    }
    
    void unfix(int idx) {
        if(!fl)
        {
            if(bit[idx] == 1)
            {
                bit[idx] = 0;
                cnt--;
            }
        }
        else
        {
            if(bit[idx] == 0)
            {
                bit[idx] = 1;
                cnt--;
            }
        }
    }
    
    void flip() {
        fl = !fl;
        cnt = bit.size() - cnt;
    }
        
    
    bool all() {
        return cnt == bit.size();
    }
    
    bool one() {
        return cnt >= 1;
    }
    
    int count() {
        return cnt;
    
    }
    
    string toString() {
        string ans = "";
        if(!fl)
        {
            for(auto x : bit)
            {
                if(x == 0)
                    ans += '0';
                else
                    ans += '1';
            }
        }
        else
        {
            for(auto it : bit)
            {
                if(it == 0)
                    ans += '1';
                else
                    ans += '0';
            }
        }
        return ans;
    }
};
/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */