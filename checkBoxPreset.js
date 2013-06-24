function checkBoxDrawer0(t_checkBox) {
    var borderThickness_X = t_checkBox.getborderThickness_X();
    var borderThickness_Y = t_checkBox.getborderThickness_Y();
    var innerWidth = t_checkBox.width - 2 * borderThickness_X;
    var innerHeight = t_checkBox.height - 2 * borderThickness_Y;
    var borderColor = t_checkBox.getBorderColor();
    var checkColor = t_checkBox.getCheckColor();
    var uncheckColor = t_checkBox.getUncheckColor();
    t_checkBox.drawer.DrawRect(t_checkBox.x, t_checkBox.y, t_checkBox.width, t_checkBox.height, true, borderColor);
    if (t_checkBox.getCheckBoxStatus() == 1) {
        t_checkBox.drawer.DrawRect(t_checkBox.x + borderThickness_X, t_checkBox.y + borderThickness_Y, innerWidth, innerHeight, true, checkColor);
    }
    else {
        t_checkBox.drawer.DrawRect(t_checkBox.x + borderThickness_X, t_checkBox.y + borderThickness_Y, innerWidth, innerHeight, true, uncheckColor);
    }
}
function onCheckboxChecked0(t_checkBox) {
    console.log("Checkbox Checked");
}
function onCheckboxUnChecked0(t_checkBox) {
    console.log("Checkbox UnChecked");
}

function onCheckbox2MouseDown(t_checkBox) {
    console.log("Checkbox2 MouseDown");
}
function onCheckbox2MouseHold(t_checkBox) {
    console.log("Checkbox2 MouseHold");
}
function onCheckbox2MouseUp(t_checkBox) {
    console.log("Checkbox2 MouseUp");
}
function onCheckbox2MouseOver(t_checkBox) {
    console.log("Checkbox2 MouseOver");
}
function onCheckbox2MouseOut(t_checkBox) {
    console.log("Checkbox2 MouseOver");
}

