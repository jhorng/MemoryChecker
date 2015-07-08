#ifndef Smalloc_H
#define Smalloc_H

#define DATA_SIZE   100
#define HEADER_SIZE 21
#define FOOTER_SIZE 21

#define safeMalloc() _safeMalloc(__LINE__,__FILE__)


typedef struct {
  int headerSize;
  int footerSize;
  int size;
} Space;

Space *createMemorySpace();
void patternRepeat( int timesToCopy,char *pattern, char *pointer);

#endif // Smalloc_H
