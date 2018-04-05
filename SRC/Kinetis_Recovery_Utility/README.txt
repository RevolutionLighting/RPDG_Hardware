INTRODUCTION
------------

Beginning with the L Series, certain Freescale Kinetis processors can be configured to disable the RESET pin. 
This setting is configured within the non-volatile FLASH, which causes the RESET pin to be disabled immediately 
after power up. 

Normally, this will not affect debug functionality unless the user's application itself causes the debug pins to 
become unresponsive. Some examples include entering low power mode or configuring the debug pins (eg. SWD_CLK, 
SWD_DIO) to alternate functions. When this occurs, debug functionality is lost even though the processor is operating 
and running code correctly.

This utility attempts to restore the processor by halting it before it executes the "dangerous" section of code that 
disables debug functionality. It accomplishes this by repeatedly sending halt commands to the processor while the user 
is toggling power to the board. If the processor is halted quickly enough, the user can then erase the flash and 
restore the processor back to factory conditions.


USAGE
------------

- Run the utility (Kinetis_Recovery_Utility.exe)
- Select the appropriate P&E hardware interface from the list on the left
- Press the START button
- The utility will now prompt you to repeatedly toggle power to your board
- If the utility is successful, it will display the following message:
"Success. Processor halted."
- Once halted, you must erase the flash before you power down the board. This can be accomplished using P&E's PROGACMP 
programming software or third party debuggers such as Freescale CodeWarrior.


WARNING
------------

It is possible that the processor cannot be restored if the "dangerous" section of code is executed too quickly after 
power up. If the utility appears to be unsuccessful, please visit our website at www.pemicro.com to see if a new version
of this utility is available.

To avoid this problem on future designs, P&E recommends leaving the RESET pin enabled whenever possible. 



VERSION HISTORY
------------
v0.02 
Initial release