// 编写一个c语言函数，名为 reversewordsInsentence ,该函数接收一个字符数组(字符串)作为参数，该字符串代表一个句子。
// 句子中可能包含空格和标点符号。你的任务是反转句子中的每个单词的顺序，但保持单词内部的字符顺序不变，同时保持句子中单词的相对位置不变。
// 注意，你需要在原地修改输入的字符串，且不得使用额外的字符串缓冲区。

//void reverseWordsInSentence(char *sentence)
// 输
// sentence:一个以 \0 结尾的字符串，表示一个句子,
// 输出// 修改输入的 sentence使得其中的单词顺序被反转。示例假设函数被调用如下:
// char sentence[]="Hello, world! This is a test.";

//reversewordsInSentence(sentence);// printf("%s",sentence);//应输出:"test. a is This world! Hello,
#include "stdio.h"
#include "string.h"
void reversewordsInsentence(char *s)
{ 
    int n = strlen(s);

    //步骤1: 反转整个字符串
    int start = 0;
    int end = n - 1;
    while (start < end) 
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    // 步骤2: 反转每个单词
    start = 0;
    for (int i = 0; i <= n; i++) 
    {
    // 找到单词的结尾
        if (s[i] == ' ' || s[i] == '\0') 
        {
            int wordEnd = i - 1;
            // 反转当前单词
            while (start < wordEnd) 
            {
                char temp = s[start];
                s[start] = s[wordEnd];
                s[wordEnd] = temp;
                start++;
                wordEnd--;
                // 更新start到下一个单词的起始位置
                start = i + 1;
            }
        }
    }
    //输出修改后的句子
    printf("%s\n", s);
}


int main()
{
    char sentence[]="Hello, world! This is a test.";
    reversewordsInsentence(sentence);
    return 0;
}