const { SerialPort } = require('serialport');
const robot = require('robotjs');

const port = new SerialPort({
    path: 'COM8', //You might need to change this to the port where your Arduino is connected
    baudRate: 9600,
});

console.log("You can now move the mouse using the joystick.");

const screenSize = robot.getScreenSize();

port.on('data', (data) => {
    const [yAxis, xAxis, pulse] = data.toString().split(',');

    const mouseX = Math.round((parseInt(xAxis) / 1023) * screenSize.width);
    const mouseY = Math.round((parseInt(mapValue(yAxis, 1023, 0, 0, 1023)) / 1023) * screenSize.height);

    const sensitivity = 0.6;

    const currentMousePos = robot.getMousePos();
    const newMouseX = currentMousePos.x + sensitivity * (mouseX - currentMousePos.x);
    const newMouseY = currentMousePos.y + sensitivity * (mouseY - currentMousePos.y);

    //If joystick is not moved, do not move the mouse
    if (500 < xAxis && xAxis < 534 && 500 < yAxis && yAxis < 534) {
        voidf();
    } else {
        robot.moveMouseSmooth(newMouseX, newMouseY, 0.1);
    }

    if (parseInt(pulse) === 0) {
        robot.mouseClick();
    }
});




function mapValue(value, fromLow, fromHigh, toLow, toHigh) {
    return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

function voidf() {
    return;
}