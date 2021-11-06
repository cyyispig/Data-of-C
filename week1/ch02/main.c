#include <stdio.h>
#include <string.h>
 
char puzzle[4][4] = {
    {'t','h','i','s'},
    {'w','a','t','s'},
    {'o','a','h','g'},
    {'f','g','g','t'}
};
 
char *dict[4] = {"this","two","fat","that"};
 
int wordExist(int x, int y, int dir, int strlen, char *word);
 
int main()
{
    char word[5];
    int x, y, dir, strlen;
 
    for(x = 0;x < 4;x++){
        for(y = 0;y < 4;y++){
            for(dir = 0;dir < 8;dir++){
                for(strlen = 2;strlen < 5;strlen++){
                    // 坐标 x y
                    // 方向 dir
                    // 单词长度从2开始
                    if(wordExist(x, y, dir, strlen, word) == 1){
                        printf("存在: %s\n",word);
                        break;
                    }
                }
            }
        }
    }
 
    return 0;
}
 
int wordExist(int x, int y, int dir, int strlen, char *word)
{
    char sword[5];
    int i = 0, j;
    while(i < strlen){
        sword[i++] = puzzle[x][y];
        sword[i] = '\0';
        for(j=0;j<4;j++){
            if(strcmp(sword,dict[j]) == 0){
                strcpy(word,dict[j]);
                return 1;
            }
        }
        switch (dir){
            case 0:        //从左到右
                y++;
                break;
            case 1:        //从右到左
                y--;
                break;
            case 2:        //从上到下
                x++;
                break;
            case 3:        //从下到上
                x--;
                break;
            case 4:        //从左上到右下
                x++;
                y++;
                break;
            case 5:        //从右下到左上
                x--;
                y--;
                break;
            case 6:        //从左下到右上
                x--;
                y++;
                break;
            case 7:        //从右上到左下
                x++;
                y--;
                break;
            default:
                puts("方向不存在");
                return 0;
         }
         if(x < 0 || y < 0) //数组溢出 
            return 0;
    }
    return 0;
}
