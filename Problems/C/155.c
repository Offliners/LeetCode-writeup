


typedef struct {
    int* data;
    int* mins;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* stack = malloc(sizeof(MinStack));
    stack->data = NULL;
    stack->mins = NULL;
    stack->size = 0;
    
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    obj->data = realloc(obj->data, sizeof(int) * (obj->size + 1));
    obj->mins = realloc(obj->mins, sizeof(int) * (obj->size + 1));
    obj->data[obj->size] = x;
    
    if((obj->size == 0)||(obj->mins[obj->size - 1] > x))
        obj->mins[obj->size] = x;
    else
        obj->mins[obj->size] = obj->mins[obj->size - 1];
    
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->size - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->mins);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
