#include"acllib.h"
#include<stdio.h>
#include<time.h>
int even=2;
int eat_x=-1;
int eat_y=0;
int door_1_x=35;
int door_1_y=20;
int door_2_x=65;
int door_2_y=40;
int score=0; 
int loca[6000];
int eatl=-1;
typedef struct _snake{
	int snake_x;
	int snake_y;
	int snake_direction;
	struct _snake *next;
}snake;
snake snakebegin;
snake *snakehead=&snakebegin;

typedef struct _location{
	int loca[6000][2];
	int cnt;
}location;
location lo;
location *l=&lo;
void snake_draw(int x,int y){
	beginPaint();
	x=8*x;
	y=8*y;
	int i=y;
	for(i;i<y+8;i++){
		line(x,i,x+8,i);
	}
	//putPixel(x,y,RED);
	endPaint();
}

void snake_door(int x,int y){
	beginPaint();
	x=8*x;
	y=8*y;
		line(x,y,x+8,y);
		line(x,y,x,y+8);
		line(x+7,y,x+7,y+8);
		line(x,y+7,x+8,y+7);
	//putPixel(x,y,RED);
	endPaint();
}

void snake_move(){
	//loca_res();
	snake *p=snakehead;
	snake ts_1;
	snake ts_2;
	//snake *r1=&ts_1;
	snake *r2=&ts_2;
	for(ts_2=*snakehead,p=snakehead->next;p;ts_2=ts_1,p=p->next){
		ts_1=*p;
		p->snake_x=r2->snake_x;
		p->snake_y=r2->snake_y;
		p->snake_direction=r2->snake_direction;
		//printf("x=%d,y=%d\n",r->snake_x,r->snake_y);
		snake_draw(p->snake_x,p->snake_y);
		//loca[p->snake_x+p->snake_y*100]=0;
		
	}
	p=snakehead;
	switch (p->snake_direction){
		case 37:
			if(p->snake_x==door_1_x&&p->snake_y==door_1_y){
				p->snake_x=door_2_x;
				p->snake_y=door_2_y;
			}else if(p->snake_x==door_2_x&&p->snake_y==door_2_y){
				p->snake_x=door_1_x;
				p->snake_y=door_1_y;
			} 
			if(p->snake_x<=0) p->snake_x=100;
			p->snake_x--;
			break;
		case 38:
			if(p->snake_x==door_1_x&&p->snake_y==door_1_y){
				p->snake_x=door_2_x;
				p->snake_y=door_2_y;
			}else if(p->snake_x==door_2_x&&p->snake_y==door_2_y){
				p->snake_x=door_1_x;
				p->snake_y=door_1_y;
			} 
			if(p->snake_y<=0) p->snake_y=60;
			p->snake_y--;
			break;
		case 39:
			if(p->snake_x==door_1_x&&p->snake_y==door_1_y){
				p->snake_x=door_2_x;
				p->snake_y=door_2_y;
			}else if(p->snake_x==door_2_x&&p->snake_y==door_2_y){
				p->snake_x=door_1_x;
				p->snake_y=door_1_y;
			}
			if(p->snake_x>=99) p->snake_x=-1;
			p->snake_x++;
			break;
		case 40:
			if(p->snake_x==door_1_x&&p->snake_y==door_1_y){
				p->snake_x=door_2_x;
				p->snake_y=door_2_y;
			}else if(p->snake_x==door_2_x&&p->snake_y==door_2_y){
				p->snake_x=door_1_x;
				p->snake_y=door_1_y;
			}
			if(p->snake_y>=59) p->snake_y=-1;
			p->snake_y++;
			break;
	}
	snake_draw(p->snake_x,p->snake_y);
}
void snake_long(){
	int a=0;
	snake *p=snakehead;
	for(p;p;p=p->next){
		a++;
		printf("%d: x=%d,y=%d\n",a,p->snake_x,p->snake_y);
	}
}
void snake_add(){
	snake *q=(snake*)malloc(sizeof(snake));
	q->next=NULL;
	snake *p=snakehead;
	
	for(;p->next;p=p->next){}
	q->snake_direction=p->snake_direction;
	p->next=q;
}

void loca_res(){
	int i=0;
	l->cnt=0;
	for(i=0;i<6000;i++){
		loca[i]=1;
		l->loca[i][0]=0;
		l->loca[i][1]=0;
	}
	loca[door_1_x+door_1_y*100]=0;
	loca[door_2_x+door_2_y*100]=0;
}

void snake_eat(){
	snake *p=snakehead;
	int i=0;
	if(p->snake_x==eat_x&&p->snake_y==eat_y){
		snake_add();
		score++;
		printf("score = %d\n",score);
		eat_x=-1;
	}
	//printf("1");
	if(eat_x==-1){
		
		//int a=1;
		//while(a){
		loca_res();
		//printf("2");
		p=snakehead;
		for(p;p->next;p=p->next){
			loca[p->snake_x+(p->snake_y)*100]=0;
		}
		//while(p!=NULL){
			
		//	p=p->next;
		//}
		
		l->cnt=0;
		int x=0;
		for(i=0;i<6000;i++){
			if(loca[i]){
				x=l->cnt;
				l->loca[x][0]=i%100;
				l->loca[x][1]=i/100;
				l->cnt++;
			}
		}
		//printf("3");
		//printf("cnt = %d",l->cnt);
			srand(time(0));
			eatl=rand()%(l->cnt/100);
			//printf("\neatl = %d",eatl);
			if(eatl>0){
				eatl=eatl*100-rand()%(100)+l->cnt%100; 
			}else{
				eatl=rand()%(100);
				if(eatl>l->cnt%100&&l->cnt/100==0){
					eatl=l->cnt;
				}
			}
			
			eat_x=l->loca[eatl][0];
			eat_y=l->loca[eatl][1];
			//for(p=snakehead;p->next;p=p->next){
			//	if(eat_x==p->snake_x&&eat_y==p->snake_y){
			//		break;
			//	}
			//}
			//if(p->next==NULL&&(eat_x!=door_1_x&&eat_y!=door_1_y)&&(eat_x!=door_2_x&&eat_y!=door_2_y)){
			//	a=0;
			//}
		//}
	}
}
void keyListener(int key,int event){
	if(key>=37&&key<=40){
		if(event==0&&even==2){
			even=1;
		}else if(event==0&&even==1){
			even=0;
		}else if(event==1){
			even=2;
		}
		if(even==1){
			snakehead->snake_direction=key;
			beginPaint();
			clearDevice();
			endPaint();
			snake_door(door_1_x,door_1_y);
			snake_door(door_2_x,door_2_y);
			snake_eat();
			snake_move();
			snake_draw(eat_x,eat_y);
			
			
				
		}
	//printf("key = %d,event = %d\n ",key,event);
	} 	
}
void timerListener(int id){
	switch (id){
		case 0:
			beginPaint();
			clearDevice();
			endPaint();
			snake_door(door_1_x,door_1_y);
			snake_door(door_2_x,door_2_y);
			snake_eat();
			snake_move();
			snake_draw(eat_x,eat_y);
			
			break;
	}
}

void initi(){
	snake *p=snakehead;
	p->next=NULL;
	p->snake_direction=39;
	p->snake_x=20;
	p->snake_y=20;
	
}


int Setup(){
	initConsole();
	initWindow("Ì°Ê³Éß",200,200,800,480);
	initi();
	loca_res();
	snake_eat();
	registerKeyboardEvent(keyListener);
	registerTimerEvent(timerListener);
	startTimer(0,300);
	return 0;
}
 
