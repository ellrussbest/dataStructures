function newFunc(...deps) {
  const sum = deps.reduce((acc, current) => {
    return (acc += current);
  }, 0);

  return sum;
}

function returnNewFunc(...deps) {
  return newFunc(...deps);
}

console.log(returnNewFunc(10, 20));
