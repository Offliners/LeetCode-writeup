int lengthOfLastWord(char* s) {
    int last_word_length = 0;
    bool is_word = false;

    for(int i = strlen(s) - 1; i >= 0; --i)
    {
        if(s[i] == ' ')
        {
            if(!is_word)
                continue;
            else
                break;
        }

        is_word = true;
        ++last_word_length;
    }

    return last_word_length;
}