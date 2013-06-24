function keyboardClass() {
    var keyboard = {};
    //keyboard public member variables
    keyboard.char = null; //ASCII code
    keyboard.keyStatus = -1;//up 1, down 0
    keyboard.controlKey = -1; //up 1, down 0
    keyboard.shiftKey = -1; //up 1, down 0
    //keyboard public member methods
    keyboard.setPropertes = function (controlKey, shiftKey, char, keyStatus) {
        keyboard.controlKey = controlKey;
        keyboard.shiftKey = shiftKey;
        keyboard.char = char;
        keyboard.keyStatus = keyStatus;
    }
    keyboard.keyboardEvent = function (handler, event) {
        var controlKey, shiftKey, controlKey;
        window.event.ctrlKey ? controlKey = 0 : controlKey = 1;
        window.event.shiftKey ? shiftKey = 0 : shiftKey = 1;
        char = event.char;
        handler(controlKey, shiftKey, char);
    }
    keyboard.onKeyDown = function (controlKey, shiftKey, char) {
        keyboard.setPropertes(controlKey, shiftKey, char, 0);
    }
    keyboard.onKeyUp = function (controlKey, shiftKey, char) {
        keyboard.setPropertes(controlKey, shiftKey, char, 1);
    }
    keyboard.onKeyPress = function (controlKey, shiftKey, char) {
        keyboard.setPropertes(controlKey, shiftKey, char, 2);
    }
    keyboard.reset = function () {
        keyboard.char = null; //ASCII code
        keyboard.keyStatus = -1;//up 1, down 0
        keyboard.controlKey = -1; //up 1, down 0
        keyboard.shiftKey = -1; //up 1, down 0
    }
    return keyboard;
}