function isPalindromeNumber(num) {
    const str = num.toString();
    const reversedStr = str.split('').reverse().join('');
    return str === reversedStr;
}



console.log(isPalindromeNumber(531135));

function calculateDiscountedPrice(price, discount) {
    if (typeof price !== 'number' || typeof discount !== 'number') {
        throw new Error('Both price and discount should be numbers');
    }
    if (price < 0 || discount < 0 || discount > 100) {
        throw new Error('Invalid price or discount value');
    }
    return price - (price * (discount / 100));
}

console.log(calculateDiscountedPrice(100, 20)); // 80
console.log(calculateDiscountedPrice(200, 50)); // 100
console.log(calculateDiscountedPrice(150, 0));  // 150
console.log(calculateDiscountedPrice(100, 100)); // 0


arr = ['SpiderMan', 'IronMan', 'CaptainAmerica', 'Hulk', 'Thor'];

test = arr;
console.log(test);

test[2] = 'DoctorStrange';

console.log(test);

console.log(test[test.length - 1]);

console.log(test.slice(-1)[0]);

const lastItem = test.pop();
console.log(lastItem);
test.push(lastItem);

test.unshift("SuperMan");

console.log(test);

var longestWord = 'Web Development Tutorial'

var longestWord = longestWord.split(' ').reduce((a, b) => a.length > b.length ? a : b);

console.log("The longest word is: " + longestWord);