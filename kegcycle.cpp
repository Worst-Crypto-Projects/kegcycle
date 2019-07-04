#include <blake2.h>
#define DATASET_SIZE 2500000000 //in bytes
#define HASH_BYTES 32 // Lenght of each hash

for(uint32_t i=0; i<DATASET_SIZE/HASH_BYTES;i++){
    calcDatasetItem(seed, i, &dataset[i*HASH_BYTES]);
}
void calcDatasetItem(uint8_t* seed, uint32_t itemNumber, uint8_t* out){
    blake2s(out, 32, itemNumber, 4, seed, 32);
}

