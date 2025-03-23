#include<iostream>

using namespace std;
int st_size = 0;//global variable
struct StudentType{
string name;
string id;
double GPA;
};
void Studentdata(StudentType& student){
cout<<"enter student information "<<endl;
cout<<"enter student name "<<endl;
cin>>student.name;
cout<<"enter student ID "<<endl;
cin>>student.id;
cout<<"enter student GPA "<<endl;
cin>>student.GPA;
cout<<"student information successfully registered "<<endl;
}
void printstudentdata(StudentType student){
    cout<<"\n\t name \t id\tGPA"<<endl;
    for(int i = 0;i< st_size;i++){
cout<<student.name<<endl<<student.id<<endl<<student.GPA<<endl;
    }
}
void sortstudentByname(StudentType student[]){
 cout<<"sort student data by name using bubble sort"<<endl;
    bool flag;
 StudentType temp;
    for(int i =0;i<st_size-1;i++){
        flag = false;
        cout<<"\n"<<i+1<<"pass\n";
        for(int j = 0;j<st_size-1;j++){// if(num[i] > num[sum]
            if(student[j].name > student[j+1].name){
                temp = student[j];
                student[j]= student[j+1];
                student[j+1] = temp;
                flag =  true;
            }
        }
        if(flag = false ){
            break;

        }
    }

}
void sortstudentByid(StudentType student[]){
   int smallest;
  StudentType temp;
for(int i = 0;i<st_size-1;i++){
    smallest = i;
    cout<<"\n"<<i+1<<"pass\n";
 for(int j=i+1;j<st_size-1;j++){
    if(student[j].id <student[smallest].id){
        smallest = j;
    }
    if(smallest != j){
         StudentType temps = student[smallest];
        student[smallest] = student[i];
       student[i] = temps;
    }
 }


}
}
/*void sortstudentByGPA(StudentType student[]){
 int smallest;
  StudentType temp;
for(int i = 0;i<st_size-1;i++){
    smallest = i;
    cout<<"\n"<<i+1<<"pass\n";
 for(int j=i+1;j<st_size-1;j++){
    if(student[j].GPA <student[smallest].GPA){
        smallest = j;
    }
    if(smallest != i){
        int temp = student[smallest];
        student[smallest] = student[i];
       student[i] = temp;
    }
 }

}*/
int main() {
  StudentType student[10];
  int op;
  menu:
      cout<<"press 1: enter new student information"<<endl;
      cout<<"press 2:to print student information "<<endl;
      cout<<"press 3:sort  student information by name"<<endl;
      cout<<"press 4:student information by ID "<<endl;
      cout<<"press 4:student information by GPA "<<endl;
      cout<<"\n select your choice ";
      cin>>op;
 switch(op) {
 case 1:
    Studentdata(student[st_size]);
    st_size++;
    break;
    case 2:
printstudentdata(student[st_size]);
break;
    case 3:
  //  sortstudentByname(student);
  cout<<"************"<<endl;
break;
    default:
        cout<<"invalid choice ,try again"<<endl;

 }
goto menu;
    return 0;
}
