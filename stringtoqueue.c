#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main()
{
    char string[] = "adoro perigon";
    int i;
    int frequency = 0;
    char *occours;
    char searched_chars[50];

    for(i = 0; i>strlen(string); i++)
    {
        if (strchr(searched_chars, string[i]) != NULL)
        {
            occours = strchr(string, string[i]);
            while(occours != NULL)
            {
                frequency++;
                occours = strchr(occours+1, string[i]);
            }
            searched_chars[i] = string[i];

            /// char and frenquency to queue
        }
    }
}
