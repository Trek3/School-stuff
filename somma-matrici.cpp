#include <cstdlib>
#include <iostream>

#define DIM 5000
#define MAX 10

using namespace std;

void carica(int arr[]){
          for(int i=0;i<DIM;i++)
                  arr[i]=rand()%MAX;
}

void somma(int a[], int b[], int c[]){
     for(int i=0;i<DIM;i++){
                c[i]+=a[i]+b[i];
                if(c[i]>9){
                    c[i]-=10;
                    c[i+1]++;
                }
                    
    }
                    

}

void stampa(int a[], int b[], int c[]){
     for(int i=0;i<DIM;i++)
             cout<<a[i]<<" + "<<b[i]<<" = "<<c[i]<<endl;    
}

int main(){
    int a[DIM];
    int b[DIM];
    int c[DIM+1]={0};
    
    srand(time(NULL));
    
    carica(a);
    carica(b);
    somma(a, b, c);
    stampa(a, b, c);
    
    system("PAUSE");
        
}
