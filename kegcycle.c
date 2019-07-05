#include <blake2.h>
#include <aesb.c>
#define DATASET_SIZE 2500000000 //in bytes
#define HASH_BYTES 32 // Lenght of each hash


for(uint32_t i=0; i<DATASET_SIZE/HASH_BYTES;i++){
    calcDatasetItem(seed, i, &dataset[i*HASH_BYTES]);
}
void calcDatasetItem(uint8_t* seed, uint32_t itemNumber, uint8_t* out){
    blake2s(out, 32, itemNumber, 4, seed, 32);
}

void rawCycle(uint64_t data, uint64_t output) {
    uint32_t data_32 = (uint32_t*) data;
    uint32_t data32Temp = data_32;
    crc32i(data_32);
    aesb_single_round((uint8*)data_32, (uint8*)data_32, (uint8_t*)data);
    for (uint32_t i = 1; i < 10; i++) {
        aesb_single_round((uint8*)data_32, (uint8*)data_32, (uint8_t*)data);
    }
}
