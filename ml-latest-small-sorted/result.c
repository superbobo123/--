#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *p1, *p2, *p3;
    int userID = 0, movieID, tmp;
    long long timestamp;
    float rating;

    p1 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\output1.txt", "a+");
    p2 = fopen("D:\\VSCODE_c++\\test\\cpp\\homework\\ml-latest-small-sorted\\ratings.csv", "r");

    while (!feof(p2))
    {
        fscanf(p2, "%d,%d,%f,%lld", &tmp, &movieID, &rating, &timestamp);
        if (tmp != userID)
        {
            userID = tmp;
            fprintf(p1, "-1\n%d: ", userID);
        }
        if (rating >= 3)
        {
            fprintf(p1, "%d ", movieID);
        }
    }
    fclose(p1);
    fclose(p2);

    return 0;
}