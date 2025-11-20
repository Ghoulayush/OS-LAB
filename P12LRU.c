#include <stdio.h>

int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    int frames[10], pages[30], time[10];
    int frameCount, pageCount, counter = 0, flag1, flag2;
    int i, j, pos, faults = 0, hits = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frameCount);
    printf("Enter number of pages: ");
    scanf("%d", &pageCount);
    printf("Enter the page sequence: ");
    for (i = 0; i < pageCount; ++i)
        scanf("%d", &pages[i]);
    for (i = 0; i < frameCount; ++i)
        frames[i] = -1;
    printf("\n");
    for (i = 0; i < pageCount; ++i){
        flag1 = flag2 = 0;
        for (j = 0; j < frameCount; ++j){
            if (frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                hits++;
                break;
            }
        }
        if (flag1 == 0){
            for (j = 0; j < frameCount; ++j){
                if (frames[j] == -1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0){
            pos = findLRU(time, frameCount);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("Page: %-3d\t", pages[i]);
        if (flag1 == 1)
            printf("HIT\t");
        else
            printf("MISS\t");
        printf("FRAMES: ");
        for (j = 0; j < frameCount; ++j){
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults: %d\n", faults);
    printf("Total Number of Page Hits: %d\n", hits);
    float faultRatio = (float)faults / pageCount;
    printf("Fault Ratio: %.2f\n", faultRatio);
    return 0;
}
