#include <stdio.h>

void printFrames(int frame[], int frames) {
    for(int i = 0; i < frames; i++) {
        if(frame[i] == -1)
            printf("- ");
        else
            printf("%d ", frame[i]);
    }
}

// FIFO Algorithm
void fifo(int pages[], int n, int frames) {

    int frame[frames];
    int faults = 0, hits = 0;

    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    int index = 0;

    printf("\nFIFO:\n");

    for(int i = 0; i < n; i++) {

        int found = 0;

        // Check page hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        // Page Fault
        if(!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        printFrames(frame, frames);

        if(found)
            printf("  HIT");
        else
            printf("  FAULT");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits   = %d\n", hits);
}

// LRU Algorithm
void lru(int pages[], int n, int frames) {

    int frame[frames], time[frames];
    int faults = 0, hits = 0, counter = 0;

    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = -1;
    }

    printf("\nLRU:\n");

    for(int i = 0; i < n; i++) {

        int found = 0;

        // Check page hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                hits++;
                break;
            }
        }

        // Page Fault
        if(!found) {

            int pos = 0;

            // Find empty frame first
            for(int j = 0; j < frames; j++) {

                if(frame[j] == -1) {
                    pos = j;
                    break;
                }

                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];

            counter++;
            time[pos] = counter;

            faults++;
        }

        printf("Page %d -> ", pages[i]);
        printFrames(frame, frames);

        if(found)
            printf("  HIT");
        else
            printf("  FAULT");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits   = %d\n", hits);
}

// Optimal Algorithm
void optimal(int pages[], int n, int frames) {

    int frame[frames];
    int faults = 0, hits = 0;

    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nOptimal:\n");

    for(int i = 0; i < n; i++) {

        int found = 0;

        // Check page hit
        for(int j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        // Page Fault
        if(!found) {

            int pos = -1;

            // Check empty frame
            for(int j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // Apply Optimal Replacement
            if(pos == -1) {

                int farthest = -1;

                for(int j = 0; j < frames; j++) {

                    int k;

                    // Find next use
                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k])
                            break;
                    }

                    // Never used again
                    if(k == n) {
                        pos = j;
                        break;
                    }

                    // Select farthest page
                    if(k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        printFrames(frame, frames);

        if(found)
            printf("  HIT");
        else
            printf("  FAULT");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Page Hits   = %d\n", hits);
}

int main() {

    int n, frames;

    printf("Gabriel E Nitin\n");
    printf("1BM25CS442\n\n");

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    fifo(pages, n, frames);
    lru(pages, n, frames);
    optimal(pages, n, frames);

    return 0;
}
