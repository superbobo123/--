#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct people
{
    int id;
    int tags[20];
} p;

char *tag[20] = {"Action\0",
                 "Adventure\0",
                 "Animation\0",
                 "Children\0",
                 "Comedy\0",
                 "Crime\0",
                 "Documentary\0",
                 "Drama\0",
                 "Fantasy\0",
                 "Film-Noir\0",
                 "Horror\0",
                 "IMAX\0",
                 "Musical\0",
                 "Mystery\0",
                 "Romance\0",
                 "Sci-Fi\0",
                 "Thriller\0",
                 "War\0",
                 "Western\0",
                 "(no genres listed)\0"};

int main()
{
    FILE *p1, *p2, *p3;
    int id = 0, movieID, tmp, n = 10;
    char buf[200], temp[22];

    p1 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\output1.txt", "r");
    p3 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\oupt.txt", "a+");
    while (!feof(p1))
    {
        for (int i = 0; i < 21; i++)
        {
            p.tags[i]=0;
        }
        
        fscanf(p1, "%d:", &id);
        fprintf(p3, "%3d:", id);
        while (fscanf(p1, "%d", &tmp) && tmp != -1)
        {
            p2 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\output2.txt", "r");
            while (!feof(p2))
            {
                fscanf(p2, "%d:", &movieID);
                fgets(buf, 100, p2);
                if (movieID == tmp)
                {
                    int j = 0, k = 0;
                    while (buf[j] != '\n')
                    {
                        if (buf[j] != ',')
                        {
                            temp[k] = buf[j];
                            k++;
                        }
                        else
                        {
                            temp[k] = '\0';
                            for (int t = 0; t < 21; t++)
                            {
                                if (strcmp(tag[t], temp) == 0)
                                {
                                    p.tags[t]++;
                                }
                            }
                            k = 0;
                        }
                        j++;
                    }
                    break;
                }
            }
            fclose(p2);
        }
        for (int i = 0; i < 20; i++)
        {
            //if (p.tags[i] != 0)
            {
                fprintf(p3, " %s %5d |", tag[i], p.tags[i]);
            }
        }
        fprintf(p3, "\n");
    }
    fclose(p1);
    fclose(p3);

    printf("Time = %.3f s\n", (double)clock()/CLOCKS_PER_SEC);

    return 0;
}