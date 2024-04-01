任务描述：
有一种奇怪的方言，语言本身由26个小写英文字母构成，任何学过英语的人都看不懂这个语言在表达什么，但该语言与英语的英文字母之间存在双射关系。

例如，若有如下的对应关系：‘a’→‘y’，’o’→‘e’，‘z’→‘q’，从中可推断那么该方言中“y qee”的意思是“a zoo”。（此处仅为示例，不代表真实的映射关系）。

现在给出一些该方言与英语之间的对应语句对，请尝试将新的方言语句翻译成英语语句。

第1行一个整数n(1≤n≤20)，表示方言语句的个数。第2行两个字符串，表示方言和英语的对应关系，空格隔开(第一个字符串是英语，第二个是方言，保证每个字母在方言或英语中只出现一次，且是双射关系，一一对应)。第3到n+2行每行一个字符串，表示一条方言(字符串长度小于300)。

一共n行，每一行表示对应方言所代表的英语语句。
Sample
Input:
2
abcdefghijklmnopqrstuvwxyz ynficwlbkuomxsevzpdrjgthaq
seneia jsicpdrysid rbcx dksfc rbca ypc dvcyoksl xadrcpkcd ks rbc dvkpkr
tbeeeeeeeeeeeeeeeeeeeyyyyyyyyy k oset f vmjd vmjd

Output:
nobody understands them since they are speaking mysteries in the spirit
whoooooooooooooooooooaaaaaaaaa i know c plus plus

提示：可以使用cin.ignore()忽略输入第二行的'\n'，从而不影响用getline读入后续的方言句子。
