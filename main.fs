// comments
/*	multiline
	comments	*/ 


deploy importedUtilities.holo
deploy customMadeUtilities.holo 


/* duck typing, functions may or may not return value */ 
order function(Var arg) /* function with var argument */ 
	vision(arg) //print in console arg

order function2(int a, int b) /* function with typed variables */ 
	return a+b 

//global variables 
int counter = 0
double percentage = 0.0
float timer = 0.0
char flag = ''
string name = ""
var doubleExample = 10.2d
var floatExample = 9.8f
var arrayExample[] = [1, "words", 'c', 10.2d, 5, 9.8f]
Vector someGeometricalVector = [10, 5] /* only has x = 10, y = 5 */ 
station exampleStation  /* this is how you build structs */ 
	var speed
	Vector direction
	string name
	element reference

element someElementOnScreen

sacredtexts myStates idle done error /* one liner enum */ 

sacredtexts exampleEnums  /* multiline enum */ 
	state1
	state2
	state3

mystates currentState = idle /* enum type variables */ 

order calculateDistanceToPlane(vector planePointA, vector planePointB, vector pointC)
	vector unitVector = normalize(planePointB - planePointA)
	vector N = vector(unitVector.y, -unitVector.x)	/* plane pointing downward */ 
	float offset = dot(N, planePointA)
	float distanceToPlane = dot(N, pointC) - D
	return distanceToPlane
	
order isInsideShape(vector bounds[], point)
	int size = bounds.size
	int countCheck = 0
	for [0, 1, size-1]->x /* find a plane to which the point is infront of `aka positive distance */ 
		if (execute order calculateDistanceToPlane(bounds[x], bounds[x+1], point)) > 0
			return lie
	return truth

order shapeCollides(vector shape1Bounds[], shape2Bounds[])
	int size = shape1Bounds.size
	for [0, 1, size]->x
		if isInsideShape(shape1Bounds[x], shape2Bounds) == lie
			return truth
	return lie
			

/* main loop functioons */ 
ENTER(Var args[])
	counter =  args[0]
	double = args[1] 
	timer = args[2]
	flag = args[3]
	name = args[4]
	for args->x
		vision(x)	
	someElementOnScreen = locate("element name or id")
	element newELement = locate(10)
	move(newElement, vector(10, 0))
	rotate(newElement, deg2rad(-30))
	scale(newELement, Vector(10, 10))
		
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
		Var a = 10 + 2 /* = 12 */ 
		Var b = 9.2 + 2 /* = 18.4 */ 
		Var c = 3^3 /* = 27 */ 
		Var d = 16^^2 /* = 4, this is 16 (square root of) 2 */ 
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
		

