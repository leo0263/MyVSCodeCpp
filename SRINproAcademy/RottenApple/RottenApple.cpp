// C++ program to find minimum time required to make all
// oranges rotten
#include <iostream>
#include <queue>
using namespace std;
int R, C;
int map[100][100];

// function to check whether a cell is valid / invalid
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < R && j < C);
}
 
// structure for storing coordinates of the cell
struct ele {
    int x, y;
};
 
// Function to check whether the cell is delimiter
// which is (-1, -1)
bool isdelim(ele temp)
{
    return (temp.x == -1 && temp.y == -1);
}
 
// Function to check whether there is still a fresh
// orange remaining
bool checkall()
{
    for (int i=0; i<R; i++)
       for (int j=0; j<C; j++)
          if (map[i][j] == 1)
             return true;
    return false;
}
 
// This function finds if it is possible to rot all oranges or not.
// If possible, then it returns minimum time required to rot all,
// otherwise returns -1
int rotOranges()
{
    // Create a queue of cells
    queue<ele> Q;
    ele temp;
    int ans = 0;
 
    // Store all the cells having rotten orange in first time frame
    for (int i=0; i<R; i++)
    {
       for (int j=0; j<C; j++)
       {
            if (map[i][j] == 2)
            {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }
 
    // Separate these rotten oranges from the oranges which will rotten
    // due the oranges in first time frame using delimiter which is (-1, -1)
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);
 
    // Process the grid while there are rotten oranges in the Queue
    while (!Q.empty())
    {
        // This flag is used to determine whether even a single fresh
        // orange gets rotten due to rotten oranges in current time
        // frame so we can increase the count of the required time.
        bool flag = false;
 
        // Process all the rotten oranges in current time frame.
        while (!isdelim(Q.front()))
        {
            temp = Q.front();
 
            // Check right adjacent cell that if it can be rotten
            if (isvalid(temp.x+1, temp.y) && map[temp.x+1][temp.y] == 1)
            {
                // if this is the first orange to get rotten, increase
                // count and set the flag.
                if (!flag) ans++, flag = true;
 
                // Make the orange rotten
                map[temp.x+1][temp.y] = 2;
 
                // push the adjacent orange to Queue
                temp.x++;
                Q.push(temp);
 
                temp.x--; // Move back to current cell
            }
 
            // Check left adjacent cell that if it can be rotten
            if (isvalid(temp.x-1, temp.y) && map[temp.x-1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                map[temp.x-1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }
 
            // Check top adjacent cell that if it can be rotten
            if (isvalid(temp.x, temp.y+1) && map[temp.x][temp.y+1] == 1) {
                if (!flag) ans++, flag = true;
                map[temp.x][temp.y+1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }
 
            // Check bottom adjacent cell if it can be rotten
            if (isvalid(temp.x, temp.y-1) && map[temp.x][temp.y-1] == 1) {
                if (!flag) ans++, flag = true;
                map[temp.x][temp.y-1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
            }
 
            Q.pop();
        }
 
        // Pop the delimiter
        Q.pop();
 
        // If oranges were rotten in current frame than separate the
        // rotten oranges using delimiter for the next frame for processing.
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }
 
        // If Queue was empty than no rotten oranges left to process so exit
    }
 
    // Return -1 if all arranges could not rot, otherwise -1.
    return (checkall())? -1: ans;
}
 
// Drive program
int main()
{
    int T; cin >> T; 
    for (int t = 1; t <= T; t++) {
        cin >> R >> C; 
        for (int y = 0; y < R; y++)
            for(int x = 0; x < C; x++)
                cin >> map[y][x];
        
        cout << rotOranges() << endl;
    }

    return 0;
}