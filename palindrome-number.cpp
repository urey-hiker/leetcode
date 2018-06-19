class isPalindrome {
public:
    bool solve(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int y = x%10;
        if (y == 0) {
            return false;
        }
        while (y <= x) {
            if (y == x) {
                return true;
            }
            x = x / 10;
            if (y == x) {
                return true;
            }
            y = y*10 + (x%10);
            
        }
        return false;
    }
};