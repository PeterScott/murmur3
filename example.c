/* Murmur3 example: hash the first command line argument. */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "murmur3.h"

int main(int argc, char **argv) {
  uint32_t hash[4];                /* Output for the hash */
  uint32_t seed = 42;              /* Seed value for hash */

  /*
   * Use custom input
   */
  if (argc == 2) {
    printf("\nInput: \"%s\"\n\n", argv[1]);

    MurmurHash3_x86_32(argv[1], strlen(argv[1]), seed, hash);
    printf("x86_32 hex:  %08x\n", hash[0]);
    printf("x86_32 dec:  %d\n\n", hash[0]);

    MurmurHash3_x86_128(argv[1], strlen(argv[1]), seed, hash);
    printf("x86_128 hex: %08x %08x %08x %08x\n",
           hash[0], hash[1], hash[2], hash[3]);
      printf("x86_128 dec: %d %d %d %d\n\n",
             hash[0], hash[1], hash[2], hash[3]);

    MurmurHash3_x64_128(argv[1], strlen(argv[1]), seed, hash);
    printf("x64_128 hex: %08x %08x %08x %08x\n", hash[0], hash[1], hash[2], hash[3]);
      printf("x64_128 dec: %d %d %d %d\n\n", hash[0], hash[1], hash[2], hash[3]);

    return 0;
  }
  /*
   * Use hello world example
   */
  else {
    char *input = "Hello world";

    printf("\nInput: \"%s\"\n\n", input);

    MurmurHash3_x86_32(input, strlen(input), seed, hash);
    printf("x86_32 hex:  %08x\n", hash[0]);
      printf("x86_32 dec:  %d\n\n", hash[0]);

    MurmurHash3_x86_128(input, strlen(input), seed, hash);
    printf("x86_128 hex: %08x %08x %08x %08x\n",
           hash[0], hash[1], hash[2], hash[3]);
      printf("x86_128 dec: %d %d %d %d\n\n",
             hash[0], hash[1], hash[2], hash[3]);

    MurmurHash3_x64_128(input, strlen(input), seed, hash);
    printf("x64_128 hex: %08x %08x %08x %08x\n", hash[0], hash[1], hash[2], hash[3]);
      printf("x64_128 dec: %d %d %d %d\n\n", hash[0], hash[1], hash[2], hash[3]);

    return 0;
  }
}
