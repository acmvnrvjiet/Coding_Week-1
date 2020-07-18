//Question Link: https://www.interviewbit.com/problems/find-duplicate-in-array/

/*
Asked in:  
	Amazon,
	VMWare,
	Riverbed.
Question:
Given a read only array of n + 1 integers between 1 and n, 
find one number that repeats in linear time ,using less than O(n) 
space and traversing the stream sequentially O(1) times.
Sample Input:
		[3 4 1 4 1]
Sample Output:
		1
If there are multiple possible answers ( like in the sample case above ), output any one.
If there is no duplicate, output -1
*/
//Solution is Starts here..

int Solution::repeatedNumber(const vector<int> &A) {
     int i,n=A.size();  	 //storing size of given vector in variable n
    vector<bool>b(n,false);	//creating a boolean vector 'b' and initializing it to false
    for(i=0;i<n;i++)		//Looping over vector 'b' 
    {
        if(b[A[i]]==false)
        {
            b[A[i]]=true;      //if the number is occured for once,changing its value to true.
        }
        else
        {   
            return A[i];	//if it is already true-- indicates the number is repeating,so return the number and exit the function.
        }
    }
 
    return -1;			//if there is no duplicate in given vector,returning "-1"
}

//Solution Ends here..
//Solution Posted by: CH.Ullas Reddy.
