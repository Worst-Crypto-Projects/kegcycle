#include <blake2.h>
#define DATASET_SIZE 2500000000
#define DATABIT_SIZE 1
uint64_t gendataset(uint64_t data) {
  uint64_t* dataset = (uint64_t*)malloc(2500000000); // Initilise dataset in Ram (2.5 GB)
  dataset[0] = data;
  dataset[1] = aes(dataset[0],dataset[0]);
  dataset[1] = blake2(dataset[1]);
  for (uint8_t i = 2; i < DATASET_SIZE / DATABIT_SIZE; i++) {
    dataset[i] = aes(dataset[i-1],dataset[i-2]);
    dataset[i] = blake2(dataset[i]);
  }
  return dataset;
}
