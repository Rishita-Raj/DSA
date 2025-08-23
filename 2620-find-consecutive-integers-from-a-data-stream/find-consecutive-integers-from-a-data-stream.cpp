class DataStream {
public:
    int cnt = 0, v, K;
    DataStream(int value, int k) {v = value, K = k;}
    bool consec(int num) {
        if(v == num) cnt++;
        else cnt = 0;
        if(cnt >= K) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */