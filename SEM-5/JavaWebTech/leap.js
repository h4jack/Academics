function isLeapYear(year){
    return (year % 4 === 0 && year % 100 !== 0) || year % 400 === 0;
}

let a = 10;
console.log(a);
console.log("is Leap Year");
console.log(isLeapYear(1002));
console.log(isLeapYear(1004));
console.log(isLeapYear(2004));
console.log(isLeapYear(2000));
console.log(isLeapYear(2100));
