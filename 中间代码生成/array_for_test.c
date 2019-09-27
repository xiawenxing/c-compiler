extern int printf(string str)
extern int puts(string str)

int main(){
    int[5] testarray = [ 1,2,3,4,5 ]

    int i
    
    for(i=0; i<5; i=i+1){
        printf("%d", testarray[i])
        puts("")
    }
  
    return 0
}
