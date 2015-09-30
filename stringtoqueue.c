#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main()
{
    char string[] = "adoro perigon";
    int count;
    int frequency = 0;
    char *occours;
    char searched_chars[50];

    for(count = 0; count<strlen(string); count++)
    {
        printf("letter: %c\n", string[count]);
        if (strchr(searched_chars, string[count]) == NULL)
        {
            occours = strchr(string, string[count]);
            while(occours != NULL)
            {
                printf("repetiu\n");
                frequency++;
                occours = strchr(occours+1, string[count]);
            }
            searched_chars[count] = string[count];
            printf("Frequency: %d\n", frequency);
            frequency = 0;
            printf("\n");
            /// char and frequency to queue
            /// queue(string[count], frequency)
        }
    }

}
