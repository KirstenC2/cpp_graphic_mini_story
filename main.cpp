#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<graphics.h>
#include<time.h>
#include<dos.h>

void face(){
	rectangle(80,50,550,350);
	//face
	circle(330,200,130);
	//body
	line(330,330,330,500);
	//left arm
	line(330,330,280,430);
	//right arm
	line(330,330,380,430);
}
void closeEyes(int value){
	face();
	//left eye
	arc(280+value,170,210,330,35);
	//right eye
	arc(380+value,170,210,330,35);
	//mouth
	line(350+value,250,290+value,250);
}
void openEyes(int value){
	face();
	//left eye
	circle(280+value,180,30);
	//right eye
	circle(370+value,180,30);
	//mouth
	line(350+value,250,290+value,250);
}
void sleeping(){
	face();
	//left eye
	arc(280,150,210,330,35);
	//right eye
	arc(380,150,210,330,35);
	//mouth
	circle(350,250,20);
	//body

}
void txtOnScreen(int style){
	settextstyle(2,0,8);	
	outtextxy(230,140+style,"Windows");	//text on screen
	settextstyle(3,0,3);	
	outtextxy(505,285,"07:59");
}
void scene1BG(){
	//scene 1
    //table
    
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    rectangle(30,330,600,350);		//table surface
    floodfill(31,331,WHITE);
    rectangle(50,350,580,450);		
    rectangle(60,365,320,430);		//left drawer
    circle(180,385,10); 			//left drawer knob
	rectangle(330,365,570,430);		//right drawer
	circle(450,385,10); 			//right drawer knob

	//computer
	setfillstyle(SOLID_FILL,BROWN);
	rectangle(180,120,440,280);
	floodfill(181,121,WHITE);
	
	setfillstyle(SOLID_FILL,BLACK);
	rectangle(190,130,430,270);		//screen computer
	floodfill(191,131,WHITE);
	
	rectangle(287,280,334,320);		//hanger
	rectangle(247,320,374,330);		//base
	
	//books on table
	
	setfillstyle(SOLID_FILL,CYAN);
	rectangle(55,200,70,330);
	floodfill(56,201,WHITE);
	setfillstyle(SOLID_FILL,YELLOW);
	rectangle(70,230,90,330);
	floodfill(71,231,WHITE);
	setfillstyle(SOLID_FILL,LIGHTGREEN);
	rectangle(90,215,105,330);
	floodfill(91,216,WHITE);	
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(105,207,120,330);
	floodfill(106,208,WHITE);
	//clock
	rectangle(480,270,580,330);
	rectangle(490,280,570,320);
	
}
void screenClockMoving(){
    int i=0,count=3;
    
	while(i!=110 && count!=0){
		count--;
    	scene1BG();
	    txtOnScreen(i);
	    delay(400);
	    cleardevice();
	    i+=20;
	    int x=100;
	    if(x==100){
	    	x=0;
		    while(x!=100){
		    	scene1BG();
			    txtOnScreen(x);
			    delay(400);
			    cleardevice();
			    x+=20;
			}
		}
	}
}
void alarmBuzzing(){
		line(480,240,510,260);
		line(530,230,530,260);
		line(580,240,550,260);
}
void scene1(){
	outtextxy(505,285,"07:59");
    screenClockMoving();
   //scene 1
    int i=0;
	while(i!=6){
		scene1BG();
	    txtOnScreen(0);
		outtextxy(505,285,"08:00");
		alarmBuzzing();
		delay(400);
		cleardevice();
		i++;
		if(i%2==0){
			scene1BG();
		    txtOnScreen(0);
			outtextxy(505,285,"08:00");
			delay(400);
			cleardevice();
		}
	}
}
void blinkEyes(int value){
	int countBlink=0;
    while(countBlink!=2){
    	closeEyes(value);
	    delay(400);
	    cleardevice();
	    
	    openEyes(value);
	    delay(400);
	    cleardevice();
	    countBlink++;
	}
}
void lookLeftRight(){
	for(int i=0;i<=30;i++){
    	openEyes(-i);
    	delay(40);
    	cleardevice();
    	
	}
	openEyes(-30);
	delay(800);
	cleardevice();
	blinkEyes(-30);
	cleardevice();
	settextstyle(4,0,4);
	outtextxy(255,205,"Oh... ");
	delay(1500);
	for(int i=0;i<=60;i++){
    	openEyes(i-30);
    	delay(40);
    	cleardevice();
	}
	
	openEyes(30);
	delay(800);
	cleardevice();
	blinkEyes(30);
	cleardevice();
	settextstyle(4,0,4);
	outtextxy(185,205,"It's 8:00am");
	delay(2000);
    for(int i=0;i<=30;i++){
    	openEyes(30-i);
    	delay(40);
    	cleardevice();
	}
	openEyes(0);
	delay(300);
	cleardevice();
}
void wakeUpLines(){
	settextstyle(4,0,4);
	outtextxy(185,125,"I ");
	delay(380);
	outtextxy(220,125,"know... ");
	delay(1900);
	outtextxy(65,185,"I ");
	delay(380);
	outtextxy(110,185,"should ");
	delay(380);
	outtextxy(280,185,"wake ");
	delay(380);
	outtextxy(410,185,"up...");
	delay(1900);
	outtextxy(105,245,"and ");
	delay(1900);
	outtextxy(215,245,"go ");
	delay(380);
	outtextxy(300,245,"to ");
	delay(380);
	outtextxy(370,245,"work...");
	delay(2000);
	cleardevice();
}
void scene2(){
	sleeping();
    delay(3000);
    cleardevice();
    
	blinkEyes(0);
	
    closeEyes(0);
    delay(800);
    cleardevice();
    
    openEyes(0);
    delay(1200);
    cleardevice();
    lookLeftRight();
    //blink eyes
    blinkEyes(0);
	
   	openEyes(0);
	delay(600);
    cleardevice();
	
	wakeUpLines();
}
void movingManFace(int value){
	circle(320+value,235,8);//right eye
	circle(280+value,235,8);//left eye
	line(280+value,260,320+value,260);
}
void stickman(int value){
    circle(300+value,240,50);//head
    circle(320+value,235,8);//right eye
	circle(280+value,235,8);//left eye
	line(280+value,260,320+value,260);
    line(300+value,290,300+value,390);//body
    line(300+value,290,258+value,340);//left arm
    line(300+value,290,347+value,345);//right arm
    line(300+value,390,260+value,440);//left leg
    line(300+value,390,340+value,440);//right leg
}
void happyStickman(int value){
    circle(300+value,240,50);//head
    circle(320+value,235,8);//right eye
	circle(280+value,235,8);//left eye
	line(280+value,260,320+value,260);
	arc(300+value,260,180,360,20);
    line(300+value,290,300+value,390);//body
    line(300+value,290,258+value,340);//left arm
    line(300+value,290,347+value,345);//right arm
    line(300+value,390,260+value,440);//left leg
    line(300+value,390,340+value,440);//right leg
}
void bed(){
	setfillstyle(SOLID_FILL,BROWN);
	rectangle(0,150,50,425);//bedframe
	floodfill(1,151,WHITE);
	setfillstyle(SOLID_FILL,DARKGRAY);
    rectangle(50,320,500,425);//bed
    floodfill(51,321,WHITE);
    rectangle(50,300,150,320);//pillow
    rectangle(80,20,250,180);//window frame
    rectangle(90,30,160,170);//left window
    rectangle(170,30,240,170);//right window
    
}

void scene3(){
	for(int i=0;i<=400;i++){
    	bed();
    	stickman(i);
    	movingManFace(i);
    	delay(10);
    	cleardevice();
	}
}
void minion(int value){
	    //minion's body
	arc(450+value,300,0,180,55);
	line(395+value,300,395+value,380);
	arc(450+value,380,180,360,55);
	line(505+value,300,505+value,380);
	
	circle(450+value,300,35);//goggle
	circle(450+value,300,25);
	line(395+value,290,415+value,290); //goggle left belt
	line(395+value,310,415+value,310);
	line(484+value,290,505+value,290); //goggle right belt
	line(484+value,310,505+value,310);
	
	circle(450+value,305,10);//eyeball
	arc(450+value,340,190,345,20);//lip
	line(395+value,370,505+value,370);//cloth
	line(420+value,390,480+value,390);//pocket
	arc(450+value,390,182,360,30);
	line(375+value,340,395+value,360);//left hand
	line(520+value,340,505+value,360);//right hand
	line(430+value,430,430+value,450);//right leg
	line(470+value,430,470+value,450);//right leg
}

void scene4BG(){
	//fan
	rectangle(280,0,340,20);
	rectangle(300,20,320,60);
	rectangle(260,60,360,70);
	rectangle(40,60,260,70);//left wing 
	rectangle(260,60,580,70);//right wing
	rectangle(280,70,340,85);
	
	//table
	rectangle(20,300,250,320);//surface
	rectangle(40,320,50,430);//left table leg
	rectangle(220,320,230,430);//right table leg
	
}

void scene4(){
	//stickman met minion
	for(int i=0;i<=320;i++){
		scene4BG();
		minion(0);
		stickman(-300+i);
		delay(10);
		cleardevice();
		if(i==320){
			scene4BG();
			minion(0);
			stickman(-300+i);
			delay(10);
		}
	}
	settextstyle(3,0,3);
	outtextxy(100,150,"Good Morning, Stuart...");
	delay(1000);
	cleardevice();
	
	scene4BG();
	minion(0);
	stickman(20);
	delay(10);
	outtextxy(415,170,"Morning, Stickman...");
	delay(1500);
	cleardevice();
	
	scene4BG();
	minion(0);
	stickman(20);
	delay(10);
	outtextxy(100,150,"Yeah...GOOD Morning");
	delay(1500);
	cleardevice();
	
	scene4BG();
	minion(0);
	stickman(20);
	delay(10);
	outtextxy(415,170,"Go and get ready,");
	outtextxy(455,200,"Stickman");
	delay(1500);
	cleardevice();
	
	scene4BG();
	minion(0);
	stickman(20);
	delay(10);
	outtextxy(150,150,"FINE...");
	delay(1500);
	cleardevice();
	
	scene4BG();
	minion(0);
	stickman(20);
	delay(10);
	outtextxy(415,170,"I'll prepare your");
	outtextxy(455,200,"breakfast");
	delay(1500);
	cleardevice();
	
	scene4BG();
	minion(0);
	stickman(20);
	delay(10);
	outtextxy(150,150,"Thanks, Stuart...");
	delay(1900);
	cleardevice();
	
	for(int i=0;i<=380;i++){
		scene4BG();
		minion(i);
		stickman(20+i);
		delay(6);
		cleardevice();
	}
}

void scene5BG(){
	rectangle(440,120,630,438);
}
void scene5(){
	//walk to toilet
	for(int i=0;i<=320;i++){
		scene5BG();
		circle(600,300,8);
		line(620,438,620,120);
		stickman(-300+i);
		delay(10);
		cleardevice();
		if(i==320){
			scene5BG();
			stickman(-300+i);
			delay(10);
		}
	}
	scene5BG();
	circle(600,300,8);
	line(620,438,620,120);
	settextstyle(3,0,4);
	outtextxy(145,55,"Hey Sara, Open toilet door.");
	stickman(20);
	delay(4000);
	cleardevice();
	//open toilet door
	for(int i=0;i<=150;i++){
		scene5BG();
		stickman(20);
		circle(600-i,300,8);
		line(620-i,438,620-i,120);
		delay(30);
		cleardevice();
		if(i==170){
			stickman(20);
			scene5BG();
			circle(600-i,300,8);
			line(620-i,438,620-i,120);
		}
	}
	//stickman walk into the toilet
	cleardevice();
	for(int i=0;i<=380;i++){
		stickman(20+i);
		scene5BG();
		circle(450,300,8);
		line(470,438,470,120);
		delay(15);
		cleardevice();
		if(i==380){
			stickman(20+i);
			scene5BG();
			circle(450,300,8);
			line(470,438,470,120);
			delay(500);
			cleardevice();
		}
	}
	//close toilet door
	for(int i=0;i<=150;i++){
		scene5BG();
		circle(450+i,300,8);
		line(470+i,438,470+i,120);
		delay(30);
		cleardevice();
		if(i==170){
			scene5BG();
			circle(450-i,300,8);
			line(470-i,438,470-i,120);
		}
	}
}
void brushTeeth(){
	for(int i=0;i<=30;i++){
		circle(330,200,130);//face to brush teeth
		//left eye
		arc(280,170,210,330,35);
		//right eye
		arc(380,170,210,330,35);
		circle(325,260,30);//mouth
		line(295,260,355,260);
		line(330,330,330,500);//body
		line(330,330,260,420);//left hand
		line(260,420,330,470);
		line(330,330,430,360);//right hand
		line(430,360,390-i,260);
		rectangle(360-i,255,420-i,265);//toothbrush
		rectangle(330-i,253,360-i,267);//toothbrush head
		delay(20);
		cleardevice();
	} 
	for(int i=0;i<=30;i++){
		circle(330,200,130);//face to brush teeth
		circle(280,180,30);//eye
		circle(370,180,30);//right eye
		circle(325,260,30);//mouth
		line(295,260,355,260);
		line(330,330,330,500);//body
		line(330,330,260,420);//left hand
		line(260,420,330,470);
		line(330,330,430,360);//right hand
		line(430,360,355+i,260);
		rectangle(330+i,255,390+i,265);//toothbrush
		rectangle(300+i,253,330+i,267);//toothbrush head
		delay(20);
		cleardevice();
	} 
	
}
void swingHandS6(){
	for(int i=0;i<=30;i++){
		settextstyle(3,0,4);
		outtextxy(145,10,"Wow! I'm all good now!");
		circle(330,200,130);//face to brush teeth
		//left eye
		arc(280,180,360,180,30);
		//right eye
		arc(370,180,360,180,30);
		arc(325,230,180,360,25);//mouth
		line(330,330,330,500);//body
		line(330,330,260,420);//left hand
		line(260,420,330,470);
		line(330,330,400,420);//right hand
		line(400,420,420,360);
		line(420,360,440,375-i);
		rectangle(465,455,525,465);//toothbrush
		rectangle(435,453,465,465);//toothbrush head
		delay(25);
		cleardevice();
	}
	for(int i=0;i<=30;i++){
		settextstyle(3,0,4);
		outtextxy(145,10,"Wow! I'm all good now!");
		circle(330,200,130);//face to brush teeth
		//left eye
		arc(280,180,360,180,30);
		//right eye
		arc(370,180,360,180,30);
		arc(325,230,180,360,25);//mouth
		line(330,330,330,500);//body
		line(330,330,260,420);//left hand
		line(260,420,330,470);
		line(330,330,400,420);//right hand
		line(400,420,420,360);
		line(420,360,440,345+i);
		rectangle(465,455,525,465);//toothbrush
		rectangle(435,453,465,465);//toothbrush head
		delay(25);
		cleardevice();
	}
}
void scene6(){
	int i=0;
	while(i!=4){
		brushTeeth();
		i++;
	}
		//stop brushing
	circle(330,200,130);//face to brush teeth
	circle(280,180,30);//eye
	circle(370,180,30);//right eye
	line(295,260,355,260);//mouth
	line(330,330,330,500);//body
	line(330,330,260,420);//left hand
	line(260,420,330,470);
	line(330,330,430,360);//right hand
	line(430,360,390,260);
	rectangle(365,255,425,265);//toothbrush
	rectangle(335,253,365,267);//toothbrush head
	delay(20);
	
	//put away tooth brush
	for(int i=0;i<=100;i++){
		circle(330,200,130);//face to brush teeth
		circle(280,180,30);//eye
		circle(370,180,30);//right eye
		line(295,260,355,260);//mouth
		line(330,330,330,500);//body
		line(330,330,260,420);//left hand
		line(260,420,330,470);
		line(330,330,430,360);//right hand
		line(430,360,390+i,260);
		rectangle(365+i,255,425+i,265);//toothbrush
		rectangle(335+i,253,365+i,267);//toothbrush head
		delay(10);
		cleardevice();
	}
	// put down toothbrush
	for(int i=0;i<=200;i++){
		circle(330,200,130);//face to brush teeth
		circle(280,180,30);//eye
		circle(370,180,30);//right eye
		line(295,260,355,260);//mouth
		line(330,330,330,500);//body
		line(330,330,260,420);//left hand
		line(260,420,330,470);
		line(330,330,430,360);//right hand
		line(430,360,490,260+i);
		rectangle(465,255+i,525,265+i);//toothbrush
		rectangle(435,253+i,465,267+i);//toothbrush head
		delay(15);
		cleardevice();
	}
	circle(330,200,130);//face to brush teeth
	//left eye
	arc(280,170,210,330,35);
	//right eye
	arc(380,170,210,330,35);
	line(295,260,355,260);//mouth
	line(330,330,330,500);//body
	line(330,330,260,420);//left hand
	line(260,420,330,470);
	line(330,330,430,360);//right hand
	line(430,360,490,460);
	rectangle(465,455,525,465);//toothbrush
	rectangle(435,453,465,465);//toothbrush head
	delay(1500);
	cleardevice();
	
	settextstyle(3,0,4);
	outtextxy(105,205,"Okay...Give me five minutes");
	delay(2800);
	cleardevice();
	
	settextstyle(3,0,4);
	outtextxy(135,205,"I got a feeling...");
	delay(2800);
	cleardevice();
	
	settextstyle(3,0,4);
	outtextxy(95,205,"I needa do some big business...");
	delay(2000);
	cleardevice();
	
	for(int i=0;i<=310;i++){
		settextstyle(3,0,4);
		outtextxy(655-i*4,205,"10 minutes later...");
		delay(1);
		cleardevice();
	}
	int count=0;
	while(count!=3){
		swingHandS6();
		count++;
	}
	settextstyle(3,0,4);
	outtextxy(35,10,"Lemme get my breakfast and go to work!");
	circle(330,200,130);//face to brush teeth
	//left eye
	arc(280,180,360,180,30);
	//right eye
	arc(370,180,360,180,30);
	arc(325,230,180,360,25);//mouth
	line(330,330,330,500);//body
	line(330,330,260,420);//left hand
	line(260,420,330,470);
	line(330,330,400,420);//right hand
	line(400,420,420,360);
	line(420,360,440,375);
	rectangle(465,455,525,465);//toothbrush
	rectangle(435,453,465,465);//toothbrush head
	delay(3500);
	cleardevice();
}
void bento(int value){
	//bento box
	rectangle(180+value,240,240+value,300);
	arc(210+value,245,360,180,20);
}
void scene7BG(){
	//fan
	rectangle(280,0,340,20);
	rectangle(300,20,320,60);
	rectangle(260,60,360,70);
	rectangle(40,60,260,70);//left wing 
	rectangle(260,60,580,70);//right wing
	rectangle(280,70,340,85);
	
	//table
	rectangle(20,300,250,320);//surface
	rectangle(40,320,50,430);//left table leg
	rectangle(220,320,230,430);//right table leg
	

}
void scene7(){
	scene7BG(); 
	//bento box
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(350,140,"Stuart");
	delay(1500);
	cleardevice();

	scene7BG(); 
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	happyStickman(0);
	delay(1800);
	cleardevice();

	scene7BG(); 
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(350,140,"Stuart!!!");
	delay(2000);
	cleardevice();
	
	for(int i=0;i<=350;i++){
		scene7BG();
		rectangle(180,240,240,300);
		arc(210,245,360,180,20);
		minion(400-i);
		happyStickman(0);
		delay(10);
		cleardevice();
	}
	scene7BG();
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	minion(50);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(420,200,"What's up?");
	delay(2000);
	cleardevice();
	
	scene7BG();
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	minion(50);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(350,140,"Is this mine?");
	delay(2000);
	cleardevice();
	
	scene7BG();
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	minion(50);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(420,200,"Of course...");
	delay(2000);
	cleardevice();
	
	scene7BG();
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	minion(50);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(350,140,"Nice! Thanks!");
	delay(2000);
	cleardevice();

	scene7BG();
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	minion(50);
	happyStickman(0);
	settextstyle(3,0,4);
	outtextxy(420,200,"My pleasure");
	delay(2000);
	cleardevice();
	
	scene7BG();
	rectangle(180,240,240,300);
	arc(210,245,360,180,20);
	minion(50);
	happyStickman(0);
	settextstyle(3,0,3);
	outtextxy(420,200,"Have a nice day");
	delay(2000);
	cleardevice();
	
	
	for(int i=0;i<=55;i++){
		scene7BG();
		//bento
		rectangle(180,240,240,300);
		arc(210,245,360,180,20);
		
		minion(50);
		circle(300,240,50);//head
	    circle(320,235,8);//right eye
		circle(280,235,8);//left eye
		line(280,260,320,260);
		arc(300,260,180,360,20);
	    line(300,290,300,390);//body
	    line(300,290,258,340-i);//left arm
	    line(300,290,347,345);//right arm
	    line(300,390,260,440);//left leg
	    line(300,390,340,440);//right leg
	    delay(30);
	    cleardevice();
	}
	for(int i=0;i<=20;i++){
		scene7BG();
		rectangle(180,240,240,300);
		arc(210,245,360,180,20);
		minion(50);
		circle(300,240,50);//head
	    circle(320,235,8);//right eye
		circle(280,235,8);//left eye
		line(280,260,320,260);
		arc(300,260,180,360,20);
	    line(300,290,300,390);//body
	    line(300,290,258-i,280);//left arm
	    line(300,290,347,345);//right arm
	    line(300,390,260,440);//left leg
	    line(300,390,340,440);//right leg
	    delay(30);
	    cleardevice();
	}	
	
	for(int i=0;i<=80;i++){
		scene7BG();
		rectangle(180+i,240,240+i,300);
		arc(210+i,245,360,180,20);
		minion(50);
		circle(300+i,240,50);//head
	    circle(320+i,235,8);//right eye
		circle(280+i,235,8);//left eye
		line(280+i,260,320+i,260);
		arc(300+i,260,180,360,20);
	    line(300+i,290,300+i,390);//body
	    line(300+i,290,238+i,280);//left arm
	    line(300+i,290,347+i,345);//right arm
	    line(300+i,390,260+i,440);//left leg
	    line(300+i,390,340+i,440);//right leg
	    delay(30);
	    cleardevice();
	}
	
	for(int i=0;i<=50;i++){
		scene7BG();
		rectangle(260,240+i,320,300+i);
		arc(290,245+i,360,180,20);
		minion(50);
		circle(380,240,50);//head
	    circle(400,235,8);//right eye
		circle(360,235,8);//left eye
		line(360,260,400,260);
		arc(380,260,180,360,20);
	    line(380,290,380,390);//body
	    line(380,290,318,280+i);//left arm
	    line(380,290,427,345);//right arm
	    line(380,390,340,440);//left leg
	    line(380,390,420,440);//right leg
	    delay(30);
	    cleardevice();
	}	
	
	scene7BG();
	settextstyle(3,0,4);
	outtextxy(250,140,"Okay I'm ready for work!'");
	rectangle(260,290,320,350);
	arc(290,295,360,180,20);
	minion(50);
	circle(380,240,50);//head
    circle(400,235,8);//right eye
	circle(360,235,8);//left eye
	line(360,260,400,260);
	arc(380,260,180,360,20);
    line(380,290,380,390);//body
    line(380,290,318,330);//left arm
    line(380,290,427,345);//right arm
    line(380,390,340,440);//left leg
    line(380,390,420,440);//right leg
    delay(1500);
    cleardevice();
    
    for(int i=0;i<=500;i++){
    	scene7BG();
    	rectangle(260+i,290,320+i,350);
		arc(290+i,295,360,180,20);
		minion(50+i);
		circle(380+i,240,50);//head
	    circle(400+i,235,8);//right eye
		circle(360+i,235,8);//left eye
		line(360+i,260,400+i,260);
		arc(380+i,260,180,360,20);
	    line(380+i,290,380+i,390);//body
	    line(380+i,290,318+i,330);//left arm
	    line(380+i,290,427+i,345);//right arm
	    line(380+i,390,340+i,440);//left leg
	    line(380+i,390,420+i,440);//right leg
	    delay(10);
	    cleardevice();
	}
}
void sun(){
	//sun
		line(450,80,470,80);//left line
		circle(500,80,20);
		line(530,80,550,80);//right line
		line(500,30,500,50);//top line
		line(500,110,500,130);//bottom line
}
void scene8(){
	for(int i=0;i<250;i++){
		//homne 
		rectangle(40,220,210,300);//window frame
    	rectangle(50,230,120,290);//left window
    	rectangle(130,230,200,290);//right window
    
		line(0,80,200,80);
		line(200,80,250,180);
		line(0,180,250,180);
		rectangle(-20,180,230,400);
		
		sun();
		
		happyStickman(i*2);
		rectangle(215+i*2,345,275+i*2,405);
		arc(245+i*2,350,360,180,20);
		delay(5);
		cleardevice();
	}
}
void car(){
	//car
	rectangle(320,200,550,280);//upper part of car
	rectangle(290,280,580,370);//car body
	circle(340,390,20);//left wheel
	circle(540,390,20);//right wheel
}
void scene9(){
	for(int i=0;i<=200;i++){
		car();
		sun();
		happyStickman(-350+i);
		rectangle(215-350+i,345,275-350+i,405);
		arc(245-350+i,350,360,180,20);
		delay(5);
		cleardevice();
	}
	
	//car
	car();
	sun();
	happyStickman(-350+200);
	settextstyle(3,0,4);
	outtextxy(80,100,"Well...");
	rectangle(215-150,345,275-150,405);
	arc(245-150,350,360,180,20);
	delay(2000);
	cleardevice();

	car();
	sun();
	happyStickman(-350+200);
	settextstyle(3,0,4);
	outtextxy(60,100,"This is part of my daily life");
	rectangle(215-150,345,275-150,405);
	arc(245-150,350,360,180,20);
	delay(2000);
	cleardevice();
	
	car();
	sun();
	happyStickman(-350+200);
	settextstyle(3,0,4);
	outtextxy(60,100,"How about you?");
	rectangle(215-150,345,275-150,405);
	arc(245-150,350,360,180,20);
	delay(2000);
	cleardevice();
	
	car();
	sun();
	happyStickman(-350+200);
	settextstyle(3,0,4);
	outtextxy(60,100,"Hope you have a nice day too!");
	rectangle(215-150,345,275-150,405);
	arc(245-150,350,360,180,20);
	delay(2000);
	cleardevice();
	
	settextstyle(3,0,8);
	outtextxy(130,170,"The End");
	delay(2000);
	cleardevice();
	
	settextstyle(3,0,8);
	outtextxy(130,170,"Thank you");	
	
}
int main(){
	int gd = DETECT, gm;
    initgraph(&gd,&gm, "C:\\tc\\bgi");

   	scene1();//computer desk
    scene2();//stickman wake up
    scene3();// walking from bed to get ready
	scene4();//scene 4 met minions
	scene5();//scene 5 stickman go toilet
	scene6();// brush teeth
	scene7();//take bento
	scene8();//walk out the house
	scene9();//ending scene
	
    getch();
    closegraph();
    return 0;
}
