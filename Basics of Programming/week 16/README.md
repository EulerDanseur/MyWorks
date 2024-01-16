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

# sql

SQL（StructuredQuery Language）是一种用于管理关系型数据库的编程语言。在本题目中，我们将介绍 SQL 的一个简化版本 SQL-Minus，并使用 C 语言实现一个 SQL-Minus 解释器（SQL-Minus Interpreter，SMI）。

在本项目中，我们将实现一个简易的数据库，并在数据库中维护若干存放数据的表格。你的程序需要读取一段 SQL-Minus 程序，并根据读入的指令，完成下面的操作：在数据库中创建一个表，向表中插入数据，删除表中的数据，修改表中的数据，以及查询表格中符合条件的数据。

SQL 数据库基础知识

数据库（database）：数据库包含多个基本表，通常来说一个数据库对应一个应用。

基本表（table）：一张二维表格，有多个行和列。每一行也称作一条记录，每一列也称作一个字段；

字段（field）：字段具有字段名和字段类型，用于标记该列中的数据特征。比如，一个名为 njuid，类型为 INT 的字段，表示这一列存储的是 INT 类型的学号；

记录（record）：记录是基本表中的一行，用于存储一条数据。比如，一条记录为 (201250172，"熊丘桓"，"软件学院")，其中第一个字段为
学号，第二个字段为 姓名，第三个字段为 院系；

主键（primary key）：主键是一种特殊的字段，用于标记一条记录的唯一性。通常来说，主键需要能够与记录一一对应，也就是通过主键可以找到唯一的一条记录；例如，在全校学生信息中，学号是学生记录的主键。

基本表和字段名称均为只含大小写字符和下划线的字符串，且和关键字不冲突。名称长度均不超过
32 个字符。

例如，下表是一个具体的基本表，每行是一个记录，每列是一个字段（其实也可以说每个单元格是每个记录的一个字段），其中学号是基本表的主键。

学号（主键，唯一且非空）       姓名       院系       爱好

201250172     熊丘桓    软件学院       写代码

221900029     王思齐    技术科学实验班    NULL

ant-hengxin  蚂蚁蚂蚁       软件学院       备课讲课

201250114     LabelrayUniversity of Wisconsin–Madison      打麦麦

SQL-Minus 基本语法

约定

为了降低小朋友们的作业难度，我们 对 SQL-Minus 做了如下约定：

一条 SQL-Minus 语句一般以分号 ; 结尾，但程序最后一条 SQL 语句可以不以 ; 结尾；

SQL-Minus 程序包括若干条
SQL-Minus 语句，并可以包含若干空格和换行符；

SMI 中，我们不需要考虑多个数据库；

所有 SQL 关键字全部大写；

SMI 的测试数据中的所有字符串均只包括 ASCII 字符，不包括中文等其他语言的字符，字符串中可能包含 !@#$等特殊字符，但不会有换行符。特别地，字符串中可能出现 ;，也可能出现转义的引号 \'。

关键字集合包括：

key_word = {"INT",
"CHAR", "CREATE", "TABLE", "PRIMARY",
"KEY", "NOT", "NULL", "UNIQUE",
"INSERT", "INTO", "VALUES", "DELETE", "FROM",
"WHERE", "UPDATE", "ORDER", "BY",
"ASC", "DESC", "AND", "OR",
"BETWEEN", "IS"};

如无特殊说明，以下语法内容都是 SQL-Minus 语言标准，不代表 SQL 标准。如果小朋友们想要了解 SQL 标准，可以简单浏览助教的课程笔记：数据库系统概论-03-关系数据库标准语言 SQL，尽管助教认为这对 SQL-Minus 的实现并不会有什么帮助。

创建基本表

在数据库中创建一张空的基本表，并指定表名和字段信息。语句格式为：

CREATE TABLE <table_name> (

<field_name1> <field_type1> [NOT NULL] [PRIMARY KEY]
[UNIQUE]

[,<field_name2> <field_type2> [NOT NULL] [PRIMARY KEY]
[UNIQUE]]

...

);

如何阅读语句格式的描述？

尖括号内的是子句的名称，相应的子句。子句会在下面的文字中给出描述。

方括号内的为可选部分，表示对应位置可以出现括号内的部分，也可以不出现任何内容，方括号可以嵌套，表示在外层出现的情况下，内层内容也可以不出现。

省略号永远跟在方括号后，表示前面一个方括号中的内容可以重复任意多次。

其他内容（空白符除外）在合法的语句中出现。

其中，<field_name1> 是字段名称，<field_type1> 是字段类型。在 SMI 中，只有 INT 和 CHAR(N) 两种字段类型。其中，INT 为 32 位有符号整数，CHAR(N)
表示长度为 N 的定长字符串（SQL 中字符串长度不包括终止字符 \0）。此外，值也可以为 NULL，表示空值。

定长字符串并不意味着长度字符串的长度严格等于 N ，比如 'abc' 也属于 CHAR(5) 类型，只是省略了末尾的空白字符（相当于C语言中的 "abc\0\0"），但 'abcdef' 不属于 CHAR(5) 类型。

字符串类型应按字典序比较，实现方法可以参考 strcmp 函数。

在 SQL 标准中，字段类型还有很多很多，包括但不限于 DATE、TIME 等。

其中，PRIMARY KEY 表示该字段为主键，NOT NULL 表示该字段不允许为空，UNIQUE 表示该字段的值在所有记录中唯一。在 SQL-Minus 中，创建基本表时必须显式声明唯一一个主键。

根据 SQL 标准，创建表时可以选择不定义主键。这将使表成为一个没有主键约束的普通表。在这种情况下，表中的每一行都可以具有重复的值，包括 NULL 值。

声明了 PRIMARY KEY 的字段隐含了 NOT NULL 和 UNIQUE，也就是说，只要指定为 PRIMARY KEY，字段必须非空且唯一。只能有一个字段被指定为 PRIMARY
KEY，否则执行错误。

假如表格已经存在，该语句执行错误。

成功创建表格后，输出一行：CREATE TABLE SUCCESSFULLY。

SQL 标准允许用户删除和修改基本表，SMI
不提供这一功能。

插入记录

向表格中添加一条记录。语句格式为：

INSERT INTO <table_name> VALUES
(`<value1>` [, `<value2>`] ...);

若表格不存在，语句执行失败。

其中，`<value1>`，`<value2>`，... 为按顺序排列的字段值。若字段值的数量与字段数量不匹配，语句执行失败。

对插入的记录的每个字段，检查字段类型、主键和其他约束条件。

若检查失败，语句执行失败。

成功插入记录后，输出一行 `<count>` RECORDS INSERTED，其中 `<count>` 为一个整数，表示插入记录数量。

聪明的小朋友已经发现，我们在 SMI 中，一条语句最多只能插入一条记录。

SMI 不需要支持将查询结果存入基本表这一功能。

SQL-Minus 不允许只插入到部分指定字段，必须按照创建字段的顺序一次全部显式插入所有字段。

删除记录

从表格中删除符合条件的记录。语句格式为：

DELETE FROM <table_name> WHERE
<condition_clause>;

其中，<condition_clause> 是条件子句，将在下文中详细介绍。

<table_name> 为表名，若表格不存在，语句执行失败。

成功删除记录后，输出一行 `<count>` RECORDS DELETED，其中 `<count>` 为一个整数，表示删除记录数量。

如果没有符合条件的记录，输出一行 0 RECORDS DELETED。

更新记录

更新表格中符合条件的记录。语句格式为：

UPDATE <table_name> SET
`<field1>` = `<value1>` [,`<field2>` = `<value2>`] ... WHERE
<condition_clause>;

同上，条件子句 <condition_clause> 将在下文中详细介绍。

在 SQL-Minus 中，`<value1>`
为常量，不包括变量和表达式。

若表格不存在，执行错误。

对更新的记录的每个字段，检查字段名称、类型、主键和其他约束条件。

若检查失败，语句执行失败。

成功更新记录后，输出一行 `<count>` RECORDS UPDATED，其中 `<count>` 为一个整数，表示更新记录数量。

如果没有符合条件的记录，输出一行 0 RECORDS UPDATED。

查询记录

查询表格中符合条件的记录。语句格式为：

SELECT < `<field1>` [, `<field2>`]
...| *> FROM <table_name> [WHERE <condition_clause>] [ORDER BY
`<field1>` [ASC|DESC][, `<field2>` [ASC|DESC]] ... ];

同上，条件子句 <condition_clause> 将在下文中详细介绍。

可以用 * 代替字段名，此时需要查询所有字段。

SELECT 语句中可以省略
WHERE ，此时查询所有记录。

若表格不存在，执行错误。

若查询的字段中有不存在的字段，执行错误。

查询成功后，你首先需要输出一行 `<count>` RECORDS FOUND，其中 `<count>` 为一个整数，表示查询到的记录数量；如果没有符合条件的记录，输出一行 0 RECORDS FOUND。

如果 `<count>` 不为
0，你还需要输出查询到的记录。

首先输出一行字段名，用制表符 \t 分割。

ORDER BY 子句指定了对查询结果排序规则。默认或指定 ASC 为升序，指定 DESC 则降序。先按照 `<field1>` 排序，`<field1>` 相同的按照 `<field2>` 排序，以此类推。各字段都相同的，按主键升序排序。记录中的各个字段用制表符 \t 分割。

然后输出 `<count>` 行记录。若未指定排序规则，则按主键升序排序。在 SMI 中，无论升序还是倒序，当前待排序字段为 NULL 的记录应该被排在最后。

有些 SQL 的版本支持使用
NULLS FIRST 和 NULLS LAST 显式处理对空值的排序问题，但 SQL 标准并未规定应该如何实现。

SQL 标准支持 GROUP,
DISTINCT, AS 等关键字功能，在 SMI 中不需要支持此功能。

SMI 不需要支持链接查询、嵌套查询和集合查询。

条件子句

条件子句是一个逻辑表达式，用于判断一条记录是否符合特定的筛选条件。

逻辑表达式使用 BNF 范式定义如下：

# 逻辑运算符

logic_operator := AND | OR

# 比较运算符

cmp_operator := = | <> | < | >
| <= | >=

# 常量

const := '`<STRING>`' | `<INT>`

# 可比较的值

ordered_value := `<field>` |
`<const>`

# 原子子句

automic_clause := <ordered_value>
<cmp_operator> <ordered_value> |

<ordered_value> BETWEEN <ordered_value> AND
<ordered_value> |

<ordered_value> IS NULL |

<ordered_value> IS NOT NULL |

(<condition_clause>)

# 可否定子句

negatable_clause := <automic_clause>
| NOT <negatable_clause>

# 可合取子句

conjunctable_clause :=
<negatable_clause> | <negatable_clause> AND
<conjunctable_clause>

# 条件子句

condition_clause :=
<conjunctable_clause> | <conjunctable_clause> OR <condition_clause>

如何阅读 BNF 范式？

:= 表示定义为，即约定左边名称的子句必须符合右边的形式。

`<clause>` 表示必选子句，即此处必须出现符合 clause 语法的子句。

`<clause1>` | `<clause2>` 表示或，即此处应当出现符合 clause1 或 clause2 语法的语句。

BNF 中子句可以递归定义。

在 SQL-Minus 中，不支持类型转换和比较不同类型的值。因此在对条件子句求值时，应该先检查数据的类型是否一致，对类型不一致的值的比较操作应产生执行错误。即使对 NULL 值，也应该先检查其所属字段的类型。

SQL-Minus 对空值的逻辑判断与
SQL 相同，可参考：SQL 中的空值。

SQL 中允许用双引号或单引号作为字符串表示，SQL-Minus 中只允许使用单引号。

SMI 不需要实现 IN 条件子句。

SQL 中有 BOOL 类型的数据，因此存在常量 TRUE 和 FALSE 以及
BOOL 型字段可以作为一个条件子句的情况。但在 SQL-Minus 中，没有 BOOL 类型，TRUE 和
FALSE 也就不会作为条件子句。在 SQL-Minus 中，这样的写法是一个未定义行为，你可以自己决定形如 WHERE TRUE AND 'a' 这样的语句如何执行，但测试数据中一定不会出现这样的写法。

ANSI SQL 并没有规定逻辑运算是否“短路”，但 SQL-Minus 中不存在短路。也就是说，必须在逻辑运算前求出运算符两边的值，即使是 TRUE OR X 这样的表达式，也需要求出 X 的真假。

一致性

本来打算在本题基础上另外出一道关于 SQL-Minus 事务一致性的附加题，但是这学期可能来不及了。有兴趣的小朋友可以在寒假完成，不计入课程分数。

对该课题感兴趣的小朋友请和熊丘桓助教联系，欢迎一起为国产基础软件降本增效贡献力量！

异常处理

语法错误：当前 SQL-Minus 语句不符合 SQL-Minus 语法时，输出一行 SYNTAX ERROR；

其他错误：当前 SQL-Minus 语句符合 SQL-Minus 语法，但不能正确执行时，输出一行 ERROR。

无论当前语句遇到什么错误，都应该在处理错误之后继续执行下一条语句。在本题中，除了最后一条语句，所有语句以 ;结尾（包括语法错误的语句）。

关于测试用例

这不是考试题，因此请不要妄想使用欺骗或投机的手段骗取部分分数。只输出错误信息不会得到任何分数，尽管助教鼓励小朋友们在考场上进行这样的尝试。

评分规则

受限于助教们手搓测试用例的速度，整个项目过程中助教可能会对该题修改和增加测试用例，项目分数以最终测试用例占比情况为准。当然，正确的代码一定可以通过所有的测试用例。

在项目截止日期的 72 小时以内，助教不会添加新的测试用例。

例如：张三同学的代码提交后通过了现有 10 个测试用例当中的 8 个，OJ 显示其得到了 80 分的好成绩。但两天后测试用例增加到了 20 个，张三同学的代码只通过了其中的 12 个测试用例，则张三同学的最终项目 OJ 得分为 60 分。

最终计入课程总评的项目得分不一定等于项目 OJ 得分，助教会根据测试用例难度调整项目得分。为了保证公平，助教保证选择该作业的所有同学的项目得分与项目 OJ 得分的相对位次相同，并且保证项目 OJ 得分为满分的同学项目得分为满分。

数据范围约定

在最终测试用例中：

对于所有测试用例，表格数量

1

≤

�

≤

1000

1≤T≤1000， 字段数

1

≤

�

≤

256

1≤F≤256，单个语句不超过

2048

2048 字符；

至少 50% 的测试用例没有语法错误；

至少 50% 的测试用例只有一个基本表；

至少 80% 的测试用例不会在一个
condition_clause 中出现多个 `<field>`；

至少 80% 的测试用例不会在
SELECT 语句中出现 ORDER BY；

至少 80% 的测试用例在
SELECT 中只会查询所有字段（即 *）;

至少 50% 的测试用例不涉及空值；

一些测试用例没有 DELETE 语句；

一些测试用例没有 UPDATE 语句；

少部分测试用例没有 SELECT 语句。

以上测试用例限制有交叉。

输入格式

若干行，一段 SQL-Minus 程序。

输出格式

对每一条语句进行响应。即使某条语句出现错误，也应继续执行后续语句。

测试样例

Input

CREATE TABLE student (

student_id INT PRIMARY KEY,

student_name CHAR(20),

student_age INT

);

INSERT INTO student VALUES (1, 'Bob', 22);

INSERT INTO student VALUES (2, 'Alice',
NULL);

Output

CREATE TABLE SUCCESSFULLY

1 RECORDS INSERTED

1 RECORDS INSERTED

题目注解

部分小朋友关于 SQL 的语法细节还有疑惑，我们为大家提供了在线执行 SQL 的网站：在线SQL - 廖雪峰的官方网站 (liaoxuefeng.com)和Oracle Live SQL。值得注意的是，SQL-Minus 和 SQL 不完全相同，假如在线 SQL 的行为与 SQL-Minus 的约定矛盾，应首先满足 SQL-Minus 的约定。

补充样例

由于制表符在此处显示时会被替换成空格，下面的样例中存在格式问题。样例文件可以在这里下载（包含下面的样例和较大的样例3、样例4）。

Input 1

CREATE TABLE student (

student_id INT PRIMARY KEY,

student_name CHAR(20) NOT NULL,

student_age INT

);

INSERT INTO student VALUES (1, 'Bob', 22);

INSERT INTO student VALUES (2, 'Alice',NULL);

INSERT INTO student VALUES (3, NULL, 20);

SELECT * FROM student ORDER BY student_id;

SELECT * FROM student ORDER BY
student_name;

SELECT * FROM student ORDER BY student_age;

Output 1

CREATE TABLE SUCCESSFULLY

1 RECORDS INSERTED

1 RECORDS INSERTED

ERROR

2 RECORDS FOUND

student_id    student_name    student_age

1
'Bob'    22

2
'Alice'    NULL

2 RECORDS FOUND

student_id    student_name    student_age

2
'Alice'    NULL

1
'Bob'    22

2 RECORDS FOUND

student_id    student_name    student_age

1
'Bob'    22

2
'Alice'    NULL

Input 2

CREATE TABLE student (

student_id INT PRIMARY KEY,

student_name CHAR(20) PRIMARY KEY,

student_age INT

);

SELECT ababab;

INSERT INTO student VALUES (2, 'Alice',
NULL);

Output 2

CREATE TABLE SUCCESSFULLY

SYNTAX ERROR

1 RECORDS INSERTED
