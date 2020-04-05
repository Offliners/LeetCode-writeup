int next(int num)
{
    int result = 0;
    int rem;
    
    while(num != 0)
    {
        rem = num % 10;
        num /= 10;
        result += rem * rem;
    }
    
    return result;
}

bool isHappy(int n){
    int num1 = n;
    int num2 = n;
    
    do
    {
        num1 = next(num1);
        num2 = next(next(num2));
    }while(num2 != num1);
    
    return num1 == 1;
}
