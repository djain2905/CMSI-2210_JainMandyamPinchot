/* times how long you can hold your breath, reported in minutes and seconds*/

#include <stdio.h>
#include <time.h>

/* block until the user hits enter, discarding anything else typed first*/
static int waitforenter(void) {
    int c; 
    while ((c = getchar()) != '\n') {
        if (c == EOF) {
            return 1; 
        }
    }
    return 0;
}

int main(void) {
    printf("This program will time how long you can hold your breath for. \n");
    printf("Take a deep breath, then press the 'Enter' key.\n");
    printf("When you absolutely have to exhale, press the 'Enter' key again.\n"); 
    printf("The duration will be displayed in minutes and seconds.\n\n");

    if (waitforenter() !=0) {
        fprintf(stderr, "Input entered before timer started.\n"); 
        return 1; 
    }
    time_t start = time(NULL);
    printf("Hold it in!\n");
    fflush(stdout); 

    if (waitforenter() !=0) {
        fprintf(stderr, "Input entered before the timer stopped.\n");
        return 1; 
    }
    time_t stop = time(NULL); 

    if (start == (time_t)-1 || stop == (time_t)-1) {
        fprintf(stderr, "Error: could not read the system clock.\n"); 
        return 1; 
    }
    long total = (long)difftime(stop, start); 
    long minutes = total / 60; 
    long seconds = total % 60; 

    printf("You held your breath for %ld minute%s and %ld second%s.\n", 
        minutes, minutes == 1 ? "" : "s", 
        seconds, seconds == 1 ? "" : "s");
 }