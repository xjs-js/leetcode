/**
 * @date: 2021-04-01
 * @talk: 时间一晃而过来到了四月分
 */

class Solution {
public:
    /**
     * 使用模拟的方法，来进行计算
     * 每个 * / + 视为一组，将计算的结果进行相减
     */
    int clumsy(int N) {
        if (N == 1) {
            return 1;
        }

        int beg = N - 1;    // 运算符后面的数字
        int op = 0;         // 当前的运算符 0: *, 1: /, 2: +, 3: - 
        uint64_t curResult = 0;     // 当前一组的结果
        uint64_t totalResult = 0;   // 累计的答案，最终返回的结果

        // beg从N-1一直减到1
        while (beg >= 1) {
            if (op == 0) {              // 乘法
                curResult = (beg + 1) * (beg);
            } else if (op == 1) {       // 除法
                curResult = curResult / beg;
            } else if (op == 2) {       // 加法
                if (totalResult == 0) { // 第一次
                    curResult = curResult + beg;
                    totalResult = curResult;
                } else {                // 第一次之后
                    curResult = curResult - beg;
                    totalResult -= curResult;
                }
                curResult = 0;
            } else if (op == 3 && beg == 1) {   // 特殊的情况
                totalResult -= 1;
            }

            op = (op + 1) % 4;
            --beg;
        }

        // 最后一组没结束的，没有到+的
        if (curResult != 0) {
            if (totalResult == 0) {
                totalResult = curResult;
            } else {
                totalResult -= curResult;
            }
        }

        return totalResult;
    }
};