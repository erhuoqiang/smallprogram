#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//������ע��������http://hi.baidu.com/neptune_moon/item/56ac4b0fe783acc891571823
#define MAX__X 23
#define MAX__Y 50
#define MAX_FOOD 50
#define ESC 27
#define SPACE 32
typedef struct Node{
 int x;
 int y;
 struct Node *next;
}Node,*LinkList;
typedef struct{
 LinkList front;
 LinkList rear;
 int length;
}Queue;
Queue snake;
void gotoxy(int x,int y)//���궨λ
{
 COORD loc;
 loc.X  =  y;
 loc.Y  =  x;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
}
void help_info()//��ʾ������Ϣ
{
 gotoxy(8,55);
 puts("��ESC���˳�,�ո����ͣ:");
 gotoxy(10,55);
 puts("��,��,��,��:w,s,a,d");
 gotoxy(12,55);
 puts("��Խ��,�ٶ�Ҳ��Խ��:");
 gotoxy(14,55);
 puts("���޷�������,��ر�");
 gotoxy(15,56);
 puts("��д��������״̬:");
}
void game_info()//��ʾ��Ϸ��Ϣ
{
 gotoxy(3,60);
 printf("��ǰ�߳���: %d",snake.length);
 gotoxy(5,60);
 printf("               ");
 gotoxy(5,60);
 printf("��ʤ������: %d",MAX_FOOD-snake.length);
}
void enqueue(int x,int y)//���
{
 LinkList p;
 p = (LinkList)malloc(sizeof(Node));
 p->x = x;
 p->y = y;
 snake.rear->next = p;
 snake.rear = p;
 p->next = NULL;
 snake.length++;
}
void dequeue()//����
{
 LinkList p = snake.front;
 //����ʳ��λ��
 p->next->x = p->x;
 p->next->y = p->y;
 snake.front = snake.front->next;
 snake.length--;
 free(p);
}
void destroy_queue()//���ٶ���
{
 LinkList p;
 while(p = snake.front){
  snake.front = snake.front->next;
  free(p);
 }
}
void snake_init()//��ʼ����,rearָ����ͷ,frontָ��ʳ��,front->nextָ����β
{
 int i;
 snake.rear = snake.front = (LinkList)malloc(sizeof(Node));
 snake.rear->next = NULL;
 snake.length = 0;
 for(i = 0;i < 3;i++){
  enqueue(1,i + 1);
 }
}
void show_food()//�����ʳ��λ��
{
 LinkList p;
 srand(time(NULL));//��ʼ���������
 while(1){
  snake.front->x = rand() % (MAX__X-1) + 1;
  snake.front->y = rand() % (MAX__Y-1) + 1;
  p = snake.front->next;
  //��ֹʳ����������ڲ�
  while(p){
   if(snake.front->x == p->x && snake.front->y == p->y){ break; }
   else{ p = p->next; }
  }
  if( !p){ break; }
 }
 gotoxy(snake.front->x,snake.front->y);
 putchar('@');//ʳ��
}
int judge()//�ж�ʧ�����
{
 LinkList p;
 if(snake.length >= MAX_FOOD){
  system("cls");
  gotoxy(4,20);
  puts("��ϲ��,Ӯ��!!!");
  exit(0);
 }
 //��������
 p = snake.front->next;
 while(snake.rear !=  p){
  if(snake.rear->x == p->x && snake.rear->y == p->y){ break; }
  else{ p = p->next; }
 }
 if(snake.rear == p){
  //�����߽�
  if(snake.rear->x >= 1 && snake.rear->y >= 1 && snake.rear->x < MAX__X && snake.rear->y < MAX__Y){
   return 1;
  }
 }
 system("cls");
 gotoxy(4,20);
 puts("GAME OVER!!!");
 destroy_queue();
 getch();
 exit(0);
}
void drow_wall()//��ǽ
{
 int i;
 for(i = 0; i <= MAX__Y; i++){
  gotoxy(0,i);
  putchar('W');
  gotoxy(MAX__X,i);
  putchar('M');
  if(i <= MAX__X){
   gotoxy(i,0);
   putchar('I');
   gotoxy(i,MAX__Y);
   putchar('I');
  }
 }
}
void drow_snake(int i)//0��ʾ����ͷ,1��ʾ������
{
 LinkList p;
 p = snake.rear;
 gotoxy(p->x,p->y);
 if(i){ putchar('*'); }//����
 else{ putchar('%'); }//��ͷ
}
void clear_snake_tail()
{
 LinkList p = snake.front->next;
 gotoxy(p->x,p->y);
 putchar(' ');//�������β
 p = p->next;
 gotoxy(p->x,p->y);
 putchar('~');//�������β
}
void snake_auto_move(char temp)//ʵ���ߵ��Զ��ƶ�
{
 int x,y,speed;
 do{
  clear_snake_tail();
  drow_snake(1);//������
  x = snake.rear->x;
  y = snake.rear->y;
  switch(temp){
  case 'w': x--;break;
  case 's': x++;break;
  case 'a': y--;break;
  case 'd': y++;
  }
  enqueue(x,y);//����ͷ���
  if(snake.front->x == x && snake.front->y == y){//�߲�׽��ʳ���,ʳ�����������
   game_info();
   show_food();
  }
  else{ dequeue(); }//����β����
  drow_snake(0);//����ͷ
  speed = -2.3 * snake.length + 157;
  Sleep(speed);//������ͣspeed����λ����
 }while(!_kbhit() && judge());//_kbhitΪ����������
}
void snake_move()//ʵ����ҿ����ߵ��ƶ�
{
 char c,pause;
 static char temp = 0;//��̬�ֲ�����
 pause = 0;
 if( !temp){//һ��ʼ��ʱ���������Զ��ƶ�
  temp = 'd';
  snake_auto_move(temp);
 }
 while(1){
  c = getch();
  if(c == ESC){//�˳�
   system("cls");
   puts("��Ϸ�˳��ɹ�!");
   system("pause");
   destroy_queue();
   exit(0);
  }
  if(pause == SPACE){
   if(c == SPACE){//�ٰ��¿ո��������Ϸ
    pause = 0;
    gotoxy(6,20);
    printf("           ");//����~~Pause~~:
    snake_auto_move(temp);
   }
   continue;
  }
  if(c == SPACE){//���ո����ͣ��Ϸ
   pause = SPACE;
   gotoxy(6,20);
   printf("~~Pause~~:");
   continue;
  }
  if(c == 'w' || c == 'a' || c == 's' || c == 'd'){
   if((temp == 'w' && c == 's') || (temp == 's' && c == 'w') || (temp == 'd' && c == 'a') || (temp == 'a' && c == 'd')){//�����������������ڰ��෴�ļ�
    snake_auto_move(temp);
    continue;
   }
   break;
  }
  snake_auto_move(temp);
 }
 temp = c; 
 snake_auto_move(temp);
}
int main()
{
 help_info();
 snake_init();
 show_food();
 drow_wall();
 game_info();
 while(judge()){
  snake_move();
 }
 return 0;
}