#ifndef Smalloc_H
#define Smalloc_H

#define DATA_SIZE   100
#define HEADER_SIZE 21
#define FOOTER_SIZE 21

#define safeMalloc() _safeMalloc(__LINE__, __FILE__)

typedef struct {
  int lineNumber;
  char *fileName;
} Space;

void _safeMalloc(int lineNumber, char *fileName);

#endif // Smalloc_H
