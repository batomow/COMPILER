var a:int 
var b:double 
var c:char 
var d:bool 
var e:string 



order fib:int(var previous:int, var current:int, var n:int){
    if(n > 0){
       return fib(current, current + previous, n - 1)
    }
    return current
}

order enter:int(){
    var result:int = fib(0, 1, 10)
    return 0
}

