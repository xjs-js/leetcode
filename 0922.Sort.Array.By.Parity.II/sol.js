/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function(A) {
    const newArray  = new Array(A.length);

    let evenIndex = 0;
    let oddIndex  = 1;

    for (let num of A) {
        if (num % 2 === 1) { 
            newArray[oddIndex] = num;
            oddIndex += 2;
        } else {
            newArray[evenIndex] = num;
            evenIndex += 2;
        }
    }

    return newArray;
};

const newArray = sortArrayByParityII([4,2,5,7]);
console.log(newArray);