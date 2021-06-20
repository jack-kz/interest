#include"acllib.h"
#include<stdio.h>
#include<time.h>
#define x_x 9
#define y_y 9
#define mp 73//扩大倍率 
int even=0;
int site[x_x*y_y][2];//数据记录数组 
int nandu=35;//控制难度 
int place=0;//记录数独在list中位置 
int time_start=0,time_end=0; 


void bg();
void num_mode(int x,int y,int z,int bl);
void refresh();
void start();
int check(int p[][2],int cnt); 
void bg(){
	int i;
	beginPaint();
	setPenColor(RGB(200,200,200));
	for(i=0;i<=x_x;i++){
		line(i*mp,0,i*mp,y_y*mp);
		if(i%3==0){
			setPenColor(BLACK);
			line(i*mp,0,i*mp,y_y*mp);
			setPenColor(RGB(200,200,200));
		} 
	}
	for(i=0;i<= y_y;i++){
		line(0,i*mp,x_x*mp,i*mp);
		if(i%3==0){
			setPenColor(BLACK);
			line(0,i*mp,x_x*mp,i*mp);
			setPenColor(RGB(200,200,200));
		} 
	}
	for(i=mp;i<2*mp;i++){
		line(10*mp,i,11*mp,i);
	}
	for(i=3*mp;i<4*mp;i++){
		line(10*mp,i,11*mp,i);
	}
	for(i=5*mp;i<6*mp;i++){
		line(10*mp,i,11*mp,i);
	}
	
	setPenColor(BLACK);
	endPaint();
}
void num_mode(int x,int y,int z,int bl){
	int i=0;
	switch(z){
		case 0:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
		case 1:
			for(i=y+1*bl;i<y+8*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			break;
		case 2:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+4*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
		case 3:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+4*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
		case 4:
			for(i=y+1*bl;i<y+4*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			break;
		case 5:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+4*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
		case 6:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+4*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
		case 7:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			break;
		case 8:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+4*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
		case 9:
			for(i=y+1*bl;i<y+2*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+4*bl;i++){
				line(x+2*bl,i,x+3*bl,i);
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+5*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			for(i;i<y+7*bl;i++){
				line(x+6*bl,i,x+7*bl,i);
			}
			for(i;i<y+8*bl;i++){
				line(x+2*bl,i,x+7*bl,i);
			}
			break;
	}
}
void refresh(){
	beginPaint();
	clearDevice();
	endPaint();
	bg();
	int i=0;
	beginPaint();
	for(i=0;i<x_x*y_y;i++){
		
		if(site[i][1]==-1&&site[i][0]!=0){
			setPenColor(RGB(120,120,120));
			num_mode(i%x_x*mp,i/x_x*mp,site[i][0],mp/9);
		}else if(site[i][1]==0&&site[i][0]!=0){
			num_mode(i%x_x*mp,i/x_x*mp,site[i][0],mp/9);
		}else if(site[i][1]==1&&site[i][0]!=0){
			setPenColor(RGB(255,0,0));
			num_mode(i%x_x*mp,i/x_x*mp,site[i][0],mp/9);
		}else if(site[i][1]==2&&site[i][0]!=0){
			setPenColor(RGB(0,255,0));
			num_mode(i%x_x*mp,i/x_x*mp,site[i][0],mp/9);
		}
		setPenColor(BLACK);
		
	}
	num_mode(9*mp+mp/3,6*mp+mp/3,nandu/10,mp/7);
	num_mode(10*mp+mp/3,6*mp+mp/3,nandu%10,mp/7);
	num_mode(9*mp,7*mp+mp/3*2,place/1000,mp/10);
	num_mode(9*mp+mp/3*2,7*mp+mp/3*2,place/100%10,mp/10);
	num_mode(10*mp+mp/3,7*mp+mp/3*2,place%100/10,mp/10);
	num_mode(11*mp,7*mp+mp/3*2,place%10,mp/10);
	endPaint();
	for(i=0;i<81;i++){
		if(check(site,i)==0){
			break;
		}
	}
	//printf("当前难度系数：%d\n",nandu);
	if(i==81){
		time_end = time(NULL);
		printf("YOU WON!!!\ntime = %d min %d s\n",(time_end-time_start)/60,(time_end-time_start)%60);
		start();
	}
}
int check(int p[][2],int cnt){
    //printf("P[cnt] = %d,cnt = %d\n", p[cnt],cnt);
    if(p[cnt][0]==0){
    	return 0;
	}
    int ch[10];
    int i = 0;
    for (i = 0; i < 10;i++){
        ch[i] = 0;
    }
    
    for (i = cnt; i >= 0;i-=9)//列验证
    {
        ch[p[i][0]]++;
    }
    for (i = 1; i < 10;i++){
        if(ch[i]>1){
            return 0;
        }else{
            ch[i] = 0;
        }
    }


    for (i = cnt; i % 9 != 0;i--){//行验证
        ch[p[i][0]]++;
    }
    ch[p[i][0]]++;//验证每行第一个元素
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
            ch[p[i][0]]++;
        }
        ch[p[i][0]]++;
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
void mouseListener(int x,int y,int button,int event){
	int x1=0;
	int y1=0;
	x1=x/mp;
	y1=y/mp;
	//printf("mid = %d\n",button);
	if(button==1&&event==0&&x1<9&&site[x1+y1*x_x][1]!=-1){
		
		if(site[x1+y1*x_x][0]<9){
			site[x1+y1*x_x][0]++;
		}else{
			site[x1+y1*x_x][0]=0;
		}
		refresh();
	}
	if(button==1&&event==0&&x1==10&&y1==1){
		//printf("当前难度系数：%d\n",nandu);
		start();
	}
	if(button==1&&event==0&&x1==10&&y1==3){
		nandu-=5;
		//printf("当前难度系数：%d\n",nandu);
		start();
	}
	if(button==1&&event==0&&x1==10&&y1==5){
		nandu+=5;
		//printf("当前难度系数：%d\n",nandu);
		start();
	}
	if(button==3&&event==0&&x1<9&&site[x1+y1*x_x][1]!=-1){
		//site[x1+y1*x_x][1]=2;
		/*if(site[x1+y1*x_x][0]==0){
			site[x1+y1*x_x][0]=9;
		}else if(site[x1+y1*x_x][0]!=1){
			site[x1+y1*x_x][0]--;
		}else{
			site[x1+y1*x_x][0]=9;
		}*/
		if(site[x1+y1*x_x][0]==0){
			site[x1+y1*x_x][0]=9;
		}else{
			site[x1+y1*x_x][0]--;
		}
		refresh();
	}
	if(button==2&&event==0&&x1<9&&site[x1+y1*x_x][1]!=-1&&site[x1+y1*x_x][1]!=2){
		site[x1+y1*x_x][1]++;
		refresh();
	}else if(button==2&&event==0&&x1<9&&site[x1+y1*x_x][1]!=-1){
		site[x1+y1*x_x][1]=0;
		refresh();
	}
	
}

void start(){
	int i=0;
	bg();
	
	for(i=0;i<x_x*y_y;i++){
		site[i][0]=0;
		site[i][1]=0;
	}
	
	for(i=0;i<nandu;i++){
		site[rand()%(x_x*y_y)][1]=-1;
	}
	FILE *fp = fopen("data.txt", "r");
	int cnt=0;
	int num=0;
	int data=0;
	fscanf(fp,"%d",&num);
	place=rand()%(num/10)*10+rand()%(10);
	//printf("place = %d\n",place);
	for(i=0;i<place;i++){
		while(data>-1){
			fscanf(fp,"%d",&data);
		}
		data=0;
		cnt++;	
	}
	//fscanf(fp,"%d",&data);
	//printf("cnt = %d\n",cnt);
	for(i=0;i<x_x*y_y;i++){
		fscanf(fp,"%d",&site[i][0]);
	}
	fclose(fp);
	for(i=0;i<x_x*y_y;i++){
		if(site[i][1]==0){
			site[i][0]=0;
		} 
		
		//site[i][1]=0;
	}
	time_start = time(NULL);
	refresh();
}

int Setup(){
	srand(time(0));
	initConsole();
	initWindow("数独",250,100,x_x*mp+3*mp,y_y*mp+1);
	printf("说明书：\n右边\n第1个按钮刷新数独\n第2个按钮增加难度\n第3个按钮降低难度");
	printf("\n第1行数字为难度系数，值越大，难度越低\n第2行为数独所在list位置编号\n");
	printf("鼠标左键控制数字上调，右键控制数值下调\n>_<--祝游戏愉快-->_<\n");
	start();
	registerMouseEvent(mouseListener);
	return 0;
}
 
