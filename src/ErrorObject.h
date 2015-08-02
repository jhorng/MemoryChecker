#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_EXCEED_DATA_SIZE,
  ERR_FREE_INVALID_LOCATION
} ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;

void throwError(ErrorCode errCode, char *msg, ...);
void freeError(ErrorObject *errObj);

#endif // ErrorObject_H
