void pushNum(char*, int, int*);
int compress(char* chars, int charsSize){
    int n = charsSize;
    int start = 0;
    int end = 1;
    int index = 0;
    int len;
    while(end<charsSize){
        if(chars[end] != chars[end-1]){
            len = end-start;
            chars[index] = chars[start];
            start = end;
            index++;
            if(len>1){
                pushNum(chars, len, &index);
            }
        }
        end++;
    }
    len = end-start;
    chars[index] = chars[start];
    index++;
    if(len>1){
        pushNum(chars, len, &index);
    }
    return index;
}
void pushNum(char* chars, int len, int* index){
    char num[5];
    sprintf(num, "%d", len);
    int i = 0;
    while(num[i] != '\0'){
        chars[*index] = num[i];
        (*index)++;
        i++;
    }
}