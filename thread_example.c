#include <stdio.h>
#include <pthread.h>

//Int that is output to show that the thread ran
int my_global_int = 10;

//Declare function that will be threaded. Null pointer return and parameter
void* threaded_function(void* data);

int main() {
    //Variable to store ID of thread that will be spawned
    pthread_t thread_id;
    
    printf("The initial value of my_global_int is: %d\n", my_global_int);
    //Create a thread, giving the ID to thread_id, no attributes, the thread will run
	//the function threaded_function, and no extra data
    pthread_create(&thread_id, NULL, threaded_function, NULL);
    //Wait for the specified thread to finish
    pthread_join(thread_id, NULL);

    printf("The final value of my_global_int is: %d\n", my_global_int);
}

void* threaded_function(void* data) {
    // Wait for one second so that we can see what happens when pthread_join() is commented out above
    sleep(1);
    my_global_int += 10;
    printf("The child thread has increased the value of my_global_int by 10\n");
}
