
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
    var actual:int = 1
    var anterior:int = 1
    var result:int = 0
    vision("Introduce el numero fibonacci a calcular")
    var n:int = 0
    scan(n)
    for[0,1,n]->iter{
        result = anterior + actual
        anterior = actual 
        actual = result
    }
    return result
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

