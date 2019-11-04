// comments
/*	multiline
	comments	*/ 

deploy newthing.holo
deploy another.holo

//multiple var declarations

var intExample = 23
var doubleExample = 3.0d
var floatExam = 5.32
var floatExample = 5.32f
var stringExample = "string"
var charExample = 'c'
var boolExample = truth
var hexExample = #3F6D12 /* another comment */

// TEST DATA STRUCTURES

//Array
array notInit[12]
array arrayName[] = [1, "words", 'c', 10.2d, 5, 9.8f]
notInit[9] = "algo"
arrayName[0] = 5
var anotherInt = ifName[0]

//Matrix
mat newMat[4][12]
mat otherMat[][] = [
	[1, 2 ,3],
	[4, 5, 6],
	[7, 8, 9]
]
newMat[0][2] = "algo"
var anotherThing = otherMat[1][1]

//Map
map emptyMap
map someNewMap = {
	0 : "somevalue" 
	"some key": 10.2d
	2.1f: 'a'
	thingHere: rectangle({200, 300}, 50, 4, truth)
}
someNewMap[0] = "another value"
emptyMap["key"] = 4.0
var otherVar = someNewMap["some key"] 

//Geometric Vector
vector someGeometricalVector = {10, 5}
someGeometricalVector = {5, 5}

//Elements
element myPlayer = rectangle({200, 300}, 50, 4, lie)

rectangle(myPlayer.x, 10, {23, 1})

//Property Access
myPlayer.x = 150
myPlayer.y = 250
myPlayer.x = myPlayer.y

// functionName definition
order functionName(var arg1, var arg2) {
	return arg1 + arg2
}

// testFunction definition
order testFunction(var arg1, var arg2) {
	// if statement
	if(floatExample > doubleExample) {
		var a = intExample + floatExample
	}
	elif (boolExample) {
		vision(stringExample)
	}
	else {
		return truth
		// do nothing comment
	}


	// for statement
	for [0, 1, size] -> x {
		if (isInsideShape(shape1Bounds, shape2Bounds) == lie) {
			meditate
		} 

	}
	return lie
}
