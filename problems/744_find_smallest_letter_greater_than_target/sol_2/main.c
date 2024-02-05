char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int front = 0;
    int end = lettersSize - 1;
    char ans = letters[0];

    while(front <= end)
    {
        int mid = front + (end - front) / 2;
        if(letters[mid] <= target)
            front = mid + 1;
        else
        {
            ans = letters[mid];
            end = mid - 1;
        }
    }

    return ans;
}