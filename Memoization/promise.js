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
