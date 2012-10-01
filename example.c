/* Murmur3 example: hash the first command line argument. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "murmur3.h"

int main(int argc, char **argv) {
  uint32_t hash[4];                /* Output for the hash */
  uint32_t seed = 42;              /* Seed value for hash */

  if (argc != 2) {
    printf("usage: %s \"string to hash\"\n", argv[0]);
    exit(1);
  }

  printf("Input: \"%s\"\n", argv[1]);
  
  MurmurHash3_x86_32(argv[1], strlen(argv[1]), seed, hash);
  printf("x86_32:  %08x\n", hash[0]);

  MurmurHash3_x86_128(argv[1], strlen(argv[1]), seed, hash);
  printf("x86_128: %08x %08x %08x %08x\n",
         hash[0], hash[1], hash[2], hash[3]);

  MurmurHash3_x64_128(argv[1], strlen(argv[1]), seed, hash);
  printf("x64_128: %08x %08x %08x %08x\n",
         hash[0], hash[1], hash[2], hash[3]);

  return 0;
}
