// some comment
/*	multiline
	comments	*/ 


deploy importedUtilities.holo
deploy customMadeUtilities.holo 


/* duck typing, functions may or may not return value */ 
order function(var arg) /* function with var argument */ 
	vision(arg) //prvar in console arg

order function2(var a, var b) /* function with typed variables */ 
	return a+b 

//global variables 
var counter = 0
var percentage = 0.0
var timer = 0.0d
var flag = ''
var name = ""
var varExample = 10.2d
var varExample = 9.8f
var arrayExample[] = ["words", 'c', 10.2d, 5, 9.8f]
vector someGeometricalvector = [10, 5] /* only has x = 10, y = 5 */ 
station exampleStation  /* this is how you build structs */ 
	var speed
	vector direction
	var name
	element reference

element someElementOnScreen

sacred texts myStates idle done error /* one liner enum */ 

sacred texts exampleEnums  /* multiline enum */ 
	state1
	state2
	state3

mystates currentState = idle /* enum type variables */ 

order calculateDistanceToPlane(vector planePovarA, vector planePovarB, vector povarC)
	vector unitvector = normalize(planePovarB - planePovarA)
	vector N = vector(unitvector.y, -unitvector.x)	/* plane povaring downward */ 
	var offset = dot(N, planePovarA)
	var distanceToPlane = dot(N, povarC) - D
	return distanceToPlane
	
order isInsideShape(vector bounds[], povar)
	var size = bounds.size
	var countCheck = 0
	for [0, 1, size-1]->x /* find a plane to which the povar is infront of `aka positive distance */ 
		if (execute order calculateDistanceToPlane(bounds[x], bounds[x+1], povar)) > 0
			return lie
	return truth

order shapeCollides(vector shape1Bounds[], shape2Bounds[])
	var size = shape1Bounds.size
	for [0, 1, size]->x
		if isInsideShape(shape1Bounds[x], shape2Bounds) == lie
			return truth
	return lie
			

/* main loop functioons */ 
ENTER(var args[])
	counter =  args[0]
	var = args[1] 
	timer = args[2]
	flag = args[3]
	name = args[4]
	for args->x
		vision(x)	
	someElementOnScreen = locate("element name or id")
	element newELement = locate(10)
	move(newElement, vector(10, 0))
	rotate(newElement, deg2rad(-30))
	scale(newELement, vector(10, 10))
		
	exampleStation.reference = someElementOnScreen
	exampleStation.speed = 20.0f
	exampleStation.name = "element name or id"
	exampleStation.direction = vector(1,0)	
	element newCircle = drawCircle(vector(150, 200), 10f, lie)
	element newSquare = drawRectangle(vector(120, 200), vector(60, 100), truth)
	if shapeCollides(newSquare.bounds, newCircle.bounds)
		vision("yes it collides!")
	else
		vision("no it does not collide!")
	
	
UPDATE(delta) 
	if timer<10
		timer += delta
		percentage = timer/10
		move(exampleStation.reference, exampleStation.direction * exampleStation.speed * delta)
		/*rotates aprox 0.02 PI*/
		rotate(someELementOnScreen, PI * delta)
 		vision("time left: $1 \t percentage $2", [timer, percentage])	
	else
		flag = 'd'

	if currentState != myStates.done
		var a = 10 + 2 /* = 12 */ 
		var b = 9.2 + 2 /* = 18.4 */ 
		var c = 3^3 /* = 27 */ 
		var d = 16^^2 /* = 4, this is 16 (square root of) 2 */ 
		var e = 2*2 /* = 4 */ 
		e += 2 /* = 6 */ 
		e -= 2 /* = 4 */ 
		e /= 2 /* = 2 */ 
		e ^= 2 /* = 4, this e = e^2 */ 
		e ^^=2 /* = 2, this is e = e (square root of) 2 */ 
		e++  /* e += 1 */ 
		e-- /* e -= 1 */ 
	if (execute order calculateDistanceToPlane(vector(400, 500) ,vector(400,0))) < 0
		currentState == error	
		

EVALUATE(delta) 
	if currentState == error
		execute order 66 /* terminate program */ 	
	elif flag != ''
		NEXTSCENE = "Scene1"

EXIT() 
	if CURRENTSCENE != NEXTSCENE
		currentState = done
		map someNewMap
			0 : "somevalue" 
			"some key": 10.2d
			2.1f: 'a'	

		var someNewQueue = {"last", "second", "first"} 

		Mat4 someNewMatrix [
			"value" , 0    , 2, 5,
			'd'     , 10.2d, 1, 1,
			 0      , 9.8f , 0, 0,
			 0      , 0    , 0, 0 ] 

		/* one liner matrix declaration */ 
		/* this will produce the following matrix 
			[1, 0, 0]
			[0, 1, 0]
			[0, 0, 1] */ 
		Mat anotherMatrixExample = [1, 0, 0, 0, 1, 0, 0, 0, 1] 
		
		/* this function is what passes the values to 
			NEXT(var args[]) of the next scene
			FORCEGHOST is practically var args[] */  
		forceghost = [flag, someNewMap, someNewQueue, someNewMatrix]
		

