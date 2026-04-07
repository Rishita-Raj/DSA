class Robot {
private:
    int w, h;
    int x, y;
    int dir; // 0=E,1=N,2=W,3=S

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; // East
    }
    
    void step(int num) {
        
        int perimeter = 2 * (w + h) - 4;
        num %= perimeter;
        
        // Special case
        if (num == 0) {
            if (x == 0 && y == 0) {
                dir = 3; // South
            }
            return;
        }
        
        while (num > 0) {
            
            if (dir == 0) { // East
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            }
            else if (dir == 1) { // North
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            }
            else if (dir == 2) { // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            }
            else { // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */