#include "tns.h"

void test_tns_matmul_int8_int8() {
    // Test 1: Regular case, all dimensions compatible
    {
        tns_fp32_t r = NULL;
        tns_int8_t A = NULL, x = NULL;
        tns_new(r, 3, 1);
        tns_new(A, 3, 3);
        tns_new(x, 3, 1);
        
        float A_values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        float x_values[] = {1, 1, 1};
        
        tns_cpy(A, A_values);
        tns_cpy(x, x_values);
        
        tns_matmul_int8_int8(r, A, x);
        
        dbgchk(errno == 0, "Error: errno should be 0 but got %d\n", errno);
        
        float expected[] = {6, 15, 24};
        for (int i = 0; i < 3; i++) {
            dbgchk(r->values[i] == expected[i], "Error: r[%d] expected %f, got %f\n", i, expected[i], r->values[i]);
        }

        tns_free(r);
        tns_free(A);
        tns_free(x);
    }
    
    // Test 2: Dimension mismatch A->ncols != x->nrows
    {
        tns_fp32_t r = NULL;
        tns_int8_t A = NULL, x = NULL;
        tns_new(r, 2, 1);
        tns_new(A, 2, 3);
        tns_new(x, 2, 1);
        
        tns_matmul_int8_int8(r, A, x);
        
        dbgchk(errno == ERANGE, "Error: Expected ERANGE but got %d\n", errno);

        tns_free(r);
        tns_free(A);
        tns_free(x);
    }

    // Test 3: x->ncols != 1
    {
        tns_fp32_t r = NULL;
        tns_int8_t A = NULL, x = NULL;
        tns_new(r, 2, 1);
        tns_new(A, 2, 2);
        tns_new(x, 2, 2); // ncols != 1
        
        tns_matmul_int8_int8(r, A, x);
        
        dbgchk(errno == ERANGE, "Error: Expected ERANGE but got %d\n", errno);

        tns_free(r);
        tns_free(A);
        tns_free(x);
    }
    
    // Test 4: r->nrows != A->nrows
    {
        tns_fp32_t r = NULL;
        tns_int8_t A = NULL, x = NULL;
        tns_new(r, 1, 1); // nrows != A->nrows
        tns_new(A, 2, 2);
        tns_new(x, 2, 1);
        
        tns_matmul_int8_int8(r, A, x);
        
        dbgchk(errno == ERANGE, "Error: Expected ERANGE but got %d\n", errno);

        tns_free(r);
        tns_free(A);
        tns_free(x);
    }
    
    // Test 5: A->gsize != x->gsize
    {
        tns_fp32_t r = NULL;
        tns_int8_t A = NULL, x = NULL;
        tns_new(r, 2, 1);
        tns_new(A, 2, 2);
        tns_new(x, 2, 1);
        
        A->gsize = 2;
        x->gsize = 1; // gsize != A->gsize
        
        tns_matmul_int8_int8(r, A, x);
        
        dbgchk(errno == ERANGE, "Error: Expected ERANGE but got %d\n", errno);

        tns_free(r);
        tns_free(A);
        tns_free(x);
    }
}

int main() {
    test_tns_matmul_int8_int8();
    return 0;
}