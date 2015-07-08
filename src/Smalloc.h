#ifndef Smalloc_H
#define Smalloc_H

#define safeMalloc(size) _safeMalloc(size,__LINE__,__FILE__)

#define DATA_SIZE     100
#define HEADER_SIZE 	21
#define FOOTER_SIZE 	21

typedef struct {
  int headerSize;
  int footerSize;
  int size;
} Space;

Space *createMemorySpace();
void patternRepeat( int timesToCopy,char *pattern, char *pointer);

#endif // Smalloc_H
