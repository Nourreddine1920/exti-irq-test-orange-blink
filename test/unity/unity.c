#include "unity.h"
#include "NEC_IR.h"

void setUp(void) {}
void tearDown(void) {}

void test_initialization_does_not_crash(void) {
    NEC_Decoder_Init(); // This will be mocked or stubbed if needed
    TEST_ASSERT_TRUE(1); // Placeholder test
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_initialization_does_not_crash);
    return UNITY_END();
}
