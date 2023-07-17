#include <iostream>
#include "mul.h"
#define HW_COSIM

using namespace std;

int main(int argc, char **argv)
{
   int a[32][32],b[32][32];
   for(int i =0;i<32;i++)
   {
	   for(int j = 0; j <32;j++)
	   {
		   a[i][j]=i+j;
		   b[i][j]=i+2*j;
	   }
   }


   result_t hw_result[32][32],  sw_result[32][32];
   int err_cnt = 0;

   for(int i = 0; i < MAT_A_ROWS; i++) {
      for(int j = 0; j < MAT_B_COLS; j++) {
         sw_result[i][j] = 0;
         for(int k = 0; k < MAT_B_ROWS; k++) {
            sw_result[i][j] += a[i][k] * b[k][j];
         }
      }
   }

#ifdef HW_COSIM
   matrixmul(a, b, hw_result);
#endif

   for (int i = 0; i < MAT_A_ROWS; i++) {
      for (int j = 0; j < MAT_B_COLS; j++) {
#ifdef HW_COSIM
         if (hw_result[i][j] != sw_result[i][j]) {
            err_cnt++;
         }
#else
         cout << sw_result[i][j];
#endif
      }
   }

#ifdef HW_COSIM
   if (err_cnt)
      cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
   else
      cout << "Test passed." << endl;
#endif
   return err_cnt;
}
