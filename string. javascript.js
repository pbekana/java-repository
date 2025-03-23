console.log("i'm back thanks for waiting");
let mesage = `"I'm good". She said`; // this is Es6 template literals
console.log(mesage);
let name = 'John';
let message = `Hi, I'm ${name}.`;

console.log(message);
// using slash or \
let str = 'I\'m a string!';
console.log(str);
//look the difference
console.log("let str = 'I'm a string!';");
// lenths of strings
let str1 = "Good Morning!";
console.log(str1.length);  // 13
//accessing a character
let str2 = "Hello";
console.log(str2[1]); // "H"
// string concatanation
let names = 'John';
let str3 = 'Hello ' + names;

console.log(str3); // "Hello John"
//If you want to assemble a string piece by piece, you can use the += operator:
let className = 'btn';
className += ' btn-primary'
className += ' none';

console.log(className);
// converting a string from other type and convert it back to boolean type
let statuss = false;
let str4 = statuss.toString(); // "false"
console.log(str4);
let back = Boolean(str4); // true
console.log(str4)
//comparison of a strings
console.log("the comparison of a and b is :",'a'>'b');
let result = 'a' > 'B';
console.log("the comparison of a and B is :",result); // false
//object in javascript
 const person = {
    names : "james",
    number : 19
};
console.log(person.names);
 