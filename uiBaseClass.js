
function uiBaseClass(t_drawer,t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut) {
    this.drawer = t_drawer;
    this.mouse = t_mouse;
    this.keyboard = t_keyboard;

    this.x = t_x;
    this.y = t_y;
    this.width = t_width;
    this.height = t_height;

    this.defaultEventReporter = function (t_eventName) {//used for debug to report UI events
        console.log(t_eventName);
    }
    var onMouseDown = (t_onMouseDown != null) ? t_onMouseDown : this.defaultEventReporter;
    var onMouseHold = (t_onMouseHold != null) ? t_onMouseHold : this.defaultEventReporter;
    var onMouseUp = (t_onMouseUp != null) ? t_onMouseUp : this.defaultEventReporter;
    var onMouseOver = (t_onMouseOver != null) ? t_onMouseOver : this.defaultEventReporter;
    var onMouseOut = (t_onMouseOut != null) ? t_onMouseOut : this.defaultEventReporter;

    var downUpMouseStatus = -1;
    var crossOverOutMouseStatus = -1;
    var inOutMouseStatus = -1;

    this.getDownUpMouseStatus=function()
    {
        return downUpMouseStatus;
    }
    this.getCrossOverOutMouseStatus = function ()
    {
        return crossOverOutMouseStatus;
    }
    this.getInOutMouseStatus = function ()
    {
        return inOutMouseStatus;
    }
    this.updateUI = function () {
        if (this.mouse.x < this.x || this.mouse.x > this.x + this.width || this.mouse.y < this.y || this.mouse.y > this.y + this.height) {
            downUpMouseStatus = -1;

            if (inOutMouseStatus == 0)
                crossOverOutMouseStatus = -1;
            else if (inOutMouseStatus == 1)
                crossOverOutMouseStatus = 4;
            inOutMouseStatus = 0;
        }
        else {
            if (this.mouse.indicatorUpDown == 0) {
                downUpMouseStatus = this.mouse.indicatorUpDown;
                onMouseDown("onMouseDown");
            } else if (this.mouse.indicatorUpDown == 1) {
                downUpMouseStatus = this.mouse.indicatorUpDown;
                onMouseUp("onMouseUp");
            }

            if (inOutMouseStatus == 1)
                crossOverOutMouseStatus = -1;
            else if (inOutMouseStatus == 0)
                crossOverOutMouseStatus = 3;
            inOutMouseStatus = 1;
        }
        if (downUpMouseStatus == 0)
            onMouseHold("onMouseHold");

        if (crossOverOutMouseStatus == 3)
            onMouseOver("onMouseOver");
        else if (crossOverOutMouseStatus == 4)
            onMouseOut("onMouseOut");
    }
}