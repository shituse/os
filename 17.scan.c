#include <stdio.h>

void scan(int req[], int n, int head, int tc, int dir, int seq[]) {
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
        for (int i = 0; i < rightcount; i++) {
            seq[idx++] = right[i];
        }
    } else {
        for (int i = 0; i < rightcount; i++) {
            seq[idx++] = right[i];
        }
        seq[idx++] = tc; // Adding the total cylinders
        for (int i = 0; i < leftcount; i++) {
            seq[idx++] = left[i];
        }
    }

    for (int i = 0; i <=n; i++) {
        printf("%d ", seq[i]);
    }
    int seek_count;
    seek_count=abs(head-seq[0]);
    for (int i = 0; i < n ; i++) {
        seek_count += abs(seq[i + 1] - seq[i]);
    }
    printf("\nSeekcount=%d",seek_count);

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
    int seq[n];
    scan(req, n, head, totalcylinders, dir, seq);
    return 0;
}
