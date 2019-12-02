array arr:int[10]

order find:int(var n:int){
    vision("Introduce el elemento al buscar")
    var search:int
    scan(search)
    var first:int = 0
    var last:int = n - 1
    var middle:int = (first + last) / 2
    var flag:bool = lie
    //binary search
    while( (first <= last) && (flag == lie)){
        if(arr[middle] < search){
            first = middle + 1
        } elif (arr[middle] == search) {
            vision("El numero se encontro en la posicion..")
            vision(middle + 1)
            flag = truth
        }else{
            last = middle - 1
        }
        middle = (first + last)/2
    }
    if(first > last){
        vision("El numero no se encontro en el arreglo")
    }
}

order bubbleSort:int(){
    vision("introduce 20 elementos aleatorios")
    for[0,1,19]->iter{
        scan(arr[iter])
    }
    /* -- bubble
        sort ---  */
    var temp:int
    for[0, 1, 18]->i{
        for[0,1,18-i]->j {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            }
        }
    }
    vision("Aqui van ordenados")
    for[0,1,9]->n{
        vision(arr[n])
    }
    
}


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
            second = next
        }
    }
    return next
}


order enter:int(){
    element cuadrado = {0, 1, 3, 100, 100, 1, 1}
    element circulo = {0, 1, 2, 200, 100, 1, 1}

    vector vec = (10.2, 9.1)
    vision(vec.x)
    vision(vec.y)
    
    var result:int = factorialSecuencial()
    vision("El resultado del factorial es...")
    vision(result)

    result = fibonacciSecuencial()
    vision("El numero de fibonacci es...")
    vision(result)

    vision("---Bubble Sort---")
    bubbleSort()

    

    return 0
}

