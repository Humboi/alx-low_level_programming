#ifndef 	FILE_MAIN
#define FILE_MAIN

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _isdigit(char *argv);
int _atoi(char *s);
int main(int argc, char *argv[]);

#endif /* FILE_MAIN */