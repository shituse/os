#include <stdio.h>
#include <stdbool.h>

void pageFaults(int pages[], int n, int frames, int *page_faults, int *hits)
{
    bool s[100] = {false};
    int indexes[frames];
    for (int i = 0; i < frames; i++)
        indexes[i] = -1;
    *page_faults = 0;
    *hits = 0;
    int front = 0;
    int rear = -1;
    for (int i = 0; i < n; i++)
    {
        printf("Page %d: ", pages[i]);
        bool hit = false;
        if (rear < frames - 1)
        {
            if (!s[pages[i]])
            {
                s[pages[i]] = true;
                (*page_faults)++;
                rear++;
                s[indexes[rear]] = false;
                indexes[rear] = pages[i];
            }
            else
            {
                (*hits)++;
                hit = true;
            }
        }
        else
        {
            if (!s[pages[i]])
            {
                int val = indexes[front];
                front = (front + 1) % frames;
                s[val] = false;
                s[pages[i]] = true;
                rear = (rear + 1) % frames;
                indexes[rear] = pages[i];
                (*page_faults)++;
            }
            else
            {
                (*hits)++;
                hit = true;
            }
        }
        for (int j = 0; j < frames; j++)
        {
            if (indexes[j] == -1)
                printf("-1 ");
            else
                printf("%d ", indexes[j]);
        }
        if (hit)
            printf("(Hit)\n");
        else
            printf("(Page Fault)\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the reference string:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    int frames;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int page_faults, hits;
    pageFaults(pages, n, frames, &page_faults, &hits);

    double hit_ratio = (double)hits / n;
    double miss_ratio = 1 - hit_ratio;

    printf("\nHit Ratio: %.2lf\n", hit_ratio);
    printf("Miss Ratio: %.2lf\n", miss_ratio);

    return 0;
}
