#ifndef CCLASECOMPILER_SERVICE_H
#define CCLASECOMPILER_SERVICE_H


typedef struct service {
    char** (*explode)(const char *src, const char *tokens, int* len);
    int (count_chars) (const char*);
} service;

service Service();

#endif //CCLASECOMPILER_SERVICE_H
