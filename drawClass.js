function drawClass(t_context) {
    var content = t_context;
    this.DrawRect = function (x, y, width, height, filled, color) {
        if (filled) {
            content.fillStyle = color;
            content.fillRect(x, y, width, height);
        }
        else {
            content.strokeStyle = color;
            content.strokeRect(x, y, width, height);
        }
    }
    this.ClearRect = function (x, y, width, height) {
        content.clearRect(x, y, width, height);
    }
    this.DrawText = function (x, y, color, text, size, bold, align) {
        boldText = "";
        if (bold) {
            boldText = "bold";
        }
        content.font = boldText + (" "+size.toString() + "px Arial");
        content.fillStyle = color;
        content.textAlign = align;
        content.fillText(text, x, y);
    }
}