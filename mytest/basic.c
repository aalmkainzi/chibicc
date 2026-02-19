
_Nameprefix pt = "pthread_";
_Nameprefix mem = "mem";
_Nameprefix str = "str";

_Capture _Nameprefix
    pt,
    mem,
    str
{
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <string.h>
}

#define NUM_THREADS 4

void* thread_function(void* arg) {
    int id = *(int*)arg;
    printf("Hello from thread %d\n", id);
    return NULL;
}

int main() {
    char *str = "hello";
    char buf[64];
    str::cpy(buf, str);
    
    
    pt::t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        
        if (pt::create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("pthread_create failed");
            return 1;
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pt::join(threads[i], NULL);
    }
    
    printf("All threads finished.\n");
    return 0;
}