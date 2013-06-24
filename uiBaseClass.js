
function uiBaseClass(t_drawer,t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut) {
    // the following public uiBaseClass member variables are vital to any UI component, so they can not be null.
    this.drawer = (t_drawer != null) ? t_drawer : alert("t_drawer is null");
    this.mouse = (t_mouse != null) ? t_mouse : alert("t_mouse is null");
    this.keyboard = (t_keyboard != null) ? t_keyboard : alert("t_keyboard is null");
    this.x = (t_x != null) ? t_x : alert("t_x is null");
    this.y = (t_y != null) ? t_y : alert("t_y is null");
    this.width = (t_width != null) ? t_width : alert("t_width is null");
    this.height = (t_height != null) ? t_height : alert("t_height is null");

    // uiBaseClass private member methods for mouse events, are assigned with defualt debug method if not assigned by an uiBaseClass instance 
    this.defaultEventReporter = function (t_eventName) {//used for debug to report UI events
        console.log(t_eventName);
    }
    var onMouseDown = (t_onMouseDown != null) ? t_onMouseDown : this.defaultEventReporter;
    var onMouseHold = (t_onMouseHold != null) ? t_onMouseHold : this.defaultEventReporter;
    var onMouseUp = (t_onMouseUp != null) ? t_onMouseUp : this.defaultEventReporter;
    var onMouseOver = (t_onMouseOver != null) ? t_onMouseOver : this.defaultEventReporter;
    var onMouseOut = (t_onMouseOut != null) ? t_onMouseOut : this.defaultEventReporter;

    //uiBaseClass private members variables for mouse movement status on the corresponding UI component instance: key up/down, cross over/out, within/out of the UI component. 
    var downUpMouseStatus = -1;
    var crossOverOutMouseStatus = -1;
    var inOutMouseStatus = -1;
    // get mouse status through priviledge uiBaseClass member methods
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
    // Update UI component instance apperance by this priviledge member method
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