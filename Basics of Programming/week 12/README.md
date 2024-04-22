#### 任务描述

小花正在对一堆石头进行对撞实验：每次从所有石头中选出最重的两块石头进行对撞。对撞处理结果是: 如果两块一样重，则两块石头被完全撞碎；如果两块石头不一样重，那么对撞会剩下一块重量为两者之差的石头放回石头堆中。如此循环对撞。实验结果：如果剩下一块石头，则为此石头的重量；如果没有石头剩下，则为 0。请你设计C/C++程序，根据这堆石头中每块石头的重量计算实验结果。

#### 输入格式

第一行，一个正整数n（代表石头的个数）
第二行， n个正整数（代表每块石头的重量，<= 10000）

#### 输出格式

一行，一个正整数（代表最后剩下那块石头的重量）

#### 样例1

输入：
`5`
`5` `2` `7` `10` `10`
预期输出：
`0`

#### 任务描述

请你设计C/C++程序，对输入的一个算术表达式（字符串），检查其中的圆括号配对情况，如果配对则输出Y，否则输出N。（多左括号、多右括号或左右括号颠倒均算作不配对）。

#### 输入格式（2行）

第一行，一个正整数n（表达式的长度）
第二行，一个字符串

#### 输出格式

一个字母（要么是Y；要么是N）

#### 样例

输入：
15
(x+y) *)a+b(* (x-y)
预期输出：
`N`
解释：a+b两边的圆括号颠倒

请你设计C/C++程序，判别一个字符串是否为回文串（从左到右或者从右到左读起来都一样的字符串）。

#### 输入格式（1行）

一个字符串

#### 输出格式

一个字母（要么是Y；要么是N）

#### 样例1

输入：
level
预期输出：
`Y`

#### 样例2

输入：
895323598
预期输出：
`Y`

1. 用一个函数计算 main 函数中输入的一行字符中阿拉伯数字及大小写英文字母的个数，并用指针型参数将两类字符的个数传递给 main 函数输出。

   对内容非常熟悉

   目录非常清晰

   图片非常清楚

   部分ppt字体可以调大一些,（比如发展历史那张ppt）

   可以加一些数字在ppt上

1 1 1 1 1 1 1 1
1 0 0 1 1 0 0 1
1 0 0 0 0 0 0 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 0 0 0 0 0 0 1
1 0 0 1 1 0 0 1
1 1 1 1 1 1 1 1

![1701225753778](image/README/1701225753778.jpg)



1. 编程输出一个N阶（N为大于1的奇数）幻方。即在一个由N×N个方格组成的方阵中，填入1、2、3、...、N2各个数，使得每一行、每一列及两个对角线上的数之和均相等。例如，一个三阶幻方：
   8    1    6
   3    5    7
   4    9    2
   （填数方法提示：把1填在第一行最中间的格子中，然后依次将下一个数填在上一个数的右上角格子中。如果目标格子在第一行的上方，则填入该列的最后一行格子中；如果目标格子在最后一列的右方，则填入该行的第一列格子中；如果目标格子已经被占用，则填入当前格子的下方格子中。）




1. （分糖果）十个小孩围成一圈分糖果，每个小孩分得的糖果数依次为：10、2、8、22、16、4、10、6、14、20。然后所有的小孩同时将自己手中的糖果分一半给右边的小孩；块数为奇数的人可向老师要一块。问需要几次这样的调整后，小孩手中糖果的块数就都一样了？每人有多少块糖果？编程求解上述问题。提示：经过16次调整，每人有18块糖果。



1. （筛法求素数）首先假设 2 ~ n 之间所有的数从小到大排列在筛子中，然后从 2 开始依次将每个数的倍数从筛子中筛掉，最终输出筛子中剩下的数（均为素数）。



输入格式：
每个输入文件包含一个测试用例。对于每个案例，第一行包含两个数字：N（≤10^4）总客户数，和K（≤100）- 窗口数。接下来的N行，每行包含两个时间：HH:MM:SS  到达时间，以及P -客户的处理时间（以分钟为单位）。这里HH的范围是[00, 23]，MM和SS的范围是[00, 59]。假设没有两个客户在同一时间到达。
注意，银行的营业时间是从08:00到17:00。任何提前到达的客户都必须等到08:00才能办理业务，而任何太晚到达（在或之后的17:00:01）的客户将不会被服务或计入平均等待时间，17:00(包括17:00)之前的客户一定会被服务。

输出格式：
对于每个测试用例，打印所有顾客的平均等待时间，以分钟为单位，精确到小数点后1位。

测试说明
平台会对你编写的代码进行测试：

测试输入：
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

08:30:00
08 02 00
09 01 00
预期输出：
8.2

2 1 2 1 2 1 2
1 0 1 0 1 0 1
2 1 2 1 2 1 2
1 0 1 0 1 0 1
2 1 2 1 2 1 2
1 0 1 0 1 0 1
1 0 1 0 1 0 1
2 1 2 1 2 1 2