function buttonDrawer0(t_button) {
    var buttonText = t_button.getButtonText();
    var fontSize = t_button.getFontSize();
    var textColor = t_button.getTextColor();
    var boldText = t_button.getBoldText();
    var borderColor = t_button.getBorderColor();
    var filled = t_button.getFilled();
    var borderThickness_X = t_button.getBorderThickness_X();
    var borderThickness_Y = t_button.getBorderThickness_Y();
    var fillColor = t_button.getFillColor();
    var pressDownOffset_x = t_button.getPressDownOffset_x();
    var pressDownOffset_y = t_button.getPressDownOffset_y();
    var renderTextColor = t_button.getRenderTextColor();
    var renderBorderColor = t_button.getRenderBorderColor();
    var renderFillColor = t_button.getRenderFillColor();
    if (fontSize > t_button.height)
        t_button.height = fontSize;
    context.font = boldText + (" " + fontSize.toString() + "px Arial");
    var metrics = context.measureText(buttonText);
    if (metrics.width > t_button.width)
        t_button.width = metrics.width;
    if (filled == 0) {
        drawer.DrawRect(t_button.x - borderThickness_X, t_button.y - borderThickness_Y,
            t_button.width + borderThickness_X * 2, t_button.height + borderThickness_Y * 2, true, renderFillColor);
    }
    drawer.DrawRect(t_button.x, t_button.y, t_button.width, t_button.height, true, renderBorderColor);
    drawer.DrawText(t_button.x + t_button.width * 0.5, t_button.y + t_button.height - 0.5 * (t_button.height - fontSize), renderTextColor, buttonText, fontSize, boldText, "center");
}
function onButtonOn0(t_button) {
    t_button.setRenderColor("rgb(255, 0, 0)", "rgb(50, 60, 60)", "rgb(50, 50, 240)");
}

function onButton2Down(t_button) {
    console.log("Button2 Down");
}
function onButton2Holding(t_button) {
    console.log("Button2 Holding");
}
function onButton2Up(t_button) {
    console.log("Button2 Up");
}
