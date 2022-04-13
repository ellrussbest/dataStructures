//write a function `allConstruct(target, wordBank)` that accepts a
//target string and an array of strings.
//the function should return a 2d array containing all the ways that the 
//`target` can be constructed by concatenating elements of the `wordBank`
//array.
//each element of the 2d array should represent one combination that
//constructs the `target`.
//yo may reuse elements of `wordBank` as many times as needed.
//

const allConstruct = (target, wordBank, memo = {} ) => {
	if ( target in memo ) return memo[target];
	if ( target.length === 0 ) return [[]];
	const result = [];
	for ( let word of wordBank ) {
		if ( target.indexOf(word) === 0 ) {
			const suffix = target.slice(word.length);
			const arrayHolder = allConstruct(suffix, wordBank, memo);
			const finalArray = memo[target] = arrayHolder.map(way => [word,...way]);
			result.push(...finalArray);
		}
	}
	return memo[target] = result;
}

console.log( allConstruct( "purple", ["purp", "p", "ur", "le", "purpl"]));
console.log( allConstruct( "abcdef", ["ab", "abc", "cd", "def", "abcd"] ) );
console.log( allConstruct( "skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar" ] ) );
console.log( allConstruct( "enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"] ) );
console.log ( allConstruct( "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
        "e",
        "ee",
        "eee",
        "eeee",
        "eeeee",
        "eeeeee"
]));

