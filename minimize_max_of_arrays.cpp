//https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {

        div1=divisor1,div2=divisor2,cnt_1=uniqueCnt1,cnt_2=uniqueCnt2;
        lcm_ans=lcm(div1,div2);

        unsigned long long left=1,right=INT_MAX,mid;
        while(left<right)
        {
            mid=(left+right)/2;
            if(enough(mid))
                right=mid;
            else
                left=mid+1;
        }
        return left;
    
    }
    bool enough(int end)
    {
        if((end - end/div1)< cnt_1 ||
            (end-end/div2)< cnt_2 ||
            (end-end/lcm_ans)<(cnt_1+cnt_2))
            return false;
        else
            return true;

    }
private:
    unsigned long long div1,div2,cnt_1,cnt_2;
    unsigned long long lcm_ans;
};
