var num = 2345;

function sumOfNumbers(num) {
    arr = num.toString();
    sum = 0;
    for (i = 0; i < arr.length; i++) {
        sum += parseInt(arr[i]);
    }
    return sum;
}

console.log(sumOfNumbers(num));

console.log("\nTask2\n=====================================");

var testString = "Hello World";


var vowels = [{'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}];

function vowelsCounter(str) {
    for (let i = 0; i < str.length; i++) {
        let index = str[i].toLowerCase();

        if (index === 'a') vowels[0]['a']++;
        else if (index === 'e') vowels[0]['e']++;
        else if (index === 'i') vowels[0]['i']++;
        else if (index === 'o') vowels[0]['o']++;
        else if (index === 'u') vowels[0]['u']++;
    }

    return vowels;
}


console.log(vowelsCounter(testString));

console.log("\nTask3\n=====================================");


function occurenceOfChar(str, charrr){
    var count = 0;
    for(i = 0; i < str.length; i++){
        if(str[i] == charrr){
            count++;
        }
    }
    return count;
}

console.log(occurenceOfChar("hello world", "o"));



console.log("\nTask4\n=====================================");

Day = "1999-02-27";

function calculateAge(dob) {
    var dob = new Date(dob);
    var diff_ms = Date.now() - dob.getTime();
    var age_dt = new Date(diff_ms); 

    return Math.abs(age_dt.getUTCFullYear() - 1970);

}

console.log(calculateAge(Day));