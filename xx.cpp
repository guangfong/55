//����ͷ�ļ�
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>


//ȫ�ֱ���
int GamePhase;	//������һ������
int mouseX;	//���ĺ�����
int mouseY;	//����������
int cell[9][10];	//ɫ��
int award=0;	//����
char score[10];	//����������ַ�������
char judge[10][3];
int count=0;	//ͳ�������ķ�������
MOUSEMSG m;	// �����Ϣ����

/****��������****/
void StartDraw();		//��ʼ�Ľ���
void GameingDraw();		//����Ϸ�Ľ���
void setting();			//���ý���
void help();
void select_color(int cell[9][10]);		//���������ɫ

void on(int a,int b,int k,int cell[9][10]);
void left(int a,int b,int k,int cell[9][10]);
void right(int a,int b,int k,int cell[9][10]);
void down(int a,int b,int k,int cell[9][10]);

void Playing(int x,int y);	//��Ϸ
void mouse();	//������
void over();	//��Ϸ����
void jifen(int count);	//����


//������
void main()
{
	initgraph(640,480);
	srand((unsigned)time(NULL));
	rectangle(10,10,630,470);

	// ��ȡ���ھ��
    HWND hwnd = GetHWnd();
	// ���ô��ڱ�������
	SetWindowText(hwnd, "Popstar! �������ǹٷ���ʽ��!");

	StartDraw();
	GamePhase=0;

	while(!kbhit())
	{
			m=GetMouseMsg();
			mouse();
	}
	getch();
	closegraph();
}

//����������
void mouse()
{	
	if(GamePhase==0)    
	{
		if(m.uMsg==WM_MOUSEMOVE)   // �ж����������λ��
		{
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//������Ϸ
			{
				settextstyle(22,12,_T("΢���ź�"));	//ѡ��
				settextcolor(RGB(255,255,255));
				outtextxy(250,225,_T("��ʼ��Ϸ"));
				
				/*****ȡ��ѡ��*****/

				//����
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("��Ϸ����"));
				
				//����
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("��Ϸ����"));   // ���ַ�������������ָ��λ��
				settextcolor(BLACK);
				outtextxy(120,330,_T("���ڶ��ң�"));
				outtextxy(370,330,_T("��ô�򵥻�Ҫ������"));
				
				//�˳�
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("�˳���Ϸ"));

			}

			else if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//��������
			{
				settextstyle(22,12,_T("΢���ź�"));	//ѡ��
				settextcolor(RGB(255,255,255));
				outtextxy(250,275,_T("��Ϸ����"));
				
				/*****ȡ��ѡ��*****/
				
				//��ʼ��Ϸ
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("��ʼ��Ϸ"));
				
				//����
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("��Ϸ����"));
				settextcolor(BLACK);
				outtextxy(120,330,_T("���ڶ��ң�"));
				outtextxy(370,330,_T("��ô�򵥻�Ҫ������"));
				
				//�˳�
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("�˳���Ϸ"));
			}

			else if(m.x>=240 && m.x<=365 && m.y>=320 && m.y<=355)	//��������
			{
				settextstyle(22,12,_T("΢���ź�"));	//ѡ��
				settextcolor(RGB(255,255,255));
				outtextxy(250,325,_T("��Ϸ����"));

				outtextxy(120,330,_T("���ڶ��ң�"));
				outtextxy(370,330,_T("��ô�򵥻�Ҫ������"));
				/*****ȡ��ѡ��*****/
				
				//��ʼ��Ϸ
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("��ʼ��Ϸ"));
				
				//��������
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("��Ϸ����"));
				
				//�˳�
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("�˳���Ϸ"));
			}

			else if(m.x>=240 && m.x<=365 && m.y>=370 && m.y<=405)	//�˳�
			{
				settextstyle(22,12,_T("΢���ź�"));	//ѡ��
				settextcolor(RGB(255,255,255));
				outtextxy(250,375,_T("�˳���Ϸ"));
				/*****ȡ��ѡ��*****/
				
				//��ʼ��Ϸ
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("��ʼ��Ϸ"));
				
				//��������
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("��Ϸ����"));
				
				//�������
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("��Ϸ����"));
				settextcolor(BLACK);
				outtextxy(120,330,_T("���ڶ��ң�"));
				outtextxy(370,330,_T("��ô�򵥻�Ҫ������"));

			}

			else	//��û��ѡ��
			{
				//��ʼ��Ϸ
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("��ʼ��Ϸ"));
				
				//����
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("��Ϸ����"));
				
				//����
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("��Ϸ����"));
				settextcolor(BLACK);
				outtextxy(120,330,_T("���ڶ��ң�"));
				outtextxy(370,330,_T("��ô�򵥻�Ҫ������"));

				//�˳�
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("�˳���Ϸ"));
			}

		}

		if(m.uMsg == WM_LBUTTONDOWN)
		{
			cleardevice();
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//������Ϸ����
			{
				GamePhase=1;
				GameingDraw();
			}

			if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//�������ý���
			{
				GamePhase=2;
				setting();
			}

			if(m.x>=240 && m.x<=365 && m.y>=320 && m.y<=355)	//�����������
			{
				GamePhase=3;
				help();
			}

			if(m.x>=240 && m.x<=365 && m.y>=370 && m.y<=405)	//�˳���Ϸ
			{
				closegraph();
			}

		}
	}

	if(GamePhase==1)	//��ʼ��Ϸ
	{
		if(m.uMsg == WM_LBUTTONDBLCLK)
		{
			Playing(m.x,m.y);
		}
	}

	if(GamePhase==2)	//����
	{
		if(m.uMsg == WM_MOUSEMOVE)
		{
			if(m.x>=250 && m.x<=325 && m.y>=360 && m.y<=395)	//ѡ��
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,255,255));
				outtextxy(260,365,_T("����"));
			}

			else										//ȡ��ѡ��
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(260,365,_T("����"));
			}

		}

		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=250 && m.x<=325 && m.y>=360 && m.y<=395)
			{
				cleardevice();
				StartDraw();
				GamePhase=0;
			}
		}

	}

	if(GamePhase==3)	//��������
	{
		if(m.uMsg == WM_MOUSEMOVE)
		{
			if(m.x>=250 && m.x<=325 && m.y>=360 && m.y<=395)	//ѡ��
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,255,255));
				outtextxy(260,365,_T("����"));
			}

			else										//ȡ��ѡ��
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(260,365,_T("����"));
			}
		}

		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=250 && m.x<=325 && m.y>=360 && m.y<=395)
			{
				cleardevice();
				StartDraw();
				GamePhase=0;
			}
		}
	}
	
	//��������
	if(GamePhase==4)
	{
		if(m.uMsg == WM_MOUSEMOVE)
		{
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//ѡ������
			{
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,255,255));
				outtextxy(250,225,_T("����һ��"));

				//ȡ��ѡ��	
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("��Ϸ����"));
			}

			else if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//ѡ����Ϸ����
			{
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,255,255));
				outtextxy(250,275,_T("��Ϸ����"));

				//ȡ��ѡ��
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("����һ��"));
			}

			else	//����ѡ
			{	
				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("��Ϸ����"));

				settextstyle(22,12,_T("΢���ź�"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("����һ��"));
			}
		}

		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//����
			{
				cleardevice();
				GamePhase=1;
				award=0;
				GameingDraw();
			}
			if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//����
			{
				closegraph();
			}
		}
	}




	//��������Ϣ����
	FlushMouseMsgBuffer();
}


//��ʼ����
void StartDraw()
{
	//����
	settextstyle(52, 30, _T("��Բ"));//�ֵĳ��ȣ�52�� �� ��ȣ�30��
	settextcolor(RGB(255, 51, 68));
	outtextxy(190, 90, _T("Popstar"));

	//�汾
	settextstyle(22, 10, _T("��Բ"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(340, 153, _T("�������ǹٷ���ʽ��!"));

	//��ʼ��Ϸ
	rectangle(240,220,365,255);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,225,_T("��ʼ��Ϸ"));

	//��������
	rectangle(240,270,365,305);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,275,_T("��Ϸ����"));

	//�������
	rectangle(240,320,365,355);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,325,_T("��Ϸ����"));

	//�˳���Ϸ
	rectangle(240,370,365,405);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,375,_T("�˳���Ϸ"));
	settextcolor(RGB(255,255,255));
	outtextxy(165, 430, _T("Programing By VC++ & EasyX"));
}

//��Ϸ����
void GameingDraw()
{
	cleardevice();
	bar(8,8,412,472);
	setfillcolor(RGB(255,255,255));
	int points[]={10,10,410,10,410,470,10,470,10,10};
	int i,j;
	drawpoly(5,points);
	settextcolor(WHITE);
	// ���Ʊ���
	settextstyle(24, 0, _T("����"));
	outtextxy(490, 40, _T("Popstar"));
	settextstyle(20,0,_T("����"));
	outtextxy(480,65,_T("�ٷ���ʽ��"));

	// ���Ʋ���˵��
	RECT r = {470, 100, 590, 470};
	settextstyle(14, 0, _T("����"));
	drawtext(_T("[��Ϸ˵��]\n�� ��һ�ֵ��������ǿ�ʼ�ˣ�������\n\n[����˵��]\n����ֻ��Ҫ�㶯һ���ĵ��������ʹ���\n"),&r, DT_WORDBREAK);

	//�������
	RECT mark={470,250,590,300};
	settextstyle(30, 0, _T("����"));
	drawtext("score",&mark,DT_WORDBREAK);
	
	sprintf(score,"%d",award);
	outtextxy(470,310,score);

	for(i=0;i<9;i++)
	{
		for(j=0;j<10;j++)
		{
			cell[i][j]=rand()%15+1;
		}
	}
		select_color(cell);	
}

//��ÿ��С�ľ��ο���ɫ
void select_color(int cell[9][10])
{
	int i,j;
	for(i=0;i<9;i++)
		{
			for(j=0;j<10;j++)
			{
				switch(cell[i][j])
				{
				case 11:
				case 6:
				case 1:	setfillcolor(RGB(255,0,0));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//���ɫ
					break;
				case 2:
				case 7:
				case 12:setfillcolor(RGB(128,255,0));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//��ɫ
					break;
				case 3:
				case 8:
				case 13:setfillcolor(RGB(0,255,255));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//��ɫ
					break;
				case 4:
				case 9:
				case 14:setfillcolor(RGB(255,128,128));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//��ɫ
					break;
				case 5:
				case 10:
				case 15:setfillcolor(RGB(255,255,0));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//��ɫ
					break;
				case 110:
					setfillcolor(RGB(255,255,255));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//��ɫ
					break;
				}
			}
		}
}

//���ý���
void setting()
{
	//����
	settextstyle(52, 30, _T("��Բ"));//�ֵĳ��ȣ�52�� �� ��ȣ�30��
	settextcolor(RGB(255, 51, 68));
	outtextxy(190, 90, _T("Popstar"));

	//�汾
	settextstyle(22, 10, _T("��Բ"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(340, 153, _T("�������ǹٷ���ʽ��!"));

	//����
	rectangle(250,220,325,255);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,225,_T("����"));

	//��Ч
	rectangle(250,290,325,325);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,295,_T("��Ч"));

	//����
	rectangle(250,360,325,395);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,365,_T("����"));
}

void help()		//��������
{
	settextstyle(30,0,_T("΢���ź�"));
	outtextxy(210,150,_T("û�а������Լ�����ȥ�ɣ�"));

	//����
	rectangle(250,360,325,395);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,365,_T("����"));
}

//����Ϸ
void Playing(int x,int y)
{
	int i,j;
	int k,p,q,c=0,d,e,g=0,n,h=0,o=0,t,w;
			
		for(i=0;i<9;i++)
		{
			for(j=0;j<10;j++)
			{
				if(x>=(10+j*40)&&y>=(110+i*40)&&x<=(10+(j+1)*40)&&y<=(110+(i+1)*40))
				{
					p=i;
					q=j;
					setlinestyle(PS_SOLID,5);
					rectangle(10+j*40,110+i*40,10+(j+1)*40,110+(i+1)*40);
					k=cell[i][j];
					cell[i][j]=110;
					count++;
					if(i-1>=0)
					{
						if(cell[i-1][j]==k||cell[i-1][j]==k+5||cell[i-1][j]==k+10||cell[i-1][j]==k-10||cell[i-1][j]==k-5)
						{
							setlinestyle(PS_SOLID,5);
							rectangle(10+j*40,110+(i-1)*40,10+(j+1)*40,110+i*40);
							cell[i-1][j]=110;
							count++;
							on(i-1,j,k,cell);
						}
					}
					if(j-1>=0)
					{
						if(cell[i][j-1]==k||cell[i][j-1]==k+5||cell[i][j-1]==k+10||cell[i][j-1]==k-10||cell[i][j-1]==k-5)
						{
							setlinestyle(PS_SOLID,5);
							rectangle(10+(j-1)*40,110+i*40,10+j*40,110+(i+1)*40);
							cell[i][j-1]=110;
							count++;
							left(i,j-1,k,cell);
						}
					}
					if(j+1<10)
					{
						if(cell[i][j+1]==k||cell[i][j+1]==k+5||cell[i][j+1]==k+10||cell[i][j+1]==k-10||cell[i][j+1]==k-5)
						{
							setlinestyle(PS_SOLID,5);
							rectangle(10+(j+1)*40,110+i*40,10+(j+2)*40,110+(i+1)*40);
							cell[i][j+1]=110;
							count++;
							right(i,j+1,k,cell);
						}
					}
					if(i+1<9)
					{
						if(cell[i+1][j]==k||cell[i+1][j]==k+5||cell[i+1][j]==k+10||cell[i+1][j]==k-10||cell[i+1][j]==k-5)
						{
							setlinestyle(PS_SOLID,5);
							rectangle(10+j*40,110+(i+1)*40,10+(j+1)*40,110+(i+2)*40);
							cell[i+1][j]=110;
							count++;
							down(i+1,j,k,cell);
						}
					}
					if(count==1)
								cell[i][j]=k;
							if(count!=1)
							{
								jifen(count);
							}
							count=0;
				}
			}
		}
		select_color(cell);
		//�����ϵ�һ���׿鿪ʼ���� �׿�ĸ��� ����ѭ���Ĵ���
		for(j=0;j<10;j++)
		{
			i=0;
			if(cell[i][j]==110)
			{
				g++;
				while(cell[i+1][j]==110)
				{
					g++;
					i++;
				}
			}//�Ӷ�����ʼ�����İ׿�ĸ���
			for(i=0;i<9;i++)
			{
				if(cell[i][j]==110)
				{
					c++;
					e=i;//���һ���׿�����iֵ
				}
			}//�ܵİ׿�ĸ���
			for(d=0;d<(c-g);d++)//��ʼ����ѭ�� ���Ƶ�ѭ���Ĵ���
			{
				for(i=e;i>=d;i--)
				{
					cell[i][j]=cell[i-1][j];
				}
				cell[d][j]=110;
			}
			c=0;
			g=0;
			select_color(cell);
		}
		//�����ƶ����е���ɺ� ��������ƶ�
		//ֻ�����������һ��
		for(j=0;j<10;j++)
		{
			while(cell[8][j]==110)
			{
				h++;	//h��ʾ�����İ׿�ĸ���
				n=j;
				j++;
			}
			if(n==9)
			{
				h=0;
			}
			for(d=0;d<h;d++)//��ʼ����ѭ�� ���Ƶ�ѭ���Ĵ���
			{
				for(i=0;i<9;i++)
				{
					for(j=n-h+1;j<10;j++)//�ӵ�һ���׿鿪ʼ �����һ��
					{
						cell[i][j]=cell[i][j+1];
					}
					cell[i][9-d]=110;
				}
			}
			h=0;
			select_color(cell);
		}

		//�����ٴα��� ��֤���ڵ�ɫ�鶼����ͬʱ������Ϸ
		
		for(i=0;i<8;i++)
		{
			j=0;
			if(i==0||i==9)
			{
				for(j=0;j<8;j++)
				{
					if(cell[1][j+1]==cell[i][j]&&cell[i][j]!=110)
						o=1;
				}
			}
			if(i>0&&i<9)
			{
				if(j=0)
				{
					for(w=0;w<9;w++)
					{
						if(cell[w+1][j]==cell[w][j]&&cell[w][j]!=110)
							o=1;
					}
				}
				j++;
				while(j>0&&j<9)
				{
					t=cell[i][j];
					if(t!=110)
					{
						if(cell[i-1][j]==t||cell[i+1][j]==t||cell[i][j+1]==t||cell[i][j-1]==t
							||cell[i-1][j]==t+5||cell[i+1][j]==t+5||cell[i][j+1]==t+5||cell[i][j-1]==t+5
							||cell[i-1][j]==t+10||cell[i+1][j]==t+10||cell[i][j+1]==t+10||cell[i][j-1]==t+10
							||cell[i-1][j]==t-5||cell[i+1][j]==t-5||cell[i][j+1]==t-5||cell[i][j-1]==t-5
							||cell[i-1][j]==t-10||cell[i+1][j]==t-10||cell[i][j+1]==t-10||cell[i][j-1]==t-10)
							o=1;
					}
					j++;
				}
				if(j=9)
				{
					for(w=0;w<9;w++)
					{
						if(cell[w+1][j]==cell[w][j]&&cell[w][j]!=110)
							o=1;
					}
				}
			}
			
		}
		if(o==0)
		{
			Sleep(300);
			over();
			GamePhase=4;
		}
}
void over()	//��������
{
	cleardevice();

	// ���Ʊ���
	settextstyle(52, 30, _T("��Բ"));//�ֵĳ��ȣ�52�� �� ��ȣ�30��
	settextcolor(RGB(255, 51, 68));
	outtextxy(190, 90, _T("Popstar"));

	settextcolor(WHITE);
	outtextxy(240,150,score);
	//����һ��
	rectangle(240,220,365,255);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,225,_T("����һ��"));

	//�˳���Ϸ
	rectangle(240,270,365,305);
	settextstyle(22,12,_T("΢���ź�"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,275,_T("��Ϸ����"));

		
}


void on(int a,int b,int k,int cell[9][10])
{
	if(a-1>=0)
	{
		if(cell[a-1][b]==k||cell[a-1][b]==k+5||cell[a-1][b]==k+10||cell[a-1][b]==k-10||cell[a-1][b]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+b*40,110+(a-1)*40,10+(b+1)*40,110+a*40);
			cell[a-1][b]=110;
			on(a-1,b,k,cell);
		}
	}
	if(b-1>=0)
	{
		if(cell[a][b-1]==k||cell[a][b-1]==k+5||cell[a][b-1]==k+10||cell[a][b-1]==k-10||cell[a][b-1]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+(b-1)*40,110+a*40,10+b*40,110+(a+1)*40);
			cell[a][b-1]=110;
			left(a,b-1,k,cell);
		}
	}
	if(b+1<10)
	{
		if(cell[a][b+1]==k||cell[a][b+1]==k+5||cell[a][b+1]==k+10||cell[a][b+1]==k-10||cell[a][b+1]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+(b+1)*40,110+a*40,10+(b+2)*40,110+(a+1)*40);
			cell[a][b+1]=110;
			right(a,b+1,k,cell);
		}
	}
}



void left(int a,int b,int k,int cell[9][10])
{
	if(a-1>=0)
	{
		if(cell[a-1][b]==k||cell[a-1][b]==k+5||cell[a-1][b]==k+10||cell[a-1][b]==k-10||cell[a-1][b]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+b*40,110+(a-1)*40,10+(b+1)*40,110+a*40);
			cell[a-1][b]=110;
			on(a-1,b,k,cell);
		}
	}
	if(b-1>=0)
	{
		if(cell[a][b-1]==k||cell[a][b-1]==k+5||cell[a][b-1]==k+10||cell[a][b-1]==k-10||cell[a][b-1]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+(b-1)*40,110+a*40,10+b*40,110+(a+1)*40);
			cell[a][b-1]=110;
			left(a,b-1,k,cell);
		}
	}
	if(a+1<9)
	{
		if(cell[a+1][b]==k||cell[a+1][b]==k+5||cell[a+1][b]==k+10||cell[a+1][b]==k-10||cell[a+1][b]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+b*40,110+(a+1)*40,10+(b+1)*40,110+(a+2)*40);
			cell[a+1][b]=110;
			down(a+1,b,k,cell);
		}
	}
}


void right(int a,int b,int k,int cell[9][10])
{
	if(a-1>=0)
	{
		if(cell[a-1][b]==k||cell[a-1][b]==k+5||cell[a-1][b]==k+10||cell[a-1][b]==k-10||cell[a-1][b]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+b*40,110+(a-1)*40,10+(b+1)*40,110+a*40);
			cell[a-1][b]=110;
			on(a-1,b,k,cell);
		}
	}
	if(b+1<10)
	{
		if(cell[a][b+1]==k||cell[a][b+1]==k+5||cell[a][b+1]==k+10||cell[a][b+1]==k-10||cell[a][b+1]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+(b+1)*40,110+a*40,10+(b+2)*40,110+(a+1)*40);
			cell[a][b+1]=110;
			right(a,b+1,k,cell);
		}
	}
	if(a+1<9)
	{
		if(cell[a+1][b]==k||cell[a+1][b]==k+5||cell[a+1][b]==k+10||cell[a+1][b]==k-10||cell[a+1][b]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+b*40,110+(a+1)*40,10+(b+1)*40,110+(a+2)*40);
			cell[a+1][b]=110;
			down(a+1,b,k,cell);
		}
	}
}


void down(int a,int b,int k,int cell[9][10])
{
	
	if(b-1>=0)
	{
		if(cell[a][b-1]==k||cell[a][b-1]==k+5||cell[a][b-1]==k+10||cell[a][b-1]==k-10||cell[a][b-1]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+(b-1)*40,110+a*40,10+b*40,110+(a+1)*40);
			cell[a][b-1]=110;
			left(a,b-1,k,cell);
		}
	}
	if(b+1<10)
	{
		if(cell[a][b+1]==k||cell[a][b+1]==k+5||cell[a][b+1]==k+10||cell[a][b+1]==k-10||cell[a][b+1]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+(b+1)*40,110+a*40,10+(b+2)*40,110+(a+1)*40);
			cell[a][b+1]=110;
			right(a,b+1,k,cell);
		}
	}
	if(a+1<9)
	{
		if(cell[a+1][b]==k||cell[a+1][b]==k+5||cell[a+1][b]==k+10||cell[a+1][b]==k-10||cell[a+1][b]==k-5)
		{
			setlinestyle(PS_SOLID,5);
			rectangle(10+b*40,110+(a+1)*40,10+(b+1)*40,110+(a+2)*40);
			cell[a+1][b]=110;
			down(a+1,b,k,cell);
		}
	}
}

void jifen(int count)
{
	switch(count)
	{
	case 2:award=award+20;
		break;
	case 3:award=award+45;
		break;
	case 4:award=award+80;
		break;
	case 5:award=award+125;
		break;
	case 6:award=award+180;
		break;
	case 7:award=award+245;
		break;
	case 8:award=award+320;	
		break;
	case 9:award+=405;
		break;
	case 10:award+=500;
		break;
	case 11:award+=605;
		break;
	case 12:award+=720;
		break;
	case 13:award+=845;
		break;
	case 14:award+=980;
		break;
	case 15:award+=1125;
		break;
	case 16:award+=1280;
		break;
	case 17:award+=1445;
		break;
	case 18:award+=1620;
		break;
	case 19:award+=1805;
		break;
	case 20:award+=2000;
	}
	sprintf(score,"%d",award);
	outtextxy(470,310,score);
}