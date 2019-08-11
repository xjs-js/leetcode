# leetcode


## 2018-5-5  
最近在看这本书[Competitive Programmer's Handbook](https://cses.fi/book.pdf), 然后就来刷刷题。书看到了找子集、排列、贪心、回溯。到这里要写写代码。  

昨天突然发现前几名的代码都添加了几行一摸一样的代码，和书上写的差不多，优化输入输出的，我靠。顿时豁然开朗，为什么我的代码运行得那么慢，原来是这个原因.  

```cpp
using namespace std;

static vector<string> _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return vector<string>{};
}();

/* or this method */
static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

```

最近又不能刷题了，我还有7-8个实验要写，写不完就💊  

### 题目注释

#### 0890.Find and Replace Pattern

昨晚没写完，逻辑很乱，下次还是用两个map吧，那样肯能简单一点。