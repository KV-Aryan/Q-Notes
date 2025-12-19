class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n1=num+1;
        int n2=num+2;
        for(int i=sqrt(n2);i>=1;i--){      //the middle divisor is always less than or equal to sqrt
            if(n1%i==0){
                return {n1/i,i};
            }if(n2%i==0){
                return {n2/i,i};
            }
        }return {};
    }
};
