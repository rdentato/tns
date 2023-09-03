#include "tns.h"

void test_tns_fp32_softmax() {
    tns_fp32_t tns;
    float epsilon = 0.0001f; // small constant to check for float equality

    // Test Case 1: Single element tensor
    tns_new(tns, 1); // Create a 1-element tensor
    float single_value[] = {5.0f};
    tns_cpy(tns, single_value);
    tns_fp32_softmax(tns,tns);
    dbgchk(fabs(tns_get(tns, 0) - 1.0f) < epsilon, "Error in single element tensor. Expected 1, got %f", tns_get(tns, 0));
    tns_free(tns);

    // Test Case 2: All elements are the same
    tns_new(tns, 4); // Create a 4-element tensor
    float same_values[] = {2.0f, 2.0f, 2.0f, 2.0f};
    tns_cpy(tns, same_values);
    tns_fp32_softmax(tns,tns);
    for (int i = 0; i < 4; i++) {
        dbgchk(fabs(tns_get(tns, i) - 0.25f) < epsilon, "Error in all elements same tensor. Expected 0.25, got %f", tns_get(tns, i));
    }
    tns_free(tns);

    // Test Case 3: Elements in decreasing order
    tns_new(tns, 4); // Create a 4-element tensor
    float decreasing_values[] = {4.0f, 3.0f, 2.0f, 1.0f};
    tns_cpy(tns, decreasing_values);
    tns_fp32_softmax(tns,tns);

    float expected_values3[4];
    float sum3 = 0.0f;
    for (int i = 0; i < 4; i++) {
        expected_values3[i] = expf(decreasing_values[i]);
        sum3 += expected_values3[i];
    }
    for (int i = 0; i < 4; i++) {
        expected_values3[i] /= sum3;
        dbgchk(fabs(tns_get(tns, i) - expected_values3[i]) < epsilon, "Error in decreasing values tensor. Expected %f, got %f", expected_values3[i], tns_get(tns, i));
    }
    tns_free(tns);

    
    // Test Case 4: Elements in increasing order
    tns_new(tns, 4); // Create a 4-element tensor
    float increasing_values[] = {1.0f, 2.0f, 3.0f, 4.0f};
    tns_cpy(tns, increasing_values);
    tns_fp32_softmax(tns,tns);

    float expected_values4[4];
    float sum4 = 0.0f;
    for (int i = 0; i < 4; i++) {
        expected_values4[i] = expf(increasing_values[i]);
        sum4 += expected_values4[i];
    }
    for (int i = 0; i < 4; i++) {
        expected_values4[i] /= sum4;
        dbgchk(fabs(tns_get(tns, i) - expected_values4[i]) < epsilon, "Error in increasing values tensor. Expected %f, got %f", expected_values4[i], tns_get(tns, i));
    }
    tns_free(tns);

    // Test Case 5: Random float values
    tns_new(tns, 3); // Create a 3-element tensor
    float random_values[] = {1.2f, 3.4f, 2.2f};
    tns_cpy(tns, random_values);
    tns_fp32_softmax(tns,tns);

    float expected_values5[3];
    float sum5 = 0.0f;
    for (int i = 0; i < 3; i++) {
        expected_values5[i] = expf(random_values[i]);
        sum5 += expected_values5[i];
    }
    for (int i = 0; i < 3; i++) {
        expected_values5[i] /= sum5;
        dbgchk(fabs(tns_get(tns, i) - expected_values5[i]) < epsilon, "Error in random values tensor. Expected %f, got %f", expected_values5[i], tns_get(tns, i));
    }
    tns_free(tns);

    // Test Case 6: All elements are zero
    tns_new(tns, 4); // Create a 4-element tensor
    float zero_values[] = {0.0f, 0.0f, 0.0f, 0.0f};
    tns_cpy(tns, zero_values);
    tns_fp32_softmax(tns,tns);
    for (int i = 0; i < 4; i++) {
        dbgchk(fabs(tns_get(tns, i) - 0.25f) < epsilon, "Error in all zero elements tensor. Expected 0.25, got %f", tns_get(tns, i));
    }
    tns_free(tns);
}

int main() {
    test_tns_fp32_softmax();
    return 0;
}