/*https://practice.geeksforgeeks.org/problems/jumping-numbers/0
Problem Statement : 

Solution's Author : Madhurendra Tripathy

SOLUTION : 
1. It is already been clearly specified in the problem statement that "All the single digit numbers are Jumping Numbers".
2. Now once we are clear with the above point, let's analyse how can we generate other Jumping Numbers from an previously/already known Jumping Numbers.
    → Assume "x" to be a single digit jumping number => "x" can hold 10 different values ranging from 0 to 9 :
    → Assume "y" to be another single digit number whose value is x-1
    → Assume "z" to be another single digit number whose value is x+1
    → Let's analyse how does "x" behaves for all the 10 different values, while generating jumping numbers from it:
        (a) if(1<=x<=8): 
            → Two new jumping numbers can be formed from x which are : "xy" & "xz" (Here "xy" & "xz" represent a "Two Digit Number" each. It is not multiplication of x with either y or z)
            Example1: Consider "x" to be 7 => as discussed above "y" becomes 6, and "z" becomes 8.
                     =>Two new Jumping Numbers are xy,xz which are 76 & 78 respectively.
            Example2: Consider "x" to be 3 => as discussed above "y" becomes 2, and "z" becomes 4.
                     =>Two new Jumping Numbers are xy,xz which are 32 & 34 respectively.
            Example3: Consider "x" to be 2 => as discussed above "y" becomes 1, and "z" becomes 3.
                     =>Two new Jumping Numbers are xy,xz which are 21 & 23 respectively.
            Example4: Consider "x" to be 5 => as discussed above "y" becomes 4, and "z" becomes 6.
                     =>Two new Jumping Numbers are xy,xz which are 54 & 56 respectively.

        (b) if(x==0):
            → Only one new jumping number can be formed from "x", which is : "xz" (Here "xz" represents a "Two Digit Number")
            → "xy" cannot be considered as a Jumping Number as x==0 => y==-1 and "xy"(Here "xy" represents a "Two Digit Number" which is concatenation of 0 and -1) becomes meaningless and it neither fits in the definition of Jumping Number.
            Example: If "x" is 0 => as discussed above "y" becomes -1, and "z" becomes 1.
                     =>The new Jumping Number is xz which is 01.
        
        (b) if(x==9):
            → Only one new jumping number can be formed from "x", which is : "xy" (Here "xy" represents a "Two Digit Number")
            → "xz" cannot be considered as a Jumping Number as x==9 => z==10 and "xz"(Here "xz" becomes a "Three Digit Number" which is 910) and it does not fit in the definition of Jumping Number.
            Example: If "x" is 9 => as discussed above "y" becomes 8, and "z" becomes 10.
                     =>The new Jumping Number is xy only, which is equal to 98, as xz which is 910 is not a Jumping Number
    → Now that we are clear with generating Jumping Numbers from a known single digit Jumping Number, now generating Jumping Numbers from already
      known any "n" digit Jumping Number just requires some tweaking. Extract the last digit of that "n" digit number and just assume that to be "x",
      and now as "x" is now a single digit number we know how to handle it.
        Example :   Assume that we have encountered "12" is a two digit Jumping Number => last digit is 2
                    Now if x==2 => y==1 and z==3, There for newly generated Jumping Numbers are "121" and "123",
                    Similarly if we now generate jumping numbers from "121", it generates "1210" and "1213" as the new Jumping Numbers,
                    Similarly if we now generate jumping numbers from "1210", it generates "12101" as the new Jumping Number.


    CONCLUSION : Start from single digit Jumping Numbers (Store all single digit numbers from 0 to 9  in a SET & in a QUEUE as well, now for every front element of the
                 QUEUE, pop it out and generate possible Jumping Numbers form it, INSERT all the newly generated numbers in the SET and PUSH them into the queue as well,
                 In the process of generating Jumping Numbers if your Jumping Number exceeds given limit "n" do not consider it & neither perform INSERT & PUSH operatios 
                 for that particilar Jumping Number. By the time your QUEUE gets completely empty all the Jumping Numbers are stored in the SET. Finally print the values in the set.

    NOTE :  Mathematically we can concatenate a digit "D"(D>0) to any N digit number(N>0) by, multiplying the N digit number number by 10 and then adding "D" to the result.
            Example1 : To concatenate "1" to "12" inorder to make it "121" : 
                      Multiply 12 with 10 => Reslut is 120
                      Now add 1 to the Result and it becomes 121

            Example2 : To concatenate "1" to "101010" inorder to make it "1010101" : 
                      Multiply 101010 with 10 => Reslut is 1010100
                      Now add 1 to the Result and it becomes 1010101

*/

#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

set<ll> st;
void GenerateJumpingNumbers(ull n){ // Function to generate and insert all Jumping Numbers into the SET
    if(n<=10){ //Basic Case
        for(ll i=0;i<=n;i++){
            st.insert(i);
        }
        return;
    }
    queue<ll> q; // QUEUE to process all the newly generated Jumping Numbers
    for(int i=0;i<=10;i++){ // Push all single digit numbers into QUEUE and INSERT them in the set as they are considered to be Jumping Numbers
        st.insert(i);
        q.push(i);
    }
    while(!q.empty()){ // Process all the Jumping Numbers in the QUEUE
        ll num = q.front(); // Select the number in the front of the queue
        q.pop(); // Removing it will now be processed
        ll last_digit = num%10; // Extracting last digit
        ll child1=-1,child2=-1; // child1 and child2 are two possible new Jumping Numbers

        //The logic of generating new Jumping Numbers from already available Jumping Numbers in the queue
        if(last_digit==9){
            child2 = (num*10)+(last_digit-1);
        }
        else if(last_digit==0){
            child1 = (num*10)+(last_digit+1);
        }
        else{
            child1 = (num*10)+(last_digit+1);
            child2 = (num*10)+(last_digit-1);
        }
        if(child1!=-1 && child1<=n){
            q.push(child1);
            st.insert(child1);
        }
        if(child2!=-1 && child2<=n){
            q.push(child2);
            st.insert(child2);
        }
    }
}

//driver code
int main(){
    FAST_IO; // FAST_IO is replaced with "ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);" as defined in the macros, this enhances the speed of Input & Output operations(cin & cout) of CPP
    ll t;cin>>t; // Reading number of testcases
    while (t--) { // Runs until all given number of test cases are processed
        ll n;cin>>n;
        st.clear(); //Clearing the set for each new TestCase
        GenerateJumpingNumbers(n); // Call to generate the Jumping Numbers
        set<ll> :: iterator it; // Iterator declaration
        for(it=st.begin();it!=st.end();it++){ //Iterating over all the values of the Globally Declared SET.
            cout<<(*it)<<" "; // Printing the contents
        }
        cout<<"\n";
    }
    return 0;
}
