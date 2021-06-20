#include"acllib.h"
#include<stdio.h>
#include<time.h>
int site[600][4];
int score=0;
int n=80; 
int t=0;
void background(){
	int i=0;
	int j=0;
	beginPaint();
	for(i=0;i<601;i+=20)
		line(i,0,i,400);
	for(i=0;i<401;i+=20)
		line(0,i,600,i);
	endPaint();
}
void num_mode(int x,int y,int z){
	int i=0;
	switch(z){
		
		case 1:
			for(i=x+13;i<x+15;i++){
				line(i,y+3,i,y+17);
			}
			break;
		case 2:
			for(i=y+3;i<y+5;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+9;i++){
				line(x+14,i,x+15,i);
			}
			for(i;i<y+11;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+15;i++){
				line(x+6,i,x+7,i);
			}
			for(i;i<y+17;i++){
				line(x+6,i,x+15,i);
			}
			break;
		case 3:
			for(i=y+3;i<y+5;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+9;i++){
				line(x+14,i,x+15,i);
			}
			for(i;i<y+11;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+15;i++){
				line(x+14,i,x+15,i);
			}
			for(i;i<y+17;i++){
				line(x+6,i,x+15,i);
			}
			break;
		case 4:
			for(i=y+3;i<y+9;i++){
				line(x+6,i,x+7,i);
				line(x+14,i,x+15,i);
			}
			for(i;i<y+11;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+17;i++){
				line(x+14,i,x+15,i);
			}
			break;
		case 5:
			for(i=y+3;i<y+5;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+9;i++){
				line(x+6,i,x+7,i);
			}
			for(i;i<y+11;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+15;i++){
				line(x+14,i,x+15,i);
			}
			for(i;i<y+17;i++){
				line(x+6,i,x+15,i);
			}
			break;
		case 6:
			for(i=y+3;i<y+5;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+9;i++){
				line(x+6,i,x+7,i);
			}
			for(i;i<y+11;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+15;i++){
				line(x+6,i,x+7,i);
				line(x+14,i,x+15,i);
			}
			for(i;i<y+17;i++){
				line(x+6,i,x+15,i);
			}
			break;
		case 7:
			for(i=y+3;i<y+5;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+17;i++){
				line(x+14,i,x+15,i);
			}
			break;
		case 8:
			for(i=y+3;i<y+5;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+9;i++){
				line(x+6,i,x+7,i);
				line(x+14,i,x+15,i);
			}
			for(i;i<y+11;i++){
				line(x+6,i,x+15,i);
			}
			for(i;i<y+15;i++){
				line(x+6,i,x+7,i);
				line(x+14,i,x+15,i);
			}
			for(i;i<y+17;i++){
				line(x+6,i,x+15,i);
			}
			break;
	}
}
void site_draw(int x,int y,int j){
	
	int z=site[j][2];
	x=x*20;
	y=y*20;
	int i=0;
	beginPaint();
	if(z==9){
		setPenColor(RGB(200,200,200));
	}else if(z==10){
		setPenColor(GREEN);
	}else if(z==1){
		setPenColor(WHITE);
	}else if(z==2){
		setPenColor(RED);
	}
	
	for(i=x+1;i<x+20;i++){
		line(i,y+1,i,y+20);
	}
	setPenColor(BLACK);
	if(z==1&&site[j][1]!=0){
		num_mode(x,y,site[j][1]);
	}
	endPaint();
	
	
}

void show(int n){
	if(n>=0&&n<600&&site[n][1]==0&&site[n][3]<2){
		if(n-1>=0&&n%30!=0){
			site[n-1][2]=1;
			site[n-1][3]++;
			show(n-1);
		}
		if(n+1<600&&n%30!=29){
			site[n+1][2]=1;
			site[n+1][3]++;
			show(n+1);
		}
		if(n-30>=0){
			site[n-30][2]=1;
			site[n-30][3]++;
			show(n-30);
		}
		if(n+30<600){
			site[n+30][2]=1;
			site[n+30][3]++;
			show(n+30);
		}
		if(n-31>=0&&n%30!=0){
			site[n-31][3]++;
			site[n-31][2]=1;
			show(n-31);
		}
		if(n-29>=0&&n%30!=29){
			site[n-29][3]++;
			site[n-29][2]=1;
			show(n-29);
		}
		if(n+29<600&&n%30!=0){
			site[n+29][2]=1;
			site[n+29][3]++;
			show(n+29);
		}
		if(n+31<600&&n%30!=29){
			site[n+31][2]=1;
			site[n+31][3]++;
			show(n+31);
		}
	}
} 
void visit(int x,int y,int z){
	x=x*20;
	y=y*20;
	int i=0;
	beginPaint();
	if(site[z][0]==1){
		setPenColor(RED);
	}else if(site[z][2]==9&&site[z][1]!=0){
		setPenColor(YELLOW);
	}else if(site[z][2]==9){
		setPenColor(RGB(200,200,200));
	}
	for(i=x+1;i<x+20;i++){
		line(i,y+1,i,y+20);
	}
	setPenColor(BLACK);
	endPaint();
}

void refresh(){
	int i=0;
	int a=0;
	int b=0;
	for(i=0;i<600;i++){
		site_draw(i%30,i/30,i);
		//visit(i%30,i/30,i);
		if(site[i][0]){
			a++;
		}
		if(site[i][2]==1){
			b++;
		}
	}
	if(a+b==600){
		printf("YOU WIN ! ! !");
		printf("   time = %ds\n",t);
	}
}
void check(int n){
	
	if(n-1>=0&&n%30!=0&&site[n-1][0]==1){
		site[n][1]++;
	}
	if(n+1<600&&n%30!=29&&site[n+1][0]==1){
		site[n][1]++;
	}
	if(n-30>=0&&site[n-30][0]==1){
		site[n][1]++;
	}
	if(n-31>=0&&n%30!=0&&site[n-31][0]==1){
		site[n][1]++;
	}
	if(n-29>=0&&n%30!=29&&site[n-29][0]==1){
		site[n][1]++;
	}
	if(n+30<600&&site[n+30][0]==1){
		site[n][1]++;
	}
	if(n+29<600&&n%30!=0&&site[n+29][0]==1){
		site[n][1]++;
	}
	if(n+31<600&&n%30!=29&&site[n+31][0]==1){
		site[n][1]++;
	}
	
}
void start(){
	int i=0;
	int a=0;
	score=0;
	t=0;
	for(i=0;i<600;i++){
		site[i][0]=0;
		site[i][1]=0;
		site[i][2]=9;
		site[i][3]=0;
	}
	srand(time(0));
	for(i=0;i<n;i++){
		a=rand()%(60);
		if(a>0){
			site[a*10-rand()%(10)][0]=1;	
		}else{
			site[rand()%(10)][0]=1;
		}
	}
	
	for(i=0;i<600;i++){
		check(i); 
	}
	refresh();
}

void mouseListener(int x,int y,int button,int event){
	int x1=0;
	int y1=0;
	x1=x/20;
	y1=y/20;
	if(button==1&&event==0){
		if(site[x1+y1*30][0]){
			site[x1+y1*30][2]=2;
			printf("your last score : %d  ,time = %ds\n",score,t);
			
			start();
		}else{
			score++;
			site[x1+y1*30][2]=1;
			show(x1+y1*30); 
		}
		
		refresh();
	}
	if(button==3&&event==0){
		if(site[x1+y1*30][2]==9){
			site[x1+y1*30][2]=10;
		}else if(site[x1+y1*30][2]==10){
			site[x1+y1*30][2]=9;
		}
		
		refresh();
	}
}
void timerListener(int id){
	t++;

}

int Setup(){
	initConsole();
	initWindow("É¨À×",200,200,601,401);
	
	/*while(n<1||n>600){
		printf("please enter the number of bomb £¨0<n<600£©: ");
		scanf("%d",&n);
	}*/
	printf("Õ¨µ¯´ó¸Å£º%d¸ö\n",n);
	background();
	start();
	registerMouseEvent(mouseListener);
	registerTimerEvent(timerListener);
	startTimer(0,1000);
	return 0;
}
 
