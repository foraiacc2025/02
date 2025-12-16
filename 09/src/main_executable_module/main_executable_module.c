#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../yet_another_decision_module/decision.h"

#ifdef USE_DYNAMIC
#include <dlfcn.h>
#else
#include "../data_module/data_process.h"
#endif

int main() {
    int result = 0;
    int n;
    double *data = NULL;
    
#ifdef USE_DYNAMIC
    void *handle = NULL;
    int (*normalization)(double *, int) = NULL;
    void (*sort)(double *, int) = NULL;
    
    handle = dlopen("/workspaces/02/build/data_process.so", RTLD_LAZY);
    if (handle) {
        normalization = dlsym(handle, "normalization");
        sort = dlsym(handle, "sort");
        if (!normalization || !sort) {
            fprintf(stderr, "Cannot load symbols: %s\n", dlerror());
            result = 1;
        }
    } else {
        fprintf(stderr, "Cannot open library: %s\n", dlerror());
        result = 1;
    }
#endif

    if (result == 0) {
        printf("LOAD DATA...\n");
        scanf("%d", &n);
        
        if (n <= 0) {
            printf("n/a\n");
            result = 1;
        } else {
            data = (double *)malloc(n * sizeof(double));
            if (data == NULL) {
                printf("n/a\n");
                result = 1;
            } else {
                input(data, n);

                printf("RAW DATA:\n\t");
                output(data, n);

                printf("NORMALIZED DATA:\n\t");
                if (normalization(data, n)) {
                    output(data, n);
                    
                    printf("SORTED NORMALIZED DATA:\n\t");
                    sort(data, n);
                    output(data, n);
                    
                    printf("FINAL DECISION:\n\t");
                    if (make_decision(data, n)) {
                        printf("YES\n");
                    } else {
                        printf("NO\n");
                    }
                } else {
                    printf("ERROR\n");
                    result = 1;
                }
                
                free(data);
            }
        }
    }
    
#ifdef USE_DYNAMIC
    if (handle) {
        dlclose(handle);
    }
#endif
    
    return result;
}
