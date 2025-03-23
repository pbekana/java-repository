//object in javascript 
var myvar = "global";
function print(){
    var myvar = "local";
    console.log(myvar);
}
function operators(){
var a = 33;
var b = 10;
var result =  a + b;
console.log("the addition of two numbers is :"+result);
result =  a-b;
console.log("the substraction of two numbers is :"+result);
++a;
console.log("the value of a in post-increement is :"+a);
++b;
console.log("the value of b in post-increement is :"+b);
result = a * b;
console.log("the value of a * b in post-increement is :"+result);

}
const Person = {
    name  : "james",
    age :30
}
console.log(Person.name);
console.log(Person.age);
print();
operators();