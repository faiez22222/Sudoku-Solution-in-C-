
//Sudoku Problem with solution..........................................


#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
bool canPlace(int arr[9][9],int i,int j,int n,int number);
bool solve(int arr[9][9],int i,int j,int n);

bool canPlace(int arr[9][9],int i,int j,int n,int number)
{
	// checking row and column
    for(int k=0;k<n;k++)
    {
       if(arr[k][j]==number or arr[i][k]==number)
       {
         return false;
       }
    }
    //checking subgrid
    int l=sqrt(n);
    int sx,sy;
    sx=(i/l)*l;
    sy=(j/l)*l;
    for(int x=sx;x<sx+l;x++)
    {
       for(int y=sy;y<sy+l;y++)
       {
         if(arr[x][y]==number)
         {
           return false;
         }
       }
    }
    // if number is not present in row , column abd in subgrid then
    return true;
}
bool solve(int arr[][9],int i,int j,int n)
{
   // Base case
    if(i==n)
    {
       // Print the Matrix
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
         cout<<endl;
       }
       return true;
    }

   // Recursive case
   // Column end or Row change
    if(j==n)
    {
       return solve(arr,i+1,0,n);
    }
    // Skip the cell if the number is already placed
    if(arr[i][j]!=0)
    {
       return solve(arr,i,j+1,n);
    }
    //Main answer finding
    // Filling the current cell with possible options
    for(int number=1;number<=n;number++)
    {
       if(canPlace(arr,i,j,n,number) == true)
       {
          // Assume that the number is the correct option
          arr[i][j]=number;
          bool couldWeSolve=solve(arr,i,j+1,n);
          if(couldWeSolve == true)
          {
             return true;
          }
       } 
    }
    // when any number is not compatible with sudoku then 
    arr[i][j]=0; // place zero at that cell
    return false;// and return false to the previous cell that please change your number so that i can be able to fill my cell.
}
int main()
{
    int arr[9][9];
    for(int i=0;i<9;i++)
      for(int j=0;j<9;j++)
        cin>>arr[i][j];
    solve(arr,0,0,9);
}
