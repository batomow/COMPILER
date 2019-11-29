/* var a:int 
var b:double 
var c:char 
var d:bool 
var e:string 

order fib:int(var previous:int, var current:int, var n:int){
    if(n > 0){
       return fib(current, current + previous, n - 1)
    }
    return current
} */
order factorial:int(var n:int){
	if(n == 0){
		return 1
	} else {
		return n * factorial(n - 1)
	}
}


order enter:int(){
	var result:int = factorial(10)
    
	print(result)
	return 0
}

