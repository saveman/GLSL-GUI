document.write("<script language='javascript' src='uiBaseClass.js'></script>");
document.write("<script language='javascript' src='buttonPreset.js'></script>");
function buttonClass(t_drawer, t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut,
    t_buttonText,
    t_fontSize, t_textColor, t_boldText,
    t_borderColor, t_filled, t_borderThickness_X, t_borderThickness_Y, t_fillColor,
    t_pressDownOffset_x, t_pressDownOffset_y,
    t_onMouseOn,
    t_buttonDrawer) {

    uiBaseClass.call(this, t_drawer, t_mouse, t_keyboard,
        t_x, t_y, t_width, t_height,
        t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut);

    var buttonText = t_buttonText;
    var fontSize = (t_fontSize!=null)?t_fontSize:20;
    var textColor = (t_textColor != null) ? t_textColor : "rgb(255, 0, 0)";
    var boldText = (t_boldText != null) ? t_boldText : true;
    var borderColor = (t_borderColor != null) ? t_borderColor : "rgb(20, 20, 20)";
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
    var renderBorderColor = borderColor;
    var renderFillColor = fillColor;
    this.setRenderColor = function (t_renderTextColor, t_renderBorderColor, t_renderFillColor) {
        renderTextColor = t_renderTextColor;
        renderBorderColor = t_renderBorderColor;
        renderFillColor = t_renderFillColor;
    };
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
    this.getBorderColor = function () {
        return borderColor;
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
    this.getRenderBorderColor = function () {
        return renderBorderColor;
    }
    this.getRenderFillColor = function () {
        return renderFillColor;
    }

    function drawButton(t_button) {
        buttonDrawer(t_button);       
    }
    function updateButton(t_button) {
        if (t_button.getInOutMouseStatus() == 0) {
            x = x0;
            y = y0;
            renderTextColor = textColor;
            renderBorderColor = borderColor;
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
    this.drawing = function () {
        this.updateUI();
        updateButton(this);
        drawButton(this);
    };
};

buttonClass.prototype.Draw = function () {
    this.drawing();
}