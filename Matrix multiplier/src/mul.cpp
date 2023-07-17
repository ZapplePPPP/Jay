#include "mul.h"

void matrixmul(
      mat_a_t a[MAT_A_ROWS][MAT_A_COLS],
      mat_b_t b[MAT_B_ROWS][MAT_B_COLS],
      result_t res[MAT_A_ROWS][MAT_B_COLS])
{
	int tempA[MAT_A_ROWS][MAT_A_COLS];
	int tempB[MAT_B_ROWS][MAT_B_COLS];
	int tempAB[MAT_A_ROWS][MAT_B_COLS];

	 for (int ia = 0; ia<MAT_A_ROWS ;ia++){
		 for(int ja = 0; ja< MAT_A_COLS; ja++){
			 tempA[ia][ja] = a[ia][ja];
		 }
	 }
	 for (int ib = 0; ib<MAT_B_ROWS ;ib++){
		 for(int jb = 0; jb< MAT_B_COLS; jb++){
			 tempB[ib][jb] = b[ib][jb];
		 }
	 }
	  /* for each row and column of AB */

	 row: for(int i = 0; i < MAT_A_ROWS; ++i) {

		 col: for(int j = 0; j < MAT_B_COLS; ++j) {

	      /* compute (AB)i,j */

	      int ABij = 0;

	    product: for(int k = 0; k < MAT_A_COLS; ++k) {
	        ABij += tempA[i][k] * tempB[k][j];

	      }
	      tempAB[i][j] = ABij;
	    }
	  }

	  for (int iab = 0; iab<MAT_A_ROWS ;iab++){
	 	 for(int jab = 0; jab< MAT_B_COLS; jab++){
	 		res[iab][jab] = tempAB[iab][jab];
	 	 }
	  }

}
