第2关：滚雪球-链表
300
任务要求
评论
任务描述
返回值
注意
输入
输出
样例1
样例2
某日，在NJU的某个小山坡上，有一个n*m大小的网格，每个网格的单元格有三种类型。：
1.空网格，用.表示
2.一个雪球，用o表示
3.一个障碍物，用#表示
所有的雪球会从上往下滚，直到碰到坡底（网格最下面一行），或碰到一个障碍物，或碰到其他不能再往下滚的雪球。
给出一个网格的初始状态，当雪球都不能再滚动时，网格最终会变成什么样？

任务描述
你需要设计函数get_snowball_grid，根据输入的n，m和字符（从标准输入流中读取），返回最终的网格。

struct Node{
    char unit_type; // 单元类型
    Node *top; // 上面的节点
    Node *bottom; // 下面的节点
    Node *left; // 左边的节点
    Node *right; // 右边的节点
};
Node* get_snowball_grid(){
    // write your code here......
}
返回值
返回一个指针，指向最终状态网格的最左上的节点。

注意
对于位于网格边界的节点，使用NULL填充指向边界外的指针。比如最左上节点的top和left为NULL。

输入
第一行包含整数n和m（1≤n,m≤50），为网格的大小，接下来n行，每行包含m个字符，每个字符为.，o，#其中之一。

输出
输出最终的网格状态。

样例1
输入：

4 6
...o..
o..o.o
......
.o...o
最终状态：

......
......
...o.o
oo.o.o
样例2
输入：

7 11
.o.o....o..
.o........o
...#..o.#..
.o.o.#..o..
.....o...o.
...o.o...#.
.#......#.o
最终状态：

...........
...o....o..
...#....#..
.o...#.....
.o.......o.
.o.o.o..o#o
.#.o.oo.#.o

4 4
1 2 3 4
5 6 7 8
9 a b c
d e f g

# 单词背诵

## 题目描述

灵梦有 $n$ 个单词想要背，但她想通过一篇文章中的一段来记住这些单词。

文章由 $m$ 个单词构成，她想在文章中找出连续的一段，其中包含最多的她想要背的单词（重复的只算一个）。并且在背诵的单词量尽量多的情况下，还要使选出的文章段落尽量短，这样她就可以用尽量短的时间学习尽可能多的单词了。

## 输入格式

第 $1$ 行一个数 $n$，接下来 $n$ 行每行是一个长度不超过 $10$ 的字符串，表示一个要背的单词。

接着是一个数 $m$，然后是 $m$ 行长度不超过 $10$ 的字符串，每个表示文章中的一个单词。

## 输出格式

输出文件共 $2$ 行。第 $1$ 行为文章中最多包含的要背的单词数，第 $2$ 行表示在文章中包含最多要背单词的最短的连续段的长度。

## 样例 #1

### 样例输入 #1

```
3
hot
dog
milk
5
hot
dog
dog
milk
hot
```

### 样例输出 #1

```
3
3
```

## 提示

### 数据规模与约定

- 对于 $30\%$ 的数据，$n \le 50$，$m \le 500$；
- 对于 $60\%$ 的数据，$n \le 300$，$m \le 5000$；
- 对于 $100\%$ 的数据，$n \le 1000$，$m \le 10^5$。

给定一个字符串 `s` ，请你找出其中不含有重复字符的 **最长子串 **的长度。

**示例 1:**

<pre><strong>输入: </strong>s = "abcabcbb"
<strong>输出: </strong>3 
<strong>解释:</strong> 因为无重复字符的最长子串是 <code>"abc"</code>，所以其长度为 3。
</pre>

**示例 2:**

<pre><strong>输入: </strong>s = "bbbbb"
<strong>输出: </strong>1
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"b"</code>，所以其长度为 1。
</pre>

**示例 3:**

<pre><strong>输入: </strong>s = "pwwkew"
<strong>输出: </strong>3
<strong>解释: </strong>因为无重复字符的最长子串是 <code>"wke"</code>，所以其长度为 3。
     请注意，你的答案必须是 <strong>子串 </strong>的长度，<code>"pwke"</code> 是一个<em>子序列，</em>不是子串。
</pre>

**提示：**

* `0 <= s.length <= 5 * 10<sup>4</sup>`
* `s` 由英文字母、数字、符号和空格组成




将一个给定字符串 `s` 根据给定的行数 `numRows` ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 `"PAYPALISHIRING"` 行数为 `3` 时，排列如下：

```
P   A   H   N
A P L S I I G
Y   I   R
```

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"PAHNAPLSIIGYIR"`。

请你实现这个将字符串进行指定行数变换的函数：

```
string convert(string s, int numRows);
```

**示例 1：**

<pre><strong>输入：</strong>s = "PAYPALISHIRING", numRows = 3
<strong>输出：</strong>"PAHNAPLSIIGYIR"
</pre>

 **示例 2：**

<pre><strong>输入：</strong>s = "PAYPALISHIRING", numRows = 4
<strong>输出：</strong>"PINALSIGYAHRPI"
<strong>解释：</strong>
P     I    N
A   L S  I G
Y A   H R
P     I
</pre>

**示例 3：**

<pre><strong>输入：</strong>s = "A", numRows = 1
<strong>输出：</strong>"A"
</pre>

**提示：**

* `1 <= s.length <= 1000`
* `s` 由英文字母（小写和大写）、`','` 和 `'.'` 组成
* `1 <= numRows <= 1000`




给你一个字符串数组，请你将 **字母异位词** 组合在一起。可以按任意顺序返回结果列表。

**字母异位词** 是由重新排列源单词的所有字母得到的一个新单词。

**示例 1:**

<pre><strong>输入:</strong> strs = <code>["eat", "tea", "tan", "ate", "nat", "bat"]</code>
<strong>输出: </strong>[["bat"],["nat","tan"],["ate","eat","tea"]]</pre>

**示例 2:**

<pre><strong>输入:</strong> strs = <code>[""]</code>
<strong>输出: </strong>[[""]]
</pre>

**示例 3:**

<pre><strong>输入:</strong> strs = <code>["a"]</code>
<strong>输出: </strong>[["a"]]</pre>

**提示：**

* `1 <= strs.length <= 10<sup>4</sup>`
* `0 <= strs[i].length <= 100`
* `strs[i]` 仅包含小写字母
