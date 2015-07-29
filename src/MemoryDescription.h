#ifndef MemoryDescription_H
#define MemoryDescription_H

typedef struct MemoryDescription_t MemoryDescription;
struct MemoryDescription_t{
  MemoryDescription *next;
  int mallocLine;
  int dataSize;
  char *mallocFile;
  char *headerAddress;
  char *memoryAddress;
  char *footerAddress;
  int freeLine;
  char *freeFile;
};

MemoryDescription *createMemoryDescription(int lineNumber, int sizeDefined, char *fileName);

#endif // MemoryDescription_H
