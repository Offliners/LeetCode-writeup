char* triangleType(int* nums, int numsSize) {
    int a = nums[0];
    int b = nums[1];
    int c = nums[2];

    if(!(a + b > c && b + c > a && a + c > b))
        return "none";

    if(a == b && b == c)
        return "equilateral";
    
    if(a == b || b == c || a == c)
        return "isosceles";

    return "scalene";
}