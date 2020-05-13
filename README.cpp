// Remove-k-digits-to-get-smallest-number

//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

//Note:
 //The length of num is less than 10002 and will be ≥ k.
//The given num does not contain any leading zero.

//Input: num = "1432219", k = 3
//Output: "1219"
//Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

//solution using stack
// Time complexity: O(n) space complexity: O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        
    /* the idea is to store the numbers into the stack one by one and check for following  
       things:
       1. we can get smallest number only if the we store smaller elements into the stack
          k times;
       
       2. so we push the elements into the stack and check if the tos is less grater than the
        curr element to be pushed, also k is not zero, we pop the tos and push curr element
        
       3. onr exception rises when 0 is the curr elemnt and tos is any number, in this case 
          if we pushed the curr element i.e "0" we will get leading zeros.
          so we only pop thats why nums[i]!='0';
          
       4. at last we store the elements into a string and reverse and return it.
       
       Time complexity: O(n) space: O(n);    */
        
        
        
        stack<char>st;
        if(k>=num.length())
            return "0";
        
        for(int i=0;i<num.length();i++)
        {
            while(st.size()!=0&&st.top()-'0'>num[i]-'0' && k)
                     {
                        st.pop();
                        k--;
                     }
            if(st.size()!=0||num[i]!='0')
                st.push(num[i]);
            
        }
        while(st.size()!=0&&k--)
        {
            st.pop();
        }
        
        string ans="";
        if(st.size()==0)
            return "0";
        
        while(st.size()!=0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
