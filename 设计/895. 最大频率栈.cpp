895. 最大频率栈

实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

FreqStack 有两个函数：

push(int x)，将整数 x 推入栈中。
pop()，它移除并返回栈中出现最频繁的元素。
如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。

示例：

输入：
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
输出：[null,null,null,null,null,null,null,5,7,5,4]
解释：
执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

pop() -> 返回 5，因为 5 是出现频率最高的。
栈变成 [5,7,5,7,4]。

pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
栈变成 [5,7,5,4]。

pop() -> 返回 5 。
栈变成 [5,7,4]。

pop() -> 返回 4 。
栈变成 [5,7]。

=========================================

题解：

这道题目的关键是设计一个hashmap将相同频率的数值存为一组。
另外设计一个hashmap记录数值到频率的mapping。

class FreqStack {
public:
    FreqStack() {

    }
    
    void push(int x) {
        ++freq[x];
        mxFreq = max(mxFreq, freq[x]);
        m[freq[x]].push_back(x);
    }
    
    int pop() {
        int x = m[mxFreq].back();
        --freq[x];
        m[mxFreq].pop_back();
        if (m[mxFreq].empty()) --mxFreq;
        return x;
    }

private:
    int mxFreq;
    unordered_map<int, int> freq; // val->freq;
    unordered_map<int, vector<int>> m; // freq->vector of same freq
};

