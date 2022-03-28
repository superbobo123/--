#include <stdio.h>
#include <string.h>

int main()
{
    FILE *p1, *p2;
    char buffer[210], ch;
    int movieID, i;

    p1 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\output2.txt", "a+");
    p2 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\movies.csv", "r");

    while (!feof(p2))
    {
        i = 0;
        fscanf(p2, "%d,", &movieID);
        fprintf(p1, "%d:", movieID);
        ch = fgetc(p2);
        if (ch == '\"')
        {
            fgets(buffer, 209, p2);
            //buffer[strlen(buffer) - 2] = '\0';
            while (buffer[i] != '\"')
            {
                i++;
            }
            i += 2;
            while (buffer[i] != '\0')
            {
                if (buffer[i] != '|'&&buffer[i]!='\n')
                {
                    fputc(buffer[i], p1);
                }
                else
                {
                    fputc(',', p1);
                }
                i++;
            }
        }
        else
        {
            fgets(buffer, 209, p2);
            while (buffer[i] != ',')
            {
                i++;
            }
            i++;
            while (buffer[i] != '\0')
            {
                if (buffer[i] != '|'&&buffer[i]!='\n')
                {
                    fputc(buffer[i], p1);
                }
                else
                {
                    fputc(',', p1);
                }
                i++;
            }
        }
        fprintf(p1, "\n");
    }
    fclose(p1);
    fclose(p2);

    return 0;
}