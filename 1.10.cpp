
#include<stdio.h>
#include<conio.h>
#include<math.h>
struct Diem
{
    float x;
    float y;
};
typedef struct Diem DIEM;

void NhapDiem(DIEM &);
void XuatDiem(DIEM);

struct DuongTron
{
    DIEM I;
    float R;
};
typedef struct DuongTron DUONGTRON;

void NhapDuongTron(DUONGTRON &);
void XuatDuongTron(DUONGTRON);

oid NhapDiem(DIEM &d)
{
    float temp;
    printf("\nNhap x: ");
    scanf("%f", &temp);
    d.x = temp;

    printf("\nNhap y: ");
    scanf("%f", &temp);
    d.y = temp;
}

void XuatDiem(DIEM d)
{
    printf("(%8.3f, %8.3f)" , d.x, d.y);
}

void NhapDuongTron(DUONGTRON &dt)
{
    float temp;
    NhapDiem(dt.I);
    printf("\nNhap ban kinh: ");
    scanf("%f", &temp);
    dt.R = temp;
}

void XuatDuongTron(DUONGTRON dt)
{
    printf("((%8.3f, %8.3f), %8.3f)", dt.I.x, dt.I.y, dt.R);
}
float TinhChuViDuongTron(DUONGTRON a)
{
    return 2 * PI * a.R;
}

int main()
{
    DIEM d;
    DUONGTRON a;
    NhapDuongTron(a);
    XuatDuongTron(a);
    float ChuVi = TinhChuViDuongTron(a);
    printf("\nChu vi duong tron = %.2f", ChuVi);
    NhapDiem(d);
    XuatDiem(d);
    getch();
    return 0;
}
