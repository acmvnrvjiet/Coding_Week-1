/* 
Question Link: https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial/0

APPROACH:Lets decompose probelem into smaller statements.
If we observe a number and its prime factorisation,if the number is divisible by 10
the it contains 10 in its prime factorisation.
            10=2*5
so,to count number of tens we need to count either number of twos or number of fives.
But number of twos may be greater than number of fives.So lets take into account of
counting number of fives.*/
//LANGUAGE:CPP

#include<iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long int n;
  cin>>n;
  long long int count=0;
  while((n/5)>0)
  {
     count+=n/5;   //Adding number of fives in n at that particular instant to count.
     n=n/5;        //Dividing n by 5.
  }
  cout<<count<<endl;
}
return 0;
}


// Solution Provided by : S.Niharika
