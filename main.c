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
    int v1, v2, v3, v5, v6, v7, v9, v11, v12, v13, v14, v15, o1, a2a;
    v4 = a2;
    v5 = a1;
    v6 = 0;
    v7 = a2[a1];
    v9 = -1;
    v14 = a2[a1 - 1];
    // a2[a1 - 1] = 10000;  a2 value shouldn't change
    v15 = v7;
    // a2[a1] = -10000;     a2 value shouldn't change
    o1 = 0;
    a2a = 0;

    if (a1 > 0)
    {
        // v10 = a4;
//       do
//       {
            v11 = v4[v6++]; // REMOVE (int)&
            //*v10 = v11;
            v12 = v4[v6];   // REMOVE (int)&
            v1 = v9 * (v11 - v12);  // Do branch arithmetic outside for better readability
            if (v1 < a3)    // REMOVE *(int *)s
            {
//              do
//              {
                    // v2 = v9 * v12;
                    // v3 = v9 * v11;
//                  if (v2 > v3) // REMOVE *(int *) 
//                  {
//                      *v10 = v12;
//                  }
                    v13 = v12 + 4;
                    v12 += 4;
                    ++v6;
//             } while (v9 * (*(int *)*v10 - v13) < a3);
//             v5 = a1;
            }
            //++v10;
          v9 = -v9;
          a2a++; // separate a2a++ from a2a++ + 1
          o1 = a2a + 1; 
//       } while (v6 < v5);
    }
//    if (o1 % 2)
//       --o1;
//    v4[v5 - 1] = v14;
//    v4[v5] = v15;
//    return o1;
    return 1;
}

int main() {

    //int arr[1408]; // a2
    //int arr2[116]; // a4

    int arr[10] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4};
    int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // ---------------  TESTING: *(int *)&x == x  ---------------------
    // int y[1] = {1};
    // int v11 = (int)&y[0]; 
    // printf("(int)&y[0]:    %d\n", (int)&y[0]);
    // printf("&y[0]:         %d\n\n", &y[0]);
    // printf("*(int *)&y[0]: %d\n", *(int *)&y[0]);
    // printf("y[0]:          %d\n", y[0]);


    f0700( 2, arr, 2, arr2);
    return 0;
}

