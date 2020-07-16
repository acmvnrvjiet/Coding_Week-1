/*https://leetcode.com/problems/escape-the-ghosts/
Approch:Here we have two vectors i.e., ghosts and target which define their positions. The player is at origin
(0,0). We have to calculate the distance b/w player and target which is done by simply subtracting target's x 
value from player's x and similarly y. Now, adding these 2 values gives no. of moves to reach the target by 
player since in each move, you can move 1 unit from current position. Similarly calculate distance from each 
ghost to the target.If the player takes less moves compared to all the ghosts, then he can escape.(true)
Example: 
ghosts=[[1,0][0,3]]
target=[0,1]
Distance b/w player and target=(0-0)+(1-0)=1 move
Distance b/w 1st ghost and target=abs(1-0)+abs(0-1)=2 moves
Distance b/w 1st ghost and target=abs(0-0)+abs(3-1)=2 moves
1<2
Hence, the player can escape and we print true.*/
//Cpp program to Escape the ghosts
#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int movesofplayer = abs(target[0]) + abs(target[1]); //distance from origin
        for (vector<int>& ghost : ghosts) {//for loop to check for each ghost individually 
            int movesofghost = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);//calculating moves taken 
             //by each ghost and abs converts neg int to pos int
            if (movesofghost <= movesofplayer)
              return false;
        }
        return true;
    }
};
int main(){
    Solution s; //object of Solution class
    vector<vector<int>> ghosts{{1,0},{3,0}};
    vector<int> target{0,1};
    if(s.escapeGhosts(ghosts,target))// Calling "escapeGhosts" function using object of the class.
        cout<<"true\n";
    else
        cout<<"false\n";
    return 0;
}


//Solution Posted by : Y.Nikitha
