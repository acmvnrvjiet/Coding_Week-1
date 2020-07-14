/*
https://leetcode.com/problems/happy-number/
Definition of a Happy Number :- A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of 
                                the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle
                                which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 @Solution Author : Madhurendra Tripathy
 
 LET'S OBSERVE THE EXAMPLES BELOW :
 Example-1:
 Input: 20
 Output: false
 Explanation:
 2^2 + 0^2 = 4
 4^2 = 16
 1^2 + 6^2 = 37
 3^2 + 7^2 = 58;
 5^2 + 8^2 = 89
 8^2 + 9^2 = 145
 1^2 + 4^2 + 5^2 = 42
 4^2 + 2^2 = 20
 2^2 + 0^2 = 4 -- repeated
 4^2 = 16  -- repeated
 1^2 + 6^2 = 37 -- repeated
 3^2 + 7^2 = 58 -- repeated
 5^2 + 8^2 = 89 -- repeated
 8^2 + 9^2 = 145 -- repeated
 1^2 + 4^2 + 5^2 = 42 -- repeated
 4^2 + 2^2 = 20 -- repeated
 Same cycle continues again & again indefinitely.
 Here given input(20) leads to infinite looping while being checked for it being a Happy Number and it will never reach 1. Hence answer is false
 
 Example-2:
 Input: 19
 Output: true
 Explanation:
 1^2 + 9^2 = 82
 8^2 + 2^2 = 68
 6^2 + 8^2 = 100
 1^2 + 0^2 + 0^2 = 1
 Here for given input(19) none of the Squared Digits Sum values repeated and we eventualy reached 1. Hence the answer is true
 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
 
 CONCLUSION : HENCE IF A NUMBER IS HAPPY THEN ITS SQUARED DIGITS SUM VALUES WILL NEVER RESULT IN REPETITION/CYCLE AND WILL EVENTUALLY REACH 1
 
 SOLUTION : We can use a "SET" and keep the track of all the Squared Digits Sum values,
            for every newly generated Squared Digits Sum value of "n" we can check if we have already encountered this value previously,
            if yes then we can conclude that from this point we will land into an infinite loop and the given number is not Happy,
            else we can conclude that the given number is a Happy Number.
 
 NOTE :
 1. Instead of using a "SET" we can also implement the same by storing the Squared Digits Sum values in an "ARRAY"
    and sorting it everytime we insert a new value to the array,and then searching for repetetion can be done applying a "Binary Search".
    
 2. "SET" does the same for us automatically, it automatically sorts its contents, removes the duplicates(if any) and the predefined
    search on a set (which is set.find(...) method/function) is a binary search as its contents are always sorted.
 3. Time Complexity of Binary Search is O(log2 N) which is much better than Traditional Search whose Time Complexity is O(N).
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


class Solution {    
public:
    //Constructor for the class
    Solution(){
        FAST_IO; /*FAST_IO is replaced with ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); as defined in the macros,
                   the replacement occurs during compile time, this enhances the speed of Input & Output operations(cin & cout) of CPP,
                   there by resulting in smaller runtime of the program*/
    }
    
    //Function to Square and Add the digits of a number
    int DigitsSquareSum(int n){ // "n"(received as the argument) is the number whose digits are to be squared first and then added
        
        int ans = 0; //initiaising our final answer variable
        
        while(n){ // The loop runs until "n!=0" it can also be written as, while(n!=0){...} or while(n>0){...}
            int x = n%10; // n%10 results is the last digit(digit in one's place) of "n", here it is stored in "x"
            ans+=(x*x); // squaring the last digit "x", and then adding it to the ans, this can also be written as, "ans=(ans+(x*x));"
            n/=10; // Integer Division "n" by 10, this simply removes the last digit form "n". It can also be written as "n=(n/10);"
        }
        
        return ans; // returning the ans after complete calculation
    }
    
    bool isHappy(int n) {
        set<int>st; //Declaration of a new set
        st.insert(n); //Inserting "n" into the set
        while(n!=1){ //Running the loop until n becomes 1
            int new_value_of_n = DigitsSquareSum(n); // Fetching the Squared Digits Sum and storing it as "new_value_of_n"
            
            if(st.find(new_value_of_n)!=st.end()){ //"st.find(new_value_of_n)!=st.end()" implies that the "new_value_of_n" is already found in the set, which means "n" never reach to "1" as the Squared Digits Sum values will loop infinitely from this point onwards
                
                return false; // as we can never reach 1 returning false
            }
            else{ //if "new_value_of_n" is not found in the set, we should insert it in the set so that we can check for infinite looping on later Squared Digits Sum values
                st.insert(new_value_of_n);
            }

            n=new_value_of_n; // assigning "new_value_of_n" to "n"
        }
        
        return true; // if the control reaches this point, that means "n==1" and hence we return true.
    }
};

/*Do not write the driver code in the leetcode's editor, as it is already coded but hidden, Just Implement the Class Solution*/
//driver code
int main(){
    FAST_IO; //Faster Input/Output(cin & cout)
    Solution s; // Creating an object of Solution class
    cout<<s.isHappy(20)<<"\n"; // Calling "isHappy" function and printing the retiurned answer.
    return 0;
}
