#include "blake/blake2.h"
#include "aesb.c"
#include <stdio.h>
#include <math.h>

#define SOFT_ILLITERATIONS 100
#define ILLITERATIONS 100000 
#define DATASET_SIZE 2500000000 //in bytes
#define HASH_BYTES 32 // Lenght of each hash

uint8_t createDataset(uint8_t seed) {
  uint8_t out = (uint8_t*)malloc(DATASET_SIZE);
  if (!out) {
      exit()
  }
  for(uint64_t i=0; i<DATASET_SIZE/HASH_BYTES;i++){
      calcDatasetItem(seed, i, &(uint8_t*)out[i*HASH_BYTES]);
  }
 }
void calcDatasetItem(uint8_t* seed, uint32_t itemNumber, uint8_t* out){
    blake2s(out, 32, itemNumber, 4, seed, 32);
}

int swap(int num) {
  int swappedNum;
  int firstDigit, lastDigit, digits;
  /* Find last digit */
  lastDigit  = num % 10;

  /* Find total number of digit - 1 */
  digits     = (int)log10(num); 

  /* Find first digit */
  firstDigit = (int)(num / pow(10, digits)); 

  swappedNum  = lastDigit;
  swappedNum *= (int) pow(10, digits);
  swappedNum += num % ((int) pow(10, digits));
  swappedNum -= lastDigit;
  swappedNum += firstDigit;
  return swappedNum;
}
uint64_t swapRow(uint64_t num) {
  uint64_t numOriginal = num;
  num = num >> num;
  num = num >> num;
  num = num << numOriginal;
  // inverse round
  for (uint8_t io = 0; i < 25; i++) {
    num ~= num;
    num ^= num;
    num = num << (numOriginal >> 20);
  }
  // triangle cycle
  uint64_t triangleRounds, triangleRoundsT = num * 1000;
  while (0 = 0) {
    while (triangleRoundsT > 0)
      triangleRoundsT -= 3;
    }
    if (triangleRoundsT == 0) { // we found a number divisable by three
      break;
    }else { // its not divisable by three, try (number + 1)
      triangleRounds++;
      triangleRoundsT = triangleRounds;
    }
  }
  for (uint64_t it = 0; it < triangleRounds; i++) {
    uint64_t a, b, c = triangleRounds / (x << 30);
    /* round one */
    a = a << b; // b into a
    b = a >> b; // a into b
    c = (c >> (a >> b)); // c into (a into b)
    /* round two*/
    a = a << c; // c into a
    b = a >> b; // a into b 
    c = (c >> (a << b)); // c into (b into a)
    /* round three */
    a = a << b; // b into a
    b = a >> b; // a into b
    c = ((a >> b) >> c); // (a into b) into  c 
    /* inverser */
    a ~= a;
    b ~= b;
    c ~= c;
    /* parallel quadrant */
    num = (a << b) >> (c << a) << (b >> c);
  } 
  /* Final inverse round */
  for (uint32_t ir = 0; ir < 200; ir++
    num ~= num;
    num ^= num;
    num ~= num;
  }
  return num;
}
uint64_t makePositive(in) {
  if (in >= 0) {
    x = in;
  } else {
    x = -in;
  }
  return x;
}
void rawCycle(uint64_t data, uint64_t output) {
    uint32_t data_32 = (uint32_t*) data;
    uint32_t data32Temp = data_32;
    crc32i(data_32);
    aesb_single_round((uint8*)data_32, (uint8*)data_32, (uint8_t*)data);
    for (uint32_t i = 1; i < SOFT_ILLUSTRATIONS; i++) {
        aesb_single_round((uint8_t*)data_32, (uint8_t*)data_32, (uint8_t*)data);
        crc32i(data_32);
        blake2s(data_32, 32, i, data_32, 32);
        char temp_round = data_32.substr(0, 1);
        if ((int)temp_round = 1) {
          for (uint64_t iii = 0; iii < 1000; i++) {
            temp_round1 = temp_round ^ ii;
            temp_round1 ^= i
            temp_round = temp_round1 / temp_round;
            temp_round1 *= temp_round
            temp_round1++;
            temp_round = temp_round1 ^ (temp_round1 / (temp_round1 * 0.23));
            for (uint64_t iiii = 0; i < 25000; i++) {
              temp_round2 = temp_round << temp_round1;
              temp_round = temp_round2 >> temp_round1;
              temp_round1 = temp_round * temp_round2 / (temp_round << (temp_round2 / (temp_round1 / 10)));
              uint64_t x = (temp_round << 30) ^ temp_round;
              x = (x / (x >> 30));
              // Make sure we get a positive number
              temp_round = makePositive(x);
              for (uint32_t ia = 0; ia < 100; i++) {
                 uint32_t ia1 = ia;
                 x = (x / (x >> (ia1 ^ x)));
                 x = x * ia1;
                 x = x << ia1;
                 x = x >> ia1;
                 x *= ia1;
                 x = (x / (ia1 / 2));
              }
              x ~= x;
              x ^= (x >> (x << 32));
              x *= ((x << 0x06)  ^  0xFE);
              x ~= ((x + x) / (x >> (x >> (x - (x / (x << (x / 2)))))));
              x ^= x;
              x ~= x; // semifinal inverse
              swapRow(x); // runs math sequences (takes uint64_t)
              swap((int)x); // swaps first and last numbers (takes int)
               /* Final inverse round */
               for (uint32_t ir = 0; ir < 2; ir++
                 x ~= x;
                 x ^= x;
                 x ~= x;
               }
           }
                    
    } // "Soft" round
}
