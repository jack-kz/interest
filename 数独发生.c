#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int site[81];
void produce(int p[]);
int check(int p[], int j);

int main(){
    srand(time(0));
    int i = 0;
    for (i = 0; i < 81;i++){
        site[i] = 1;
    }
    FILE *fp = fopen("data.txt", "w");
    fprintf(fp,"-1\n");
	fclose(fp); 
    int start = time(NULL);
    produce(site);
    int end = time(NULL);
    printf("\ntime = %ds\n", end - start);
    return 0;
}
int check(int p[],int cnt){
    //printf("P[cnt] = %d,cnt = %d\n", p[cnt],cnt);
    int ch[10];
    int i = 0;
    for (i = 0; i < 10;i++){
        ch[i] = 0;
    }
    
    for (i = cnt; i >= 0;i-=9)//列验证
    {
        ch[p[i]]++;
    }
    for (i = 1; i < 10;i++){
        if(ch[i]>1){
            return 0;
        }else{
            ch[i] = 0;
        }
    }


    for (i = cnt; i % 9 != 0;i--){//行验证
        ch[p[i]]++;
    }
    ch[p[i]]++;//验证每行第一个元素
    for (i = 1; i < 10;i++){
        if(ch[i]>1){
            return 0;
        }else{
            ch[i] = 0;
        }
    }
    int j = 0;
    int n = 0;
    for (j = (cnt / 9) % 3; j >= 0;j--){//验证九宫格
        if (n != 0){//第一次循环只需要判断该数据前的几个数据
            for (i = cnt - n * 9; i % 9 % 3 != 2;i++);//一次以后的循环需要判断该九宫格内该行的三个元素
                                                        //故需要将 i % 9 % 3的值增加到2
        }else{
            i = cnt;
        }

        for (; i % 9 % 3 != 0; i--)
        {
            ch[p[i]]++;
        }
        ch[p[i]]++;
        n++;
    }
    for (i = 1; i < 10;i++){
        if(ch[i]>1){
            return 0;
        }else{
            ch[i] = 0;
        }
    }
    return 1;
}
void produce(int p[]){
    int i = 0;
    int cnt1 = 0;
    while(p[0]<=9){
        //for (i = rand() % (8) + 2; i % 9 == 0;i=rand() % (8) + 2);
        i=rand()%(8)+2;
        if (p[i] < 9)
        {
            p[i]++;
        }
        else
        {
            p[i] = 1;
            i--;
            p[i]++;
        }
        for (i = 0; i < 81;){
            if(p[i]<10&&check(p,i)){
                i++;
            }else if(p[i]<9){
                p[i]++;
            }else{
                p[i] = 1;
                i--;
                if(i<0){
                    p[0] = 10;//i<0说明本次搜索已经找不到符合的数独了，需要跳出循环，p[0]>9为跳出条件
                    break;
                }
                p[i]++;
            }
        }

        if(i==81){
            FILE *fp = fopen("data.txt", "a");
            fprintf(fp, "\n-1");
            for (i = 0; i < 81;i++){
                if(i%9==0){
                    fprintf(fp, "\n");
                    //printf("\n");
                }
                fprintf(fp, "%d ", p[i]);
                //printf("%d ", p[i]);
            }

            /*for (i = rand() % (15) + 1; i % 9 == 0;i=rand() % (15) + 1);
            if (p[i] < 9)
            {
                p[i]++;
            }
            else
            {
                p[i] = 1;
                i--;
                p[i]++;
            }*/
            
            fclose(fp);
            //printf("\n-----------------------------");
        }
        cnt1++;
    }
    FILE *fp = fopen("data.txt", "r+");
    fprintf(fp, "%d\n",cnt1-1);
    fclose(fp);
    printf("count = %d", cnt1-1);
}
