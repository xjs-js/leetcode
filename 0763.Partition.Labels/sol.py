class Solution:
    def partitionLabels(self, S: str):
        ```
        Parameters:
            S - input string

        Returns:
            A list of each partition string lengths
        ```
        List = []
        
        # 字符串的长度为1
        if len(S) == 1 :
            List.append(1)
            return List
        
        # 字符串的长度大于1
        elif len(S) > 1 :
            
            start = 0                            # 开始标志
            
            while True:
                curStart = start
                
                # 跳出循环，直接返回
                if (start >= len(S)) :
                    break;
                
                end = S.rfind(S[start], start+1)   # 最右边能找到的相同的字符
                
                if (end == -1) :
                    List.append(1)
                    start = start + 1
                else :
                    # 开始移动start直到End的位置
                    # 先移动一个位置
                    start = start + 1
                    # 判断边界
                    while start < end:
                        findResult = S.rfind(S[start], start+1)
                        if ( findResult > end ) :
                            end = findResult
                        # 一个循环内递增
                        start = start + 1
                    List.append(end-curStart+1)
                    # 下一个外层循环
                    start = start + 1      
            
            return List
                    
