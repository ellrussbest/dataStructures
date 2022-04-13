//write a function `fib(n)` that takes in a number as an argument.
//the function should return the n-nth number of the fibonacci sequence
//
//memoization
//js object, key will be arg to fn, value will be the return value

const fib = (n, memo = {} ) => {
	if ( n in memo ) return memo[n];
	if ( n <= 2 ) return 1;

	return memo[n] = fib(n-1, memo) + fib(n-2, memo);
}

console.log(fib(6));
console.log(fib(7));
console.log(fib(50));
