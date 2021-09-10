/*
มินาเสะ นางิสะ เด็กสาวมัธยมปลายในโรงเรียนแห่งนึง ได้เรียนคาบคณิตศาสตร์ในคาบสุดท้ายก่อนเลิกเรียน ซึ่งเป็นเรื่องเมตริกซ์
ซึ่งหลังจบคาบอาจารย์ได้สั่งการบ้านไว้ แต่ มินาเสะ มัวแต่ใจลอยคิดถึง นาโอยะ แฟนหนุ่มของเธอ มินาเสะ เลยทำการบ้านไม่เป็น
แล้วนาโอยะก็ดันไม่อยู่อีก มินาเสะ อยากคุณช่วยเขียนโปรแกรมคำนวณเมตริกซ์ โดยโปรแกรมจะรับค่าเมตริก A และ B เป็นจำนวนเต็ม ซึ่งเป็นเมตริกขนาด 3x3 
แล้วโปรแกรมจะแสดงผลลัพธ์ต่อไปนี้ Transpose(A),Transpose(B),Det(A),Det(B),Inverse(A),Inverse(B),A+B,A-B,AB (Inverse แสดงทศนิยม 4 ตำแหน่ง)
*/
//Formula Method
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
            printf("%.4f ",mat[i][j]);
        cout << endl;
    }
}
void swap(int &x,int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void transpose(int** mat)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j] = mat[i][j];
    
    swap(arr[1][0],arr[0][1]);
    swap(arr[2][0],arr[0][2]);
    swap(arr[2][1],arr[1][2]);
    
    printMatrix(arr);
    delete arr;
}
int sum(int x,int y)
{
    while(y != 0)
    {
        unsigned carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
void summation(int** matA,int** matB)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j] = sum(matA[i][j],matB[i][j]);

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
            arr[i][j] = sum(matA[i][j],-matB[i][j]);
    
    printMatrix(arr);
    delete arr;
}
void multiplication(int** matA,int** matB)
{
    int** arr = new int*[3];
    for(int i=0;i<3;i++)
        arr[i] = new int[3];
    
    arr[0][0] = matA[0][0]*matB[0][0] + matA[0][1]*matB[1][0] + matA[0][2]*matB[2][0];
    arr[0][1] = matA[0][0]*matB[0][1] + matA[0][1]*matB[1][1] + matA[0][2]*matB[2][1];
    arr[0][2] = matA[0][0]*matB[0][2] + matA[0][1]*matB[1][2] + matA[0][2]*matB[2][2];

    arr[1][0] = matA[1][0]*matB[0][0] + matA[1][1]*matB[1][0] + matA[1][2]*matB[2][0];
    arr[1][1] = matA[1][0]*matB[0][1] + matA[1][1]*matB[1][1] + matA[1][2]*matB[2][1];
    arr[1][2] = matA[1][0]*matB[0][2] + matA[1][1]*matB[1][2] + matA[1][2]*matB[2][2];

    arr[2][0] = matA[2][0]*matB[0][0] + matA[2][1]*matB[1][0] + matA[2][2]*matB[2][0];
    arr[2][1] = matA[2][0]*matB[0][1] + matA[2][1]*matB[1][1] + matA[2][2]*matB[2][1];
    arr[2][2] = matA[2][0]*matB[0][2] + matA[2][1]*matB[1][2] + matA[2][2]*matB[2][2];

    printMatrix(arr);
    delete arr;
}
int determinant(int** mat)
{
    return mat[0][0]*(mat[1][1]*mat[2][2] - mat[2][1]*mat[1][2]) - mat[0][1]*(mat[1][0]*mat[2][2] - mat[2][0]*mat[1][2]) + mat[0][2]*(mat[1][0]*mat[2][1] - mat[2][0]*mat[1][1]);
}
void inverse(int **mat)
{
    int d = determinant(mat);

    if(d == 0)
    {
        cout << "No inverse available" << endl;
        return;
    }
    
    float** arr = new float*[3];
    for(int i=0;i<3;i++)
        arr[i] = new float[3];

    arr[0][0] = float(mat[1][1]*mat[2][2] - mat[2][1]*mat[1][2]) / d;
    arr[0][1] = float(mat[0][2]*mat[2][1] - mat[2][2]*mat[0][1]) / d;
    arr[0][2] = float(mat[0][1]*mat[1][2] - mat[1][1]*mat[0][2]) / d;

    arr[1][0] = float(mat[1][2]*mat[2][0] - mat[2][2]*mat[1][0]) / d;
    arr[1][1] = float(mat[0][0]*mat[2][2] - mat[2][0]*mat[0][2]) / d;
    arr[1][2] = float(mat[0][2]*mat[1][0] - mat[1][2]*mat[0][0]) / d;

    arr[2][0] = float(mat[1][0]*mat[2][1] - mat[2][0]*mat[1][1]) / d;
    arr[2][1] = float(mat[0][1]*mat[2][0] - mat[2][1]*mat[0][0]) / d;
    arr[2][2] = float(mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]) / d;

    printMatrixFloat(arr);
    delete arr;
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
    cout << determinant(matA) << endl;
    cout << "Det(B):" << endl;
    cout << determinant(matB) << endl;
    cout << "Inverse(A):" << endl;
    inverse(matA);
    cout << "Inverse(B):" << endl;
    inverse(matB);
    cout << "A+B:" << endl;
    summation(matA,matB);
    cout << "A-B:" << endl;
    subtraction(matA,matB);
    cout << "AB:" << endl;
    multiplication(matA,matB);
    delete matA;
    delete matB;
}
