# Test file for Lab2_introToAVR


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


Test “PINA: 0  => PORTB: 1”
set state = start
setPINA 0x00
Continue 2
expectPORTB 0x01
expect state led0on
checkResult

Test “PINA: 1  => PORTB: 2”
set state = start
setPINA 0x01
Continue 2
expectPORTB 0x02
expect state led0press
checkResult

Test “PINA: 0,1,1,0  => PORTB: 1,2,2,2”
set state = start
setPINA 0x00
Continue 2
expectPORTB 0x01
expect state led0on
setPINA 1
Continue 2
expectPORTB 2
expect state led0press
setPINA 1
Continue 2
expectPORTB 2
expect state led0press
setPINA 0
Continue 2
expectPORTB 2
expect state led2on
checkResult

Test “PINA: 1,1,0,1,0  => PORTB: 2,2,2,1,1”
set state = start
setPINA 0x01
Continue 2
expectPORTB 0x02
expect state led0press
setPINA 1
Continue 2
expectPORTB 2
expect state led0press
setPINA 0
Continue 2
expectPORTB 2
expect state led2on
setPINA 1
Continue 2
expectPORTB 1
expect state led2press
setPINA 0
Continue 2
expectPORTB 1
expect state led0on
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
