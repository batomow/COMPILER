// comments
/*	multiline
	comments	*/ 

//multiple var declarations

var intExample:int = 23
var doubleExample:double = 3.0d 
var floatExam:float = 5.32
var floatExample:float = 5.32f
var stringExample:string = "string"
var charExample:char = 'c'
var boolExample:bool = truth /* another comment */

// TEST DATA STRUCTURES

//Array
array notInit:int[12]
array arrayName:char[6] = ['a', 'b', 'c', 'd', 'e', 'f']
notInit[9] = "algo"
arrayName[0] = 5
var anotherInt:float = ifName[0]

//Matrix
mat newMat:int[4][12]
mat otherMat:int[3][3] = [
	[1, 2 ,3],
	[4, 5, 6],
	[7, 8, 9]
]
newMat[0][2] = "algo"
var anotherThing:string = otherMat[1][1]

//Geometric Vector
vector someGeometricalVector = {10, 5}
someGeometricalVector.x = 5
someGeometricalVecotr.y = 5

//Elements
element myPlayer = rectangle({200, 300}, 50, 4, lie)

rectangle(myPlayer.x, 10, {23, 1})

//Property Access
myPlayer.x = 150
myPlayer.y = 250
myPlayer.x = myPlayer.y


//Expression testing
var a:int = 5 * 2 + 1 / 2 / 1.0 - 5


// function definition
order sumameUnosDoubles:double(var arg1:int, var arg2:double) {
	return arg1 + arg2
}

// another definition
order calculaUnascosas:int(var arg1:char, var arg2:int) {
    var a:float
 	// if statement
	if(floatExample > doubleExample) {
	    a = intExample + floatExample
    } elif (boolExample) {
		if (isInsideShape(shape1Bounds, shape2Bounds) == lie) {
			meditate
		}
	} else {
		return truth
		// do nothing comment
	}

	// for statement
    var x:int 
	for [0, 1, size] -> x {
		if (isInsideShape(shape1Bounds, shape2Bounds) == lie) {
			meditate
		}
	}
    var y:int 
	for arrayName -> y {
		meditate
	}
    
	while (x > 5) {
		vision(x)
        x = x - 1
	}

	return lie
}
