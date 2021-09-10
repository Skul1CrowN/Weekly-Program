/*
มินาเสะ นางิสะ เด็กสาวมัธยมปลายในโรงเรียนแห่งนึง ได้เรียนคาบคณิตศาสตร์ในคาบสุดท้ายก่อนเลิกเรียน ซึ่งเป็นเรื่องเมตริกซ์
ซึ่งหลังจบคาบอาจารย์ได้สั่งการบ้านไว้ แต่ มินาเสะ มัวแต่ใจลอยคิดถึง นาโอยะ แฟนหนุ่มของเธอ มินาเสะ เลยทำการบ้านไม่เป็น
แล้วนาโอยะก็ดันไม่อยู่อีก มินาเสะ อยากคุณช่วยเขียนโปรแกรมคำนวณเมตริกซ์ โดยโปรแกรมจะรับค่าเมตริก A และ B เป็นจำนวนเต็ม ซึ่งเป็นเมตริกขนาด 3x3 
แล้วโปรแกรมจะแสดงผลลัพธ์ต่อไปนี้ Transpose(A),Transpose(B),Det(A),Det(B),Inverse(A),Inverse(B),A+B,A-B,AB (Inverse แสดงทศนิยม 4 ตำแหน่ง)
*/
//Actually Method
#include<iostream>
using namespace std;
void inputMatrix(int** mat)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int** mat)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
void printMatrixFloat(float** mat)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%.4f ", mat[i][j]);
        cout << endl;
    }
}

void transpose(int** mat)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j] = mat[j][i];
    
    printMatrix(arr);
    delete arr;
}
void summation(int** matA,int** matB)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j] = matA[i][j] + matB[i][j];

    printMatrix(arr);
    delete arr;
}
void subtraction(int** matA,int** matB)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j] = matA[i][j] - matB[i][j];
    
    printMatrix(arr);
    delete arr;
}
void multiplication(int** matA,int** matB)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j] = 0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                arr[i][j] += matA[i][k]*matB[k][j];

    printMatrix(arr);
    delete arr;
}
void cofactor(int** mat,int **target,int row,int col,int n)
{
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i != row && j != col)
            {
                target[a][b++] = mat[i][j];

                if(b == n-1)
                {
                    b=0;
                    a++;
                }
            }
        }
    }
}
int determinant(int** mat,int n)
{
    int d=0;

    int** temp = new int*[n-1];
    for(int i=0;i<n-1;i++)
        temp[i] = new int[n-1];

    if(n==1)
        return mat[0][0];

    int sign=1;

    for(int i=0;i<n;i++)
    {
        cofactor(mat,temp,0,i,n);
        d+=sign*mat[0][i]*determinant(temp,n-1);
        sign=-sign;
    }

    delete temp;
    return d;
}
void adjoint(int **mat,int **target,int n)
{
    int** cofac = new int*[n-1];
    for(int i=0;i<n-1;i++)
        cofac[i] = new int[n-1];

    int sign=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cofactor(mat,cofac,i,j,n);
            target[j][i] = sign*determinant(cofac,n-1);
            sign=-sign;
        }
    }
    delete cofac;
}
void inverse(int **mat,int n)
{
    int d = determinant(mat,3);

    if(d==0)
    {
        cout << "No inverse available" << endl;
        return;
    }
    
    int** temp = new int*[n];
    for(int i=0;i<n;i++)
        temp[i] = new int[n];
    
    float** inverse = new float*[n];
    for(int i=0;i<n;i++)
        inverse[i] = new float[n];

    adjoint(mat,temp,n);
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            inverse[i][j] = float(temp[i][j]) / d;
        }
    }

    printMatrixFloat(inverse);
    delete temp;
    delete inverse;
}
main()
{
    int** matA = new int*[3];
    for(int i=0;i<3;i++)
        matA[i] = new int[3];

    int** matB = new int*[3];
    for(int i=0;i<3;i++)
        matB[i] = new int[3];

    cout << "Input Matrix A:" << endl;
    inputMatrix(matA);
    cout << "Input Matrix B:" << endl;
    inputMatrix(matB);
    cout << "Transpose(A):" << endl;
    transpose(matA);
    cout << "Transpose(B):" << endl;
    transpose(matB);
    cout << "Det(A):" << endl;
    cout << determinant(matA,3) << endl;
    cout << "Det(B):" << endl;
    cout << determinant(matB,3) << endl;
    cout << "Inverse(A):" << endl;
    inverse(matA,3);
    cout << "Inverse(B):" << endl;
    inverse(matB,3);
    cout << "A+B:" << endl;
    summation(matA,matB);
    cout << "A-B:" << endl;
    subtraction(matA,matB);
    cout << "AB:" << endl;
    multiplication(matA,matB);
    delete matA;
    delete matB;
}
