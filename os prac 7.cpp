#include <stdio.h>
#include <stdbool.h>

#define NUM_FRAMES 3
#define NUM_PAGES 20

int main() {
    int frames[NUM_FRAMES];
    bool used[NUM_FRAMES] = {false};
    int page_seq[NUM_PAGES] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_faults = 0;
    for (int i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1;
    }
    for (int i = 0; i < NUM_PAGES; i++) {
        int page = page_seq[i];
        bool found = false;
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                found = true;
                used[j] = true;
                break;
            }
        }

        if (!found) {
            int lru = 0;
            for (int j = 1; j < NUM_FRAMES; j++) {
                if (!used[j] || used[j] < used[lru]) {
                    lru = j;
                }
            }
            frames[lru] = page;
            used[lru] = true;
            num_faults++;
        }
    }
    printf("Number of page faults: %d\n", num_faults);

    return 0;
}
