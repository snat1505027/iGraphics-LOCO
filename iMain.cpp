# include "iGraphics.h"
#include<string.h>
#include<stdio.h>
#include <time.h>
void iMouse(int button, int state, int mx, int my) ;
void iKeyboard(unsigned char key);
void result(int R[],int V[],int l);
void show_result(float res_resistance);
void PlaySound_2();
//int x= 650, y = 395, r = 40;
char c[100];
int x[100];
int y[100];
int p[100];
int q[100];
unsigned char key,k[100];
char value[100];
int total=0,t,total1,a=0,i,vol=0,finish=0;
int f=0,flag=0,flag1=0,m=0,l=0,h=0,length=1000,width=600;
int con=0,rs=0,rp=0;
int result_f=0;
float res_resistance=0;
int Rp[100],Rs[100],V[100];
//int x_val=835;
int tim[3]= {};
void resistance()
{
    iFilledCircle(70,500,40);//100,500,50,30
    iSetColor(255, 255, 0);
    iLine(40,490,45,490);
    for(i=0; i<4; i++)
    {
        iLine(45+(i*12),490,51+(i*12),510);
        iLine(51+(i*12),510,57+(i*12),490);
    }
    iLine(93,490,98,490);
}

void _switch()
{
    iFilledCircle(70,300,40);
    iSetColor(50,50,50);
    iLine(40,295,60,295);
    iLine(60,295,75,310);
    iLine(73,295,93,295);
}

void VOLTAGE_SOURCE()
{

    iFilledCircle(70,400,40);
    iSetColor(255,255,0);
    iCircle(70,400,20);
    iLine(70,405,70,415);
    iLine(65,410,75,410);
    iLine(65,390,75,390);
}
void CAPACITOR()
{
    iFilledCircle(70,200,40);
    iSetColor(1000,500,590);
    iLine(63,180,63,220);
    iLine(63,200,40,200);
    iLine(77,180,77,220);
    iLine(77,200,100,200);
}
void CURRENT_SOURCE()
{

    iFilledCircle(70,100,40);
    iSetColor(255,228,181);
    iCircle(70,100,20);
    iLine(70,90,70,110);
    iLine(70,110,65,106);
    iLine(70,110,75,106);
}
void SCREEN()
{
    iSetColor(128,0,128);
    iFilledRectangle(150,50,650,480);
    iSetColor(0,0,0);
    iFilledRectangle(160,60,630,460);
    iSetColor(350,0,0);
    iFilledRectangle(820,330,160,200);
    iSetColor(0,0,0);
    iFilledRectangle(825,335,150,190);
    iSetColor(255,20,147);

    i=165;
    while(i<785)
    {
        iSetColor(50,50,50);
        iLine(i,60,i,520);
        iSetColor(20,20,20);
        iLine(i+10,60,i+10,520);
        i=i+20;
    }
    i=65;
    while(i<520)
    {
        iSetColor(50,50,50);
        iLine(160,i,790,i);
        iSetColor(20,20,20);
        iLine(160,i+10,790,i+10);
        i=i+20;
    }
}
void gettime(int tim[])
{
    time_t ctime;
    struct tm * current;
    time ( &ctime );
    current = localtime ( &ctime );
    tim[0] = current->tm_hour;
    tim[1] = current->tm_min;
    tim[2] = current->tm_sec;
}


void screen_clear(unsigned char ol)
{
    int i;
    if(ol=='u')
    {
        iSetColor(0,0,0);
        iFilledRectangle(160,60,630,460);
        i=165;
        while(i<785)
        {
            iSetColor(50,50,50);
            iLine(i,60,i,520);
            iSetColor(20,20,20);
            iLine(i+10,60,i+10,520);
            i=i+20;
        }
        i=65;
        while(i<520)
        {
            iSetColor(50,50,50);
            iLine(160,i,790,i);
            iSetColor(20,20,20);
            iLine(160,i+10,790,i+10);
            i=i+20;
        }
    }
}
void value_bar()
{
    int i;
    iSetColor(255,215,0);
    iRectangle(830,450,140,50);
    iRectangle(830,400,140,30);
    iSetColor(255,215,0);
    iFilledRectangle(850,360,95,30);
    iSetColor(255,69,0);
    iText(880,368,"OK",GLUT_BITMAP_TIMES_ROMAN_24);
}
void result_bar()
{
    iSetColor(127,255, 212);
    iFilledRectangle(820,50,160,270 );
    iSetColor(255,20,147);
    iFilledRectangle(825,55,150,260 );
    iSetColor(0,0,0);
    iFilledRectangle(830,60,140,250);
    iSetColor(255,250,205);
    iText(868,290," CLICK ",GLUT_BITMAP_HELVETICA_18);
    iText(868,250," HERE ",GLUT_BITMAP_HELVETICA_18);
    iText(868,210," TO ",GLUT_BITMAP_HELVETICA_18);
    iText(868,170," SEE ",GLUT_BITMAP_HELVETICA_18);
    iText(868,130," THE ",GLUT_BITMAP_HELVETICA_18);
    iText(868,90," RESULT ",GLUT_BITMAP_HELVETICA_18);
}
void show_value(unsigned char ch,int x_val)
{
    char str[1];
    str[0]=ch;
    iSetColor(255,255,255);
    iText(x_val,410,str);
}
void blink_cursor()
{
    int i,u,t,t1,num,j=0;
    int con=0;
    gettime(tim);
    for(i=0; i<3; i++)
    {

        t1=tim[i];
        num=0;
        while(num<2)
        {

            t=t1/10;
            t1=(t1%10)*10;
            num++;
            if((t%2)==0)
            {
                iSetColor(255,255,255);
                con=1;
            }
            else
            {
                iSetColor(0, 0, 0);
                con=0;
            }
        }
    }
}
void move_cursor(int x)
{
    blink_cursor();
    iLine(x,405,x+10,405);
}
void clear_cursor(int x)
{
    iSetColor(0,0,0);
    iLine(x,405,x-10,405);
}
void draw_resistance(int p,int q,unsigned char ch)
{
    //printf("%d %d %c\n", p, q, ch);
    int i,s;
    iSetColor(20, 200, 0);
    resistance();
    iSetColor(20,200,0);
    if(ch=='v')
    {
        iFilledCircle(p,q-35,5);
        iLine(p,q,p,q-30);
        for(i=0; i<3; i++)
        {
            iLine(p,q+(i*12),p+20,q+6+(i*12));
            iLine(p+20,q+6+(i*12),p,q+12+(i*12));
        }
        iLine(p,q+12+24,p,q+12+24+30);
        iFilledCircle(p,q+12+24+35,5);
    }
    if(ch=='h')
    {
        iFilledCircle(p-35,q,5);
        iLine(p,q,p-30,q);
        for(i=0; i<3; i++)
        {
            iLine(p+(i*12),q,p+6+(i*12),q+20);
            iLine(p+6+(i*12),q+20,p+12+(i*12),q);
        }
        iLine(p+12+24,q,p+12+24+30,q);
        iFilledCircle(p+12+24+35,q,5);
    }
}
void draw_volSource(int p,int q,unsigned char ch)
{
    iSetColor(0,0,255);
    VOLTAGE_SOURCE();
    iSetColor(255,255,0);
    if(ch=='v')
    {
        iCircle(p,q,20);
        iFilledCircle(p,q+20+35,5);
        iLine(p,q+20,p,q+20+30);
        iLine(p,q+5,p,q+15);
        iLine(p-5,q+10,p+5,q+10);
        iLine(p-5,q-10,p+5,q-10);
        iLine(p,q-20,p,q-20-30);
        iFilledCircle(p,q-20-35,5);
    }
    if(ch=='h')
    {
        iCircle(p,q,20);
        iFilledCircle(p+20+35,q,5);
        iLine(p+20,q,p+20+30,q);
        iLine(p+5,q,p+15,q);
        iLine(p+10,q-5,p+10,q+5);
        iLine(p-10,q-5,p-10,q+5);
        iLine(p-20,q,p-20-30,q);
        iFilledCircle(p-20-35,q,5);
    }
}
void draw_switch(int p,int q,unsigned char ch)
{
    iSetColor(800,200,0);
    _switch();
    iSetColor(250,80,80);
    if(ch=='h')
    {
        iFilledCircle(p-5,q,5);
        iLine(p,q,p+30,q);
        iLine(p+30,q,p+30+20,q+20);
        iLine(p+30+13,q,p+30+49,q);
        iFilledCircle(p+30+49+5,q,5);
    }
    if(ch=='v')
    {
        iFilledCircle(p,q,5);
        iLine(p,q,p,q+30);
        iLine(p,q+30,p+20,q+30+20);
        iLine(p,q+30+13,p,q+30+49);
        iFilledCircle(p,q+30+49+5,5);
    }
}
void draw_capacitor(int p,int q,unsigned char ch)
{
    iSetColor(700,0,255);
    CAPACITOR();
    iSetColor(700,0,255);
    if(ch=='h')
    {
        iFilledCircle(p+20+35,q,5);
        iFilledCircle(p-20-35,q,5);
        iLine(p+20+30,q,p+5,q);
        iLine(p-20-30,q,p-5,q);
        iLine(p+5,q-10,p+5,q+10);
        iLine(p-5,q-10,p-5,q+10);
    }
    if(ch=='v')
    {
        iFilledCircle(p,q+20+35,5);
        iFilledCircle(p,q-20-35,5);
        iLine(p,q+20+30,p,q+5);
        iLine(p,q-20-30,p,q-5);
        iLine(p+10,q+5,p-10,q+5);
        iLine(p+10,q-5,p-10,q-5);
    }
}
void draw_cur_source(int p,int q,unsigned char ch)
{
    iSetColor(880,0,0);
    CURRENT_SOURCE();
    iSetColor(880,0,0);
    if(ch=='v')
    {
        iCircle(p,q,20);
        iFilledCircle(p,q+20+35,5);
        iLine(p,q+20,p,q+20+30);
        iLine(p,q-10,p,q+10);
        iLine(p,q+10,p+4,q+5);
        iLine(p,q+10,p-4,q+5);
        iLine(p,q-20,p,q-20-30);
        iFilledCircle(p,q-20-35,5);
    }
    if(ch=='h')
    {
        iCircle(p,q,20);
        iFilledCircle(p+20+35,q,5);
        iLine(p+20,q,p+20+30,q);
        iLine(p-10,q,p+10,q);
        iLine(p+10,q,p+5,q+4);
        iLine(p+10,q,p+5,q-4);
        iLine(p-20,q,p-20-30,q);
        iFilledCircle(p-20-35,q,5);
    }
}
void iDraw()
{
    //place your drawing codes here
    if(flag==1)
    {
        iClear();
        int i=0,j=0,u,num,len=0,n=0,lett=0,num1=0;
        //int con=0;
        iSetColor(20, 200, 0);
        resistance();
        iSetColor(800,200,0);
        _switch();
        iSetColor(0,0,255);
        VOLTAGE_SOURCE();
        iSetColor(700,0,255);
        CAPACITOR();
        iSetColor(880,0,0);
        CURRENT_SOURCE();
        SCREEN();
        value_bar();
        result_bar();
        //TITLE
        iSetColor(8,130,6);
        iText(240,550,"D R A W    Y O U R    C I R C U I T    H E R E",GLUT_BITMAP_TIMES_ROMAN_24);
        //DRAWING CIRCUIT

        for(i = 0; i <total; i++)
        {
            //screen_clear(k[j]);
            iSetColor(255,255,255);
            if(((x[i+1]<780&&x[i+1]>160)&&(y[i+1]>60&&y[i+1]<520))&&((x[i]<780&&x[i]>160)&&(y[i]>60&&y[i]<520)))
            {
                iLine(x[i],y[i],x[i+1],y[i+1]);
            }
            if((x[i]>30&&x[i]<110)&&(y[i]>460&&y[i]<540))
            {
                iSetColor(600, 500,400);
                resistance();
                //ask_resistance();
                iSetColor(0,0,0);
                iFilledRectangle(830,450,140,50);
                iSetColor(255,215,0);
                iRectangle(830,450,140,50);
                iSetColor(255,215,0);
                iText(835,485,"ENTER YOUR");
                iText(835,470,"RESISTANCE:");
                //iRectangle(830,400,140,30);
                if(rs==0)
                {
                    iSetColor(255,255,0);
                    iFilledCircle(960,415,7);
                }
                if(rs==1)
                {
                    iSetColor(0,0,0);
                    iFilledCircle(960,415,7);
                }
                if(rp==0)
                {
                    iSetColor(255,255,0);
                    iFilledCircle(941,415,7);
                }
                if(rp==1)
                {
                    iSetColor(0,0,0);
                    iFilledCircle(941,415,7);
                }


                //iFilledCircle(941,415,7);
                iSetColor(0,0,0);
                iText(956,410,"S");
                iText(937,410,"P");


                if((x[i+1]<780&&x[i+1]>160)&&(y[i+1]>60&&y[i+1]<520))
                    draw_resistance(x[i+1],y[i+1],k[j]);
                j++;
                //i++
                num1=0;
                while(lett<100)
                {
                    if(value[num1]>='0'&&value[num1]<='9'&&f==0)
                    {
                        show_value(value[num1],835+len);
                        move_cursor(835+n);
                        if(n>0)
                            clear_cursor(835+n);
                        n=n+10;
                        num1++;
                        len=len+8;
                    }
                    if(f==1)
                    {
                        break;
                    }

                    //len=len+8;
                    lett++;
                }
            }
            if((x[i]>30&&x[i]<110)&&(y[i]>360&&y[i]<440))
            {
                vol=1;
                iSetColor(600, 500,400);
                VOLTAGE_SOURCE();
                iSetColor(0,0,0);
                iFilledRectangle(830,450,140,50);
                iSetColor(255,215,0);
                iRectangle(830,450,140,50);
                iText(835,485,"ENTER YOUR");
                iText(835,470,"VOLTAGE:");

                if((x[i+1]<780&&x[i+1]>160)&&(y[i+1]>60&&y[i+1]<520))
                    draw_volSource(x[i+1],y[i+1],k[j]);
                j++;
                lett=0;
                num1=0;
                n=0;
                len=0;
                while(lett<100)
                {
                    if(value[num1]>='0'&&value[num1]<='9'&&f==0)
                    {
                        show_value(value[num1],835+len);
                        move_cursor(835+n);
                        if(n>0)
                            clear_cursor(835+n);
                        n=n+10;
                        num1++;
                        len=len+8;
                    }
                    if(f==1)
                    {
                        vol=0;
                        break;
                    }

                    //len=len+8;
                    lett++;
                }
            }
            if((x[i]>30&&x[i]<110)&&(y[i]>260&&y[i]<340))
            {
                iSetColor(600, 500,400);
                _switch();

                if((x[i+1]<780&&x[i+1]>160)&&(y[i+1]>60&&y[i+1]<520))
                    draw_switch(x[i+1],y[i+1],k[j]);
                j++;
            }
            if((x[i]>30&&x[i]<110)&&(y[i]>160&&y[i]<240))
            {
                iSetColor(600, 500,400);
                CAPACITOR();

                if((x[i+1]<780&&x[i+1]>160)&&(y[i+1]>60&&y[i+1]<520))
                    draw_capacitor(x[i+1],y[i+1],k[j]);
                j++;
            }
            if((x[i]>30&&x[i]<110)&&(y[i]>60&&y[i]<140))
            {
                iSetColor(600, 500,400);
                CURRENT_SOURCE();
                iSetColor(0,0,0);
                iFilledRectangle(830,450,140,50);
                iSetColor(255,215,0);
                iRectangle(830,450,140,50);
                iText(835,485,"ENTER YOUR");
                iText(835,470,"CURRENT:");


                if((x[i+1]<780&&x[i+1]>160)&&(y[i+1]>60&&y[i+1]<520))
                    draw_cur_source(x[i+1],y[i+1],k[j]);
                j++;
                lett=0;
                num1=0;
                n=0;
                len=0;
                while(lett<100)
                {
                    if(value[num1]>='0'&&value[num1]<='9'&&f==0)
                    {
                        show_value(value[num1],835+len);
                        move_cursor(835+n);
                        if(n>0)
                            clear_cursor(835+n);
                        n=n+10;
                        num1++;
                        len=len+8;
                    }
                    if(f==1)
                    {
                        vol=0;
                        break;
                    }

                    //len=len+8;
                    lett++;

                }
            }
            if(result_f==1)
            {
                show_result(res_resistance);
            }
            if ((x[i]>820&&x[i]<980)&&(y[i]>50&&y[i]<320))
            {
                iSetColor(127,255, 212);
                iFilledRectangle(200,100,550,400);

                iSetColor(0,0, 0);
                iFilledRectangle(210,110,530,380);
                iSetColor(240,25, 55);
                iText(400,450,"R E S U L T :", GLUT_BITMAP_TIMES_ROMAN_24);
                iText(250,120,"Press home to return to main screen", GLUT_BITMAP_TIMES_ROMAN_24);
            }
        }

    }
    else if(flag1==1)
    {
        iSetColor(0,0,0);
        iFilledRectangle(0,0,1000,600);
        iShowBMP( 100, 0, "ins.bmp");
    }
    else if(flag==4 && flag1==4)
    {
        iSetColor(0,0,0);
        iFilledRectangle(0,0,1000,600);
        iShowBMP( 250, 120, "ending.bmp");
        iSetColor(0,20,150);
        iText(10,10, "PRESS Q TO TERMINATE ",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else
    {
        iSetColor(0,0,0);
        iFilledRectangle(0,0,1000,600);
        iShowBMP( 250, 120, "starting.bmp");
    }
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
    iSetColor(0,0, 0);
    printf("here...\n");
    int i,s,q,len;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //printf("x = %d, y= %d\n",mx,my);
        if((mx>953&&mx<967)&&(my>408&&my<422))
        {
            rs=1;
            Rs[l]=atoi(value);
            printf("res:%d %d\n",Rs[l],l);
            res_resistance=res_resistance+Rs[l];
            l++;
        }
        if((mx>934&&mx<948)&&(my>408&&my<422))
        {
            rp=1;
            Rp[h]=atoi(value);
            printf("res:%d %d\n",Rp[h],h);
            if(res_resistance==0)
            {
                res_resistance=0+(1/(Rp[h]*1.0));
                res_resistance=(1/res_resistance);

            }
            else
            {
                res_resistance=(1/(res_resistance*1.0))+(1/(Rp[h]*1.0));
                res_resistance=(1/res_resistance);
            }
            h++;
        }
        if((mx>830&&mx<970)&&(my>368&&my<390))
        {
            f=1;
            if(vol==1)
            {
                V[m]=atoi(value);
                printf("vol:%d %d\n",V[m],m);
                m++;

            }

            len=strlen(value);
            for(i=0; i<len; i++)
            {
                value[i]=0;
            }
            a=0;
        }
        else if(total < 100)
        {
            f=0;
            q=a;
            rs=0;
            rp=0;
            printf("%d\n",q);
            x[total] = mx;
            y[total] = my;
            total++;
        }
    }
}
void iKeyboard(unsigned char key)
{
    char str[100];
    int i=0;
    if(t<100)
    {
        if (key == 'q'||key==27)
        {
            exit(0);
        }
        if(key>='0'&&key<='9')
        {
            value[a]=key;
            a++;
        }
        /* if(key=='n')
         {
             for(i=0;i<total;i++)
                 x[i]=0;
             for(i=0;i<t;i++)
                 k[i]=0;
         }*/
        else
        {
            k[t]=key;
            t++;
        }

        if(key=='v')
        {
            printf("v pressed....\n");
            printf("%s\n", k);

        }
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_END)
    {
        result_f=1;
    }
    if (key==GLUT_KEY_RIGHT && con==0)
    {
        flag1=1;
        con++;
    }
    else if(key==GLUT_KEY_RIGHT && con>0)
    {
        flag=1;
    }
    if(key==GLUT_KEY_UP)
    {
        PlaySound_2();
        flag=4;
        flag1=4;
    }
    // if(key==GLUT_KEY_RIGHT)
}
void result(int Rs[],int Rp[],int V[],int l,int h)
{
    float res=0;
    int j=0;
    float curr;
    for(j=0; j<=l; j++)
    {
        res=res+Rs[j];
    }
    curr=V[0]/res;
    printf("%.3f %.3f",res,curr);
}
void show_result(float res_resistance)
{
    char str[100],str1[100];
    sprintf(str,"EQUIVALENT");
    sprintf(str1,"RESISTANCE:%.2f",res_resistance);
    iText(835,240,str);
    iText(835,220,str1);
}
void PlaySound_1()
{
    PlaySound("fade_x.wav", NULL, SND_ASYNC);
}
void PlaySound_2()
{
    PlaySound("No Monkey.wav", NULL, SND_ASYNC| SND_LOOP);
}
int main()
{
    if (flag!=1)
        PlaySound_1();
    int t;
    iInitialize(length,width, "LOCO - the ultimate");
    return 0;
}
