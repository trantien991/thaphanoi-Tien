#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <malloc.h>
using namespace std;

//cot b la cot trung gian
void diChuyen(int n, char a, char b, char c) {
	if (n != 1) {
		diChuyen(n-1, a, c, b);
		diChuyen(1, a, b, c);
		diChuyen(n-1, b, a, c);
	} else {
		cout <<"\t"<<a<<"=========="<<"\t"<<c<<endl;
	}
}

//Ve Cot
void veCot() {
	//Ve cot ngang
	bar(50, 575, 950, 600);
	//ve cot A
	bar(160, 300, 170, 575);
	//ve cot B
	bar(460, 300, 470, 575);
	//ve cot C
	bar(760 , 300, 770, 575);
	//In ra chu A
	settextstyle(1, 0, 1);
	setcolor(5);
	outtextxy(100, 650, "Cot A");
	//In ra chu B
	outtextxy(400, 650, "Cot B");
	//In ra chu C
	outtextxy(700, 650, "Cot C");
}

//VeDia
void veDia(int n, int x1, int y1, int x2, int y2) {
	for (int i = 1; i<= n; i++) {
		setfillstyle(1, i);
		bar(x1+=10, y1-=25, x2-=10, y2-=25);
	}
}


int main () {
	initwindow(1000, 700);
	int n;
	char a = 'A', b = 'B', c = 'C';
	int x1 = 40, y1 = 575, x2 = 300, y2 = 600;
	void *p;
	void *p1;
	unsigned save, save1;
	int t1, t2;

	//Nhap
	do {
		cout <<"\n Nhap so luong dia n la: ";
		cin >> n;
		if (n <= 0 || n >= 5)
			cout <<"\n So luong dia tu 1-->4";
	} while(n <= 0 || n >= 5);

	//di chuyen cua dia
	diChuyen(n, a, b, c);

	//Ve cot va dia
	veCot();
	veDia(n, x1, y1, x2, y2);

	while(1) {

		//Di len
		fflush(stdin);
		if (GetAsyncKeyState(VK_LBUTTON) ) {
			save = imagesize(50, 550, 290, 575);
			p = malloc (save);
			for (int i = 0; i < 240; i++) {
				//Sao chep anh vao vung nho bitmap
				getimage(50, 550-i, 290, 575-i, p);
				//Do tre
				delay (1);
				//Xoa vi tri truoc
				putimage(50, 550-i, p, XOR_PUT);
				//Ve lai vi tri moi
				putimage(50, 550-1-i, p, XOR_PUT);
				//Ve lai cot da xoa
				bar(160, 300, 170, 575);

				t1 = 550-1-i;
				cout <<"\n vi tri cuoi cung ben tren: "<<t1;
			}
		}

		if (GetAsyncKeyState(VK_LBUTTON)) {
			//Di qua
			save = imagesize(50, 310, 290, 335);
			p = malloc (save);
			for (int i = 0; i < 600; i++) {
				//Sao chep anh vao vung nho bitmap
				getimage(50+i, 310, 290+i, 335, p);
				//Do tre
				delay (1);
				//Xoa vi tri truoc
				putimage(50+i, 310, p, XOR_PUT);
				//Ve lai vi tri moi
				putimage(50+1+i, 310, p, XOR_PUT);

			}

			// Di xuong
			save1 = imagesize(650, 310, 890, 335);
			p1 = malloc (save1);
			for (int r = 0; r < 240; r++) {
				//Sao chep anh vao vung nho bitmap
				getimage(650, 310+r, 890, 335-r, p1);
				//Do tre
				delay (1);
				//Xoa vi tri truoc
				putimage(650, 310+r, p1, XOR_PUT);
				//Ve lai vi tri moi
				putimage(650, 310+1+r, p1, XOR_PUT);
				//ve lai cot C
				bar(760 , 300, 770, 575);

			}
		}
	}

	system("pause");

	getch ();
}
