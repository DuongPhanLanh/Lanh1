
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

void NhapDiem(DIEM &a)
{
    printf("\nNhap x: ");
    scanf("%f", &a.x);

    printf("\nNhap y: ");
    scanf("%f", &a.y);
}

void XuatDiem(DIEM a)
{
    printf("<%.2f, %.2f>", a.x, a.y);
}

struct TamGiac 
{
    DIEM A;
    DIEM B;
    DIEM C;
};
typedef struct TamGiac TAMGIAC;
void NhapTamGiac(TAMGIAC &);
void XuatTamGiac(TAMGIAC);

void NhapTamGiac(TAMGIAC &a)
{
    int Check;
    do{
        printf("\nNhap dinh A: ");
        NhapDiem(a.A);

        printf("\nNhap dinh B: ");
        NhapDiem(a.B);

        printf("\nNhap dinh C: ");
        NhapDiem(a.C);
        Check = KiemTraCoPhaiTamGiac(a);

        if(Check == false)
        {
            printf("\n3 diem khong tao thanh tam giac. Xin kiem tra lai !");
        }

    }while(Check == false);

}

void XuatTamGiac(TAMGIAC a)
{
    printf("(<%.2f, %.2f>, <%.2f, %.2f>, <%.2f, %.2f>)", a.A.x, a.A.y, a.B.x, a.B.y, a.C.x, a.C.y);
}

int main()
{
    TAMGIAC a;

    NhapTamGiac(a);
    XuatTamGiac(a);
  
  getch();
    return 0;
}
