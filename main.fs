order factorial:int(var n:int){
	if(n == 0){
		return 1
	} else {
		return n * factorial(n - 1)
	}
}


order enter:int(){
    var size:int
    scan(size) 
	var result:int = factorial(size)
	vision(result)
    vector position = {4.5, 7.7}
    vision(position.x)
    vision(position.y)
	return 0
}

