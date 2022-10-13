interface Person {
    age: number,
    name: string,
    balance: number,
    say(): string
}

let person1 = {
    age: 6000, 
    name:"Dvorakz",
    balance: 500000,
    say: function() { 
        return "My name is " + this.name + 
               " and I'm " + this.age + " years old!" +
               "I have $" + this.balance + "in Holo Token"
    }
}

function sayIt(person: Person) {
    return person.say();
}

console.log(sayIt(person1))