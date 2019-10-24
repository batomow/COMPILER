// test comments
/* test multi-line 
	comments */

MAINSCENE main.fs
SCENES [main.fs, test.fs]

// deploy line

deploy newthing.holo

//multiple var declarations

var intExample = 23
var doubleExample = 3.0d
var floatExample = 5.32f
var stringExample = "string"
var charExample = 'c'
var boolExample = truth

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
	else{
		// do nothing comment
	}

	// for statement
	for [0, 1, size] -> x {
		if (isInsideShape(shape1Bounds[x], shape2Bounds) == lie) {
			return truth
		}
	}
	return lie
}

