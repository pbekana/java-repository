#include<iostream>

using namespace std;

void setdata(int num[]){
for(int i = 0;i<5;i++){
  cout<<" enter data"<<endl;
cin>>num[i];
}

}
void printdata(int num[]){
    cout<<"\n the number is ;";
   for(int i = 0;i<5;i++){
   cout<<num[i]<<"\t";
}
}
void bubblesort(int num[]){
    cout<<"enter the number of array"<<endl;
    bool flag;
    int temp;
    for(int i =0;i<5-1;i++){
        flag = false;
        cout<<"\n"<<i+1<<"pass\n";
        for(int j = 0;j<5-1;j++){
            if(num[j] > num[j+1]){
                temp = num[j];
                num[j]= num[j+1];
                num[j+1] = temp;
                flag =  true;
            }
            printdata(num);
        }
        if(flag = false ){
            break;

        }
    }
}
void selectionsort(int num[]){
int i,j,smallest;
for(i = 0 ;i<5-1;i++){
    smallest = i;
    for(j = 0;j<5;j++){
              cout<<"\n"<<i+1<<"pass\n";
        if(num[j] < num[smallest])
            smallest  = j;
    }
    if(smallest!=i){
        int temp = num[smallest];
        num[smallest] = num[i];
        num[i]  =temp;
    }
}


printdata(num);
}
void insertion_sort(int num[]){
int temp;
int j;
for(int i = 0;i<5-1;i++){
    temp = num[i];
    j = i-1;
    while( j>-1 && num[j] > temp){
       num[j+1] = num[j];
        j--;
    }
    num[j+1] = temp;
}

printdata(num);

}

int main(){

int num[5];
int sos[5];
setdata(num);
printdata(num);
//bubblesort(num);
//selectionsort(sos);
insertion_sort(num);
    return 0;
}
