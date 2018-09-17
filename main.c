#include <stdio.h>

// eliminate uneccesary pointer arithmetic, variables, loop, calculation
signed int f0700(int a1, int *a2, int a3, int *a4)
{
   // Pre-Condition:
   //    a1: possible input value = [64, 128, 256]
   //    a2: is an int[1408] array
   //        possible input value for each element = [-4095 ... 4095]
   //    a3: possible input value = [2, 3, 4, 5, 6]
   //    a4: is an int[116] array
   //        possible input value for each element = [0]
   //
   // Post-Condition:
   //    a1: value shouldn't change
   //    a2: value shouldn't change
   //    a3: value shouldn't change
   //    a4: value can change

    int *v4, *v10;
    int t1, t2, t3, t4, v5, v6, v7, v9, v11, v12, v13, v14, v15, o1, a2a;
    
    v4 = a2;
    v5 = a1;
    v6 = 0;
    v7 = a2[a1];
    v9 = -1;
    v14 = a2[a1 - 1];
    v15 = v7;
    o1 = 0;
    a2a = 0;

    if (a1 > 0)
    {
        v10 = a4;
        do
        {
            v11 = v4[v6++]; // REMOVE (int)&
            v12 = v4[v6];   // REMOVE (int)&
            *v10 = v11;
            t1 = v9 * (v11 - v12);      // Do branch arithmetic outside for better readability
            if (t1 < a3)    // REMOVE *(int *)s
            {
                do
                {
                    t2 = v9 * v12;
                    t3 = v9 * v11;
                    if (t2 > t3)    // REMOVE *(int *) 
                    {
                        *v10 = v12;
                    }
                    v13 = v12 + 4;
                    v12 += 4;
                    ++v6;
                    t4 = v9 * (*v10 - v13);
                } while (t4 < a3);    // REMOVE *(int *)
                    v5 = a1;
            }
            //++v10;
            v9 = -v9;
            a2a++;  // separate a2a++ from a2a++ + 1
            o1 = a2a + 1; 
        } while (v6 < v5);
    }
    if(o1 % 2) { // add {}
        --o1;
    }
    v4[v5 - 1] = v14;
    v4[v5] = v15;
    return o1;
}

int main() {

    //int arr[1408]; // a2
    //int arr2[116]; // a4

    int arr[10] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};
    int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


    signed int x = f0700( 2, arr, 2, arr2);
    printf("%d\n", x);
    return 0;
}

