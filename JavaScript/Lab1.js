function isPalindromeNumber(num) {
    const str = num.toString();
    const reversedStr = str.split('').reverse().join('');
    return str === reversedStr;
}

console.log(isPalindromeNumber(531135));
console.log("=====================================");

function calculateDiscountedPrice(price, discount) {
    if (typeof price !== 'number' || typeof discount !== 'number') {
        throw new Error('Both price and discount should be numbers');
    }
    if (price < 0 || discount < 0 || discount > 100) {
        throw new Error('Invalid price or discount value');
    }
    return price - (price * (discount / 100));
}

console.log(calculateDiscountedPrice(100, 20));
console.log(calculateDiscountedPrice(150, 0)); 

console.log("=====================================");
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


console.log("=====================================");
var longestWord = 'Web Development Tutorial'

var longestWord = longestWord.split(' ').reduce((a, b) => a.length > b.length ? a : b);

console.log("The longest word is: " + longestWord);

console.log("=====================================");


var orders = [
    {
      orderId: 'ORD001',
      customer: 'John Doe',
      items: 'item1:2,item2:1,item3:5',
      orderDate: '2023-12-01',
      deliveryDate: '2023-12-05',
      deliveryAddress: '123, Main Street, Springfield, USA',
    },
    {
      orderId: 'ORD002',
      customer: 'Jane Smith',
      items: 'itemA:3,itemB:4',
      orderDate: '2023-11-15',
      deliveryDate: '2023-11-20',
      deliveryAddress: 'Flat 4B, Elmwood Apartments, New York, USA',
    },
    {
      orderId: 'ORD003',
      customer: 'Alice Johnson',
      items: 'itemX:1',
      orderDate: '2023-10-10',
      deliveryDate: '2023-10-15',
      deliveryAddress: '456, Pine Lane, Denver, USA',
    }
  ];
  
  var formattedOrders = orders.map(order => {
    let totalItems = order.items.split(',').reduce((sum, item) => {
      return sum + parseInt(item.split(':')[1]);
    }, 0);
  
    let deliveryDuration = (new Date(order.deliveryDate) - new Date(order.orderDate)) / (1000 * 60 * 60 * 24);
    let [buildingNumber, deliveryStreet, deliveryCity, deliveryCountry] = order.deliveryAddress.split(',').map(part => part.trim());
  
    if (!isNaN(buildingNumber)) {
      buildingNumber = parseInt(buildingNumber);
    }
  
    return {
      orderId: order.orderId,
      customer: order.customer,
      totalItems: totalItems,
      orderDate: order.orderDate,
      deliveryDate: order.deliveryDate,
      deliveryDuration: deliveryDuration,
      deliveryCountry: deliveryCountry,
      deliveryCity: deliveryCity,
      deliveryStreet: deliveryStreet,
      buildingNumber: buildingNumber,
    };
  });
  
  console.log(formattedOrders);
