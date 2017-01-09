#include <graphics.h>

int main()
{
	initgraph(640,640);
	setrendermode(RENDER_MANUAL);
	setcaption("ºÚ°×Æå");
	PIMAGE canvas = newimage(640, 640);
	settarget(canvas);
	setfillcolor(EGERGB(0, 101, 0));
	bar(0, 0, 640, 640);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i+j)%2)
			{
				setfillcolor(EGERGB(0,152,0));
			}
			else
			{
				setfillcolor(EGERGB(101, 204, 0));
			}
			bar(j * 80 + 2, i * 80 + 2, j*80+78,i*80+78);
		}
	}

	setcolor(BLACK);
	setfillcolor(BLACK);
	fillellipse(280, 360, 36, 36);
	fillellipse(360, 280, 36, 36);

	setcolor(WHITE);
	setfillcolor(WHITE);
	fillellipse(280,280,36,36);
	fillellipse(360, 360, 36, 36);

	settarget(nullptr);
	putimage(0, 0, canvas);
	getch();
	return 0;
}