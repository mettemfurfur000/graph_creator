#include <cstdlib>
#include <cstdio>
#include <graphics.h>

int windX = 1024;
int windY = 768;

int linus(FILE *f)
{
	int px,py;
	int lpx=0,lpy=0;
	
	char str[32] = {0};
	int value;
	int value_num = 0;
	
	int color = COLOR(rand()%256,rand()%256,rand()%256);
	
	int i = 0;
	char c = 0;
	do{
		c = getc(f);
		if(isdigit(c))
		{
			str[i] = c;
			i++;
		}
		if(isspace(c)&&str[0]!=0)
		{
			value = atoi(str);
			px = (1024.0/2000.0) * value_num;
			py = (768.0/16384.0) * value;
			setcolor(color);
			line(lpx,768-lpy,px,768-py);
			putpixel(px,768-py,color);
			lpx = px;
			lpy = py;
			value_num++;
			memset(str,0,32);
			i=0;
		}
		if(c==13&&str[0]==0)
		{
			break;
		}
	}while(c!=EOF);
	if(c==EOF)
	{
		return 5;
	}
	return 0;
}

void Graph(char *path)
{
	FILE * f = fopen(path,"rb");
	int i;
	while(linus(f)!=5)
	{
		i = 0;
	}
	fclose(f);
}

int main()
{
	initwindow(windX,windY);
	Graph("stats.bin");
	getch();
}