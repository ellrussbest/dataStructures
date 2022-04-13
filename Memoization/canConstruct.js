//write a function `canConstruct(target, wordbank)` that accepts a target
//string and an array of strings.
//the function should return a boolean indicating whether or not the
//`target` can be constructed by concatenating elements of the `wordBank`
//array
//
//you may reuse elements of `wordbank` as many times as needed.
//

const canConstruct = (target, wordbank, memo = {}) => {
	if ( target in memo ) return memo[target];
	if ( target.length === 0 ) return true;

	for ( let word of wordbank) {
		if ( target.indexOf(word) === 0 ){
			const remainder = target.slice(word.length)

			if ( canConstruct ( remainder, wordbank, memo ) ) return memo[target] = true;
		}else memo[target] = false;
	}
	return memo[target] = false;
}

console.log( canConstruct( "abcdef", ["ab", "abc", "cd", "def", "abcd"] ) );
console.log( canConstruct( "skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar" ] ) );
console.log( canConstruct( "enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"] ) );
console.log ( canConstruct( "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
	"e",
	"ee",
	"eee",
	"eeee",
	"eeeee",
	"eeeeee"
]));
