/* 
**  (C) by Remo Dentato (rdentato@gmail.com)
**
** This software is distributed under the terms of the MIT license:
**  https://opensource.org/licenses/MIT
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

#include "tns.h"


int main() {
    
    // Test Case 1
    float values1[] = {1.0, 2.0, 3.0, 4.0};
    tns_int8_t tns1 = NULL;
	  tns_new(tns1, 4, 1, 2); // Assuming you have a function tns_new that initializes the tensor
    dbgchk(tns1 != NULL);
    tns_int8_cpy_v(tns1, values1);
    for (int i = 0; i<(tns_nrows(tns1)* tns_ncols(tns1)); i++) {
      dbginf("val: %f qval= %f",values1[i], tns_get(tns1,i));
    }

    dbgchk(fabs(values1[0] - (tns1->values[0] * tns1->scales[0])) < 1E3, "Test Case 1 Failed (err: %f)",fabs(values1[0] - (tns1->values[0] * tns1->scales[0])));
    tns_free(tns1); // Assuming you have a function tns_free that frees the tensor


#if 0
    // Test Case 2
    float values2[] = {0.0, 0.0, 0.0, 0.0};
    tns_int8_t tns2 = NULL;
	tns_new(tns2, 4, 1, 2);
    tns_int8_cpy_v(tns2, values2);
    dbgchk(tns2->values[0] == 0 && tns2->values[1] == 0 && tns2->values[2] == 0 && tns2->values[3] == 0, "Test Case 2 Failed");
    dbgchk(tns2->scales[0] == 0.0, "Test Case 2 Failed");
    tns_free(tns2);

    // Test Case 3
    float values3[] = {-1.0, -2.0, -3.0, -4.0};
    tns_int8_t tns3 = NULL;
	tns_new(tns3, 4, 1, 2);
    tns_int8_cpy_v(tns3, values3);
    dbgchk(tns3->values[0] == -1 && tns3->values[1] == -2 && tns3->values[2] == -3 && tns3->values[3] == -4, "Test Case 3 Failed");
    dbgchk(tns3->scales[0] == 1.0/127.0, "Test Case 3 Failed");
    tns_free(tns3);

    // Test Case 4
    float values4[] = {127.0, -127.0, 0.0, 63.5};
    tns_int8_t tns4 = NULL;
	tns_new(tns4, 4, 1, 2);
    tns_int8_cpy_v(tns4, values4);
    dbgchk(tns4->values[0] == 127 && tns4->values[1] == -127 && tns4->values[2] == 0 && tns4->values[3] == 63, "Test Case 4 Failed");
    dbgchk(tns4->scales[0] == 1.0, "Test Case 4 Failed");
    tns_free(tns4);

    // Test Case 5
    float values5[] = {0.5, 1.0, 1.5, 2.0};
    tns_int8_t tns5 = NULL;
	tns_new(tns5, 4, 1, 2);
    tns_int8_cpy_v(tns5, values5);
    dbgchk(tns5->values[0] == 0 && tns5->values[1] == 1 && tns5->values[2] == 2 && tns5->values[3] == 3, "Test Case 5 Failed");
    dbgchk(tns5->scales[0] == 2.0/127.0, "Test Case 5 Failed");
    tns_free(tns5);

    // Test Case 6
    float values6[] = {0.1, 0.2, 0.3, 0.4};
    tns_int8_t tns6 = NULL;
	tns_new(tns6, 4, 1, 2);
    tns_int8_cpy_v(tns6, values6);
    dbgchk(tns6->values[0] == 0 && tns6->values[1] == 0 && tns6->values[2] == 0 && tns6->values[3] == 0, "Test Case 6 Failed");
    dbgchk(tns6->scales[0] == 0.4/127.0, "Test Case 6 Failed");
    tns_free(tns6);

    // Test Case 7
    float values7[] = {-0.5, -1.0, -1.5, -2.0};
    tns_int8_t tns7 = NULL;
	tns_new(tns7, 4, 1, 2);
    tns_int8_cpy_v(tns7, values7);
    dbgchk(tns7->values[0] == 0 && tns7->values[1] == -1 && tns7->values[2] == -2 && tns7->values[3] == -3, "Test Case 7 Failed");
    dbgchk(tns7->scales[0] == 2.0/127.0, "Test Case 7 Failed");
    tns_free(tns7);

    // Test Case 8
    float values8[] = {100.0, 50.0, -50.0, -100.0};
    tns_int8_t tns8 = NULL;
	tns_new(tns8, 4, 1, 2);
    tns_int8_cpy_v(tns8, values8);
    dbgchk(tns8->values[0] == 127 && tns8->values[1] == 63 && tns8->values[2] == -63 && tns8->values[3] == -127, "Test Case 8 Failed");
    dbgchk(tns8->scales[0] == 1.0, "Test Case 8 Failed");
    tns_free(tns8);

    // Test Case 9
    float values9[] = {10.0, 20.0, 30.0, 40.0};
    tns_int8_t tns9 = NULL;
	tns_new(tns9, 4, 1, 2);
    tns_int8_cpy_v(tns9, values9);
    dbgchk(tns9->values[0] == 32 && tns9->values[1] == 63 && tns9->values[2] == 95 && tns9->values[3] == 127, "Test Case 9 Failed");
    dbgchk(tns9->scales[0] == 1.0, "Test Case 9 Failed");
    tns_free(tns9);

    // Test Case 10
    float values10[] = {0.01, 0.02, 0.03, 0.04};
    tns_int8_t tns10 = NULL;
	tns_new(tns10, 4, 1, 2);
    tns_int8_cpy_v(tns10, values10);
    dbgchk(tns10->values[0] == 0 && tns10->values[1] == 0 && tns10->values[2] == 0 && tns10->values[3] == 0, "Test Case 10 Failed");
    dbgchk(tns10->scales[0] == 0.04/127.0, "Test Case 10 Failed");
    tns_free(tns10);
#endif
    return 0;
}
