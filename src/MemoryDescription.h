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



// MemoryDescription *createMallocMemDesc(int mallocLine, int sizeDefined, char *mallocFile);
MemoryDescription *createMallocMemDesc(int mallocLine, int sizeDefined, char *mallocFile, MemoryDescription *allocAddr);
MemoryDescription *createFreeMemDesc(int freeLine, char *freeFile);

/* 
typedef struct MemoryDescription_t AddrDescription;
struct AddrDescription_t{
  AddrDescription *next;

  char *headerAddress;
  char *memoryAddress;
  char *footerAddress;
};
 */



#endif // MemoryDescription_H
