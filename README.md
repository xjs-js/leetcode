# leetcode


## 2018-5-5  
最近在看这本书[Competitive Programmer's Handbook](https://cses.fi/book.pdf), 然后就来刷刷题。书看到了找子集、排列、贪心、回溯。到这里要写写代码。  

昨天突然发现前几名的代码都添加了几行一摸一样的代码，和书上写的差不多，优化输入输出的，我靠。顿时豁然开朗，为什么我的代码运行得那么慢，原来是这个原因.  

```cpp
static vector<string> _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return vector<string>{};
}();

/* or this method */
static int _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

```   

最近又不能刷题了，我还有7-8个实验要写，写不完就💊  
