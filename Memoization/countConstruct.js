//write a function `countConstruct(target, wordBank)` that accepts a
//target string and an array of strings.
//the function should return the number of ways that the `target`
//can be constructed by concatenating elements of the `wordBank` array.
//you may reuse elements of `wordBank` as many times as needed.
//

const countConstruct = (target, wordBank, memo = {} ) => {
	if ( target in memo ) return memo[target];
	if ( target.length === 0 ) return 1;
	
	let sum = 0;
	for ( let word of wordBank ) {
		if ( target.indexOf(word) === 0 ) {
			const suffix = target.slice(word.length);

			memo[target] = sum = sum + countConstruct(suffix, wordBank, memo);
		}
	}
	return memo[target] = sum;
}

console.log( countConstruct( "purple", ["purp", "p", "ur", "le", "purpl"]));
console.log( countConstruct( "abcdef", ["ab", "abc", "cd", "def", "abcd"] ) );
console.log( countConstruct( "skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar" ] ) );
console.log( countConstruct( "enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"] ) );
console.log ( countConstruct( "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
        "e",
        "ee",
        "eee",
        "eeee",
        "eeeee",
        "eeeeee"
]));
