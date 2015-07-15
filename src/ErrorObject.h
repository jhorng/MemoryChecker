#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_EXCEED_DATA_SIZE
} ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;

void throwError(char *message, ErrorCode errCode);
void freeError(ErrorObject *errObj);

#endif // ErrorObject_H
