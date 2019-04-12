#include <iostream>
#include <stdlib.h>  //for using system("CLS")function
#include <windows.h>  //for using sleep()function to delay

using namespace std;

int n;
void printbox(int **arr);
void fillbox(int **arr);
void fillboxsteps(int **arr);

int main()
{

    cout << "Enter odd number : ";
    cin>>n;
    while(n%2==0)
    {
        cout << "Enter odd number : ";
        cin>>n;
    }

    int **arr={0};
    arr=new int *[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }//intilize arr with 0

    char c;
    cout<<"S - to get the magic box fill step by step "<<endl;
    cout<<"A - to get the magic box fill one step ";
    cin>>c;

    if (c=='s'||c=='S')
        fillboxsteps(arr);
    else
        fillbox(arr);

    /*printbox(arr);
    Sleep(5000);
    fillbox(arr);
    printbox(arr);*/


    return 0;
}

void printbox(int **arr)
{
    system("CLS");
    cout<<endl<<"    ";
    for(int j=0;j<((n*6)+1);j++) cout<<"-";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"    | ";
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]>99&&arr[i][j]<1000)
                cout<<arr[i][j]<<" | ";
            else if(arr[i][j]>9&&arr[i][j]<100)
                cout<<arr[i][j]<<"  | ";
            else if(arr[i][j]==0)
                cout<<"    | ";
            else
                cout<<" "<<arr[i][j]<<"  | ";
        }
        cout<<endl<<"    ";
        for(int j=0;j<((n*6)+1);j++) cout<<"-";
        cout<<endl;
    }
}

void fillbox(int **arr)
{
    system("CLS");    printbox(arr);   Sleep(1000);
    int x,y;
    x=n/2; y=n-1;
    arr[x][y]=1;
    for(int k=2;k<=(n*n);k++)
    {
        x--;y++;
        if(x==-1)x=n-1;
        if(y==n) y=0;

        if(arr[x][y]==0)
        {
            arr[x][y]=k; continue;
        }
        else
        {
            while(arr[x][y]!=0)
            {
                x++;if(x==n) x=0;
                y--;if(y==-1)y=n-1;
                y--;if(y==-1)y=n-1;
            }//end while
            arr[x][y]=k; continue;
        }
    }//end for
    system("CLS");    printbox(arr);   Sleep(1000);
}

void fillboxsteps(int **arr)
{
    system("CLS");    printbox(arr);   Sleep(500);
    int x,y;
    x=n/2; y=n-1;
    arr[x][y]=1;
    system("CLS");    printbox(arr);   Sleep(500);
    for(int k=2;k<=(n*n);k++)
    {
        x--;y++;
        if(x==-1)x=n-1;
        if(y==n) y=0;

        if(arr[x][y]==0)
        {
            arr[x][y]=k;
            system("CLS");    printbox(arr);   Sleep(500);
            continue;
        }
        else
        {
            while(arr[x][y]!=0)
            {
                x++;if(x==n) x=0;
                y--;if(y==-1)y=n-1;
                y--;if(y==-1)y=n-1;
            }//end while
            arr[x][y]=k;
            system("CLS");    printbox(arr);   Sleep(500);
            continue;
        }
    }//end for
}
