document.write("<script language='javascript' src='uiBaseClass.js'></script>");
document.write("<script language='javascript' src='checkBoxPreset.js'></script>");
function checkBoxClass(t_drawer, t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut,
    t_borderColor, t_borderThickness_X, t_borderThickness_Y, t_checkColor, t_uncheckColor,
    t_onCheckBoxChecked, t_onCheckBoxUnChecked,
    t_checkBoxDrawer) {

    uiBaseClass.call(this, t_drawer, t_mouse, t_keyboard,
    t_x, t_y, t_width, t_height,
    t_onMouseDown, t_onMouseHold, t_onMouseUp, t_onMouseOver, t_onMouseOut);

    var borderColor = (t_borderColor != null) ? t_borderColor : "rgb(0, 0, 0)";
    var borderThickness_X = (t_borderThickness_X != null) ? t_borderThickness_X : 30;
    var borderThickness_Y = (t_borderThickness_Y != null) ? t_borderThickness_Y : 10
    var checkColor = (t_checkColor != null) ? t_checkColor : "rgb(200, 0, 0)";
    var uncheckColor = (t_uncheckColor != null) ? t_uncheckColor : "rgb(255, 255, 255)";
    var onCheckBoxChecked = (t_onCheckBoxChecked != null) ? t_onCheckBoxChecked : onCheckboxChecked0;
    var onCheckBoxUnChecked = (t_onCheckBoxUnChecked != null) ? t_onCheckBoxUnChecked : onCheckboxUnChecked0;
    var checkBoxDrawer = (t_checkBoxDrawer != null) ? t_checkBoxDrawer : checkBoxDrawer0;

    var checkBoxStatus = -1;
    this.getBorderColor = function () {
        return borderColor;
    }
    this.getborderThickness_X = function () {
        return borderThickness_X;
    }
    this.getborderThickness_Y = function () {
        return borderThickness_Y;
    }
    this.getCheckColor = function () {
        return checkColor;
    }
    this.getUncheckColor = function () {
        return uncheckColor;
    }

    function drawCheckBox(t_checkBox) {
        checkBoxDrawer(t_checkBox);
    }
    function updateCheckBox(t_checkBox) {
        if (t_checkBox.getInOutMouseStatus()== 0) {
            checkBoxStatus = checkBoxStatus;
        }
        else {
            if (t_checkBox.mouse.indicatorUpDown == 0) {
                checkBoxStatus = checkBoxStatus;
            }
            else if (t_checkBox.mouse.indicatorUpDown == 1) {
                if (checkBoxStatus == -1)
                    onCheckBoxChecked();
                else if (checkBoxStatus == 1)
                    onCheckBoxUnChecked();
                checkBoxStatus = -checkBoxStatus;
            }
        }
    }
    this.drawing = function () {
        this.updateUI();
        updateCheckBox(this);
        drawCheckBox(this);
    }
    //set/get checkBox status is often used to confirm whether a system need a feature indicated by the checkBox
    this.getCheckBoxStatus=function(){
        return checkBoxStatus;
    }
    this.setCheckBoxStatus = function (t_checkBoxStatus) {
        checkBoxStatus = t_checkBoxStatus;
    }
}

//checkBoxClass.prototype.constructor = checkBoxClass;
checkBoxClass.prototype.Draw = function () {
    this.drawing();
}