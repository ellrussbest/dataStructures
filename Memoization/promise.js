const division = (a, b) => {
    if ( b == 0 ) return "error";
    return a/b;
}

const asyncFunc = (division) => {
    return new Promise ( (resolve, reject) => {
        if ( division == "error" ) {
            reject(division);
        }else{
            setTimeout( () => {
                resolve(division);
            }, 1000);
        }
    });
}

asyncFunc( division(3, 3) )
.then( (resolved) => {
    console.log(`The quotient is ${resolved}`);
    return asyncFunc( division(6, 3));
}, (rejected) => {
    console.log(rejected);
}).then ( (resolved) => {
    console.log(`The quotient is ${resolved}`);
}, (rejected) => {
    console.log(rejected);
});

console.log("End");

const recordVideoOne = new Promise( (resolve, reject) => {
	resolve('video 1 recorded');
});


const recordVideoTwo = new Promise ( (resolve, reject) => {
	resolve('Video 2 recorded');
});

const recordVideoThree = new Promise ( (resolve, reject) => {
	resolve('Video 2 recorded');
});

Promise.all([
	recordVideoOne,
	recordVideoTwo,
	recordVideoThree
]).then( (resolved) => {
	console.log(resolved)
});

// we also have Promise.race - this on the other hand, will return the first promise to complete execution. It is almost the same to Promise.all but it returns the first promise in the array of promises to be completed.
