#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX 10
#define DIM 100

void carica(int a[], int dim){
    for(int i=0;i<dim;i++){
            a[i]=rand()%MAX;
    }    
}

void print(int a[], int dim, int inv){
     
     switch(inv){
        case 0:
             for(int i=0;i<dim;i++){
                cout<<a[i]<<" ";
             }
             break;
        case 1:   
             for(int i=dim-1;i>=0;i--){
                cout<<a[i]<<" ";
             }
             break; 
        default:
             break;                  
     }
    cout<<endl;
}

void merge(int a[], int left, int center, int right){
    int n1=center-left+1, n2=right-center;
    int l1[n1], l2[n2];
    
    for(int i=0;i<n1;i++)
        l1[i]=a[left+i];
    for(int i=0;i<n2;i++)
        l2[i]=a[i+center+1];
        
    l1[n1]=1<<31-1;
    l2[n2]=1<<31-1;
    
    int k1=0, k2=0;
    
    for(int i=left;i<=right;i++)
        if(l1[k1]<=l2[k2])
            a[i]=l1[k1++];
        else
            a[i]=l2[k2++];
}

void mergesort(int a[], int left, int right){
    
    int center;
    if(left<right){
        center=(left+right)/2;
        mergesort(a, left, center);
        mergesort(a, center+1, right);
        merge(a, left, center, right);    
    }    
}

int factorial(int a){
    long long int b=1;
    
    for(int i=1;i<a+1;i++){
            b=b*i;
            } 
           return b;   
}

int calculate_combination(int n, int k){
    int res;
    
    if(n<=k)
         cout<<"error! n must be greater than k!"<<endl;
    else{
         res=(factorial(n))/(factorial(n-k)*factorial(k));
    }
     
    return res;
}

int calculate_disposition(int n, int k){
    int res;
    
    if(n<=k)
         cout<<"error! n must be greater than k!"<<endl;
    else{
         res=(factorial(n))/(factorial(n-k));
    }
     
    return res;
     }

int main(){
    int A[DIM];
    int disp, comb;
    int n=4, k=3;
    
    srand(time(NULL));
    
    carica(A, DIM);
    cout<<"array normale: "; 
    print(A, DIM, 0);
    cout<<"array al contrario: "; 
    print(A, DIM, 1);
    mergesort(A, 0, DIM-1);
    cout<<"array in ordine crescente: "; 
    print(A, DIM, 0);
    cout<<"array in ordine decrescente: "; 
    print(A, DIM, 1);
    disp=calculate_disposition(n, k);
    cout<<"numero disposizioni: "<<disp<<endl;
    comb=calculate_combination(n, k); 
    cout<<"numero combinazioni: "<<comb<<endl;
    
    
    system("pause");

}
