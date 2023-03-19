
#include <iostream>
#include <iomanip>
using namespace std;

const int n = 8;
int a[n][n];//luu tru thu tu di tuan

//Luu cac vi tri co the qua
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void KhoiTao()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = 0;
}


//i: So luot da di, (x,y): toa do ma o vi tri cuoi cung
void ThuNuocDiKe(int i, int x, int y, bool &q)
{
    int k, u, v;
    bool q1;//q1: Luu thanh cong/that bai
    k = 0;//Chi so cac kha nang con ma di chuyen
    do{
        //Thu vi tri moi --> that bai
        q1 = false;

        u = x + dx[k];
        v = y + dy[k];

        if((0 <= u) && (u < n) && (0 <= v) && (v < n) && (a[u][v] == 0))
        {
            //Gan vi tri con ma di qua
            a[u][v] = i;
            
            if(i < n * n)//con vi tri trong
            {
                ThuNuocDiKe(i + 1, u, v, q1);
                if(q1 == false)
                    a[u][v] = 0;
            }
            else q1 = true;        
        }
        k++;
    }while((q1 == false) && (k < 8));
    q = q1;
}

void InBanCo()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<setw(4)<<a[i][j];
        cout<<endl;
    }
}
int main()
{
    bool q = false;
    KhoiTao();
    a[4][5] = 1;
    ThuNuocDiKe(2, 4, 5, q);
    InBanCo();
    return 0;
}
