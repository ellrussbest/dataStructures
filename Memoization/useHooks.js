// create a handler function
// a handler function is basically used to create
// a function that will return a function that will return
// an object e.g.

const handler = (deps) => () => {
  return {
    useThisHook: deps ? "This deps exists" : "This deps doesn't exist",
  };
};

// create a setup hook function
// this function is used to create a custom hook
// using the handler function

const setupHook = (deps) => {
  return handler(deps);
};

// create an object that will receive the above hook
const deps = true;
const obj = {
  getHook: setupHook(deps),
};

// create a usehook function
const useHook = (cb) => {
  const { getHook } = obj;
  return cb(getHook());
};

// getting the hook itself
const useThisHook = () => {
  return useHook((hooksObject) => hooksObject.useThisHook);
};

console.log(useThisHook());
