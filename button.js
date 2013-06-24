document.write("<script language='javascript' src='uiBaseClass.js'></script>");
document.write("<script language='javascript' src='buttonPreset.js'></script>");
function buttonClass(t_drawer, t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut,
    t_buttonText,
    t_fontSize, t_textColor, t_boldText,
    t_ButtonColor, t_filled, t_borderThickness_X, t_borderThickness_Y, t_fillColor,
    t_pressDownOffset_x, t_pressDownOffset_y,
    t_onMouseOn,
    t_buttonDrawer) {
    //initiate public member variables for each UI component instance inherited from base class uiBaseClass
    uiBaseClass.call(this, t_drawer, t_mouse, t_keyboard,
        t_x, t_y, t_width, t_height,
        t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut);
    //initiate private member variables of each UI component instance
    var buttonText = t_buttonText;
    var fontSize = (t_fontSize!=null)?t_fontSize:20;
    var textColor = (t_textColor != null) ? t_textColor : "rgb(255, 0, 0)";
    var boldText = (t_boldText != null) ? t_boldText : true;
    var buttonColor = (t_ButtonColor != null) ? t_ButtonColor : "rgb(20, 20, 20)";
    var filled = (t_filled != null) ? t_filled : true;
    var borderThickness_X = (t_borderThickness_X != null) ? t_borderThickness_X : 20;
    var borderThickness_Y = (t_borderThickness_Y != null) ? t_borderThickness_Y : 10;
    var fillColor = (t_fillColor != null) ? t_fillColor : "rgb(0, 0, 200)";
    var pressDownOffset_x = (t_pressDownOffset_x != null) ? t_pressDownOffset_x : 10;
    var pressDownOffset_y = (t_pressDownOffset_y != null) ? t_pressDownOffset_y : 5;
    var onMouseOn = (t_onMouseOn != null) ? t_onMouseOn : onButtonOn0;
    var buttonDrawer = (t_buttonDrawer != null) ? t_buttonDrawer : buttonDrawer0;

    var x0 = t_x;
    var y0 = t_y;
    
    var renderTextColor = textColor;
    var renderButtonColor = buttonColor;
    var renderFillColor = fillColor;
    this.setRenderColor = function (t_renderTextColor, t_renderButtonColor, t_renderFillColor) {
        renderTextColor = t_renderTextColor;
        renderButtonColor = t_renderButtonColor;
        renderFillColor = t_renderFillColor;
    };
    //define priviledge member methods to get values of private member variables
    this.getButtonText = function () {
        return buttonText;
    }
    this.getFontSize = function () {
        return fontSize;
    }
    this.getTextColor = function () {
        return textColor;
    }
    this.getBoldText = function () {
        return boldText;
    }
    this.getButtonColor = function () {
        return buttonColor;
    }
    this.getFilled = function () {
        return filled;
    }
    this.getBorderThickness_X = function () {
        return borderThickness_X;
    }
    this.getBorderThickness_Y = function () {
        return borderThickness_Y;
    }
    this.getFillColor = function () {
        return fillColor;
    }
    this.getPressDownOffset_x = function () {
        return pressDownOffset_x;
    }
    this.getPressDownOffset_y = function () {
        return pressDownOffset_y;
    }
    this.getRenderTextColor = function () {
        return renderTextColor;
    }
    this.getRenderButtonColor = function () {
        return renderButtonColor;
    }
    this.getRenderFillColor = function () {
        return renderFillColor;
    }
    //define private member method to draw a button instance
    function drawButton(t_button) {
        buttonDrawer(t_button);       
    }
    //define private member method to update a button status
    function updateButton(t_button) {
        if (t_button.getInOutMouseStatus() == 0) {
            x = x0;
            y = y0;
            renderTextColor = textColor;
            renderButtonColor = buttonColor;
            renderFillColor = fillColor;
        }
        else {
            if (t_button.mouse.indicatorUpDown == 0) {
                t_button.x = x0 + pressDownOffset_x;
                t_button.y = y0 + pressDownOffset_y;
            }
            else if (t_button.mouse.indicatorUpDown == 1) {
                t_button.x = x0;
                t_button.y = y0;
            }
            onMouseOn(t_button);
        }
    }
    //define priviledge member method to update a button instance
    this.drawing = function () {
        this.updateUI();
        updateButton(this);
        drawButton(this);
    };
};
//define the public member method to update a button instance
buttonClass.prototype.Draw = function () {
    this.drawing();
}