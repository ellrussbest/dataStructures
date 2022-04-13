//write a funciton `bestSum(targetSum, numbers)` that takes in a 
//targetSum and an array of numbers as arguments.
//
//the function should return an array containing the shortest combination
//of numbers that add up to exactly the targetSum;
//if there is a tie for the shortest combination, you may return any one
//of the shortest
const bestSum = (targetSum, numbers, memo = {}) => {
	if ( targetSum in memo ) return memo[targetSum];
	if ( targetSum === 0 ) return [];
	if ( targetSum < 0 ) return null;
	
	let bestArray = null;

	for ( let num of numbers ) {
		const remainder = targetSum - num;
		const arrayHolder = bestSum ( remainder, numbers, memo );
		if ( arrayHolder ) {
			const combination = [...arrayHolder, num ];
			//if the combination is shorter than the current "shortest", update it
			if( bestArray === null || combination.length < bestArray.length ) {
				memo[targetSum] = bestArray = combination;
			}
		}
	}
	return memo[targetSum] = bestArray;
}

console.log(bestSum(7, [5, 3, 4, 7, ]));
console.log(bestSum(8, [2, 3, 5]));
console.log(bestSum(8, [1, 4, 5]));
console.log(bestSum(100, [1, 2, 4, 25]));
