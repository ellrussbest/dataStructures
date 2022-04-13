//write a funciton `howSum(targetSum, numbers)` that takes in a targetSum
//and an array of numbers as arguments.
//the function should return an array containig any combination of
//elements that add up to exactly the targetSum. if there is no
//combination that adds up to the targetSum, then return null
//
//if there are multiple combinations possible, you may return any
//single one.


const howSum = (targetSum, numbers, memo = {}) => {
	if ( targetSum in memo ) return memo[targetSum];
	if ( targetSum === 0 ) return [];
	if ( targetSum < 0 ) return null;
	
	for ( let num of numbers ) {
		const remainder = targetSum - num;
		const arrayHolder = howSum(remainder, numbers, memo);
		if (arrayHolder) {
			return memo[targetSum] = [...arrayHolder, num];
		}
	}
	return memo[targetSum] = null;
}

console.log(howSum(7, [2,3]));
console.log(howSum(7, [5,3,4,7]));
console.log(howSum(7, [2,4]));
console.log(howSum(8, [2,3,5]));
console.log(howSum(300, [7, 14]));
