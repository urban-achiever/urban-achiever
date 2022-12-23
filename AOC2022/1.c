#include "stdio.h"
#include "stdlib.h"

void checkTop (int newsum, unsigned int* toplist, int size)
{
    int tmp;
    for (int i = 0; i < size; i++)
    {
        if (newsum > toplist[i])
        {
            tmp = toplist[i];
            toplist[i] = newsum;
            newsum = tmp;
        }
    }
}
int main (void) {
    FILE *input = fopen("input1.txt", "r");
    char *line = NULL;
    size_t len = 0;
    size_t numread;
    unsigned int top3[3] = {0, 0, 0};
    unsigned int currentSum = 0;
    unsigned int maxSum = 0;
    
    if (input == NULL) 
    {
        printf("File opening failed.\n");
    }
    else 
    {
        while ((numread = getline(&line, &len, input)) != -1) 
        {
            if (numread == 1)
            {
                if (currentSum > maxSum)
                {
                    maxSum = currentSum;
                }
                checkTop(currentSum, top3, 3);
                currentSum = 0;
                continue;
            }
            else
            {
                currentSum += atoi(line);
            }

        }
        printf("Largest sum is: %u\n", maxSum);
        printf("3 largest sums are: %u %u %u Total: %u\n", top3[0], top3[1], top3[2], top3[0] + top3[1] + top3[2]);
        fclose(input);
    }
}
