#include <stdio.h>
#include <stdlib.h> // for abs function

void cscan(int req[], int n, int head, int tc, int dir, int seq[]) {
    int left[n], right[n], leftcount = 0, rightcount = 0;
    for (int i = 0; i < n; i++) {
        if (req[i] < head) {
            left[leftcount++] = req[i];
        } else {
            right[rightcount++] = req[i];
        }
    }

    // Sorting left array in descending order
    for (int i = 0; i < leftcount - 1; i++) {
        for (int j = 0; j < leftcount - 1 - i; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    // Sorting right array in ascending order
    for (int i = 0; i < rightcount - 1; i++) {
        for (int j = 0; j < rightcount - 1 - i; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    int idx = 0;
    if (dir == 0) {
        for (int i = 0; i < leftcount; i++) {
            seq[idx++] = left[i];
        }
        seq[idx++] = 0; // Adding the head position
        seq[idx++] = tc - 1; // Adding the total cylinders
        for (int i = rightcount - 1; i >= 0; i--) {
            seq[idx++] = right[i];
        }
    } else {
        for (int i = 0; i < rightcount; i++) {
            seq[idx++] = right[i];
        }
        seq[idx++] = tc - 1; // Adding the total cylinders
        seq[idx++] = 0; // Adding the head position
        for (int i = leftcount - 1; i >= 0; i--) {
            seq[idx++] = left[i];
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        printf("%d ", seq[i]);
    }

    int seek_count = abs(head - seq[0]);
    for (int i = 1; i < n + 1; i++) {
        seek_count += abs(seq[i] - seq[i - 1]);
    }
    printf("\nSeekcount=%d", seek_count);
}

int main() {
    int n;
    printf("Enter no. of requests:");
    scanf("%d", &n);
    int req[n], head, totalcylinders, dir;
    printf("Enter all requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    printf("Enter head request:");
    scanf("%d", &head);
    printf("Enter total no. of cylinders:");
    scanf("%d", &totalcylinders);
    printf("Enter direction(1-->right 0-->left):");
    scanf("%d", &dir);
    int seq[n + 2];
    cscan(req, n, head, totalcylinders, dir, seq);
    return 0;
}

//176 79 34 60 92 11 41 114
