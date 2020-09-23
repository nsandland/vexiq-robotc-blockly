# vexiq-robotc-blockly
Blockly editor for generating RobotC code for use on Vex IQ.

This is a Blockly IDE which produces RobotC code for VexIQ. My main purpose is to make the powerful functionality in RobotC more accessible for my son’s beginner team. But I also thought I’d share with anyone else who’d like to use it or improve it.

Because it’s very new, it has somewhat limited functionality. In particular, there is still no support for Touch LED’s or Color sensors. But it’s a github project, so if you have some javascript skills and need those sensors I can help point you in the right direction.

It does have some cool features you may like:
* Event based programming, e.g. kick off a piece of code when a value changes from false to true or true to false.
* No need for the typical "main loop" style program
* Definition of brain ports as part of the visual language
* Points as first class objects, plus built in support for point rotation
* Asynchronous operation (aka tasks)

To use it:

* Go to https://vexiq.sandlands.org/
* Build out a program
* Hit the save button and save the file locally
* Open the saved file in the RobotC IDE
* Compile and run

You can also clone the code to your local machine and run it there by opening index.html in a web browser.

Sample programs are found at:
https://github.com/nsandland/vexiq-robotc-blockly/tree/master/Samples
