//write a function `canSum(targetSum, numbers)` that takes in a 
//targetSum and an array of numbers as arguments.
//The function should return a boolean indicating wheter or not it is
//possible to generate the targetSum using numbers from the array
//
//yo may use an element of the array as many times as needed.
//you may assume that all input numbers are nonnegative


const canSum = (targetSum, numbers, memo = {}) => {
	if ( targetSum in memo ) return memo[targetSum];
	if ( targetSum === 0 ) return true;
	if ( targetSum < 0 ) return false;

	for ( let num of numbers ) {
		const remainder = targetSum - num;
		if ( canSum(remainder, numbers, memo) ) return memo[targetSum] = true;
		else memo[targetSum] = false;
	}
	return memo[targetSum] = false;
}

console.log(canSum(7, [2,3]));
console.log(canSum(7, [5, 3, 4, 7]));
console.log(canSum(7, [2, 4]));
console.log(canSum(8, [2, 3, 5]));
console.log(canSum(300, [7,14]));
