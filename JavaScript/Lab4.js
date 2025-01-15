Array.prototype.average = function () {
    if (!this.every(num => typeof num === "number")) {
        throw new Error("Array must contain only numbers.");
    }
    return this.length === 0 ? 0 : this.reduce((sum, num) => sum + num, 0) / this.length;
};

var arr = [1, 2, 3, 4];
console.log(arr.average());

Object.prototype.toString = function () {
    return this.message ? this.message : "This is an object";
};

var obj1 = { message: "This is a message" };
var obj2 = {};
console.log(String(obj1));
console.log(String(obj2));

var Vehicle = (function () {
    var count = 0;

    function Vehicle(type, speed) {
        if (count >= 50) throw new Error("Vehicle limit reached");
        this.type = type;
        this.speed = speed;
        count++;
    }

    Vehicle.prototype.start = function () {
        console.log(this.type + " is starting");
    };

    Vehicle.prototype.stop = function () {
        console.log(this.type + " is stopping");
    };

    return Vehicle;
})();

function Car(type, speed) {
    Vehicle.call(this, type, speed);
}

Car.prototype = Object.create(Vehicle.prototype);
Car.prototype.constructor = Car;

Car.prototype.drive = function () {
    console.log(this.type + " is driving at " + this.speed + " km/h");
};

function isCarInstance(obj) {
    return obj instanceof Car || obj.constructor === Car;
}

var car = new Car("Sedan", 120);
car.start();
car.drive();
car.stop();

console.log(isCarInstance(car));
var vehicle = new Vehicle("Truck", 100);
console.log(isCarInstance(vehicle));
