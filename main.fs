
order factorialSecuencial:int(){
    var result:int = 1
    vision("Introduce el factorial a calcular...")
    var n:int = 0
    scan(n)
    for[1,1,n]->iter{
        result = result * iter
    }
    return result
}

order fibonacciSecuencial:int(){
    var first:int = 0
    var second:int = 1
    var next:int
    vision("Introduce el numero fibonacci a calcular")
    var n:int 
    scan(n)
    for[0,1,n]->iter{
        if(iter <= 1){
            next = iter
        } else { 
            next = first + second
            first = second
            secodn = next
        }
    }
    return next
}


order enter:int(){
    var result:int = factorialSecuencial()
    vision("El resultado del factorial es...")
    vision(result)

    result = fibonacciSecuencial()
    vision("El numero de fibonacci es...")
    vision(result)

    return 0
}

