extern int printf(string format)
extern int puts(string s)


int cal(int a, int b){
    int ret = 0
    if( a <= b ) {
        ret = a + b
    }
    else {ret = a - b}
    return ret
}

int main(){
    int i
    i=cal(3,7)
    printf("i=%d",i)
    puts("")
    return 0
}
