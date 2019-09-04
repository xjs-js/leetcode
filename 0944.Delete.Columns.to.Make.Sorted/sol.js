
var A = ["cba", "daf", "ghi"]

var minDeletionSize = function(A) {
    let result = 0;

    for (let i = 0; i < A[0].length; ++i)
    {
        let tempArray = new Array();
        for (let j = 0; j < A.length; ++j)
        {
            tempArray.push(A[j][i]);
        }
    
        let beforeSort = tempArray.slice();
        let afterSort = tempArray.sort();
       
        if ( beforeSort.toString() !== afterSort.toString() ) {
            result += 1;
        }
    }
    return result;
};

var num = minDeletionSize(A);
console.log(num);
