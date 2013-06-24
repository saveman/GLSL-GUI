document.write("<script language='javascript' src='uiBaseClass.js'></script>");
document.write("<script language='javascript' src='textBoxPreset.js'></script>");
function textBoxClass(t_drawer,t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut,
    t_borderColor, t_borderThickness,
    t_textBoxText, t_fontSize, t_textColor, t_boldText,
    t_fillColor, t_editable,
    t_textBoxDrawer) {
    //initiate public member variables for each UI component instance inherited from base class uiBaseClass
    uiBaseClass.call(this, t_drawer,t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut);

    //initiate private member variables of each UI component instance
    var borderColor = (t_borderColor != null) ? t_borderColor : "rgb(10, 0, 0)";
    var borderThickness = (t_borderThickness != null) ? t_borderThickness : 2;
    var textBoxText = (t_textBoxText != null) ? t_textBoxText : "editable textBox";
    var fontSize = (t_fontSize != null) ? t_fontSize : 20;
    var textColor = (t_textColor != null) ? t_textColor : "rgb(30, 30, 0)";
    var boldText = (t_boldText != null) ? t_boldText : false;
    var fillColor = (t_fillColor != null) ? t_fillColor : "rgb(200, 200, 200)";
    var editable = (t_editable != null) ? t_editable : true;
    var textBoxDrawer = (t_textBoxDrawer != null) ? t_textBoxDrawer : textBoxDrawer0;
    //define priviledge member methods to get values of private member variables
    this.getBorderColor = function () {
        return borderColor;
    }
    this.getBorderThickness = function () {
        return borderThickness;
    }
    this.getTextBoxText = function () {
        return textBoxText;
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
    this.getFillColor = function () {
        return fillColor;
    }
    //make sure textbox height is larger than the font height
    if (this.height < fontSize)
        this.height = fontSize;
    //define private member method to draw a text box instance
    function drawTextBox(t_textBox) {
        textBoxDrawer(t_textBox);
    }
    //define private member method to update a text box status
    function updateTextBox(t_textBox) {
        if (editable) {
            if (t_textBox.getInOutMouseStatus() == 1) {
                if (t_textBox.keyboard.keyStatus == 1) {
                    if (t_textBox.keyboard.char == '\b')
                        textBoxText = textBoxText.substring(0, textBoxText.length - 1);
                    else
                        textBoxText += t_textBox.keyboard.char.toString();
                }
                else {
                    textBoxText = textBoxText;
                }
            }
        }
        //max characters limited by text box width
        var metrics = context.measureText(textBoxText);
        if (metrics.width > t_textBox.width)
            textBoxText = textBoxText.substring(0, textBoxText.length - 1);
    }
    //define priviledge member method to update a text box instance
    this.drawing = function () {
        this.updateUI();
        updateTextBox(this);
        drawTextBox(this);
    };
};
//define the public member method to update a text box instance
textBoxClass.prototype.Draw = function () {
    this.drawing();
}