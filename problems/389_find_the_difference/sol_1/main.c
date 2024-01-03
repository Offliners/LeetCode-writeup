char findTheDifference(char* s, char* t) {
    int s_sum = 0;
    int t_sum = 0;

    int i;
    for(i = 0; s[i] != '\0'; ++i)
    {
        s_sum += s[i];
        t_sum += t[i];
    }
    t_sum += t[i];

    return t_sum - s_sum;
}