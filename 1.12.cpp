
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

bool KiemTraCoPhaiTamGiac(TAMGIAC);
float TinhChuViTamGiac(TAMGIAC);
float TinhDienTichTamGiac(TAMGIAC);

DIEM TimToaDoTrongTamTamGiac(TAMGIAC);


bool KiemTraCoPhaiTamGiac(TAMGIAC a)
{
    float AB = TinhKhoangCachGiua2Diem(a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem(a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem(a.A, a.C);

    if(AB + BC <= AC || AB + AC <= BC || AC + BC <= AB)
        return false;
    return true;
}
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

float TinhChuViTamGiac(TAMGIAC a)
{
    float AB = TinhKhoangCachGiua2Diem(a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem(a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem(a.A, a.C);

    return AB + BC + AC;
}

float TinhDienTichTamGiac(TAMGIAC a)
{
    float AB = TinhKhoangCachGiua2Diem(a.A, a.B);
    float BC = TinhKhoangCachGiua2Diem(a.B, a.C);
    float AC = TinhKhoangCachGiua2Diem(a.A, a.C);
    float P = TinhChuViTamGiac(a) / 2;

    return sqrt(P * (P - AB) * (P - AC) * (P - BC));
}
DIEM TimToaDoTrongTamTamGiac(TAMGIAC a)
{
    DIEM G;
    G.x = (a.A.x + a.B.x + a.C.x) / 3;
    G.y = (a.A.y + a.B.y + a.C.y) / 3;

    return G;
}

int main()
{
    TAMGIAC a, b;

    NhapTamGiac(a);
    XuatTamGiac(a);

    float ChuVi = TinhChuViTamGiac(a);
    float DienTich = TinhDienTichTamGiac(a);

    DIEM G = TimToaDoTrongTamTamGiac(a);

    printf("\nChu vi tam giac = %.2f", ChuVi);
    printf("\nDien tich tam giac = %.2f", DienTich);
    printf("\nToa do trong tam tam giac la <%.2f, %.2f>", G.x, G.y);
  
    getch();
    return 0;
}
