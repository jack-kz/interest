#include"acllib.h"
#include<stdio.h>
#include<time.h>
#define x_x 12
#define y_y 20
#define mp 30
int even=0;
int site[x_x*y_y];
int next_d[12];
int l=x_x-1,r=0,a=0;
int now_centre=0;
int score=0;
int next=0;
void bg(){
	int i;
	beginPaint();
	setPenColor(RGB(200,200,200));
	for(i=0;i<=x_x;i++){
		line(i*mp,0,i*mp,y_y*mp);
	}
	for(i=0;i<= y_y;i++){
		line(0,i*mp,x_x*mp,i*mp);
	}
	setPenColor(BLACK);
	endPaint();
}
void draw(int x,int y){
	
	int i=0;
	beginPaint();
	//setPenColor(RGB(rand()%(10)*20+30,rand()%(10)*20+20,rand()%(10)*20+10));
	for(i=x+1;i<x+mp;i++){
		line(i,y+1,i,y+mp);
	}
	endPaint();
}
void destination(){
	int i=0;
	for(i=0;i<x_x*y_y;i++){
		if(site[i]){
			site[i]=2;
		}
	}
}

void number_draw(int num,int place){
	int i=10;
	switch(num){
		case 0:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place,i,place+10,i);
				line(place+30,i,place+40,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
		case 1:
			beginPaint();
			//int i=10;
			for(i=10;i<60;i++){
				line(place+30,i,place+40,i);
			}
			endPaint();
			break;
		case 2:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<30;i++){
				line(place+30,i,place+40,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place,i,place+10,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
		case 3:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<30;i++){
				line(place+30,i,place+40,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place+30,i,place+40,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
		case 4:
			beginPaint();
			//int i=10;
			for(i=10;i<30;i++){
				line(place,i,place+10,i);
				line(place+30,i,place+40,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<60;i++){
				line(place+30,i,place+40,i);
			}
			endPaint();
			break;
		case 5:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<30;i++){
				line(place,i,place+10,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place+30,i,place+40,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
		case 6:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<30;i++){
				line(place,i,place+10,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place+30,i,place+40,i);
				line(place,i,place+10,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
		case 7:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<60;i++){
				line(place+30,i,place+40,i);
			}
			endPaint();
			break;
		case 8:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<30;i++){
				line(place,i,place+10,i);
				line(place+30,i,place+40,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place+30,i,place+40,i);
				line(place,i,place+10,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
		case 9:
			beginPaint();
			//int i=10;
			for(i=10;i<20;i++){
				line(place,i,place+40,i);
			}
			for(i;i<30;i++){
				line(place,i,place+10,i);
				line(place+30,i,place+40,i);
			}
			for(i;i<40;i++){
				line(place,i,place+40,i);
			}
			for(i;i<50;i++){
				line(place+30,i,place+40,i);
			}
			for(i;i<60;i++){
				line(place,i,place+40,i);
			}
			endPaint();
			break;
	}
}

void score_draw(int _score){
	int a=_score/100;
	int b=_score/10%10;
	int c=_score%10;
	number_draw(a,x_x*mp+5);
	number_draw(b,x_x*mp+5+50);
	number_draw(c,x_x*mp+5+100);
}

void move(){
	
	int i=0;
	for(i=x_x*y_y-1;i>=0;i--){
		if(site[i]==1||site[i]==3){
			if(site[i+x_x]==2||i+x_x>=x_x*y_y){
				destination();
				break;
			}
		}
	}
	for(i=x_x*y_y-1;i>=0;i--){
		if(site[i]==1||site[i]==3){
			if(site[i]==3){
				now_centre=i;
			}
			site[i+x_x]=site[i];
			site[i]=0;
		}
	}
			

	
}
void check_move(){
	l=x_x-1;
	r=0;
	int i=0;
	for(i=x_x*y_y-1;i>=0;i--){
		if(site[i]==1||site[i]==3){
			a=i%x_x;
			if(l>a){
				l=a;
			}
			if(r<a){
				r=a;
			}
			if(site[i-1]==2&&a!=0){
				l=0;
			}
			if(site[i+1]==2&&a!=x_x-1){
				r=x_x-1; 
			}
			if(site[i]==3){
				now_centre=i;
			}
		}
	}
}
void movel(){
	//printf("l = %d, r=%d\n",l,r);
	int i=0;
	int cnt=0;
	if(l!=0){
		for(i=0;i<x_x*y_y&&cnt<5;i++){
			if(site[i]==1||site[i]==3){
				site[i-1]=site[i];
				site[i]=0;
				cnt++;
			}
		}
	}
}
void mover(){
	int i=0;
	int cnt=0;
	if(r!=x_x-1){
		for(i=x_x*y_y-1;i>=0&&cnt<5;i--){
			if(site[i]==1||site[i]==3){
				site[i+1]=site[i];
				site[i]=0;
				cnt++;
			}
		}
	}
}

void clean(){
	int i=0;
	for(i=0;i<12;i++){
		next_d[i]=0;
	}
}
void next_produce(){
	clean();
	next_d[6]=1;
	switch(next){
		case 0:
			next_d[6-1]=1;
			next_d[6-2]=1;
			next_d[6+1]=1;
			break;
		case 1:
			next_d[6-1]=1;
			next_d[6+1]=1;
			next_d[6+4]=1;
			break;
		case 2:
			next_d[6+1]=1;
			next_d[6+4]=1;
			next_d[6+4-1]=1;
			break;
		case 3:
			next_d[6-1]=1;
			next_d[6+4]=1;
			next_d[6+4+1]=1;
			break;
		case 4:
			next_d[6+1]=1;
			next_d[6+4]=1;
			next_d[6+4+1]=1;
			break;
		case 5:
			next_d[6-1]=1;
			next_d[6+1]=1;
			next_d[6+4-1]=1;
			break;
		case 6:
			next_d[6-1]=1;
			next_d[6+1]=1;
			next_d[6+4+1]=1;
		}
}

void new_produce(){
	int i=0;
	int centre=x_x/2;
	int a=1;
	for(i=0;i<x_x*y_y;i++){
		if(site[i]==1||site[i]==3){
			a=0;
			break; 
		}
	}
	if(a){
		site[centre]=3;
		
		switch(next){
			case 0:
				site[centre-1]=1;
				site[centre-2]=1;
				site[centre+1]=1;
				break;
			case 1:
				site[centre-1]=1;
				site[centre+1]=1;
				site[centre+x_x]=1;
				break;
			case 2:
				site[centre+1]=1;
				site[centre+x_x]=1;
				site[centre+x_x-1]=1;
				break;
			case 3:
				site[centre-1]=1;
				site[centre+x_x]=1;
				site[centre+x_x+1]=1;
				break;
			case 4:
				site[centre+1]=1;
				site[centre+x_x]=1;
				site[centre+x_x+1]=1;
				break;
			case 5:
				site[centre-1]=1;
				site[centre+1]=1;
				site[centre+x_x-1]=1;
				break;
			case 6:
				site[centre-1]=1;
				site[centre+1]=1;
				site[centre+x_x+1]=1;
		}
		next=rand()%(7);
		next_produce();
		//printf("next = %d\n",next);
	}
}

void rotate(){
	int n=now_centre;
	//printf("n = %d\n",n);
	int a=0;
	int b=0;
	int c=0;
	if(n%x_x!=0&&n%x_x!=1&&n%x_x!=x_x-1&&n%x_x!=x_x-2&&site[n-1]!=2&&site[n-2]!=2&&site[n+2]!=2&&site[n+1]!=2&&site[n+x_x]!=2&&site[n+2*x_x]!=2&&site[n+x_x-1]!=2&&site[n+x_x+1]!=2&&n-2*x_x>=0){
		//printf("in 2\n");
		a=site[n-1];
		b=site[n-x_x-1];
		c=site[n-2];
		
		site[n-1]=site[n+x_x];
		site[n+x_x]=site[n+1];
		site[n+1]=site[n-x_x];
		site[n-x_x]=a;
		site[n-x_x-1]=site[n+x_x-1];
		site[n+x_x-1]=site[n+x_x+1];
		site[n+x_x+1]=site[n-x_x+1];
		site[n-x_x+1]=b;
		site[n-2]=site[n+2*x_x];
		site[n+2*x_x]=site[n+2];
		site[n+2]=site[n-2*x_x];
		site[n-2*x_x]=c; 
		
	}
}
void move_score(){
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<4;i++){
		for(j=x_x*y_y-1;j>=0;j--){
			if(site[j]==6){
				for(k=j;k>=x_x;k--){
					if((site[k-x_x]==2||site[k-x_x]==0||site[k-x_x]==6)&&site[k]!=1&&site[k]!=3){
						site[k]=site[k-x_x];
					}
				}
			}
		}
	}
}
void check_score(){
	int i=0;
	int j=0;
	int cnt=0;
	for(i=0;i<y_y*x_x;i+=x_x){
		for(j=i;j<i+x_x;j++){
			if(site[j]==2){
				cnt++;
			}	
		}
		if(cnt==x_x){
			for(j=i;j<i+x_x;j++){
				site[j]=6;
			}
			score++;
			printf("your score : %d\n",score);
			move_score();
		}
		cnt=0;
	}
	
}
void keyListener(int key,int event){
	
	//if(key>=37&&key<=40){
		/*if(event==0&&even==2){
			even=1;
		}else if(event==0&&even==1){
			even=0;
		}else if(event==1){
			even=2;
		} 
		if(even==1){
		
		}*/
		//printf("a = %d\n",key);
		check_move();
		int i=0;
		
		if(event==0&&(key==37||key==65)){
			movel();
		}
		if(event==0&&(key==39||key==68)){
			mover();
		}
		if(event==0&&(key==38||key==87)){
			rotate();
		}
		if(event==0&&(key==40||key==83)){
			move();
		}
		beginPaint();
		clearDevice();
		endPaint();
		bg();
		for(i=0;i<x_x*y_y;i++){
			if(site[i]){
				draw(i%x_x*mp,i/x_x*mp);
			}
		}
		for(i=0;i<12;i++){
			if(next_d[i]==1){
				draw((i%4+x_x)*mp,(i/4+5)*mp);
			}
		}
		score_draw(score);
		//printf("event = %d\n",event);
	//} 	
}

void start(){
	int i=0;
	score=0;
	srand(time(0));
	next=rand()%(7);
	for(i=0;i<x_x*y_y;i++){
		site[i]=0;
	}
}
void timerListener(int id){
	int i=0;
	switch(id){
		case 0:
			check_score();
			move();
			new_produce();
			
			break;
		case 1:
			beginPaint();
			clearDevice();
			endPaint();
			bg();
			for(i=0;i<x_x*y_y;i++){
				if(site[i]>0&&site[i]<5){
					draw(i%x_x*mp,i/x_x*mp);
				}
				if(site[i]==2&&i<x_x*2){
					printf("your last score : %d\n",score);
					
					start();
					break;
				}
			}
			for(i=0;i<12;i++){
				if(next_d[i]==1){
					draw((i%4+x_x)*mp,(i/4+5)*mp);
				}
			}
			score_draw(score);	
	}
}

int Setup(){
	initConsole();
	initWindow("¶íÂÞË¹·½¿é",200,200,x_x*mp+150,y_y*mp+1);
	start();
	registerKeyboardEvent(keyListener);
	registerTimerEvent(timerListener);
	startTimer(0,500);
	startTimer(1,40);
	return 0;
}
 
