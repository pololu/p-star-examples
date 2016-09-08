# P-Star Examples

This repository contains example code for the [P-Star 25K50 Micro][pstar25m].
To use these examples, you will need a P-Star, a [Micro-USB
cable](https://www.pololu.com/product/2073), and a computer running Windows,
Linux, or Mac OS X.

The [P-Star 25K50 Micro][pstar25m] is a tiny programmable module featuring
Microchip's PIC18F25K50 microcontroller.  The examples in this repository can be
compiled using either the [MPLAB XPress IDE][xpressinfo], an online IDE from
Microchip that does not require any software installation, or the [MPLAB X
IDE][x], a more powerful IDE that is installed on your computer.  If you are not
sure which IDE to use, we recommed using the MPLAB XPress IDE.


## Compiling examples with the MPLAB XPress IDE

These examples are available on the [MPLAB Xpress Code Examples][examples] page.
In the "Board" column of that page, select "P-Star 25K50" to display all the
examples for the P-Star 25K50.  (Some of those examples might be from other
sources.)  Click the "Open" button next to an example to open that example in
the online IDE.

If you cannot find the example you are looking for on the Examples page, you
might have to upload it to the online IDE yourself.  First, download this
repository as a ZIP files.  Extract the folder containing the example you want
to run, and make a new ZIP file that just contains that folder.  Next, start the
MPLAB XPress IDE by opening [this link][xpressrun] in a new tab.  In the IDE's
"File" menu, select "Import Project" and upload the new ZIP file.

Once you have succeeeded in opening the project in the MPLAB XPress IDE, you
should see some source code on the right side of your browser window, and you
should see the "Project" pane on the left side, which shows all the source and
header files in the project.  Click the "Make and Program Device" button (the
button with a green arrow pointing down).  This will cause the IDE to compile
your program and then download it to your computer as a HEX file.

Once you have the HEX file, you can program it onto your P-Star as described in
the "Programming using p-load" section of the [P-Star user's guide][guide].

For more information about using the MPLAB XPress IDE, see Microchip's [main
page for the MPLAB XPress IDE][xpressinfo].


[pstar25m]: https://www.pololu.com/product/3150
[xpressinfo]: http://www.microchip.com/mplab/mplab-xpress
[xpressrun]: https://mplabxpress.microchip.com/mplabcloud/ide
[x]: http://www.microchip.com/mplab/mplab-x-ide
[examples]: https://mplabxpress.microchip.com/mplabcloud/example
[guide]: https://www.pololu.com/docs/0J62