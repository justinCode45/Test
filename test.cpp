#include <iostream>

#define LS "/"
#define RS "\\"
#define DASH "-"
#define STAR "*"
#define SPACE " "

using namespace std;

bool inputerror(int L, int N)
{
    if (N < 1)
        return true;
    if (L < 3)
        return true;
    int maxWidth = (L * 3 - 2) * N + (L - 2) * (N - 1);
    if (maxWidth > 80)
        return true;
    return false;
}

void printM(int L, int N)
{   
    /* print
        /    \      /    \
       /      \    /      \
      *        *--*        *      ..........
       \      /    \      /
        \    /      \    /
         *--*        *--* 
    */

    for (int i = 0; i < L - 2; i++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int j = 0; j < L - 2 - i; j++)
                cout << SPACE;
            cout << LS;
            for (int j = 0; j < L + 2 * i; j++)
                cout << SPACE;
            cout << RS;
            for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                cout << SPACE;
        }
        cout << endl;
    }
    //
    for (int n = 0; n < N; n++)
    {
        if (n != 0)
        {
            for (int j = 0; j < L - 2; j++)
                cout << DASH;
        }
        cout << STAR;
        for (int j = 0; j < 3 * L - 4; j++)
            cout << SPACE;
        cout << STAR;
    }
    cout << endl;
    //
    for (int i = L - 3; i >= 0; i--)
    {
        for (int n = 0; n < N; n++)
        {
            for (int j = 0; j < L - 2 - i; j++)
                cout << SPACE;
            cout << RS;
            for (int j = 0; j < L + 2 * i; j++)
                cout << SPACE;
            cout << LS;
            for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                cout << SPACE;
        }
        cout << endl;
    }
    //
    for (int n = 0; n < N; n++)
    {
        for (int j = 0; j < L - 1; j++)
            cout << SPACE;
        cout << STAR;
        for (int j = 0; j < L - 2; j++)
            cout << DASH;
        cout << STAR;
        for (int j = 0; j < 2 * L - 3; j++)
            cout << SPACE;
    }
    cout << endl;
}

void print(int L, int N)
{   
    // print out top
    for (int n = 0; n < N - 1; n++)
    {
        /*
            print out  *-----*      *-----*  ......
        */ 
        for (int j = 0; j < (2 * (N - 1) - 2 * n) * L -  (2 * (N - 1) - 2 * n); j++)
            cout << SPACE;
        for (int j = 0; j < n + 1; j++)
        {
            for (int j = 0; j < L - 1; j++)
                cout << SPACE;
            cout << STAR;
            for (int j = 0; j < L - 2; j++)
                cout << DASH;
            cout << STAR;
            for (int j = 0; j < 2 * L - 3; j++)
                cout << SPACE;
        }
        cout<<endl;

        /*
            print out /   \     /   \     /   \     /   \   
                     /     \   /     \   /     \   /     \ .......  
                     .
                     .
                     .
                     .

        */   
        for (int i = 0; i < L - 2; i++)
        {
            for (int j = 0; j < (2 * (N - 1) - 2 * n) * L -  (2 * (N - 1) - 2 * n); j++)
                cout << SPACE;
            for (int nin = 0; nin < n+1; nin++)
            {
                for (int j = 0; j < L - 2 - i; j++)
                    cout << SPACE;
                cout << LS;
                for (int j = 0; j < L + 2 * i; j++)
                    cout << SPACE;
                cout << RS;
                for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                    cout << SPACE;
            }
            cout << endl;
        }
    }

    // Print out the middle layer
    for (int n = 0; n < N; n++)
    {
        for (int j = 0; j < L - 1; j++)
            cout << SPACE;
        cout << STAR;
        for (int j = 0; j < L - 2; j++)
            cout << DASH;
        cout << STAR;
        for (int j = 0; j < 2 * L - 3; j++)
            cout << SPACE;
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        printM(L, N);
    }

    // print out bottom
    for (int n = N-2; n >=0; n--)
    {   
        /*
            print out \     /   \     /   \     /
                       \   /     \   /     \   / ..........   
                     .
                     .
                     .
                     .

        */  
        for (int i = L-3; i >=0; i--)
        {
            for (int j = 0; j < (2 * (N - 1) - 2 * n) * L -  (2 * (N - 1) - 2 * n); j++)
                cout << SPACE;
            for (int nin = 0; nin < n+1; nin++)
            {
                for (int j = 0; j < L - 2 - i; j++)
                    cout << SPACE;
                cout << RS;
                for (int j = 0; j < L + 2 * i; j++)
                    cout << SPACE;
                cout << LS;
                for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                    cout << SPACE;
            }
            cout << endl;
        }

        /*
            print out  *-----*      *-----*  ......
        */ 
        for (int j = 0; j < (2 * (N - 1) - 2 * n) * L -  (2 * (N - 1) - 2 * n); j++)
            cout << SPACE;
        for (int j = 0; j < n + 1; j++)
        {
            for (int j = 0; j < L - 1; j++)
                cout << SPACE;
            cout << STAR;
            for (int j = 0; j < L - 2; j++)
                cout << DASH;
            cout << STAR;
            for (int j = 0; j < 2 * L - 3; j++)
                cout << SPACE;
        }
        cout<<endl;

        
    }
}

int main()
{
    int L = 4;
    int N = 5;
    cout << "Please input the length: ";
    cin >> L;
    cout << "Please input the number of layer: ";
    cin >> N;
    if (inputerror(L, N))
    {
        cout << "Input error!" << endl;
        return 0;
    }

    print(L, N);

    return 0;
}
