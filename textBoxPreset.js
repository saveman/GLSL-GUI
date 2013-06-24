function textBoxDrawer0(t_textBox) {
    // draw box and box text
    drawer.DrawRect(t_textBox.x, t_textBox.y, t_textBox.width, t_textBox.height,
        true, t_textBox.getBorderColor());
    drawer.DrawRect(t_textBox.x + t_textBox.getBorderThickness(), t_textBox.y + t_textBox.getBorderThickness(),
        t_textBox.width - 2 * t_textBox.getBorderThickness(), t_textBox.height - 2 * t_textBox.getBorderThickness(), true, t_textBox.getFillColor());
    drawer.DrawText(t_textBox.x + t_textBox.width * 0.5, t_textBox.y + t_textBox.height - 0.5 * (t_textBox.height - t_textBox.getFontSize()),
        t_textBox.getTextColor(), t_textBox.getTextBoxText(), t_textBox.getFontSize(), t_textBox.getBoldText(), "center");
}
