// if-then use &&
const x = true && "I am true"
console.log(x)

// if-undefined use ??
const y = undefined ?? "I am undefined"
console.log(y)

// double ternary or nested ifs
const z = true ? true ? "I am true twice" : "I am true only the first time": "I am never true"
console.log(z)

// normal ternary or else-if
const a = true ? "I am true": false? "I am false" : "I am neither true or false"
console.log(a)