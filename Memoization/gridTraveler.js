//say you are a traverler on a 2D grid. you begin in the top-left
//corner and your goal is to travel to the bottom-right corner.
//you may only move down or right
//
//in how many ways can you travel to the goal on a grid with
//dimensions m*n?


const gridTraveler = (m, n, memo = {}) => {
	if ( `${m},${n}` in memo ) return memo[`${m},${n}`];
	if (m <= 0 || n <= 0) return 0;
	if (m === 1 || n === 1 ) return 1;
	return memo[`${m},${n}`] = memo[`${n},${m}`] = 
		gridTraveler(m-1, n, memo) + gridTraveler(m, n-1, memo);
}

console.log(gridTraveler(2,3));
console.log(gridTraveler(3,3));
console.log(gridTraveler(18,18));
