
#include  <stdio.h>
#define LS '/'
#define RS '\\'
#define DASH '-'
#define STAR '*'
#define SPACE ' '



int inputerror(int L, int N)
{
    if (N < 1)
        return 1;
    if (L < 3)
        return 1;
    int maxWidth = (L * 3 - 2) * N + (L - 2) * (N - 1);
    if (maxWidth > 80)
        return 1;
    return 0;
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
                printf("%c",SPACE);
            printf("%c",LS);
            for (int j = 0; j < L + 2 * i; j++)
                printf("%c",SPACE);
            printf("%c",RS);
            for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                printf("%c",SPACE);
        }
        printf("\n");
    }
    //
    for (int n = 0; n < N; n++)
    {
        if (n != 0)
        {
            for (int j = 0; j < L - 2; j++)
                printf("%c",DASH);
        }
        printf("%c",STAR);
        for (int j = 0; j < 3 * L - 4; j++)
            printf("%c",SPACE);
        printf("%c",STAR);
    }
    printf("\n");
    //
    for (int i = L - 3; i >= 0; i--)
    {
        for (int n = 0; n < N; n++)
        {
            for (int j = 0; j < L - 2 - i; j++)
                printf("%c",SPACE);
            printf("%c",RS);
            for (int j = 0; j < L + 2 * i; j++)
                printf("%c",SPACE);
            printf("%c",LS);
            for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                printf("%c",SPACE);
        }
        printf("\n");
    }
    //
    for (int n = 0; n < N; n++)
    {
        for (int j = 0; j < L - 1; j++)
            printf("%c",SPACE);
        printf("%c",STAR);
        for (int j = 0; j < L - 2; j++)
            printf("%c",DASH);
        printf("%c",STAR);
        for (int j = 0; j < 2 * L - 3; j++)
            printf("%c",SPACE);
    }
    printf("\n");
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
            printf("%c",SPACE);
        for (int j = 0; j < n + 1; j++)
        {
            for (int j = 0; j < L - 1; j++)
                printf("%c",SPACE);
            printf("%c",STAR);
            for (int j = 0; j < L - 2; j++)
                printf("%c",DASH);
            printf("%c",STAR);
            for (int j = 0; j < 2 * L - 3; j++)
                printf("%c",SPACE);
        }
        printf("\n");

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
                printf("%c",SPACE);
            for (int nin = 0; nin < n+1; nin++)
            {
                for (int j = 0; j < L - 2 - i; j++)
                    printf("%c",SPACE);
                printf("%c",LS);
                for (int j = 0; j < L + 2 * i; j++)
                    printf("%c",SPACE);
                printf("%c",RS);
                for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                    printf("%c",SPACE);
            }
            printf("\n");
        }
    }

    // Print out the middle layer
    for (int n = 0; n < N; n++)
    {
        for (int j = 0; j < L - 1; j++)
            printf("%c",SPACE);
        printf("%c",STAR);
        for (int j = 0; j < L - 2; j++)
            printf("%c",DASH);
        printf("%c",STAR);
        for (int j = 0; j < 2 * L - 3; j++)
            printf("%c",SPACE);
    }
    printf("\n");
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
                printf("%c",SPACE);
            for (int nin = 0; nin < n+1; nin++)
            {
                for (int j = 0; j < L - 2 - i; j++)
                    printf("%c",SPACE);
                printf("%c",RS);
                for (int j = 0; j < L + 2 * i; j++)
                    printf("%c",SPACE);
                printf("%c",LS);
                for (int j = 0; j < ((L - 2 - i) + L - 2); j++)
                    printf("%c",SPACE);
            }
            printf("\n");
        }

        /*
            print out  *-----*      *-----*  ......
        */ 
        for (int j = 0; j < (2 * (N - 1) - 2 * n) * L -  (2 * (N - 1) - 2 * n); j++)
            printf("%c",SPACE);
        for (int j = 0; j < n + 1; j++)
        {
            for (int j = 0; j < L - 1; j++)
                printf("%c",SPACE);
            printf("%c",STAR);
            for (int j = 0; j < L - 2; j++)
                printf("%c",DASH);
            printf("%c",STAR);
            for (int j = 0; j < 2 * L - 3; j++)
                printf("%c",SPACE);
        }
        printf("\n");

        
    }
}

int main()
{
    int L = 4;
    int N = 5;
    printf("Please input the length: ");
    scanf("%d", &L);
    printf("Please input the number of layer: ");
    scanf("%d", &N);
    if (inputerror(L, N))
    {
        printf("INPUT ERROR\n");
        return 0;
    }

    print(L, N);

    return 0;
}
