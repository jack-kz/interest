#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int wordslength = 50;
int _cnt = 0;

void function1(char w[][2][wordslength], int cnt);                                               //单词随机出现，且数量无限，可能重复
void function2(char words[][2][wordslength], int cnt);                                           //可选择复习数量，单词区间，英汉互背
void function3(char words[][2][wordslength], int cnt);                                           //伪随机算法，对list进行随机的排列组合
void Strcpy(char a[wordslength], char b[wordslength]);                                           //将b字符串拷贝到a中
void lastwords(char w[][2][wordslength], int loc, int length, int type, int type2);              //将本次单词写入记忆文件（data1.txt）
void dwords(char en[wordslength], char ch[wordslength]);                                         //将单词写入错词文件（data2.txt）
void review(char words[][2][wordslength]);                                                       //调用本函数进行复习（递归）
void function4(char words[][2][wordslength], int cnt);                                           //可加载自主分组
void mixprint(char words[][2][wordslength], char group[][2][wordslength], int glength, int loc); //多种输出模式
int words_sta(int arc, char *arv[]);
int find(char words[][2][wordslength], int cnt);
int Switch(char words[][2][wordslength]); //临时转换函数
int Check(char a[wordslength], char b[wordslength]);
int main(int argc, char *argv[])
{

    printf("The word list contains %d words!!\n ", words_sta(argc, argv));
    printf("gogogo!!   come on!  come on!! \n");
    srand(time(0));
    int cnt = 0;
    int i = 0;
    FILE *last = fopen("data1.txt", "r");
    int conti = 2;
    int judge = 0;
    fscanf(last, "%d", &judge);
    fclose(last);
    FILE *fp;
    if (argc == 1)
    {
        fp = fopen("words.txt", "r");
    }
    else
    {
        fp = fopen(argv[1], "r");
    }

    char a[wordslength];
    fgets(a, wordslength - 1, fp);
    while (a[0] != '1')
    {
        cnt++;
        fgets(a, wordslength - 1, fp);
    }
    fclose(fp);

    _cnt = cnt / 2;

    if (argc == 1)
    {
        fp = fopen("words.txt", "r");
    }
    else
    {
        fp = fopen(argv[1], "r");
    }

    char words[cnt / 2 + 1][2][wordslength];
    /*
    int j = 0;
    for (i = 0; i < cnt / 2 + 1;i++){
        for (j = 0; j < wordslength;j++){
            words[i][0][j] = 0;
            words[i][1][j] = 0;
        }
    }
    */
    fgets(words[0][0], wordslength - 1, fp);
    fgets(words[0][1], wordslength - 1, fp);
    for (i = 1; words[i - 1][0][0] != '1'; i++)
    {
        fgets(words[i][0], wordslength - 1, fp);
        fgets(words[i][1], wordslength - 1, fp);
    }
    fclose(fp);

    //Switch(words);//在需要转换顺序时使用4

    if (judge != -1)
    {
        printf("Do you want to continue ? YES-->'1',NO-->'2':");
        scanf("%d", &conti);
    }
    if (conti != 2)
    {
        getchar();
        review(words);
    }
    else
    {

        printf("Fast mode enter '1',  Unit mode enter '2',  pseudorandom enter '3', Your style enter '4':");
        int mo = 3;

        scanf("%d", &mo);
        if (mo == 1)
        {
            function1(words, cnt / 2);
        }
        else if (mo == 2)
        {
            function2(words, cnt / 2);
        }
        else if (mo == 4)
        {
            function4(words, cnt / 2);
        }
        else
        {
            getchar();
            function3(words, cnt / 2);
            mixprint(words, words, cnt / 2, 0);
        }
    }
    //printf("\nend = %s", words[cnt / 2-1][0]);
    printf("\nCongratulate you!   You have made a little progress again.\n");
    lastwords(0, -1, 0, 1, 0);
    /*
    last = fopen("data1.txt", "w");
    fprintf(last, "%d", -1);
    fclose(last);
    */
    getchar();
    return 0;
}
void function1(char w[][2][wordslength], int cnt)
{
    //printf("How many words do you want to review?:");

    //int b = 0;
    //scanf("%d", &b);
    getchar();
    printf("------------------------------remaining:none");
    int lo = 0;
    while (1)
    {
        lo = rand() % (cnt);
        if (w[lo][0][0] != '1' && w[lo][0][0] != '-')
        {
            printf("\n\n--%s", w[lo][0]);
            char ch = getchar();
            if (ch != 10)
            {
                if (ch == 94)
                {
                    find(w, _cnt);
                    printf("\n\n--%s", w[lo][0]);
                }
                getchar();
                while (getchar() != 10)
                    ;
            }
            printf("--%s\n-----------------remaining:none", w[lo][1]);
        }
    }
}
void function2(char words[][2][wordslength], int cnt)
{
    int i = 0;
    int glength = 50;
    char group[glength][2][wordslength];
    for (i = 0; i < glength; i++)
    {
        group[i][0][0] = '2';
    }
    int cnt2 = cnt / glength + 1;
    printf("please choice a number(1-%d):", cnt2);
    int choose = 0;
    int location = 0;
    scanf("%d", &choose);
    getchar();

    //int j = 0;
    for (i = (choose - 1) * glength; i < choose * glength && words[i][0][0] != '1'; i++)
    {
        location = rand() % (glength);

        while (group[location][0][0] != '2')
        {
            if (location < glength - 1)
            {
                location++;
            }
            else
            {
                location = 0;
            }
        }
        Strcpy(group[location][0], words[i][0]);
        Strcpy(group[location][1], words[i][1]);
    }
    lastwords(group, 0, glength, 1, 0);
    lastwords(group, 0, glength, 3, 0);

    FILE *fp = fopen("data2.txt", "w");
    fprintf(fp, "%d\n", 0);
    fclose(fp);

    mixprint(words, group, glength, 0);
}

void function3(char words[][2][wordslength], int cnt)
{
    int i = 0;
    char a[wordslength];
    char b[wordslength];
    int lo = 0;
    for (i = 0; i < cnt; i++)
    {
        lo = rand() % (cnt);
        Strcpy(a, words[lo][0]);
        Strcpy(b, words[lo][1]);
        Strcpy(words[lo][0], words[i][0]);
        Strcpy(words[lo][1], words[i][1]);
        Strcpy(words[i][0], a);
        Strcpy(words[i][1], b);
    }
    /*
    int pattern = 0;
    printf("\nEn-->Ch input '1',Ch-->En input '2',En<-->Ch input '3':");
    scanf("%d", &pattern);
    getchar();
    */
    FILE *last = fopen("data1.txt", "r");
    int loc2 = 0, length = 0, type = 0;
    fscanf(last, "%d %d %d\n", &loc2, &length, &type);
    fclose(last);

    lastwords(words, 0, cnt, 1, type);
    lastwords(words, 0, cnt, 3, 0);

    FILE *fp = fopen("data2.txt", "w");
    fprintf(fp, "%d\n0\n0\n1\n%d\n", 0, type);
    fclose(fp);
}

void Strcpy(char a[wordslength], char b[wordslength])
{
    int i = 0;
    for (i = 0; i < wordslength; i++)
    {
        a[i] = b[i];
    }
}
void lastwords(char w[][2][wordslength], int loc, int length, int type, int type2)
{
    int i = 0;
    FILE *fp;
    switch (type)
    {
    case 1:
        fp = fopen("data1.txt", "w");
        fprintf(fp, "%d %d %d\n", loc, length, type2);
        fclose(fp);
        break;
    case 2:
        fp = fopen("data1.txt", "r+");
        if (type2 == 0)
        {
            fprintf(fp, "%d %d\n", loc, length);
        }
        else
        {
            fprintf(fp, "%d %d %d\n", loc, length, type2);
        }
        fclose(fp);
        break;
    case 3:
        fp = fopen("data1.txt", "a");
        for (i = 0; i < length; i++)
        {
            fprintf(fp, "%s", w[i][0]);
            fprintf(fp, "%s", w[i][1]);
        }
        fclose(fp);
        break;
    }
}
void dwords(char en[wordslength], char ch[wordslength])
{
    FILE *fp = fopen("data2.txt", "r");
    int len = 0;
    fscanf(fp, "%d\n", &len);
    fclose(fp);
    fp = fopen("data2.txt", "r+");
    fprintf(fp, "%d\n", len + 1);
    fclose(fp);
    fp = fopen("data2.txt", "a");
    fprintf(fp, "%s%s", en, ch);
    fclose(fp);
}
void review(char words[][2][wordslength])
{
    int i = 0;
    FILE *last = fopen("data1.txt", "r");
    int loc = 0, length = 0, type = 0;
    fscanf(last, "%d %d %d\n", &loc, &length, &type);
    if (loc != -1)
    {
        char memory[length][2][wordslength];
        for (i = 0; i < length; i++)
        {
            fgets(memory[i][0], wordslength - 1, last);
            fgets(memory[i][1], wordslength - 1, last);
        }
        fclose(last);
        //getchar();

        mixprint(words, memory, length, loc);
        /*
        printf("------------------------------remaining:%d", length - loc);
        for (i = loc; i < length; i++)
        {
            printf("\n\n--%s", memory[i][0]);
            char ch = getchar();
            if (ch != 10)
            {
                if (ch == 94)
                {
                    find(words, _cnt);
                    printf("\n\n--%s", memory[i][0]);
                    getchar();
                }
                *
                if (getchar() == 94)
                {
                    char target[wordslength];
                    int j = 0;
                    for (j = 0; j < wordslength; j++)
                    {
                        target[j] = 0;
                    }
                    scanf("%s", target);
                    int x = find(words, target, _cnt);
                    if(x==-1){
                        printf("error!\n");
                    }else{
                        printf("similar words :%d\n", x);
                    }
                }
                *

                dwords(memory[i][0], memory[i][1]);

                while (getchar() != 10)
                    ;
            }

            printf("--%s\n-----------------remaining:%d", memory[i][1], length - i - 1);
            lastwords(0, i + 1, length, 2,0);
        }
        //lastwords(0, -1, 0, 1,0);
        */
    }

    FILE *fp = fopen("data2.txt", "r");
    int len = 0;
    fscanf(fp, "%d\n", &len);
    int l = 0;
    do
    {
        fscanf(fp, "%d\n", &l);
    } while (l != 1);

    fscanf(fp, "%d\n", &l);

    lastwords(0, -1, 0, 1, l);
    if (len > 0)
    {
        char rev[len][2][wordslength];
        for (i = 0; i < len; i++)
        {
            fgets(rev[i][0], wordslength - 1, fp);
            fgets(rev[i][1], wordslength - 1, fp);
        }
        fclose(fp);
        function3(rev, len);

        printf("\n\n\nThe following words are your weaknesses! \n\n");
        review(words);
    }
    else
    {
        fclose(fp);
    }
}
void function4(char words[][2][wordslength], int cnt)
{
    int i = 0;
    int gro = 0;
    for (i = 0; i < cnt; i++)
    {
        if (words[i][0][0] == '-')
        {
            gro++;
        }
    }
    int da[gro + 1][2];
    da[0][1] = -2; //让第一组单词的位置正确
    gro = 1;
    for (i = 0; i < cnt; i++)
    {
        if (words[i][0][0] == '-')
        {
            gro++;
        }
        else
        {
            da[gro][0] = da[gro - 1][1] + 2;
            da[gro][1] = i;
        }
    }
    printf("\ngroups:\n");
    for (i = 1; i < gro; i++)
    {
        printf(" %-2d = %-3dwords ||", i, da[i][1] - da[i][0] + 1);
        if (i % 5 == 0)
        {
            printf("\n");
        }
    }
    //printf("g1-0 = %d,g1-1 = %d,g2-0 = %d,g2-1 = %d\n", da[1][0], da[1][1], da[2][0], da[2][1]);
    printf("\nplease choice a group(1-%d):", gro - 1);
    int choose = 1;
    scanf("%d", &choose);
    int len = da[choose][1] - da[choose][0] + 1;
    char cwords[len][2][wordslength];
    int j = 0;
    for (i = da[choose][0], j = 0; i <= da[choose][1]; i++, j++)
    {
        Strcpy(cwords[j][0], words[i][0]);
        Strcpy(cwords[j][1], words[i][1]);
    }
    lastwords(0, -1, 0, 1, 0);
    function3(cwords, len);
    mixprint(words, cwords, len, 0);
}

void mixprint(char words[][2][wordslength], char group[][2][wordslength], int glength, int loc)
{
    FILE *last = fopen("data1.txt", "r");
    int loc2 = 0, length = 0, type = 0;
    fscanf(last, "%d %d %d\n", &loc2, &length, &type);
    fclose(last);

    int pattern = 0;

    if (type == 0)
    {
        printf("\nEn-->Ch input '1',Ch-->En input '2',En<-->Ch input '3':");
        scanf("%d", &pattern);
        lastwords(0, loc2, length, 2, pattern);

        FILE *fp = fopen("data2.txt", "w");
        fprintf(fp, "%d\n0\n0\n1\n%d\n", 0, pattern);
        fclose(fp);

        getchar();
    }
    else
    {
        pattern = type;
    }

    int first = 0, later = 1;
    if (pattern == 2)
    {
        first = 1;
        later = 0;
    }
    printf("\n------------------------------remaining:%d", glength - loc);
    int i = 0;
    for (i = loc; i < glength; i++)
    {
        if (pattern == 3)
        {
            first = rand() % (2);
            later = 1 - first;
        }
        if (group[i][0][0] != '2' && group[i][0][0] != '-')
        {
            printf("\n\n>%s", group[i][first]);
            char ch = getchar();
            int data1 = 0;
            if (ch != 10)
            {
                if (ch == 94)
                {
                    find(words, _cnt);
                    dwords(group[i][0], group[i][1]);
                    printf("\n\n>%s", group[i][first]);
                    getchar();
                }
                else if (ch == 45)
                {

                    char b[wordslength];
                    //scanf("%s", b);
                    int j = 0;
                    for (j = 0; j < wordslength; j++)
                    {
                        b[j] = 0;
                    }

                    data1 = getchar();
                    for (j = 0; j < wordslength && data1 != 10; j++, data1 = getchar())
                    {
                        b[j] = data1;
                    }

                    if (Check(group[i][later], b))
                    {
                        printf("------------Right!!\n");
                    }
                    else
                    {
                        printf("------------Error!!\n");
                        dwords(group[i][0], group[i][1]);
                    }
                }
                else
                {
                    dwords(group[i][0], group[i][1]);
                }

                while (data1 != 10 && getchar() != 10)
                    ;
            }
            printf(">%s\n-----------------remaining:%d", group[i][later], glength - i - 1);
        }
        lastwords(0, i + 1, glength, 2, pattern);
    }
    lastwords(0, -1, 0, 1, 0);
    review(words);
}

int words_sta(int arc, char *arv[])
{

    FILE *fp;
    if (arc == 1)
    {
        fp = fopen("words.txt", "r");
    }
    else
    {
        fp = fopen(arv[1], "r");
    }

    int cnt = 0;
    char a[wordslength];
    do
    {
        fgets(a, wordslength - 1, fp);
        if (a[0] != '-' && a[0] != '1')
        {
            cnt++;
        }
    } while (a[0] != '1');

    return cnt / 2;
}

int find(char words[][2][wordslength], int cnt)
{
    int i = 0, j = 0;
    int loc = 0;
    int mo = 0;
    char target[wordslength];
    for (i = 0; i < wordslength; i++)
    {
        target[i] = 0;
    }
    scanf("%s", target);
    printf("\n\n============================\n\n");
    printf("This is the result that you find words:\n\n");
    printf("target : %s\n\n", target);
    if (target[2] >= 97 && target[2] <= 122)
    {
        mo = 0;
    }
    else if (target[2] == 0)
    {
        printf("data is few!!\n");
        return -1;
    }
    else
    {
        mo = 1;
    }

    int cnt2 = 0;

    for (i = 0; i < cnt; i++)
    {
        loc = 0;
        for (j = 0; j < wordslength - 1 && words[i][mo][j] != 10; j++)
        {
            if (target[loc] == words[i][mo][j])
            {
                loc++;
            }
            else
            {
                j = j - loc;
                loc = 0;
            }

            if (target[loc] == 0)
            {
                printf("--> %s--> %s\n", words[i][0], words[i][1]);

                cnt2++;
                break;
            }
        }
    }
    printf("similar words : %d\n", cnt2);
    printf("============================");
    return cnt2;
}
int Switch(char words[][2][wordslength])
{
    int i = 0;
    /*
    char mid[wordslength];
    for (i = 0; words[i][0][0] != '-';i++){
        Strcpy(mid, words[i][0]);
        Strcpy(words[i][0], words[i][1]);
        Strcpy(words[i][1], mid);
    }
    */
    FILE *fp;
    fp = fopen("switch.txt", "a");
    for (i = 0; words[i][i][0] != '-'; i++)
    {
        fprintf(fp, "%s%s", words[i][1], words[i][0]);
    }
    fclose(fp);
    return 0;
}

int Check(char a[wordslength], char b[wordslength])
{
    int i = 0;
    //printf("%s", b);
    for (i = 0; i < wordslength - 1; i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
        //printf("1 ");
    }

    if ((a[i] == 10 && b[i] == 0) || (a[i] == 0 && b[i] == 0) || i == wordslength - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}