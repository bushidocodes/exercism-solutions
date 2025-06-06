export const promisify = (fn) => {
  return (arg) => new Promise((resolve, reject)=>{
    return fn(arg, (err, val) => {
      if (err != null) {
        reject(err);
      } else {
        resolve(val);
      }
    });
  })
};

export const all = (promiseChain) => {
  return new Promise(async (resolve, reject) => {
    if (promiseChain === undefined || promiseChain.length === 0) {
      resolve(promiseChain);
      return;
    }

    let finalResults = [];
    try {
      for (let promise of promiseChain) {
        const result = await promise;
        finalResults.push(result);
      }
    } catch (err) {
      reject(err);
    }
    resolve(finalResults);
  });
};

export const allSettled = (promiseChain) => {
  return new Promise(async (resolve, reject) => {
    if (promiseChain === undefined || promiseChain.length === 0) {
      resolve(promiseChain);
      return;
    }

    let finalResults = [];
    try {
      for (let promise of promiseChain) {
        const result = await promise;
        finalResults.push(result);
      }
    } catch (err) {
      finalResults.push(err);
    }
    resolve(finalResults);
  });
};

export const race = (promises) => {
  return new Promise(async (resolve, reject) => {
    if (promises === undefined || promises.length === 0) {
      resolve(promises);
      return;
    }
    
    let didReturn = false;
    for (let promise of promises) {
      promise.then(res => {
        if (!didReturn){
          resolve(res);
          didReturn = true;
        }
      }).catch((err) => {
        if (!didReturn){
          reject(err);
          didReturn = true;
        }
      })
    }
  });
};

export const any = (promises) => {
  return new Promise(async (resolve, reject) => {
    if (promises === undefined || promises.length === 0) {
      resolve(promises);
      return;
    }

    let didResolve = false;
    let errors = [];
    for (let promise of promises) {
      promise.then(res => {
        if (!didResolve){
          resolve(res);
          didResolve = true;
        }
      }).catch((err) => {
        if (!didResolve) {          
          errors.push(err);
          if (errors.length == promises.length){
            reject(errors);
          }}
      })
    }
  });
};
