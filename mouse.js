function mouseClass() {
    var mouse = {};
    //mouse public member variables
    mouse.x = -1;
    mouse.y = -1;
    mouse.indicatorUpDown = -1; //up 1, down 0
    //mouse public member methods
    mouse.setPos = function (t_x, t_y) { mouse.x = t_x; mouse.y = t_y; };
    mouse.setIndicatorUpDown = function (t_updown) { mouse.indicatorUpDown = t_updown; };
    mouse.mouseEvent = function (handler, ev) {
        var t_x, t_y;
        // Get the mouse position relative to the canvas element.
        if (ev.layerX || ev.layerX == 0) { // Firefox
            t_x = ev.layerX;
            t_y = ev.layerY;
        } else if (ev.offsetX || ev.offsetX == 0) { // Opera
            t_x = ev.offsetX;
            t_y = ev.offsetY;
        }
        handler(t_x, t_y);
    };
    mouse.onMouseDown = function (t_x, t_y) {
        mouse.setIndicatorUpDown(0);
        mouse.setPos(t_x, t_y);
    };
    mouse.onMouseUp = function (t_x, t_y) {
        mouse.setIndicatorUpDown(1);
        mouse.setPos(t_x, t_y);
    };
    mouse.onMouseMove = function (t_x, t_y) {
        mouse.setPos(t_x, t_y);
    };
    mouse.reset = function () {
        mouse.indicatorUpDown = -1; //up 1, down 0
    }
    return mouse;
}