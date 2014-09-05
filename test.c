/* Tests */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "murmur3.h"

static void hex32(uint32_t *hash, char *buf) {
    sprintf(buf, "%08x", *hash);
}

static void hex128(uint32_t hash[4], char *buf) {
    sprintf(buf, "%08x%08x%08x%08x", hash[0], hash[1], hash[2], hash[3]);
}

int main(void) {
    int passed = 0, failed = 0;

#define TESTHASH(arch, nbytes, seed, str, expected) {                   \
        char *input = str;                                              \
        uint32_t hash[4];                                               \
        char buf[33];                                                   \
        MurmurHash3_##arch##_##nbytes(input, strlen(input), (seed), hash); \
        hex##nbytes(hash, buf);                                         \
        if (strcmp(buf, expected) != 0) {                               \
            printf("FAIL(line %i): %s != %s\n", __LINE__, expected, buf); \
            failed++;                                                   \
        } else passed++;                                                \
    }

    TESTHASH(x86, 32, 1234, "Hello, world!", "faf6cdb3");
    TESTHASH(x86, 32, 4321, "Hello, world!", "bf505788");
    TESTHASH(x86, 32, 1234, "xxxxxxxxxxxxxxxxxxxxxxxxxxxx", "8905ac28");
    TESTHASH(x86, 32, 1234, "", "0f2cc00b");

    TESTHASH(x86, 128, 123, "Hello, world!", "61c9129e5a1aacd7a41621629e37c886");
    TESTHASH(x86, 128, 321, "Hello, world!", "d5fbdcb3c26c4193045880c5a7170f0f");
    TESTHASH(x86, 128, 123, "xxxxxxxxxxxxxxxxxxxxxxxxxxxx", "5e40bab278825a164cf929d31fec6047");
    TESTHASH(x86, 128, 123, "", "fedc524526f3e79926f3e79926f3e799");

    TESTHASH(x64, 128, 123, "Hello, world!", "8743acad421c8c73d373c3f5f19732fd");
    TESTHASH(x64, 128, 321, "Hello, world!", "f86d4004ca47f42bb9546c7979200aee");
    TESTHASH(x64, 128, 123, "xxxxxxxxxxxxxxxxxxxxxxxxxxxx", "becf7e04dbcf74637751664ef66e73e0");
    TESTHASH(x64, 128, 123, "", "4cd9597081679d1abd92f8784bace33d");

    printf("Total tests: %i\nPassed: %i\nFailed: %i\n", passed + failed, passed, failed);
    return failed > 0;
}
