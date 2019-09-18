/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    // Get a copy of original Array Object
    const heightsCopy = heights.slice();

    // then sort
    heightsCopy.sort((a, b) => { return a <= b ? -1 : 1 });

    // last walk through the Array, find different elements
    let counter = 0;
    for (let i = 0; i < heights.length; ++i) {
        if (heights[i] !== heightsCopy[i]) {
            counter += 1;
        }
    }

    return counter;
};

console.log(heightChecker([10,6,6,10,10,9,8,8,3,3,8,2,1,5,1,9,5,2,7,4,7,7]));