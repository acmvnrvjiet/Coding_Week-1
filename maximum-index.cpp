/*
https://practice.geeksforgeeks.org/problems/maximum-index/0
Problem Statement : Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Solution's Author : Madhurendra Tripathy

SOLUTION :- The problem statement clearly states that the maximum value of j-i is to be found such that A[i] <= A[j], to start with, consider the final answer
            to be the maximum possibe difference which is difference between the last and first index (j==n-1 and i==0) which is n-1, now check if the condition 
            A[i] <= A[j] is satisfied, if yes then we have our answer right away, else we will repeatedly decrement the our final answer by 1, now consider this
            as new final answer.
            For every new consideration of final answer, generate all possible i,j value pairs which will result in their difference being our consideration of current 
            final answer.
            
            This process of iterating our final answer in reverse order(From : maximum possible diffrence among the indices, To : 0) will always ensure that whenever a pair (i,j)
            is found & if the pair satisfies the required condition (A[i] <= A[j]) they will definitely be the pair with maximum differnece.
*/


#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
//driver code
int main(){
    FAST_IO;// FAST_IO is replaced with "ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);" as defined in the macros, this enhances the speed of Input & Output operations(cin & cout) of CPP
    int t;cin>>t; // Reading the number of test cases
    while(t--){ 
        int n;cin>>n; // Reading the size of input array
        vector<ull> a(n); // "ull" will be replaced by "unsigned long long int" as defined in macros. Arrays can also be used instead of vector : "ull a[n];"
    
        for(int i=0;i<n;i++){
            cin>>a[i]; // Reading input array
        }

        int max_diff = n-1; // As the maximum attainable value of j-i is achieved when j=(n-1) & i=0, which is n-1
        
        if(a[0]<=a[n-1]){  //Considering i==0 & j==n-1 if a[0]<=a[n-1] right away the MaxIndex difference is n-1
            cout<<max_diff<<"\n"; // Printing max_index_difference
            continue; // Skipping other calculations & moving to next testcase as answer for this one is already found and is equal to n-1.
        }

        bool found_max_diff = false; // Assuming that the answer is yet to be found.
        for(int diff = max_diff-1;diff>=0;diff--){ //Iterating in reverse order reducing the difference from n-1 to 0 to eventually find the answer
            if(found_max_diff) break; // If the answer if found, we will stop immediately & not perform excessive calculations to save time.
            for(int j=diff;j<n;j++){ // Assuming j to be the current difference & we keep increasing j upto n-1
                int i = j-diff; // Calculating the value of i for the assumed j
                if(a[i]<=a[j]){ // Checking if the conditions are met for the new i & j values
                    cout<<diff<<"\n"; // If the conditions are met we print the answer right away
                    found_max_diff=true; // Toggling the found_max_diff to true
                    break;// stop calculating & break right away to move to our next testcase.
                }
            }
        }
    }
    return 0;
}
