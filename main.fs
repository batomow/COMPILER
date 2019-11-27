var a:int = 10
var b:double = 2.5
var c:char = 'c'
var d:bool = lie
var e:string = "holymoly"
vector f = {3, 4}
element g



order fib:int(var previous:int, var current:int, var n:int){
    if(n > 0){
       return fib(current, current + previous, n - 1)
    }
    return current
}

order main:int(){
    var result:int = fib(0, 1, 10)
    return 0
}
