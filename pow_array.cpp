/*this program prints every figure of a power of 2 in an array.*/

#include <cstdlib>
#include <iostream>

using namespace std;



//load the array with 1 in the first index and zeros
void load_array(unsigned long long int a[], int dim){
     a[0]=1;
     for(int i=1;i<dim;i++)
             a[i]=0;    
}

//prints the array
void print_array(unsigned long long int a[], int dim){
     for(int i=dim-1;i>=0;i--)
             cout<<a[i]<<"\t";     
}

/*this method handles the power. 
*a for loop multiplies the c[0] value exponent-times for the base. 
*after the first for loop, another one handles the carry by increasing the c[i+1] value by one and reducing the c[i] value of
*ten.
*/
void pow(int a, int b, unsigned long long int c[], int dim){
     int currExp=0;
     for(int i=0;i<dim;i++){
          while(currExp<b){
               c[i]*=a;
               currExp++;
          }
          for(int i=0;i<dim;i++){
               while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;            
               }
          }
     }
}

int main(){

    int base=2, exp;
    cout<<"2^";
    cin>>exp;
    cout<<"= ";
    int cDIM=(int)(exp/3.3+1);
    unsigned long long int c[cDIM];
    load_array(c, cDIM);
    pow(base, exp, c, cDIM);
    print_array(c, cDIM);  
    
    
    system("PAUSE");
    return 0;    
}
