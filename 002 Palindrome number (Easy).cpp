class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        int a = x;
        int result = 0;
        while (x != 0) {
            int ld = x % 10;

            if ((result < INT_MIN / 10) || (result > INT_MAX / 10)) {return 0;}

            result = result * 10 + ld;
            x = x / 10;
        }
        if (result == a)
            {return true;}
        else
            {return false;}
    }
};
