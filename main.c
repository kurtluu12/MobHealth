#include <stdio.h>

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

    int *v4;
    int v5;
    int v6;
    int v7;
    int o1;
    int v9;
    int *v10;
    int v11;
    int v12;
    int v13;
    int v14;
    int v15;
    int a2a;

    v4 = a2;
    v5 = a1;
    v6 = 0;
    v7 = a2[a1];
    v14 = a2[a1 - 1];
    o1 = 0;
    v9 = -1;
    // a2[a1 - 1] = 10000; a2 value shouldn't change
    v15 = v7;
    // a2[a1] = -10000; a2 value shouldn't change
    a2a = 0;

//    if (a1 > 0)
//    {
//       v10 = a4;
//       do
//       {
//          v11 = (int)&v4[v6++];
//          *v10 = v11;
//          v12 = (int)&v4[v6];
//          if (v9 * (*(int *)v11 - *(int *)v12) < a3)
//          {
//             do
//             {
//                if (v9 * *(int *)v12 > v9 * *(int *)*v10)
//                   *v10 = v12;
//                v13 = *(int *)(v12 + 4);
//                v12 += 4;
//                ++v6;
//             } while (v9 * (*(int *)*v10 - v13) < a3);
//             v5 = a1;
//          }
//          ++v10;
//          v9 = -v9;
//          o1 = a2a++ + 1;
//       } while (v6 < v5);
//    }
//    if (o1 % 2)
//       --o1;
//    v4[v5 - 1] = v14;
//    v4[v5] = v15;
//    return o1;
}

int main() {

    //int arr[1408];
    //int arr2[116];

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // ---------------  TESTING: *(int *)&x == x  ---------------------
    // int y[1] = {1};
    // int v11 = (int)&y[0]; 
    // printf("(int)&y[0]:    %d\n", (int)&y[0]);
    // printf("&y[0]:         %d\n\n", &y[0]);
    // printf("*(int *)&y[0]: %d\n", *(int *)&y[0]);
    // printf("y[0]:          %d\n", y[0]);



    signed int x = f0700( 2, arr, 2, arr2);
    return 0;
}

