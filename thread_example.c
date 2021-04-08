#include <stdio.h>
#include <pthread.h>

int my_global_int = 10;

void* threaded_function(void* data);

int main() {
    pthread_t thread_id;
    
    printf("The initial value of my_global_int is: %d\n", my_global_int);
    pthread_create(&thread_id, NULL, threaded_function, NULL);

    pthread_join(thread_id, NULL);

    printf("The final value of my_global_int is: %d\n", my_global_int);
}

void* threaded_function(void* data) {
    // Wait for one second so that we can see what happens when pthread_join() is commented out above
    sleep(1);
    my_global_int += 10;
    printf("The child thread has increased the value of my_global_int by 10\n");
}
