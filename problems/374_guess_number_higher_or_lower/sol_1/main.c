/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int front = 1;
    int end = n;

    while(front <= end)
    {
        int mid = front + (end - front) / 2;
        if(guess(mid) == 0)
            return mid;
        else if(guess(mid) == 1)
            front = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}