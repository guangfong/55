//函数头文件
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>


//全局变量
int GamePhase;	//处于哪一个界面
int mouseX;	//鼠标的横坐标
int mouseY;	//鼠标的纵坐标
int cell[9][10];	//色块
int award=0;	//分数
char score[10];	//分数的输出字符串数组
char judge[10][3];
int count=0;	//统计消除的方块数量
MOUSEMSG m;	// 鼠标消息变量

/****函数声明****/
void StartDraw();		//开始的界面
void GameingDraw();		//玩游戏的界面
void setting();			//设置界面
void help();
void select_color(int cell[9][10]);		//设置随机颜色

void on(int a,int b,int k,int cell[9][10]);
void left(int a,int b,int k,int cell[9][10]);
void right(int a,int b,int k,int cell[9][10]);
void down(int a,int b,int k,int cell[9][10]);

void Playing(int x,int y);	//游戏
void mouse();	//鼠标操作
void over();	//游戏结束
void jifen(int count);	//分数


//主函数
void main()
{
	initgraph(640,480);
	srand((unsigned)time(NULL));
	rectangle(10,10,630,470);

	// 获取窗口句柄
    HWND hwnd = GetHWnd();
	// 设置窗口标题文字
	SetWindowText(hwnd, "Popstar! 消灭星星官方正式版!");

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

//处理鼠标操作
void mouse()
{	
	if(GamePhase==0)    
	{
		if(m.uMsg==WM_MOUSEMOVE)   // 判断鼠标所处的位置
		{
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//进入游戏
			{
				settextstyle(22,12,_T("微软雅黑"));	//选中
				settextcolor(RGB(255,255,255));
				outtextxy(250,225,_T("开始游戏"));
				
				/*****取消选中*****/

				//设置
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("游戏设置"));
				
				//帮助
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("游戏帮助"));   // 将字符串输出到界面的指定位置
				settextcolor(BLACK);
				outtextxy(120,330,_T("你在逗我？"));
				outtextxy(370,330,_T("这么简单还要帮助？"));
				
				//退出
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("退出游戏"));

			}

			else if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//进入设置
			{
				settextstyle(22,12,_T("微软雅黑"));	//选中
				settextcolor(RGB(255,255,255));
				outtextxy(250,275,_T("游戏设置"));
				
				/*****取消选中*****/
				
				//开始游戏
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("开始游戏"));
				
				//帮助
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("游戏帮助"));
				settextcolor(BLACK);
				outtextxy(120,330,_T("你在逗我？"));
				outtextxy(370,330,_T("这么简单还要帮助？"));
				
				//退出
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("退出游戏"));
			}

			else if(m.x>=240 && m.x<=365 && m.y>=320 && m.y<=355)	//帮助界面
			{
				settextstyle(22,12,_T("微软雅黑"));	//选中
				settextcolor(RGB(255,255,255));
				outtextxy(250,325,_T("游戏帮助"));

				outtextxy(120,330,_T("你在逗我？"));
				outtextxy(370,330,_T("这么简单还要帮助？"));
				/*****取消选中*****/
				
				//开始游戏
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("开始游戏"));
				
				//进入设置
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("游戏设置"));
				
				//退出
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("退出游戏"));
			}

			else if(m.x>=240 && m.x<=365 && m.y>=370 && m.y<=405)	//退出
			{
				settextstyle(22,12,_T("微软雅黑"));	//选中
				settextcolor(RGB(255,255,255));
				outtextxy(250,375,_T("退出游戏"));
				/*****取消选中*****/
				
				//开始游戏
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("开始游戏"));
				
				//进入设置
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("游戏设置"));
				
				//进入帮助
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("游戏帮助"));
				settextcolor(BLACK);
				outtextxy(120,330,_T("你在逗我？"));
				outtextxy(370,330,_T("这么简单还要帮助？"));

			}

			else	//都没有选中
			{
				//开始游戏
				rectangle(240,220,365,255);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("开始游戏"));
				
				//设置
				rectangle(240,270,365,305);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("游戏设置"));
				
				//帮助
				rectangle(240,320,365,355);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,325,_T("游戏帮助"));
				settextcolor(BLACK);
				outtextxy(120,330,_T("你在逗我？"));
				outtextxy(370,330,_T("这么简单还要帮助？"));

				//退出
				rectangle(240,370,365,405);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,375,_T("退出游戏"));
			}

		}

		if(m.uMsg == WM_LBUTTONDOWN)
		{
			cleardevice();
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//进入游戏界面
			{
				GamePhase=1;
				GameingDraw();
			}

			if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//进入设置界面
			{
				GamePhase=2;
				setting();
			}

			if(m.x>=240 && m.x<=365 && m.y>=320 && m.y<=355)	//进入帮助界面
			{
				GamePhase=3;
				help();
			}

			if(m.x>=240 && m.x<=365 && m.y>=370 && m.y<=405)	//退出游戏
			{
				closegraph();
			}

		}
	}

	if(GamePhase==1)	//开始游戏
	{
		if(m.uMsg == WM_LBUTTONDBLCLK)
		{
			Playing(m.x,m.y);
		}
	}

	if(GamePhase==2)	//设置
	{
		if(m.uMsg == WM_MOUSEMOVE)
		{
			if(m.x>=250 && m.x<=325 && m.y>=360 && m.y<=395)	//选中
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,255,255));
				outtextxy(260,365,_T("返回"));
			}

			else										//取消选中
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(260,365,_T("返回"));
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

	if(GamePhase==3)	//帮助界面
	{
		if(m.uMsg == WM_MOUSEMOVE)
		{
			if(m.x>=250 && m.x<=325 && m.y>=360 && m.y<=395)	//选中
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,255,255));
				outtextxy(260,365,_T("返回"));
			}

			else										//取消选中
			{
				rectangle(250,360,325,395);
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(260,365,_T("返回"));
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
	
	//结束界面
	if(GamePhase==4)
	{
		if(m.uMsg == WM_MOUSEMOVE)
		{
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//选中重来
			{
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,255,255));
				outtextxy(250,225,_T("重来一局"));

				//取消选择	
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("游戏结束"));
			}

			else if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//选中游戏结束
			{
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,255,255));
				outtextxy(250,275,_T("游戏结束"));

				//取消选择
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("重来一局"));
			}

			else	//都不选
			{	
				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,275,_T("游戏结束"));

				settextstyle(22,12,_T("微软雅黑"));
				settextcolor(RGB(255,51,68));
				outtextxy(250,225,_T("重来一局"));
			}
		}

		if(m.uMsg == WM_LBUTTONDOWN)
		{
			if(m.x>=240 && m.x<=365 && m.y>=220 && m.y<=255)	//重来
			{
				cleardevice();
				GamePhase=1;
				award=0;
				GameingDraw();
			}
			if(m.x>=240 && m.x<=365 && m.y>=270 && m.y<=305)	//结束
			{
				closegraph();
			}
		}
	}




	//清除鼠标消息队列
	FlushMouseMsgBuffer();
}


//开始界面
void StartDraw()
{
	//标题
	settextstyle(52, 30, _T("幼圆"));//字的长度（52） 和 宽度（30）
	settextcolor(RGB(255, 51, 68));
	outtextxy(190, 90, _T("Popstar"));

	//版本
	settextstyle(22, 10, _T("幼圆"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(340, 153, _T("消灭星星官方正式版!"));

	//开始游戏
	rectangle(240,220,365,255);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,225,_T("开始游戏"));

	//进入设置
	rectangle(240,270,365,305);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,275,_T("游戏设置"));

	//进入帮助
	rectangle(240,320,365,355);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,325,_T("游戏帮助"));

	//退出游戏
	rectangle(240,370,365,405);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,375,_T("退出游戏"));
	settextcolor(RGB(255,255,255));
	outtextxy(165, 430, _T("Programing By VC++ & EasyX"));
}

//游戏界面
void GameingDraw()
{
	cleardevice();
	bar(8,8,412,472);
	setfillcolor(RGB(255,255,255));
	int points[]={10,10,410,10,410,470,10,470,10,10};
	int i,j;
	drawpoly(5,points);
	settextcolor(WHITE);
	// 绘制标题
	settextstyle(24, 0, _T("楷体"));
	outtextxy(490, 40, _T("Popstar"));
	settextstyle(20,0,_T("楷体"));
	outtextxy(480,65,_T("官方正式版"));

	// 绘制操作说明
	RECT r = {470, 100, 590, 470};
	settextstyle(14, 0, _T("宋体"));
	drawtext(_T("[游戏说明]\n　 新一轮的消灭星星开始了，铛铛铛\n\n[控制说明]\n仅仅只需要你动一动的的鼠标左键和大脑\n"),&r, DT_WORDBREAK);

	//输出分数
	RECT mark={470,250,590,300};
	settextstyle(30, 0, _T("宋体"));
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

//对每个小的矩形框赋颜色
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
					//大红色
					break;
				case 2:
				case 7:
				case 12:setfillcolor(RGB(128,255,0));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//绿色
					break;
				case 3:
				case 8:
				case 13:setfillcolor(RGB(0,255,255));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//蓝色
					break;
				case 4:
				case 9:
				case 14:setfillcolor(RGB(255,128,128));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//粉色
					break;
				case 5:
				case 10:
				case 15:setfillcolor(RGB(255,255,0));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//黄色
					break;
				case 110:
					setfillcolor(RGB(255,255,255));
					bar(12+j*36+j*4,112+i*36+i*4,12+(j+1)*36+j*4,112+(i+1)*36+i*4);
					//白色
					break;
				}
			}
		}
}

//设置界面
void setting()
{
	//标题
	settextstyle(52, 30, _T("幼圆"));//字的长度（52） 和 宽度（30）
	settextcolor(RGB(255, 51, 68));
	outtextxy(190, 90, _T("Popstar"));

	//版本
	settextstyle(22, 10, _T("幼圆"));
	settextcolor(RGB(255, 51, 68));
	outtextxy(340, 153, _T("消灭星星官方正式版!"));

	//音乐
	rectangle(250,220,325,255);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,225,_T("音乐"));

	//音效
	rectangle(250,290,325,325);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,295,_T("音效"));

	//返回
	rectangle(250,360,325,395);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,365,_T("返回"));
}

void help()		//帮助界面
{
	settextstyle(30,0,_T("微软雅黑"));
	outtextxy(210,150,_T("没有帮助，自己摸索去吧！"));

	//返回
	rectangle(250,360,325,395);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(260,365,_T("返回"));
}

//玩游戏
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
		//当碰上第一个白块开始往数 白块的个数 决定循环的次数
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
			}//从顶部开始连续的白块的个数
			for(i=0;i<9;i++)
			{
				if(cell[i][j]==110)
				{
					c++;
					e=i;//最后一个白块数的i值
				}
			}//总的白块的个数
			for(d=0;d<(c-g);d++)//开始进行循环 控制的循环的次数
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
		//向下移动所有的完成后 完成向左移动
		//只需检查最下面的一排
		for(j=0;j<10;j++)
		{
			while(cell[8][j]==110)
			{
				h++;	//h表示连续的白块的个数
				n=j;
				j++;
			}
			if(n==9)
			{
				h=0;
			}
			for(d=0;d<h;d++)//开始进行循环 控制的循环的次数
			{
				for(i=0;i<9;i++)
				{
					for(j=n-h+1;j<10;j++)//从第一个白块开始 到最后一个
					{
						cell[i][j]=cell[i][j+1];
					}
					cell[i][9-d]=110;
				}
			}
			h=0;
			select_color(cell);
		}

		//整个再次遍历 保证相邻的色块都不相同时结束游戏
		
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
void over()	//结束界面
{
	cleardevice();

	// 绘制标题
	settextstyle(52, 30, _T("幼圆"));//字的长度（52） 和 宽度（30）
	settextcolor(RGB(255, 51, 68));
	outtextxy(190, 90, _T("Popstar"));

	settextcolor(WHITE);
	outtextxy(240,150,score);
	//重来一局
	rectangle(240,220,365,255);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,225,_T("重来一局"));

	//退出游戏
	rectangle(240,270,365,305);
	settextstyle(22,12,_T("微软雅黑"));
	settextcolor(RGB(255,51,68));
	outtextxy(250,275,_T("游戏结束"));

		
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