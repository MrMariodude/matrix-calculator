#include <iostream>
#include <math.h>

using namespace std;
const int No_rows=10;
const int No_colu=10; 
long long matrix_determant(long long matrix[10][10],int row);
void minor(long long matrix2[10][10],long long temp[10][10],int start, int end, int row );
int main()
{
    long long matrix1[No_rows][No_colu];
    long long matrix2[No_rows][No_colu];
    long long matrix_sum[No_rows][No_colu];
    long long matrix_subtract[No_rows][No_colu];
    long long matrix_multiply[No_rows][No_colu];
    int row1,colu1,row2,colu2;
    int operations;
      cout<<"Please enter dimensions of Matrix A:"<<endl;
       while(true)
       {
           cin>>row1>>colu1;
           if(row1<=0 || colu1<=0 || row1>10 || colu1>10)
           {
               cout<<"invalid dimensions!"<<endl;
           }
           else
           break;
       }
    cout<<"Please enter dimensions of Matrix B:"<<endl;
     while(true)
       {
           cin>>row2>>colu2;
           if(row2<=0 || colu2<=0 || row2>10 || colu2>10)
           {
               cout<<"invalid dimensions!"<<endl;
           }
           else
           break;
       }
    cout<<"Please enter values of Matrix A:"<<endl;
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<colu1; j++)
        {
            
            int variables1;
             while(!(cin>>variables1))
             {
                 cout<<"Invalid type of data!"<<endl;
                 cin.clear();
                 cin.ignore(123,'\n');
             }
             matrix1[i][j]=variables1;        
        }
    }
    cout<<"Please enter values of Matrix B:"<<endl;
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<colu2; j++)
        {
            int variables2;
            while(!(cin>>variables2))
             {
                 cout<<"Invalid type of data!"<<endl;
                 cin.clear();
                 cin.ignore(123,'\n');
             }
            matrix2[i][j]=variables2;  
        }
    }
    do{
    
     cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
         while(!(cin>>operations))
             {
                 cout<<"Invalid type of data!"<<endl;
                 cin.clear();
                 cin.ignore(123,'\n');
             }
        if(operations==1)
        {
        if(row1!=row2 || colu1!=colu2)
        cout<<"The operation you chose is invalid for the given matrices."<<endl;
        else
        {
            for(int i=0; i<row1; i++)
            {
                for(int j=0; j<colu1; j++)
                {
                    matrix_sum[i][j]=matrix1[i][j]+matrix2[i][j];
                }
            }
            for(int i=0; i<row1; i++)
        {
            {
                for(int j=0; j<colu1; j++)
                cout<<matrix_sum[i][j]<<' ';
            }
             cout<<endl;
        } 
        }
        }
        else if(operations==2)
        {
            if(row1!=row2 || colu1!=colu2)
        cout<<"The operation you chose is invalid for the given matrices."<<endl;
        else
        {
            for(int i=0; i<row1; i++)
            {
                for(int j=0; j<colu1; j++)
                {
                    matrix_subtract[i][j]=matrix1[i][j]-matrix2[i][j];
                }
            }
            for(int i=0; i<row1; i++)
            {
                for(int j=0; j<colu1; j++)
                {
                    cout<<matrix_subtract[i][j]<<' ';
                }
                cout<<endl; 
            }
        }  
    }
        else if(operations==3)
        {
           
                if((colu1==row2 && colu1>0 && row2>0) || (row1==row2 && colu1==colu2))
                {
                for(int i=0; i<row1; i++)
                {
                    for(int j=0; j<colu2; j++)
                    {
                        int total=0;
                        for(int n=0; n<row2; n++)
                        total=total+matrix1[i][n]*matrix2[n][j];
                        matrix_multiply[i][j]=total;              
                    }
                }
                for(int i=0; i<row1; i++)
                {
                for(int j=0; j<colu2; j++)
                cout<<matrix_multiply[i][j]<<' ';
                cout<<endl;
                }
                }
               
              
            else if(colu1!=row2 || row1==0 || row2==0 || colu1==0 || colu2==0)
            cout<<"The operation you chose is invalid for the given matrices."<<endl;
            
        }
        else if(operations==4)
        {
           if(row2!=colu2 || matrix_determant(matrix2,row2)==0)
               cout<<"The operation you chose is invalid for the given matrices."<<endl;
            else
            { 
                long long adj_matrix[10][10],temp[10][10];
                double long inverse[10][10];
                float deter=matrix_determant(matrix2,row2);
                    if(row2==1)
                    {
                        adj_matrix[0][0]=1; 
                    }
                    for(int i=0; i<row2; i++)
                    {
                        for(int j=0; j<row2; j++)
                        {
                            minor(matrix2,temp,i,j,row2);
                            inverse[i][j]=(pow(-1,i+j)*(matrix_determant(temp,row2-1)))/deter;
                        }
                    }
                    if((colu1==colu2 && row1==row2) || colu1==row2)
                    {
                      long double matrix_multiply[10][10];
   
                    
                        for(int i=0; i<row1; i++)
                        {
                            for(int j=0; j<colu2; j++)
                            {
                                double total=0;
                                for(int n=0; n<row2; n++)
                                total=total+matrix1[i][n]*inverse[n][j];
                                matrix_multiply[i][j]=round(total);
                                 cout<<(long long)(matrix_multiply[i][j])<<' ';              
                            }
                            cout<<endl; 
                        }             
                    }
                    else
                    {
                       cout<<"The operation you chose is invalid for the given matrices."<<endl;
                    }
                    
            }

        }
        else if(operations==5)
        {
         if(row1==colu1)
         cout<<matrix_determant(matrix1,row1)<<endl;
          else
          cout<<"The operation you chose is invalid for the given matrices."<<endl;

        }

        else if(operations==6)
        {
            if(row2==colu2)
            cout<<matrix_determant(matrix2,row2)<<endl;
            else
            cout<<"The operation you chose is invalid for the given matrices."<<endl;

        }


        else if(operations==7)
        cout<<"Thank you!";
    }
    while(operations!=7); 
}

long long matrix_determant(long long matrix[10][10],int row)
{
    long long determant=0;
    long long matrix_temp[10][10];
    if(row==1)
    {
        determant= determant + matrix[0][0];
        return determant;
    }
     else if(row==2)
    return ((matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1]));
    else
    {
        for(int i=0; i<row; i++)
        {
        int sub_i=0;
        for(int j=1; j<row; j++)
        {
            int sub_j=0;
            for(int k=0; k<row; k++)
            {
                if(k==i)
                continue;
                matrix_temp[sub_i][sub_j]=matrix[j][k];
                sub_j++;
            
            }
            sub_i++;
        } 
        determant=determant + (pow(-1,i)*matrix[0][i]*matrix_determant(matrix_temp,row-1));

        }
    }
    return determant;
}

void minor(long long matrix2[10][10],long long temp[10][10],int start, int end, int row )
{
    int x=0,y=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<row; j++)
        {
            if(i!=start && j!=end)
            {
                    temp[x][y++]=matrix2[j][i];
                    if(y== row-1 )
                    {
                        y = 0;
                        x++;
                    }
             }
        }
    }
}



