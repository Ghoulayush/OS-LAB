#include <stdio.h>
#include <stdlib.h>

int main()
{
    int frames, pages, page_faults = 0, page_hits = 0, fifo_ptr = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of page references: ");
    scanf("%d", &pages);

    int refs[pages], frame[frames];

    printf("Enter the page reference sequence: ");
    for (int i = 0; i < pages; i++)
        scanf("%d", &refs[i]);
    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nRef\tStatus\tFrames\n");

    for (int i = 0; i < pages; i++)
    {
        int page = refs[i], hit = 0;

        // Check for hit
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == page)
            {
                hit = 1;
                page_hits++;
                break;
            }
        }

        if (!hit)
        {
            page_faults++;
            // Find empty frame or use FIFO
            int placed = 0;
            for (int j = 0; j < frames; j++)
            {
                if (frame[j] == -1)
                {
                    frame[j] = page;
                    placed = 1;
                    break;
                }
            }
            if (!placed)
            {
                frame[fifo_ptr] = page;
                fifo_ptr = (fifo_ptr + 1) % frames;
            }
        }

        if (hit)
            printf("%d\tHit\t", page);
        else
            printf("%d\tFault\t", page);
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("\nTotal: %d, Faults: %d, Hits: %d, Fault Ratio: %.3f\n",
           pages, page_faults, page_hits, (double)page_faults / pages);

    return 0;
}
